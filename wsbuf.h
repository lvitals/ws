// **********************************************************************
// wsbuf.h  Macro Screen Editor Common Defines
//
// Copyright (C) 2025 Leandro Vital
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// **********************************************************************

#ifndef _WSBUF_H_
#define _WSBUF_H_

#include "ws.h"

void    BuffRec_clearIt(BuffRec* buff, int tabSize);
void    BuffRec_makeFName(BuffRec* buff);
void    BuffRec_setTabSizeFromType(BuffRec* buff);
void    BuffRec_cursToLineChar(BuffRec* buff);
char*   BuffRec_find(BuffRec* buff, char *str, int len);
void    BuffRec_findReplace(BuffRec* buff, char *findStr, int findStrLen, char *replStr,
          int replStrLen);
void    BuffRec_insert(BuffRec* buff, char *p, const char *str, long n);
void    BuffRec_del(BuffRec* buff, char *p, long n);
void    BuffRec_replace(BuffRec* buff, char *p, int c);
void    BuffRec_saveIfOpen(BuffRec* buff);
bool    BuffRec_insertFile(BuffRec* buff, char *fileName, enum InsertMode mode);
void    BuffRec_saveBuffer(BuffRec* buff);
void    BuffRec_beginLine(BuffRec* buff, char **p);
void    BuffRec_backChar(BuffRec* buff, char **p, int n);
void    BuffRec_fwdChar(BuffRec* buff, char **p, int n);
void    BuffRec_backWord(BuffRec* buff, char **p, int n);
void    BuffRec_fwdWord(BuffRec* buff, char **p, int n);
void    BuffRec_backLine(BuffRec* buff, char **p, int n);
void    BuffRec_fwdLine(BuffRec* buff, char **p, int n);
void    BuffRec_upLine(BuffRec* buff, char **p, int n);
void    BuffRec_downLine(BuffRec* buff, char **p, int n);
void    BuffRec_exec(BuffRec* buff);


extern int  lineNum, charNum;           // cursor loc in line, char
extern int  cursRow, cursCol;           // cursor loc on screen
extern bool findGlobal, findForward, findSingle, findAsk;   // find/replace options
extern bool makeBak;

// to be replaced with ncurses routines
void checkKey(char *key);
void waitKey(char *key);
void setColorPair(short pair);

#endif // _WSBUF_H_
