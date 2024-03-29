//========================================================================
//
// Lexer.h
//
// Copyright 1996-2003 Glyph & Cog, LLC
//
//========================================================================

//========================================================================
//
// Modified under the pdf-to-html project - http://pdf-to-html.freedesktop.org
//
// All changes made under the pdf-to-html project to this file are licensed
// under GPL version 2 or later
//
// Copyright (C) 2006, 2007, 2010, 2013, 2017, 2018 Albert Astals Cid <aacid@kde.org>
// Copyright (C) 2006 Krzysztof Kowalczyk <kkowalczyk@gmail.com>
// Copyright (C) 2013 Adrian Johnson <ajohnson@redneon.com>
// Copyright (C) 2013 Thomas Freitag <Thomas.Freitag@alfa.de>
//
// To see a description of the changes please see the Changelog file that
// came with your tarball or type make ChangeLog if you are building from git
//
//========================================================================

#ifndef LEXER_H
#define LEXER_H

#ifdef USE_GCC_PRAGMAS
#pragma interface
#endif

#include "Object.h"
#include "Stream.h"

class XRef;

#define tokBufSize 128		// size of token buffer

//------------------------------------------------------------------------
// Lexer
//------------------------------------------------------------------------

class Lexer {
public:

  // Construct a lexer for a single stream.  Deletes the stream when
  // lexer is deleted.
  Lexer(XRef *xrefA, Stream *str);

  // Construct a lexer for a stream or array of streams (assumes obj
  // is either a stream or array of streams).
  Lexer(XRef *xrefA, Object *obj);

  // Destructor.
  ~Lexer();

  Lexer(const Lexer &) = delete;
  Lexer& operator=(const Lexer &) = delete;

  // Get the next object from the input stream.
  Object getObj(int objNum = -1);
  Object getObj(const char *cmdA, int objNum);
  template<typename T> Object getObj(T) = delete;

  // Skip to the beginning of the next line in the input stream.
  void skipToNextLine();

  // Skip over one character.
  void skipChar() { getChar(); }

  // Get stream.
  Stream *getStream()
    { return curStr.isStream() ? curStr.getStream() : (Stream *)NULL; }

  // Get current position in file.  This is only used for error
  // messages.
  Goffset getPos()
    { return curStr.isStream() ? curStr.streamGetPos() : -1; }

  // Set position in file.
  void setPos(Goffset pos, int dir = 0)
    { if (curStr.isStream()) curStr.streamSetPos(pos, dir); }

  // Returns true if <c> is a whitespace character.
  static GBool isSpace(int c);


  // often (e.g. ~30% on PDF Refernce 1.6 pdf file from Adobe site) getChar
  // is called right after lookChar. In order to avoid expensive re-doing
  // getChar() of underlying stream, we cache the last value found by
  // lookChar() in lookCharLastValueCached. A special value
  // LOOK_VALUE_NOT_CACHED that should never be part of stream indicates
  // that no value was cached
  static const int LOOK_VALUE_NOT_CACHED = -3;
  int lookCharLastValueCached;

private:

  int getChar(GBool comesFromLook = gFalse);
  int lookChar();

  Array *streams;		// array of input streams
  int strPtr;			// index of current stream
  Object curStr;		// current stream
  GBool freeArray;		// should lexer free the streams array?
  char tokBuf[tokBufSize];	// temporary token buffer

  XRef *xref;
};

#endif
