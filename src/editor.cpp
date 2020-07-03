/*
 * This file is part of DGD, https://github.com/dworkin/dgd
 * Copyright (C) 1993-2010 Dworkin B.V.
 * Copyright (C) 2010-2020 DGD Authors (see the commit log for details)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

# include "dgd.h"
# include "str.h"
# include "array.h"
# include "object.h"
# include "interpret.h"
# include "edcmd.h"
# include "editor.h"
# include <stdarg.h>

static Editor *editors;		/* editor table */
static Editor *flist;		/* free list */
static int neditors;		/* # of editors */
static char *tmpedfile;		/* proto temporary file */
static char *outbuf;		/* output buffer */
static Uint outbufsz;		/* chars in output buffer */
static eindex newed;		/* new editor in current task */
static bool recursion;		/* recursion in editor command */
static bool internal;		/* flag editor internal error */

/*
 * initialize editor handling
 */
void Editor::init(char *tmp, int num)
{
    Editor *e, *f;

    tmpedfile = tmp;
    f = (Editor *) NULL;
    neditors = num;
    if (num != 0) {
	outbuf = ALLOC(char, USHRT_MAX + 1);
	editors = ALLOC(Editor, num);
	for (e = editors + num; num != 0; --num) {
	    (--e)->ed = (CmdBuf *) NULL;
	    e->next = f;
	    f = e;
	}
    }
    flist = f;
    newed = EINDEX_MAX;
}

/*
 * terminate all editor sessions
 */
void Editor::finish()
{
    int i;
    Editor *e;

    for (i = neditors, e = editors; i > 0; --i, e++) {
	delete e->ed;
    }
}

/*
 * allow new editor to be created
 */
void Editor::clear()
{
    newed = EINDEX_MAX;
}

/*
 * check for recursion in editor commands
 */
void Editor::checkRecursion()
{
    if (recursion) {
	error("Recursion in editor command");
    }
}

/*
 * start a new editor
 */
void Editor::create(Object *obj)
{
    char tmp[STRINGSZ + 3];
    Editor *e;

    checkRecursion();
    if (EINDEX(newed) != EINDEX_MAX) {
	error("Too many simultaneous editors started");
    }
    e = flist;
    if (e == (Editor *) NULL) {
	error("Too many editor instances");
    }
    flist = e->next;
    obj->etabi = newed = e - editors;
    obj->flags |= O_EDITOR;

    sprintf(tmp, "%s%05u", tmpedfile, EINDEX(obj->etabi));
    Alloc::staticMode();
    e->ed = new CmdBuf(tmp);
    Alloc::dynamicMode();
}

/*
 * delete an editor instance
 */
void Editor::del(Object *obj)
{
    Editor *e;

    checkRecursion();
    e = &editors[EINDEX(obj->etabi)];
    delete e->ed;
    if (obj->etabi == newed) {
	newed = EINDEX_MAX;
    }
    e->ed = (CmdBuf *) NULL;
    e->next = flist;
    flist = e;
    obj->flags &= ~O_EDITOR;
}

/*
 * fake error handler
 */
static void ed_handler(Frame *f, Int depth)
{
    /*
     * This function just exists to prevent the higher level error handler
     * from being called.
     */
    UNREFERENCED_PARAMETER(f);
    UNREFERENCED_PARAMETER(depth);
}

extern void output(const char *, ...);

/*
 * handle an editor command
 */
String *Editor::command(Object *obj, char *cmd)
{
    Editor *e;

    checkRecursion();
    if (strchr(cmd, LF) != (char *) NULL) {
	error("Newline in editor command");
    }

    e = &editors[EINDEX(obj->etabi)];
    outbufsz = 0;
    internal = FALSE;
    try {
	ErrorContext::push();
	recursion = TRUE;
	if (e->ed->command(cmd)) {
	    e->ed->edbuf.lb.inact();
	    recursion = FALSE;
	} else {
	    recursion = FALSE;
	    del(obj);
	}
	ErrorContext::pop();
    } catch (...) {
	e->ed->flags &= ~(CB_INSERT | CB_CHANGE);
	e->ed->edbuf.lb.inact();
	recursion = FALSE;
	if (!internal) {
	    error((char *) NULL);	/* pass on error */
	}
	output("%s\012", ErrorContext::exception()->text);	/* LF */
	ErrorContext::pop();
    }

    if (outbufsz == 0) {
	return (String *) NULL;
    }
    return String::create(outbuf, outbufsz);
}

/*
 * return the editor status of an object
 */
const char *Editor::status(Object *obj)
{
    if (editors[EINDEX(obj->etabi)].ed->flags & CB_INSERT) {
	return "insert";
    } else {
	return "command";
    }
}

/*
 * handle output from the editor
 */
void output(const char *f, ...)
{
    va_list args;
    char buf[2 * MAX_LINE_SIZE + 15];
    Uint len;

    va_start(args, f);
    vsprintf(buf, f, args);
    va_end(args);
    len = strlen(buf);
    if (outbufsz + len > USHRT_MAX) {
	error("Editor output string too long");
    }
    memcpy(outbuf + outbufsz, buf, len);
    outbufsz += len;
}

/*
 * handle an editor internal error
 */
void ed_error(const char *f, ...)
{
    va_list args;

    if (f != (char *) NULL) {
	internal = TRUE;
	ErrorContext::push((ErrorContext::Handler) ed_handler);
	va_start(args, f);
	error(f, args);
	va_end(args);
    } else {
	error((char *) NULL);
    }
}
