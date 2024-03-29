//========================================================================
//
// PreScanOutputDev.h
//
// Copyright 2005 Glyph & Cog, LLC
//
//========================================================================

//========================================================================
//
// Modified under the pdf-to-html project - http://pdf-to-html.freedesktop.org
//
// All changes made under the pdf-to-html project to this file are licensed
// under GPL version 2 or later
//
// Copyright (C) 2009 Carlos Garcia Campos <carlosgc@gnome.org>
// Copyright (C) 2010 Albert Astals Cid <aacid@kde.org>
// Copyright (C) 2011, 2014 William Bader <williambader@hotmail.com>
// Copyright (C) 2011, 2013 Thomas Freitag <Thomas.Freitag@alfa.de>
// Copyright (C) 2011 Adrian Johnson <ajohnson@redneon.com>
//
// To see a description of the changes please see the Changelog file that
// came with your tarball or type make ChangeLog if you are building from git
//
//========================================================================

#ifndef PRESCANOUTPUTDEV_H
#define PRESCANOUTPUTDEV_H

#ifdef USE_GCC_PRAGMAS
#pragma interface
#endif

#include "goo/gtypes.h"
#include "Object.h"
#include "GfxState.h"
#include "GlobalParams.h"
#include "OutputDev.h"

//------------------------------------------------------------------------
// PreScanOutputDev
//------------------------------------------------------------------------

class PreScanOutputDev: public OutputDev {
public:

  // Constructor.
  PreScanOutputDev(PDFDoc *docA);

  // Destructor.
  ~PreScanOutputDev();

  //----- get info about output device

  // Does this device use upside-down coordinates?
  // (Upside-down means (0,0) is the top left corner of the page.)
  GBool upsideDown() override { return gTrue; }

  // Does this device use drawChar() or drawString()?
  GBool useDrawChar() override { return gTrue; }

  // Does this device use tilingPatternFill()?  If this returns false,
  // tiling pattern fills will be reduced to a series of other drawing
  // operations.
  GBool useTilingPatternFill() override { return gTrue; }

  // Does this device use functionShadedFill(), axialShadedFill(), and
  // radialShadedFill()?  If this returns false, these shaded fills
  // will be reduced to a series of other drawing operations.
  GBool useShadedFills(int type) override { return gTrue; }

  // Does this device use beginType3Char/endType3Char?  Otherwise,
  // text in Type 3 fonts will be drawn with drawChar/drawString.
  GBool interpretType3Chars() override { return gTrue; }

  //----- initialization and control

  // Start a page.
  void startPage(int pageNum, GfxState *state, XRef *xref) override;

  // End a page.
  void endPage() override;

  //----- path painting
  void stroke(GfxState *state) override;
  void fill(GfxState *state) override;
  void eoFill(GfxState *state) override;
  GBool tilingPatternFill(GfxState *state, Gfx *gfx, Catalog *cat, Object *str,
			  double *pmat, int paintType, int tilingType, Dict *resDict,
			  double *mat, double *bbox,
			  int x0, int y0, int x1, int y1,
			  double xStep, double yStep) override;
  GBool functionShadedFill(GfxState *state,
			   GfxFunctionShading *shading) override;
  GBool axialShadedFill(GfxState *state, GfxAxialShading *shading, double tMin, double tMax) override;
  GBool radialShadedFill(GfxState *state, GfxRadialShading *shading, double tMin, double tMax) override;

  //----- path clipping
  void clip(GfxState *state) override;
  void eoClip(GfxState *state) override;

  //----- text drawing
  void beginStringOp(GfxState *state) override;
  void endStringOp(GfxState *state) override;
  GBool beginType3Char(GfxState *state, double x, double y,
		       double dx, double dy,
		       CharCode code, Unicode *u, int uLen) override;
  void endType3Char(GfxState *state) override;

  //----- image drawing
  void drawImageMask(GfxState *state, Object *ref, Stream *str,
		     int width, int height, GBool invert,
		     GBool interpolate, GBool inlineImg) override;
  void drawImage(GfxState *state, Object *ref, Stream *str,
		 int width, int height, GfxImageColorMap *colorMap,
		 GBool interpolate, int *maskColors, GBool inlineImg) override;
  void drawMaskedImage(GfxState *state, Object *ref, Stream *str,
		      int width, int height,
		      GfxImageColorMap *colorMap,
		      GBool interpolate,
		      Stream *maskStr, int maskWidth, int maskHeight,
		      GBool maskInvert, GBool maskInterpolate) override;
  void drawSoftMaskedImage(GfxState *state, Object *ref, Stream *str,
			   int width, int height,
			   GfxImageColorMap *colorMap,
			   GBool interpolate,
			   Stream *maskStr,
			   int maskWidth, int maskHeight,
			   GfxImageColorMap *maskColorMap,
			   GBool maskInterpolate) override;

  //----- transparency groups and soft masks
  void beginTransparencyGroup(GfxState *state, double *bbox,
			      GfxColorSpace *blendingColorSpace,
			      GBool isolated, GBool knockout,
			      GBool forSoftMask) override;
  void paintTransparencyGroup(GfxState *state, double *bbox) override;
  void setSoftMask(GfxState *state, double *bbox, GBool alpha,
		   Function *transferFunc, GfxColor *backdropColor) override;

  //----- special access

  // Returns true if the operations performed since the last call to
  // clearStats() are all monochrome (black or white).
  GBool isMonochrome() { return mono; }

  // Returns true if the operations performed since the last call to
  // clearStats() are all gray.
  GBool isGray() { return gray; }

  // Returns true if the operations performed since the last call to
  // clearStats() included any transparency.
  GBool usesTransparency() { return transparency; }

  // Returns true if the operations performed since the last call to
  // clearStats() are all rasterizable by GDI calls in GDIOutputDev.
  GBool isAllGDI() { return gdi; }

  // Returns true if the operations performed since the last call to
  // clearStats() included any image mask fills with a pattern color
  // space. (only level1!)
  GBool usesPatternImageMask() { return patternImgMask; }

  // Clear the stats used by the above functions.
  void clearStats();

private:

  void check(GfxColorSpace *colorSpace, GfxColor *color,
	     double opacity, GfxBlendMode blendMode);

  PDFDoc *doc;
  GBool mono;
  GBool gray;
  GBool transparency;
  GBool gdi;
  PSLevel level;		// PostScript level (1, 2, separation)
  GBool patternImgMask;		
  int inTilingPatternFill;
};

#endif
