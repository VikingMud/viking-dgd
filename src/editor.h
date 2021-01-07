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

class Editor {
public:
    class CmdBuf *ed;		/* editor instance */
    Editor *next;		/* next in free list */

    static void init(char *tmp, int num);
    static void finish();
    static void clear();
    static void create(Object *obj);
    static void del(Object *obj);
    static String *command(Object *obj, char *cmd);
    static const char *status(Object *obj);

private:
    static void checkRecursion();
};

extern ErrorContext *EDC;
