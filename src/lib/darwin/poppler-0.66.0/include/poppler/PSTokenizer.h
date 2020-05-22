//========================================================================
//
// PSTokenizer.h
//
// Copyright 2002-2003 Glyph & Cog, LLC
//
//========================================================================

//========================================================================
//
// Modified under the pdf-to-html project - http://pdf-to-html.freedesktop.org
//
// All changes made under the pdf-to-html project to this file are licensed
// under GPL version 2 or later
//
// Copyright (C) 2006 Scott Turner <scotty1024@mac.com>
//
// To see a description of the changes please see the Changelog file that
// came with your tarball or type make ChangeLog if you are building from git
//
//========================================================================

#ifndef PSTOKENIZER_H
#define PSTOKENIZER_H

#ifdef USE_GCC_PRAGMAS
#pragma interface
#endif

#include "goo/gtypes.h"

//------------------------------------------------------------------------

class PSTokenizer {
public:

  PSTokenizer(int (*getCharFuncA)(void *), void *dataA);
  ~PSTokenizer();

  // Get the next PostScript token.  Returns false at end-of-stream.
  GBool getToken(char *buf, int size, int *length);

private:

  int lookChar();
  void consumeChar();
  int getChar();

  int (*getCharFunc)(void *);
  void *data;
  int charBuf;
};

#endif
