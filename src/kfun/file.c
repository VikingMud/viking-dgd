# ifndef FUNCDEF
# define INCLUDE_FILE_IO
# define INCLUDE_CTYPE
# include "kfun.h"
# include "path.h"
# include "editor.h"
# endif

# ifdef FUNCDEF
FUNCDEF("editor", kf_editor, pt_editor)
# else
char pt_editor[] = { C_TYPECHECKED | C_VARARGS | C_STATIC, T_STRING,
		     1, T_STRING };

/*
 * NAME:	kfun->editor()
 * DESCRIPTION:	handle an editor command
 */
int kf_editor(nargs)
int nargs;
{
    object *obj;
    string *str;

    obj = cframe->obj;
    if (obj->count == 0) {
	error("editor() from destructed object");
    }
    if (obj->flags & O_USER) {
	error("editor() from interactive object");
    }
    if (!(obj->flags & O_EDITOR)) {
	ed_new(obj);
    }
    if (nargs == 0) {
	(--sp)->type = T_INT;
	sp->u.number = 0;
    } else {
	str = ed_command(obj, sp->u.string->text);
	str_del(sp->u.string);
	if (str != (string *) NULL) {
	    str_ref(sp->u.string = str);
	} else {
	    sp->type = T_INT;
	    sp->u.number = 0;
	}
    }
    return 0;
}
# endif


# ifdef FUNCDEF
FUNCDEF("query_editor", kf_query_editor, pt_query_editor)
# else
char pt_query_editor[] = { C_TYPECHECKED | C_STATIC, T_STRING, 1, T_OBJECT };

/*
 * NAME:	kfun->query_editor()
 * DESCRIPTION:	query the editing status of an object
 */
int kf_query_editor()
{
    object *obj;
    char *status;

    obj = &otable[sp->oindex];
    if (obj->flags & O_EDITOR) {
	status = ed_status(obj);
	sp->type = T_STRING;
	str_ref(sp->u.string = str_new(status, (long) strlen(status)));
    } else {
	sp->type = T_INT;
	sp->u.number = 0;
    }
    return 0;
}
# endif


# ifdef FUNCDEF
FUNCDEF("save_object", kf_save_object, pt_save_object)
# else
static int fd;			/* save/restore file descriptor */
static char *buffer;		/* save/restore buffer */
static unsigned int bufsz;	/* size of save/restore buffer */
static uindex narrays;		/* number of arrays/mappings encountered */

/*
 * NAME:	put()
 * DESCRIPTION:	output a number of characters
 */
static void put(buf, len)
register char *buf;
register unsigned int len;
{
    register unsigned int chunk;

    while (bufsz + len > BUF_SIZE) {
	chunk = BUF_SIZE - bufsz;
	memcpy(buffer + bufsz, buf, chunk);
	write(fd, buffer, BUF_SIZE);
	buf += chunk;
	len -= chunk;
	bufsz = 0;
    }
    if (len > 0) {
	memcpy(buffer + bufsz, buf, len);
	bufsz += len;
    }
}

/*
 * NAME:	save_string()
 * DESCRIPTION:	save a string
 */
static void save_string(str)
string *str;
{
    char buf[STRINGSZ];
    register char *p, *q, c;
    register unsigned short len;
    register unsigned int size;

    p = str->text;
    q = buf;
    *q++ = '"';
    for (len = str->len, size = 1; len > 0; --len, size++) {
	if (size >= STRINGSZ - 2) {
	    put(q = buf, size);
	    size = 0;
	}
	switch (c = *p++) {
	case '\0': c = '0'; break;
	case BEL: c = 'a'; break;
	case BS: c = 'b'; break;
	case HT: c = 't'; break;
	case LF: c = 'n'; break;
	case VT: c = 'v'; break;
	case FF: c = 'f'; break;
	case CR: c = 'r'; break;
	case '"':
	case '\\':
	    break;

	default:
	    /* ordinary character */
	    *q++ = c;
	    continue;
	}
	/* escaped character */
	*q++ = '\\';
	size++;
	*q++ = c;
    }
    *q++ = '"';
    put(buf, size + 1);
}

static void save_mapping	P((array*));

/*
 * NAME:	save_array()
 * DESCRIPTION:	save an array
 */
static void save_array(a)
array *a;
{
    char buf[16];
    register uindex i;
    register value *v;
    xfloat flt;

    i = arr_put(a);
    if (i < narrays) {
	/* same as some previous array */
	sprintf(buf, "#%u", i);
	put(buf, strlen(buf));
	return;
    }
    narrays++;

    sprintf(buf, "({%d|", a->size);
    put(buf, strlen(buf));
    for (i = a->size, v = d_get_elts(a); i > 0; --i, v++) {
	switch (v->type) {
	case T_INT:
	    sprintf(buf, "%ld", (long) v->u.number);
	    put(buf, strlen(buf));
	    break;

	case T_FLOAT:
	    VFLT_GET(v, flt);
	    flt_ftoa(&flt, buf);
	    put(buf, strlen(buf));
	    sprintf(buf, "=%04x%08lx", flt.high, (long) flt.low);
	    put(buf, 13);
	    break;

	case T_STRING:
	    save_string(v->u.string);
	    break;

	case T_OBJECT:
	    put("0", 1);
	    break;

	case T_ARRAY:
	    save_array(v->u.array);
	    break;

	case T_MAPPING:
	    save_mapping(v->u.array);
	    break;
	}
	put(",", 1);
    }
    put("})", 2);
}

/*
 * NAME:	save_mapping()
 * DESCRIPTION:	save a mapping
 */
static void save_mapping(a)
array *a;
{
    char buf[16];
    register uindex i, n;
    register value *v;
    xfloat flt;

    i = arr_put(a);
    if (i < narrays) {
	/* same as some previous mapping */
	sprintf(buf, "@%u", i);
	put(buf, strlen(buf));
	return;
    }
    narrays++;
    map_compact(a);

    /*
     * skip index/value pairs of which either is an object
     */
    for (i = n = a->size >> 1, v = d_get_elts(a); i > 0; --i) {
	if (v->type == T_OBJECT) {
	    /* skip object index */
	    --n;
	    v += 2;
	    continue;
	}
	v++;
	if (v->type == T_OBJECT) {
	    /* skip object value */
	    --n;
	}
	v++;
    }
    sprintf(buf, "([%d|", n);
    put(buf, strlen(buf));

    for (i = a->size >> 1, v = a->elts; i > 0; --i) {
	if (v[0].type == T_OBJECT || v[1].type == T_OBJECT) {
	    v += 2;
	    continue;
	}
	switch (v->type) {
	case T_INT:
	    sprintf(buf, "%ld", (long) v->u.number);
	    put(buf, strlen(buf));
	    break;

	case T_FLOAT:
	    VFLT_GET(v, flt);
	    flt_ftoa(&flt, buf);
	    put(buf, strlen(buf));
	    sprintf(buf, "=%04x%08lx", flt.high, (long) flt.low);
	    put(buf, 13);
	    break;

	case T_STRING:
	    save_string(v->u.string);
	    break;

	case T_ARRAY:
	    save_array(v->u.array);
	    break;

	case T_MAPPING:
	    save_mapping(v->u.array);
	    break;
	}
	put(":", 1);
	v++;
	switch (v->type) {
	case T_INT:
	    sprintf(buf, "%ld", (long) v->u.number);
	    put(buf, strlen(buf));
	    break;

	case T_FLOAT:
	    VFLT_GET(v, flt);
	    flt_ftoa(&flt, buf);
	    put(buf, strlen(buf));
	    sprintf(buf, "=%04x%08lx", flt.high, (long) flt.low);
	    put(buf, 13);
	    break;

	case T_STRING:
	    save_string(v->u.string);
	    break;

	case T_ARRAY:
	    save_array(v->u.array);
	    break;

	case T_MAPPING:
	    save_mapping(v->u.array);
	    break;
	}
	put(",", 1);
	v++;
    }
    put("])", 2);
}

char pt_save_object[] = { C_TYPECHECKED | C_STATIC, T_VOID, 1, T_STRING };

/*
 * NAME:	kfun->save_object()
 * DESCRIPTION:	save the variables of the current object
 */
int kf_save_object()
{
    static unsigned short count;
    register unsigned short i, j, nvars;
    register value *var;
    register dvardef *v;
    register control *ctrl;
    register string *str;
    register dinherit *inh;
    register dataspace *data;
    char file[STRINGSZ], buf[16], tmp[STRINGSZ + 8], *_tmp;
    object *obj;
    xfloat flt;

    strcpy(tmp, path_resolve(sp->u.string->text));
    if ((_tmp=path_file(tmp)) == (char *) NULL) {
	return 1;
    }
    strcpy(file, _tmp);

    /*
     * First save in a different file in the same directory, so a possibly
     * existing old instance will not be lost if something goes wrong.
     */
    i_add_ticks(2000);	/* arbitrary */
    _tmp = strrchr(tmp, '/');
    _tmp = (_tmp == (char *) NULL) ? tmp : _tmp + 1;
    sprintf(_tmp, "_tmp%04x", ++count);
    _tmp = path_file(tmp);
    fd = open(_tmp, O_CREAT | O_TRUNC | O_WRONLY | O_BINARY, 0664);
    if (fd < 0) {
	error("Cannot create temporary save file \"/%s\"", tmp);
    }
    buffer = ALLOCA(char, BUF_SIZE);
    bufsz = 0;

    obj = cframe->obj;
    ctrl = o_control(obj);
    data = o_dataspace(obj);
    narrays = 0;
    nvars = 0;
    for (i = ctrl->ninherits, inh = ctrl->inherits; i > 0; --i, inh++) {
	if (inh->varoffset == nvars) {
	    /*
	     * This is the program that has the next variables in the object.
	     * Save non-static variables.
	     */
	    ctrl = o_control(inh->obj);
	    for (j = ctrl->nvardefs, v = d_get_vardefs(ctrl); j > 0; --j, v++) {
		var = d_get_variable(data, nvars);
		if (!(v->class & C_STATIC) && var->type != T_OBJECT &&
		    (var->type != T_INT || var->u.number != 0) &&
		    (var->type != T_FLOAT || !VFLT_ISZERO(var))) {
		    /*
		     * don't save object values or 0
		     */
		    str = d_get_strconst(ctrl, v->inherit, v->index);
		    put(str->text, str->len);
		    put(" ", 1);
		    switch (var->type) {
		    case T_INT:
			sprintf(buf, "%ld", (long) var->u.number);
			put(buf, strlen(buf));
			break;

		    case T_FLOAT:
			VFLT_GET(var, flt);
			flt_ftoa(&flt, buf);
			put(buf, strlen(buf));
			sprintf(buf, "=%04x%08lx", flt.high, (long) flt.low);
			put(buf, 13);
			break;

		    case T_STRING:
			save_string(var->u.string);
			break;

		    case T_ARRAY:
			save_array(var->u.array);
			break;

		    case T_MAPPING:
			save_mapping(var->u.array);
			break;
		    }
		    put("\012", 1);	/* LF */
		}
		nvars++;
	    }
	}
    }

    arr_clear();
    if (bufsz > 0 && write(fd, buffer, bufsz) != bufsz) {
	close(fd);
	AFREE(buffer);
	unlink(_tmp);
	error("Cannot write to temporary save file \"/%s\"", tmp);
    }
    close(fd);
    AFREE(buffer);

    unlink(file);
    if (rename(_tmp, file) < 0) {
	unlink(_tmp);
	error("Cannot rename temporary save file to \"/%s\"",
	      path_unfile(file));
    }

    str_del(sp->u.string);
    sp->type = T_INT;
    sp->u.number = 0;
    return 0;
}
# endif


# ifdef FUNCDEF
FUNCDEF("restore_object", kf_restore_object, pt_restore_object)
# else
# define ACHUNKSZ	16

typedef struct _achunk_ {
    value a[ACHUNKSZ];		/* chunk of arrays */
    struct _achunk_ *next;	/* next in list */
} achunk;

static achunk *alist;		/* list of array chunks */
static int achunksz = ACHUNKSZ;	/* size of current array chunk */

/*
 * NAME:	achunk->put()
 * DESCRIPTION:	put an array into the array chunks
 */
static void ac_put(type, a)
short type;
array *a;
{
    if (achunksz == ACHUNKSZ) {
	register achunk *l;

	l = ALLOC(achunk, 1);
	l->next = alist;
	alist = l;
	achunksz = 0;
    }
    alist->a[achunksz].type = type;
    alist->a[achunksz++].u.array = a;
    narrays++;
}

/*
 * NAME:	achunk->get()
 * DESCRIPTION:	get an array from the array chunks
 */
static value *ac_get(n)
register uindex n;
{
    register uindex sz;
    register achunk *l;

    n = narrays - n;
    for (sz = achunksz, l = alist; n > sz; l = l->next, sz = ACHUNKSZ) {
	n -= sz;
    }
    return &l->a[sz - n];
}

/*
 * NAME:	achunk->clear()
 * DESCRIPTION:	clear the array chunks
 */
static void ac_clear()
{
    register achunk *l, *f;

    for (l = alist; l != (achunk *) NULL; ) {
	f = l;
	l = l->next;
	FREE(f);
    }
    alist = (achunk *) NULL;
    achunksz = ACHUNKSZ;
}


/*
 * NAME:	restore_int()
 * DESCRIPTION:	restore an integer
 */
static char *restore_int(buf, val)
char *buf;
value *val;
{
    char *p;

    val->u.number = strtol(buf, &p, 10);
    if (p == buf) {
	error("digit expected");
    }

    val->type = T_INT;
    return p;
}

/*
 * NAME:	restore_number()
 * DESCRIPTION:	restore a number
 */
static char *restore_number(buf, val)
char *buf;
register value *val;
{
    register char *p;
    register int i;
    xfloat flt;
    bool isfloat;

    val->u.number = strtol(p = buf, &buf, 10);
    if (p == buf) {
	error("digit expected");
    }

    isfloat = FALSE;
    p = buf;
    if (*p == '.') {
	isfloat = TRUE;
	while (isdigit(*++p)) ;
    }
    if (*p == 'e' || *p == 'E') {
	isfloat = TRUE;
	p++;
	if (*p == '+' || *p == '-') {
	    p++;
	}
	if (!isdigit(*p)) {
	    error("digit expected");
	}
	while (isdigit(*++p)) ;
    }
    if (*p == '=') {
	for (i = 4; i > 0; --i) {
	    if (!isxdigit(*++p)) {
		error("hexadecimal digit expected");
	    }
	    flt.high <<= 4;
	    if (isdigit(*p)) {
		flt.high += *p - '0';
	    } else {
		flt.high += toupper(*p) + 10 - 'A';
	    }
	}
	if ((flt.high & 0x7ff0) == 0x7ff0) {
	    error("illegal exponent");
	}
	for (i = 8; i > 0; --i) {
	    if (!isxdigit(*++p)) {
		error("hexadecimal digit expected");
	    }
	    flt.low <<= 4;
	    if (isdigit(*p)) {
		flt.low += *p - '0';
	    } else {
		flt.low += toupper(*p) + 10 - 'A';
	    }
	}

	val->type = T_FLOAT;
	VFLT_PUT(val, flt);
	return p + 1;
    } else if (isfloat) {
	if (!flt_atof(&buf, &flt)) {
	    error("float too large");
	}
	val->type = T_FLOAT;
	VFLT_PUT(val, flt);
	return p;
    }

    val->type = T_INT;
    return p;
}

/*
 * NAME:	restore_string()
 * DESCRIPTION:	restore a string
 */
static char *restore_string(buf, val)
register char *buf;
value *val;
{
    register char *p, *q;

    if (*buf++ != '"') {
	error("'\"' expected");
    }
    for (p = q = buf; *p != '"'; p++) {
	if (*p == '\\') {
	    switch (*++p) {
	    case '0': *q++ = '\0'; continue;
	    case 'a': *q++ = BEL; continue;
	    case 'b': *q++ = BS; continue;
	    case 't': *q++ = HT; continue;
	    case 'n': *q++ = LF; continue;
	    case 'v': *q++ = VT; continue;
	    case 'f': *q++ = FF; continue;
	    case 'r': *q++ = CR; continue;
	    }
	}
	if (*p == '\0' || *p == LF) {
	    error("unterminated string");
	}
	*q++ = *p;
    }

    val->u.string = str_new(buf, (long) q - (long) buf);
    val->type = T_STRING;
    return p + 1;
}

static char *restore_value	P((char*, value*));
static char *restore_mapping	P((char*, value*));

/*
 * NAME:	restore_array()
 * DESCRIPTION:	restore an array
 */
static char *restore_array(buf, val)
register char *buf;
value *val;
{
    register unsigned short i;
    register value *v;
    array *a;
    
    /* match ({ */
    if (*buf++ != '(' || *buf++ != '{') {
	error("'({' expected");
    }
    /* get array size */
    buf = restore_int(buf, val);
    if (*buf++ != '|') {
	error("'|' expected");
    }

    ac_put(T_ARRAY, a = arr_new((long) val->u.number));
    for (i = a->size, v = a->elts; i > 0; --i) {
	(v++)->type = T_INT;
    }
    i = a->size;
    v = a->elts;
    if (ec_push((ec_ftn) NULL)) {
	arr_ref(a);
	arr_del(a);
	error((char *) NULL);	/* pass on the error */
    }
    /* restore the values */
    while (i > 0) {
	buf = restore_value(buf, v);
	i_ref_value(v++);
	if (*buf++ != ',') {
	    error("',' expected");
	}
	--i;
    }
    /* match }) */
    if (*buf++ != '}' || *buf++ != ')') {
	error("'})' expected");
    }
    ec_pop();

    val->type = T_ARRAY;
    val->u.array = a;
    return buf;
}

/*
 * NAME:	restore_mapping()
 * DESCRIPTION:	restore a mapping
 */
static char *restore_mapping(buf, val)
register char *buf;
value *val;
{
    register unsigned short i;
    register value *v;
    array *a;
    
    /* match ([ */
    if (*buf++ != '(' || *buf++ != '[') {
	error("'([' expected");
    }
    /* get mapping size */
    buf = restore_int(buf, val);
    if (*buf++ != '|') {
	error("'|' expected");
    }

    ac_put(T_MAPPING, a = map_new((long) val->u.number << 1));
    for (i = a->size, v = a->elts; i > 0; --i) {
	(v++)->type = T_INT;
    }
    i = a->size;
    v = a->elts;
    if (ec_push((ec_ftn) NULL)) {
	arr_ref(a);
	arr_del(a);
	error((char *) NULL);	/* pass on the error */
    }
    /* restore the values */
    while (i > 0) {
	buf = restore_value(buf, v);
	i_ref_value(v++);
	if (*buf++ != ':') {
	    error("':' expected");
	}
	buf = restore_value(buf, v);
	i_ref_value(v++);
	if (*buf++ != ',') {
	    error("',' expected");
	}
	i -= 2;
    }
    /* match ]) */
    if (*buf++ != ']' || *buf++ != ')') {
	error("'])' expected");
    }
    map_sort(a);
    ec_pop();

    val->type = T_MAPPING;
    val->u.array = a;
    return buf;
}

/*
 * NAME:	restore_value()
 * DESCRIPTION:	restore a value
 */
static char *restore_value(buf, val)
register char *buf;
register value *val;
{
    switch (*buf) {
    case '"':
	return restore_string(buf, val);

    case '(':
	if (buf[1] == '{') {
	    return restore_array(buf, val);
	} else {
	    return restore_mapping(buf, val);
	}

    case '#':
	buf = restore_int(buf + 1, val);
	if ((uindex) val->u.number >= narrays) {
	    error("bad array reference");
	}
	*val = *ac_get((uindex) val->u.number);
	if (val->type != T_ARRAY) {
	    error("bad array reference");
	}
	return buf;

    case '@':
	buf = restore_int(buf + 1, val);
	if ((uindex) val->u.number >= narrays) {
	    error("bad mapping reference");
	}
	*val = *ac_get((uindex) val->u.number);
	if (val->type != T_MAPPING) {
	    error("bad mapping reference");
	}
	return buf;

    default:
	return restore_number(buf, val);
    }
}

char pt_restore_object[] = { C_TYPECHECKED | C_STATIC, T_INT, 1, T_STRING };

/*
 * NAME:	kfun->restore_object()
 * DESCRIPTION:	restore the variables of the current object from file
 */
int kf_restore_object()
{
    struct stat sbuf;
    register int i, j;
    register unsigned short nvars, checkpoint;
    register char *buf;
    register value *var;
    register dvardef *v;
    register control *ctrl;
    register dataspace *data;
    register dinherit *inh;
    object *obj;
    char *file, *name;
    static int line;
    bool pending;

    obj = cframe->obj;
    file = path_file(path_resolve(sp->u.string->text));
    if (file == (char *) NULL) {
	return 1;
    }

    i_add_ticks(2000);	/* arbitrary */
    str_del(sp->u.string);
    sp->type = T_INT;
    sp->u.number = 0;
    fd = open(file, O_RDONLY | O_BINARY, 0);
    if (fd < 0) {
	/* restore failed */
	return 0;
    }
    fstat(fd, &sbuf);
    if ((sbuf.st_mode & S_IFMT) != S_IFREG) {
	/* not a save file */
	close(fd);
	return 0;
    }
    buffer = ALLOCA(char, sbuf.st_size + 1);
    if (read(fd, buffer, (unsigned int) sbuf.st_size) != sbuf.st_size) {
	/* read failed (should never happen, but...) */
        close(fd);
	AFREE(buffer);
	return 0;
    }
    buffer[sbuf.st_size] = '\0';
    close(fd);

    /*
     * First, initialize all non-static variables that do not hold object
     * values to 0.
     */
    ctrl = o_control(obj);
    data = o_dataspace(obj);
    nvars = 0;
    for (i = ctrl->ninherits, inh = ctrl->inherits; i > 0; --i, inh++) {
	if (inh->varoffset == nvars) {
	    /*
	     * This is the program that has the next variables in the object.
	     */
	    ctrl = o_control(inh->obj);
	    for (j = ctrl->nvardefs, v = d_get_vardefs(ctrl); j > 0; --j, v++) {
		var = d_get_variable(data, nvars);
		if (!(v->class & C_STATIC) && var->type != T_OBJECT) {
		    d_assign_var(data, var, (v->type == T_FLOAT) ?
					     &zero_float : &zero_value);
		}
		nvars++;
	    }
	}
    }

    narrays = 0;
    buf = buffer;
    line = 1;
    pending = FALSE;
    if (ec_push((ec_ftn) NULL)) {
	char err[32];

	/* error; clean up */
	arr_clear();
	ac_clear();
	AFREE(buffer);
	strcpy(err, errormesg());
	error("Format error in \"/%s\", line %d: %s", file, line, err);
    }
    for (;;) {
	var = data->variables;
	nvars = 0;
	for (i = ctrl->ninherits, inh = ctrl->inherits; i > 0; --i, inh++) {
	    if (inh->varoffset == nvars) {
		/*
		 * Restore non-static variables.
		 */
		ctrl = inh->obj->ctrl;
		for (j = ctrl->nvardefs, v = ctrl->vardefs; j > 0; --j, v++) {
		    if (pending && nvars == checkpoint) {
			/*
			 * The saved variable is not in this object.
			 * Skip it.
			 */
			buf = strchr(buf, LF);
			if (buf == (char *) NULL) {
			    error("'\\n' expected");
			}
			buf++;
			line++;
			pending = FALSE;
		    }
		    if (!pending) {
			/*
			 * get a new variable name from the save file
			 */
			while (*buf == '#') {
			    /* skip comment */
			    buf = strchr(buf, LF);
			    if (buf == (char *) NULL) {
				error("'\\n' expected");
			    }
			    buf++;
			    line++;
			}
			if (*buf == '\0') {
			    /* end of file */
			    break;
			}

			name = buf;
			if (!isalpha(*buf) && *buf != '_') {
			    error("alphanumeric expected");
			}
			do {
			    buf++;
			} while (isalnum(*buf) || *buf == '_');
			if (*buf != ' ') {
			    error("' ' expected");
			}

			*buf++ = '\0';		/* terminate name */
			pending = TRUE;		/* start checking variables */
			checkpoint = nvars;	/* from here */
		    }

		    if (!(v->class & C_STATIC) &&
			strcmp(name, d_get_strconst(ctrl, v->inherit,
						    v->index)->text) == 0) {
			value tmp;

			/*
			 * found the proper variable to restore
			 */
			buf = restore_value(buf, &tmp);
			if (v->type != tmp.type && v->type != T_MIXED &&
			    conf_typechecking() &&
			    (tmp.type != T_INT || tmp.u.number != 0 ||
			     v->type == T_FLOAT) &&
			    (tmp.type != T_ARRAY || (v->type & T_REF) == 0)) {
			    i_ref_value(&tmp);
			    i_del_value(&tmp);
			    error("value has wrong type");
			}
			d_assign_var(data, var, &tmp);
			if (*buf++ != LF) {
			    error("'\\n' expected");
			}
			line++;
			pending = FALSE;
		    }
		    var++;
		    nvars++;
		}
		if (!pending && *buf == '\0') {
		    /*
		     * finished restoring
		     */
		    ec_pop();
		    arr_clear();
		    ac_clear();
		    AFREE(buffer);
		    sp->u.number = 1;
		    return 0;
		}
	    }
	}
    }
}
# endif


# ifdef FUNCDEF
FUNCDEF("write_file", kf_write_file, pt_write_file)
# else
char pt_write_file[] = { C_TYPECHECKED | C_VARARGS | C_STATIC, T_INT, 3,
			 T_STRING, T_STRING, T_INT };

/*
 * NAME:	kfun->write_file()
 * DESCRIPTION:	write a string to a file
 */
int kf_write_file(nargs)
int nargs;
{
    struct stat sbuf;
    register Int l;
    char *file;
    int fd;

    switch (nargs) {
    case 0:
    case 1:
	return -1;

    case 2:
	l = 0;
	break;

    case 3:
	l = (sp++)->u.number;
	break;
    }
    file = path_file(path_resolve(sp[1].u.string->text));
    if (file == (char *) NULL) {
	return 1;
    }

    i_add_ticks(1000 + (Int) 2 * sp->u.string->len);
    str_del(sp[1].u.string);
    sp[1].type = T_INT;
    sp[1].u.number = 0;

    fd = open(file, O_CREAT | O_WRONLY | O_BINARY, 0664);
    if (fd < 0) {
	str_del((sp++)->u.string);
	return 0;
    }

    fstat(fd, &sbuf);
    if (l == 0) {
	/* the default is to append to the file */
	l = sbuf.st_size;
    } else if (l < 0) {
	/* offset from the end of the file */
	l += sbuf.st_size;
    }
    if (l < 0 || l > sbuf.st_size || lseek(fd, l, SEEK_SET) < 0) {
	/* bad offset */
	close(fd);
	str_del((sp++)->u.string);
	return 0;
    }

    if (write(fd, sp->u.string->text, sp->u.string->len) == sp->u.string->len) {
	/* succesful write */
	sp[1].u.number = 1;
    }
    close(fd);

    str_del((sp++)->u.string);
    return 0;
}
# endif


# ifdef FUNCDEF
FUNCDEF("read_file", kf_read_file, pt_read_file)
# else
char pt_read_file[] = { C_TYPECHECKED | C_VARARGS | C_STATIC, T_STRING, 3,
			T_STRING, T_INT, T_INT };

/*
 * NAME:	kfun->read_file()
 * DESCRIPTION:	read a string from file
 */
int kf_read_file(nargs)
int nargs;
{
    struct stat sbuf;
    register Int l, size;
    char *file;
    int fd;

    l = 0;
    size = 0;
    switch (nargs) {
    case 3:
	size = (sp++)->u.number;
    case 2:
	l = (sp++)->u.number;	/* offset in file */
    case 1:
	break;

    case 0:
	return -1;
    }
    file = path_file(path_resolve(sp->u.string->text));
    if (file == (char *) NULL) {
	return 1;
    }

    str_del(sp->u.string);
    sp->type = T_INT;
    sp->u.number = 0;

    if (size < 0) {
	/* size has to be >= 0 */
	return 0;
    }
    i_add_ticks(1000);
    fd = open(file, O_RDONLY | O_BINARY, 0);
    if (fd < 0) {
	/* cannot open file */
	return 0;
    }
    fstat(fd, &sbuf);
    if ((sbuf.st_mode & S_IFMT) != S_IFREG) {
	/* not a plain file */
	close(fd);
	return 0;
    }

    if (l != 0) {
	/*
	 * seek in file
	 */
	if (l < 0) {
	    /* offset from end of file */
	    l += sbuf.st_size;
	}
	if (l < 0 || l >= sbuf.st_size || lseek(fd, l, SEEK_SET) < 0) {
	    /* bad seek */
	    close(fd);
	    return 0;
	}
	sbuf.st_size -= l;
    }

    if (size == 0 || size > sbuf.st_size) {
	size = sbuf.st_size;
    }
    if (ec_push((ec_ftn) NULL)) {
	close(fd);
	error((char *) NULL);	/* pass on error */
    } else {
	str_ref(sp->u.string = str_new((char *) NULL, size));
	sp->type = T_STRING;
	ec_pop();
    }
    if (size > 0 && read(fd, sp->u.string->text, (unsigned int) size) != size) {
	/* read failed (should never happen, but...) */
	close(fd);
	error("Read failed in read_file()");
    }
    close(fd);
    i_add_ticks(2 * size);

    return 0;
}
# endif


# ifdef FUNCDEF
FUNCDEF("rename_file", kf_rename_file, pt_rename_file)
# else
char pt_rename_file[] = { C_TYPECHECKED | C_STATIC, T_INT, 2,
			  T_STRING, T_STRING };

/*
 * NAME:	kfun->rename_file()
 * DESCRIPTION:	rename a file
 */
int kf_rename_file()
{
    char buf[STRINGSZ], *file;

    file = path_file(path_resolve(sp[1].u.string->text));
    if (file == (char *) NULL) {
	return 1;
    }
    strcpy(buf, file);
    file = path_file(path_resolve(sp->u.string->text));
    if (file == (char *) NULL) {
	return 2;
    }

    i_add_ticks(1000);
    str_del((sp++)->u.string);
    str_del(sp->u.string);
    sp->type = T_INT;
    sp->u.number = (access(buf, W_OK) >= 0 && access(file, F_OK) < 0 &&
		    rename(buf, file) >= 0);
    return 0;
}
# endif


# ifdef FUNCDEF
FUNCDEF("remove_file", kf_remove_file, pt_remove_file)
# else
char pt_remove_file[] = { C_TYPECHECKED | C_STATIC, T_INT, 1, T_STRING };

/*
 * NAME:	kfun->remove_file()
 * DESCRIPTION:	remove a file
 */
int kf_remove_file()
{
    char *file;

    file = path_file(path_resolve(sp->u.string->text));
    if (file == (char *) NULL) {
	return 1;
    }

    i_add_ticks(1000);
    str_del(sp->u.string);
    sp->type = T_INT;
    sp->u.number = (access(file, W_OK) >= 0 && unlink(file) >= 0);
    return 0;
}
# endif


# ifdef FUNCDEF
FUNCDEF("make_dir", kf_make_dir, pt_make_dir)
# else
char pt_make_dir[] = { C_TYPECHECKED | C_STATIC, T_INT, 1, T_STRING };

/*
 * NAME:	kfun->make_dir()
 * DESCRIPTION:	create a directory
 */
int kf_make_dir()
{
    char *file;

    file = path_file(path_resolve(sp->u.string->text));
    if (file == (char *) NULL) {
	return 1;
    }

    i_add_ticks(1000);
    str_del(sp->u.string);
    sp->type = T_INT;
    sp->u.number = (mkdir(file, 0775) >= 0);
    return 0;
}
# endif


# ifdef FUNCDEF
FUNCDEF("remove_dir", kf_remove_dir, pt_remove_dir)
# else
char pt_remove_dir[] = { C_TYPECHECKED | C_STATIC, T_INT, 1, T_STRING };

/*
 * NAME:	kfun->remove_dir()
 * DESCRIPTION:	remove an empty directory
 */
int kf_remove_dir()
{
    char *file;

    file = path_file(path_resolve(sp->u.string->text));
    if (file == (char *) NULL) {
	return 1;
    }

    i_add_ticks(1000);
    str_del(sp->u.string);
    sp->type = T_INT;
    sp->u.number = (rmdir(file) >= 0);
    return 0;
}
# endif


# ifdef FUNCDEF
FUNCDEF("get_dir", kf_get_dir, pt_get_dir)
# else
/*
 * NAME:	match()
 * DESCRIPTION:	match a regular expression
 */
static int match(pat, text)
register char *pat, *text;
{
    bool found, reversed;
    int matched;

    for (;;) {
	switch (*pat) {
	case '\0':
	    /* end of pattern */
	    return (*text == '\0');

	case '?':
	    /* any single character */
	    if (*text == '\0') {
		return 0;
	    }
	    break;

	case '*':
	    /* any string */
	    pat++;
	    if (*pat == '\0') {
		/* quick check */
		return 1;
	    }
	    do {
		matched = match(pat, text);
		if (matched != 0) {
		    return matched;
		}
	    } while (*text++ != '\0');
	    return -1;

	case '[':
	    /* character class */
	    pat++;
	    found = FALSE;
	    if (*pat == '^') {
		reversed = TRUE;
		pat++;
	    } else {
		reversed = FALSE;
	    }
	    for (;;) {
		if (*pat == '\0') {
		    /* missing ']' */
		    return 0;
		}
		if (*pat == ']') {
		    /* end of character class */
		    if (found != reversed) {
			break;
		    }
		    return 0;
		}
		if (*pat == '\\') {
		    /* escaped char (should be ']') */
		    ++pat;
		    if (*pat == '\0') {
			return 0;
		    }
		}
		if (pat[1] == '-') {
		    /* character range */
		    pat += 2;
		    if (*pat == '\0') {
			return 0;
		    }
		    if (UCHAR(*text) >= UCHAR(pat[-2]) &&
			UCHAR(*text) <= UCHAR(pat[0])) {
			found = TRUE;
		    }
		} else if (*pat == *text) {
		    /* matched single character */
		    found = TRUE;
		}
		pat++;
	    }
	    break;

	case '\\':
	    /* escaped character */
	    if (*++pat == '\0') {
		/* malformed pattern */
		return 0;
	    }
	default:
	    /* ordinary character */
	    if (*pat != *text) {
		return 0;
	    }
	}
	pat++;
	text++;
    }
}

typedef struct _finfo_ {
    string *name;		/* file name */
    Int size;			/* file size */
    Int time;			/* file time */
} finfo;

/*
 * NAME:	getinfo()
 * DESCRIPTION:	get info about a file
 */
static bool getinfo(path, file, f)
char *path, *file;
register finfo *f;
{
    struct stat sbuf;

    if (stat(path_file(path), &sbuf) < 0) {
	/*
	 * the file does not exist
	 */
	return FALSE;
    }

    str_ref(f->name = str_new(file, (long) strlen(file)));
    if ((sbuf.st_mode & S_IFMT) == S_IFDIR) {
	f->size = -2;	/* special value for directory */
    } else {
	f->size = sbuf.st_size;
    }
    f->time = sbuf.st_mtime;

    return TRUE;
}

static int cmp P((cvoid*, cvoid*));

/*
 * NAME:	cmp()
 * DESCRIPTION:	compare two file info structs
 */
static int cmp(cv1, cv2)
cvoid *cv1, *cv2;
{
    return strcmp(((finfo *) cv1)->name->text,
		  ((finfo *) cv2)->name->text);
}

char pt_get_dir[] = { C_TYPECHECKED | C_STATIC, T_MIXED | (2 << REFSHIFT), 1,
		      T_STRING };

# define FINFO_CHUNK	128

/*
 * NAME:	kfun->get_dir()
 * DESCRIPTION:	remove a file
 */
int kf_get_dir()
{
    register unsigned int i, nfiles, ftabsz;
    register finfo *ftable;
    char *file, *dir, *pat, buf[STRINGSZ];
    finfo finf;
    array *a;

    file = path_resolve(sp->u.string->text);
    if (path_file(file) == (char *) NULL) {
	return 1;
    }

    strcpy(buf, file);
    pat = strrchr(buf, '/');
    if (pat == (char *) NULL) {
	dir = ".";
	pat = buf;
    } else {
	/* separate directory and pattern */
	dir = buf;
	*pat++ = '\0';
    }

    ftable = ALLOCA(finfo, ftabsz = FINFO_CHUNK);
    nfiles = 0;
    if (strpbrk(pat, "?*[\\") == (char *) NULL &&
	getinfo(file, pat, &ftable[0])) {
	/*
	 * single file
	 */
	nfiles++;
    } else if (strcmp(dir, ".") == 0 || chdir(path_file(dir)) >= 0) {
	if (P_opendir(path_file("."))) {
	    /*
	     * read files from directory
	     */
	    i = conf_array_size();
	    while (nfiles < i && (file=P_readdir()) != (char *) NULL) {
		file = path_unfile(file);
		if (match(pat, file) > 0 && getinfo(file, file, &finf)) {
		    /* add file */
		    if (nfiles == ftabsz) {
			finfo *tmp;

			tmp = ALLOCA(finfo, ftabsz + FINFO_CHUNK);
			memcpy(tmp, ftable, ftabsz * sizeof(finfo));
			ftabsz += FINFO_CHUNK;
			AFREE(ftable);
			ftable = tmp;
		    }
		    ftable[nfiles++] = finf;
		}
	    }
	    P_closedir();

	    if (nfiles == 0) {
		AFREE(ftable);
	    }
	}

	if (strcmp(dir, ".") != 0 && chdir(conf_base_dir()) < 0) {
	    fatal("cannot chdir back to base dir");
	}
    }

    /* prepare return value */
    str_del(sp->u.string);
    sp->type = T_ARRAY;
    arr_ref(sp->u.array = a = arr_new(3L));
    a->elts[0].type = T_ARRAY;
    arr_ref(a->elts[0].u.array = arr_new((long) nfiles));
    a->elts[1].type = T_ARRAY;
    arr_ref(a->elts[1].u.array = arr_new((long) nfiles));
    a->elts[2].type = T_ARRAY;
    arr_ref(a->elts[2].u.array = arr_new((long) nfiles));

    i_add_ticks(1000 + 5 * nfiles);

    if (nfiles != 0) {
	register value *n, *s, *t;

	qsort(ftable, nfiles, sizeof(finfo), cmp);
	n = a->elts[0].u.array->elts;
	s = a->elts[1].u.array->elts;
	t = a->elts[2].u.array->elts;
	for (i = nfiles; i > 0; --i, ftable++) {
	    n->type = T_STRING;
	    n->u.string = ftable->name;
	    s->type = T_INT;
	    s->u.number = ftable->size;
	    t->type = T_INT;
	    t->u.number = ftable->time;
	    n++, s++, t++;
	}
	AFREE(ftable - nfiles);
    }

    return 0;
}
# endif
