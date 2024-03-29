//========================================================================
//
// SplashFTFontEngine.h
//
//========================================================================

//========================================================================
//
// Modified under the pdf-to-html project - http://pdf-to-html.freedesktop.org
//
// All changes made under the pdf-to-html project to this file are licensed
// under GPL version 2 or later
//
// Copyright (C) 2006 Takashi Iwai <tiwai@suse.de>
// Copyright (C) 2009 Petr Gajdos <pgajdos@novell.com>
// Copyright (C) 2009, 2018 Albert Astals Cid <aacid@kde.org>
// Copyright (C) 2011 Andreas Hartmetz <ahartmetz@gmail.com>
// Copyright (C) 2013 Thomas Freitag <Thomas.Freitag@alfa.de>
// Copyright (C) 2017 Adrian Johnson <ajohnson@redneon.com>
//
// To see a description of the changes please see the Changelog file that
// came with your tarball or type make ChangeLog if you are building from git
//
//========================================================================

#ifndef SPLASHFTFONTENGINE_H
#define SPLASHFTFONTENGINE_H

#ifdef USE_GCC_PRAGMAS
#pragma interface
#endif

#include <ft2build.h>
#include FT_FREETYPE_H
#include "goo/gtypes.h"

class SplashFontFile;
class SplashFontFileID;
class SplashFontSrc;

//------------------------------------------------------------------------
// SplashFTFontEngine
//------------------------------------------------------------------------

class SplashFTFontEngine {
public:

  static SplashFTFontEngine *init(GBool aaA, GBool enableFreeTypeHintingA, GBool enableSlightHinting);

  ~SplashFTFontEngine();

  SplashFTFontEngine(const SplashFTFontEngine&) = delete;
  SplashFTFontEngine& operator=(const SplashFTFontEngine&) = delete;

  // Load fonts.
  SplashFontFile *loadType1Font(SplashFontFileID *idA, SplashFontSrc *src,  const char **enc);
  SplashFontFile *loadType1CFont(SplashFontFileID *idA, SplashFontSrc *src,  const char **enc);
  SplashFontFile *loadOpenTypeT1CFont(SplashFontFileID *idA, SplashFontSrc *src,  const char **enc);
  SplashFontFile *loadCIDFont(SplashFontFileID *idA, SplashFontSrc *src);
  SplashFontFile *loadOpenTypeCFFFont(SplashFontFileID *idA, SplashFontSrc *src,
                                      int *codeToGID, int codeToGIDLen);
  SplashFontFile *loadTrueTypeFont(SplashFontFileID *idA, SplashFontSrc *src,
				   int *codeToGID, int codeToGIDLen, int faceIndex = 0);
  GBool getAA() { return aa; }
  void setAA(GBool aaA) { aa = aaA; }

private:

  SplashFTFontEngine(GBool aaA, GBool enableFreeTypeHintingA, GBool enableSlightHintingA, FT_Library libA);

  GBool aa;
  GBool enableFreeTypeHinting;
  GBool enableSlightHinting;
  FT_Library lib;
  GBool useCIDs;

  friend class SplashFTFontFile;
  friend class SplashFTFont;
};

#endif
