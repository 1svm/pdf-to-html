//========================================================================
//
// GooString.h
//
// Simple variable-length string type.
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
// Copyright (C) 2006 Kristian Høgsberg <krh@redhat.com>
// Copyright (C) 2006 Krzysztof Kowalczyk <kkowalczyk@gmail.com>
// Copyright (C) 2008-2010, 2012, 2014, 2017 Albert Astals Cid <aacid@kde.org>
// Copyright (C) 2012-2014 Fabio D'Urso <fabiodurso@hotmail.it>
// Copyright (C) 2013 Jason Crain <jason@aquaticape.us>
// Copyright (C) 2015, 2018 Adam Reichold <adam.reichold@t-online.de>
// Copyright (C) 2016 Jakub Alba <jakubalba@gmail.com>
// Copyright (C) 2017 Adrian Johnson <ajohnson@redneon.com>
// Copyright (C) 2018 Klarälvdalens Datakonsult AB, a KDAB Group company, <info@kdab.com>. Work sponsored by the LiMux project of the city of Munich
//
// To see a description of the changes please see the Changelog file that
// came with your tarball or type make ChangeLog if you are building from git
//
//========================================================================

#ifndef GooString_H
#define GooString_H

#ifdef USE_GCC_PRAGMAS
#pragma interface
#endif

#include <stdarg.h>
#include <stdlib.h> // for NULL
#include <string>
#include "gtypes.h"

#ifdef __clang__
# define GOOSTRING_FORMAT __attribute__((__annotate__("gooformat")))
#else
# define GOOSTRING_FORMAT
#endif

class GooString {
public:

  // a special value telling that the length of the string is not given
  // so it must be calculated from the strings
  static const int CALC_STRING_LEN = -1;

  // Create an empty string.
  GooString();

  // Create a string from a C string.
  explicit GooString(const char *sA);

  // Create a string from <lengthA> chars at <sA>.  This string
  // can contain null characters.
  GooString(const char *sA, int lengthA);

  // Create a string from <lengthA> chars at <idx> in <str>.
  GooString(const GooString *str, int idx, int lengthA);

  // Set content of a string to <newStr>. If <newLen> is CALC_STRING_LEN, then
  // length of the string will be calculated with strlen(). Otherwise we assume
  // this is a valid length of <newStr> (or its substring)
  GooString* Set(const char *newStr, int newLen=CALC_STRING_LEN);

  // Copy a string.
  explicit GooString(const GooString *str);
  GooString *copy() const { return new GooString(this); }

  // Concatenate two strings.
  GooString(GooString *str1, GooString *str2);

  // Convert an integer to a string.
  static GooString *fromInt(int x);

  // Create a formatted string.  Similar to printf, but without the
  // string overflow issues.  Formatting elements consist of:
  //     {<arg>:[<width>][.<precision>]<type>}
  // where:
  // - <arg> is the argument number (arg 0 is the first argument
  //   following the format string) -- NB: args must be first used in
  //   order; they can be reused in any order
  // - <width> is the field width -- negative to reverse the alignment;
  //   starting with a leading zero to zero-fill (for integers)
  // - <precision> is the number of digits to the right of the decimal
  //   point (for floating point numbers)
  // - <type> is one of:
  //     d, x, X, o, b -- int in decimal, lowercase hex, uppercase hex, octal, binary
  //     ud, ux, uX, uo, ub -- unsigned int
  //     ld, lx, lX, lo, lb, uld, ulx, ulX, ulo, ulb -- long, unsigned long
  //     lld, llx, llX, llo, llb, ulld, ullx, ullX, ullo, ullb
  //         -- long long, unsigned long long
  //     f, g, gs -- floating point (float or double)
  //         f  -- always prints trailing zeros (eg 1.0 with .2f will print 1.00)
  //         g  -- omits trailing zeros and, if possible, the dot (eg 1.0 shows up as 1)
  //         gs -- is like g, but treats <precision> as number of significant
  //               digits to show (eg 0.0123 with .2gs will print 0.012)
  //     c -- character (char, short or int)
  //     s -- string (char *)
  //     t -- GooString *
  //     w -- blank space; arg determines width
  // To get literal curly braces, use {{ or }}.
  static GooString *format(const char *fmt, ...) GOOSTRING_FORMAT;
  static GooString *formatv(const char *fmt, va_list argList);

  // Destructor.
  ~GooString();

  // Get length.
  int getLength() const { return length; }

  // Get C string.
  char *getCString() { return s; }
  const char *getCString() const { return s; }

  // Get <i>th character.
  char getChar(int i) const { return s[i]; }

  // Change <i>th character.
  void setChar(int i, char c) { s[i] = c; }

  // Clear string to zero length.
  GooString *clear();

  // Append a character or string.
  GooString *append(char c);
  GooString *append(const GooString *str);
  GooString *append(const char *str, int lengthA=CALC_STRING_LEN);

  // Append a formatted string.
  GooString *appendf(const char *fmt, ...) GOOSTRING_FORMAT;
  GooString *appendfv(const char *fmt, va_list argList);

  // Insert a character or string.
  GooString *insert(int i, char c);
  GooString *insert(int i, const GooString *str);
  GooString *insert(int i, const char *str, int lengthA=CALC_STRING_LEN);

  // Delete a character or range of characters.
  GooString *del(int i, int n = 1);

  // Convert string to all-upper/all-lower case.
  GooString *upperCase();
  GooString *lowerCase();

  // Compare two strings:  -1:<  0:=  +1:>
  int cmp(const GooString *str) const;
  int cmpN(GooString *str, int n) const;
  int cmp(const char *sA) const;
  int cmpN(const char *sA, int n) const;

  // Return true if string ends with suffix
  GBool endsWith(const char *suffix) const;

  GBool hasUnicodeMarker(void) const;
  void prependUnicodeMarker();
  GBool hasJustUnicodeMarker(void) const { return length == 2 && hasUnicodeMarker(); }

  // Sanitizes the string so that it does
  // not contain any ( ) < > [ ] { } / %
  // The postscript mode also has some more strict checks
  // The caller owns the return value
  GooString *sanitizedName(GBool psmode) const;

  // Conversion from and to std::string
  explicit GooString(const std::string& str) : GooString(str.data(), str.size()) {}
  std::string toStr() const { return std::string(getCString(), getLength()); }

private:
  GooString(const GooString &other);
  GooString& operator=(const GooString &other);

  // You can tweak the final object size for different time/space tradeoffs.
  // In libc malloc(), rounding is 16 so it's best to choose a value that
  // is a multiple of 16.
  static const int STR_FINAL_SIZE = 32;
  static const int STR_STATIC_SIZE = STR_FINAL_SIZE - sizeof(int) - sizeof(char*);

  int  roundedSize(int len);

  char sStatic[STR_STATIC_SIZE];
  int length;
  char *s;

  void resize(int newLength);
  static void formatInt(long long x, char *buf, int bufSize,
			GBool zeroFill, int width, int base,
			char **p, int *len, GBool upperCase = gFalse);
  static void formatUInt(unsigned long long x, char *buf, int bufSize,
			 GBool zeroFill, int width, int base,
			 char **p, int *len, GBool upperCase = gFalse);
  static void formatDouble(double x, char *buf, int bufSize, int prec,
			   GBool trim, char **p, int *len);
  static void formatDoubleSmallAware(double x, char *buf, int bufSize, int prec,
				     GBool trim, char **p, int *len);
};

#endif
