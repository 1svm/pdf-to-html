//========================================================================
//
// Function.h
//
// Copyright 2001-2003 Glyph & Cog, LLC
//
//========================================================================

//========================================================================
//
// Modified under the pdf-to-html project - http://pdf-to-html.freedesktop.org
//
// All changes made under the pdf-to-html project to this file are licensed
// under GPL version 2 or later
//
// Copyright (C) 2009, 2010, 2018 Albert Astals Cid <aacid@kde.org>
// Copyright (C) 2010 Christian Feuersänger <cfeuersaenger@googlemail.com>
// Copyright (C) 2011 Andrea Canciani <ranma42@gmail.com>
// Copyright (C) 2012 Thomas Freitag <Thomas.Freitag@alfa.de>
// Copyright (C) 2012 Adam Reichold <adamreichold@myopera.com>
//
// To see a description of the changes please see the Changelog file that
// came with your tarball or type make ChangeLog if you are building from git
//
//========================================================================

#ifndef FUNCTION_H
#define FUNCTION_H

#ifdef USE_GCC_PRAGMAS
#pragma interface
#endif

#include "goo/gtypes.h"
#include "Object.h"
#include <set>

class Dict;
class Stream;
struct PSObject;
class PSStack;
class pdf-to-htmlCache;

//------------------------------------------------------------------------
// Function
//------------------------------------------------------------------------

#define funcMaxInputs        32
#define funcMaxOutputs       32
#define sampledFuncMaxInputs 16

class Function {
public:

  Function();

  virtual ~Function();

  Function(const Function &) = delete;
  Function& operator=(const Function &other) = delete;

  // Construct a function.  Returns NULL if unsuccessful.
  static Function *parse(Object *funcObj);

  // Initialize the entries common to all function types.
  GBool init(Dict *dict);

  virtual Function *copy() = 0;

  // Return the function type:
  //   -1 : identity
  //    0 : sampled
  //    2 : exponential
  //    3 : stitching
  //    4 : PostScript
  virtual int getType() = 0;

  // Return size of input and output tuples.
  int getInputSize() { return m; }
  int getOutputSize() { return n; }

  double getDomainMin(int i) { return domain[i][0]; }
  double getDomainMax(int i) { return domain[i][1]; }
  double getRangeMin(int i) { return range[i][0]; }
  double getRangeMax(int i) { return range[i][1]; }
  GBool getHasRange() { return hasRange; }
  virtual GBool hasDifferentResultSet(Function *func) { return gFalse; }

  // Transform an input tuple into an output tuple.
  virtual void transform(double *in, double *out) = 0;

  virtual GBool isOk() = 0;

protected:
  static Function *parse(Object *funcObj, std::set<int> *usedParents);

  Function(const Function *func);

  int m, n;			// size of input and output tuples
  double			// min and max values for function domain
    domain[funcMaxInputs][2];
  double			// min and max values for function range
    range[funcMaxOutputs][2];
  GBool hasRange;		// set if range is defined
};

//------------------------------------------------------------------------
// IdentityFunction
//------------------------------------------------------------------------

class IdentityFunction: public Function {
public:

  IdentityFunction();
  ~IdentityFunction();
  Function *copy() override { return new IdentityFunction(); }
  int getType() override { return -1; }
  void transform(double *in, double *out) override;
  GBool isOk() override { return gTrue; }

private:
};

//------------------------------------------------------------------------
// SampledFunction
//------------------------------------------------------------------------

class SampledFunction: public Function {
public:

  SampledFunction(Object *funcObj, Dict *dict);
  ~SampledFunction();
  Function *copy() override { return new SampledFunction(this); }
  int getType() override { return 0; }
  void transform(double *in, double *out) override;
  GBool isOk() override { return ok; }
  GBool hasDifferentResultSet(Function *func) override;

  int getSampleSize(int i) { return sampleSize[i]; }
  double getEncodeMin(int i) { return encode[i][0]; }
  double getEncodeMax(int i) { return encode[i][1]; }
  double getDecodeMin(int i) { return decode[i][0]; }
  double getDecodeMax(int i) { return decode[i][1]; }
  double *getSamples() { return samples; }
  int getSampleNumber() { return nSamples; }

private:

  SampledFunction(const SampledFunction *func);

  int				// number of samples for each domain element
    sampleSize[funcMaxInputs];
  double			// min and max values for domain encoder
    encode[funcMaxInputs][2];
  double			// min and max values for range decoder
    decode[funcMaxOutputs][2];
  double			// input multipliers
    inputMul[funcMaxInputs];
  int *idxOffset;
  double *samples;		// the samples
  int nSamples;			// size of the samples array
  double *sBuf;			// buffer for the transform function
  double cacheIn[funcMaxInputs];
  double cacheOut[funcMaxOutputs];
  GBool ok;
};

//------------------------------------------------------------------------
// ExponentialFunction
//------------------------------------------------------------------------

class ExponentialFunction: public Function {
public:

  ExponentialFunction(Object *funcObj, Dict *dict);
  ~ExponentialFunction();
  Function *copy() override { return new ExponentialFunction(this); }
  int getType() override { return 2; }
  void transform(double *in, double *out) override;
  GBool isOk() override { return ok; }

  double *getC0() { return c0; }
  double *getC1() { return c1; }
  double getE() { return e; }

private:

  ExponentialFunction(const ExponentialFunction *func);

  double c0[funcMaxOutputs];
  double c1[funcMaxOutputs];
  double e;
  bool isLinear;
  GBool ok;
};

//------------------------------------------------------------------------
// StitchingFunction
//------------------------------------------------------------------------

class StitchingFunction: public Function {
public:

  StitchingFunction(Object *funcObj, Dict *dict, std::set<int> *usedParents);
  ~StitchingFunction();
  Function *copy() override { return new StitchingFunction(this); }
  int getType() override { return 3; }
  void transform(double *in, double *out) override;
  GBool isOk() override { return ok; }

  int getNumFuncs() { return k; }
  Function *getFunc(int i) { return funcs[i]; }
  double *getBounds() { return bounds; }
  double *getEncode() { return encode; }
  double *getScale() { return scale; }

private:

  StitchingFunction(const StitchingFunction *func);

  int k;
  Function **funcs;
  double *bounds;
  double *encode;
  double *scale;
  GBool ok;
};

//------------------------------------------------------------------------
// PostScriptFunction
//------------------------------------------------------------------------

class PostScriptFunction: public Function {
public:

  PostScriptFunction(Object *funcObj, Dict *dict);
  ~PostScriptFunction();
  Function *copy() override { return new PostScriptFunction(this); }
  int getType() override { return 4; }
  void transform(double *in, double *out) override;
  GBool isOk() override { return ok; }

  const GooString *getCodeString() const { return codeString; }

private:

  PostScriptFunction(const PostScriptFunction *func);
  GBool parseCode(Stream *str, int *codePtr);
  GooString *getToken(Stream *str);
  void resizeCode(int newSize);
  void exec(PSStack *stack, int codePtr);

  GooString *codeString;
  PSObject *code;
  int codeSize;
  double cacheIn[funcMaxInputs];
  double cacheOut[funcMaxOutputs];
  GBool ok;
};

#endif
