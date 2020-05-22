/* pdf-to-html.h: glib interface to pdf-to-html
 * Copyright (C) 2004, Red Hat, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef __pdf-to-html_GLIB_H__
#define __pdf-to-html_GLIB_H__

#include <glib-object.h>

G_BEGIN_DECLS

GQuark pdf-to-html_error_quark (void);

#define pdf-to-html_ERROR pdf-to-html_error_quark ()

/**
 * pdf-to-htmlError:
 * @pdf-to-html_ERROR_INVALID: Generic error when a document operation fails
 * @pdf-to-html_ERROR_ENCRYPTED: Document is encrypted
 * @pdf-to-html_ERROR_OPEN_FILE: File could not be opened for writing when saving document
 * @pdf-to-html_ERROR_BAD_CATALOG: Failed to read the document catalog
 * @pdf-to-html_ERROR_DAMAGED: Document is damaged
 *
 * Error codes returned by #pdf-to-htmlDocument
 */
typedef enum
{
  pdf-to-html_ERROR_INVALID,
  pdf-to-html_ERROR_ENCRYPTED,
  pdf-to-html_ERROR_OPEN_FILE,
  pdf-to-html_ERROR_BAD_CATALOG,
  pdf-to-html_ERROR_DAMAGED
} pdf-to-htmlError;

/**
 * pdf-to-htmlPageTransitionType:
 * @pdf-to-html_PAGE_TRANSITION_REPLACE: the new page replace the old one
 * @pdf-to-html_PAGE_TRANSITION_SPLIT: two lines sweep across the screen, revealing the new page
 * @pdf-to-html_PAGE_TRANSITION_BLINDS: multiple lines, evenly spaced across the screen, synchronously
 * sweep in the same direction to reveal the new page
 * @pdf-to-html_PAGE_TRANSITION_BOX: a rectangular box sweeps inward from the edges of the page or
 * outward from the center revealing the new page
 * @pdf-to-html_PAGE_TRANSITION_WIPE: a single line sweeps across the screen from one edge to the other
 * revealing the new page
 * @pdf-to-html_PAGE_TRANSITION_DISSOLVE: the old page dissolves gradually to reveal the new one
 * @pdf-to-html_PAGE_TRANSITION_GLITTER: similar to #pdf-to-html_PAGE_TRANSITION_DISSOLVE, except that the effect
 * sweeps across the page in a wide band moving from one side of the screen to the other
 * @pdf-to-html_PAGE_TRANSITION_FLY: changes are flown out or in to or from a location that is offscreen
 * @pdf-to-html_PAGE_TRANSITION_PUSH: the old page slides off the screen while the new page slides in
 * @pdf-to-html_PAGE_TRANSITION_COVER: the new page slides on to the screen covering the old page
 * @pdf-to-html_PAGE_TRANSITION_UNCOVER: the old page slides off the screen uncovering the new page
 * @pdf-to-html_PAGE_TRANSITION_FADE: the new page gradually becomes visible through the old one
 *
 * Page transition types
 */
typedef enum
{
  pdf-to-html_PAGE_TRANSITION_REPLACE,
  pdf-to-html_PAGE_TRANSITION_SPLIT,
  pdf-to-html_PAGE_TRANSITION_BLINDS,
  pdf-to-html_PAGE_TRANSITION_BOX,
  pdf-to-html_PAGE_TRANSITION_WIPE,
  pdf-to-html_PAGE_TRANSITION_DISSOLVE,
  pdf-to-html_PAGE_TRANSITION_GLITTER,
  pdf-to-html_PAGE_TRANSITION_FLY,
  pdf-to-html_PAGE_TRANSITION_PUSH,
  pdf-to-html_PAGE_TRANSITION_COVER,
  pdf-to-html_PAGE_TRANSITION_UNCOVER,
  pdf-to-html_PAGE_TRANSITION_FADE
} pdf-to-htmlPageTransitionType;

/**
 * pdf-to-htmlPageTransitionAlignment:
 * @pdf-to-html_PAGE_TRANSITION_HORIZONTAL: horizontal dimension
 * @pdf-to-html_PAGE_TRANSITION_VERTICAL: vertical dimension
 *
 * Page transition alignment types for #pdf-to-html_PAGE_TRANSITION_SPLIT
 * and #pdf-to-html_PAGE_TRANSITION_BLINDS transition types
 */
typedef enum
{
  pdf-to-html_PAGE_TRANSITION_HORIZONTAL,
  pdf-to-html_PAGE_TRANSITION_VERTICAL
} pdf-to-htmlPageTransitionAlignment;

/**
 * pdf-to-htmlPageTransitionDirection:
 * @pdf-to-html_PAGE_TRANSITION_INWARD: inward from the edges of the page
 * @pdf-to-html_PAGE_TRANSITION_OUTWARD: outward from the center of the page
 *
 * Page transition direction types for #pdf-to-html_PAGE_TRANSITION_SPLIT,
 * #pdf-to-html_PAGE_TRANSITION_BOX and #pdf-to-html_PAGE_TRANSITION_FLY transition types
 */
typedef enum
{
  pdf-to-html_PAGE_TRANSITION_INWARD,
  pdf-to-html_PAGE_TRANSITION_OUTWARD
} pdf-to-htmlPageTransitionDirection;

/**
 * pdf-to-htmlSelectionStyle:
 * @pdf-to-html_SELECTION_GLYPH: glyph is the minimum unit for selection
 * @pdf-to-html_SELECTION_WORD: word is the minimum unit for selection
 * @pdf-to-html_SELECTION_LINE: line is the minimum unit for selection
 *
 * Selection styles
 */
typedef enum
{
  pdf-to-html_SELECTION_GLYPH,
  pdf-to-html_SELECTION_WORD,
  pdf-to-html_SELECTION_LINE
} pdf-to-htmlSelectionStyle;

/**
 * pdf-to-htmlPrintFlags:
 * @pdf-to-html_PRINT_DOCUMENT: print main document contents
 * @pdf-to-html_PRINT_MARKUP_ANNOTS: print document and markup annotations
 * @pdf-to-html_PRINT_STAMP_ANNOTS_ONLY: print document and only stamp annotations
 * @pdf-to-html_PRINT_ALL: print main document contents and all markup annotations
 *
 * Printing flags
 *
 * Since: 0.16
 */
typedef enum /*< flags >*/
{
  pdf-to-html_PRINT_DOCUMENT          = 0,
  pdf-to-html_PRINT_MARKUP_ANNOTS     = 1 << 0,
  pdf-to-html_PRINT_STAMP_ANNOTS_ONLY = 1 << 1,
  pdf-to-html_PRINT_ALL               = pdf-to-html_PRINT_MARKUP_ANNOTS
} pdf-to-htmlPrintFlags;

/**
 * pdf-to-htmlFindFlags:
 * @pdf-to-html_FIND_DEFAULT: use default search settings
 * @pdf-to-html_FIND_CASE_SENSITIVE: do case sensitive search
 * @pdf-to-html_FIND_BACKWARDS: search backwards
 * @pdf-to-html_FIND_WHOLE_WORDS_ONLY: search only whole words
 *
 * Flags using while searching text in a page
 *
 * Since: 0.22
 */
typedef enum /*< flags >*/
{
  pdf-to-html_FIND_DEFAULT          = 0,
  pdf-to-html_FIND_CASE_SENSITIVE   = 1 << 0,
  pdf-to-html_FIND_BACKWARDS        = 1 << 1,
  pdf-to-html_FIND_WHOLE_WORDS_ONLY = 1 << 2
} pdf-to-htmlFindFlags;

typedef struct _pdf-to-htmlDocument            pdf-to-htmlDocument;
typedef struct _pdf-to-htmlIndexIter           pdf-to-htmlIndexIter;
typedef struct _pdf-to-htmlFontsIter           pdf-to-htmlFontsIter;
typedef struct _pdf-to-htmlLayersIter          pdf-to-htmlLayersIter;
typedef struct _pdf-to-htmlPoint               pdf-to-htmlPoint;
typedef struct _pdf-to-htmlRectangle           pdf-to-htmlRectangle;
typedef struct _pdf-to-htmlTextAttributes      pdf-to-htmlTextAttributes;
typedef struct _pdf-to-htmlColor               pdf-to-htmlColor;
typedef struct _pdf-to-htmlLinkMapping         pdf-to-htmlLinkMapping;
typedef struct _pdf-to-htmlPageTransition      pdf-to-htmlPageTransition;
typedef struct _pdf-to-htmlImageMapping        pdf-to-htmlImageMapping;
typedef struct _pdf-to-htmlFormFieldMapping    pdf-to-htmlFormFieldMapping;
typedef struct _pdf-to-htmlAnnotMapping        pdf-to-htmlAnnotMapping;
typedef struct _pdf-to-htmlPage                pdf-to-htmlPage;
typedef struct _pdf-to-htmlFontInfo            pdf-to-htmlFontInfo;
typedef struct _pdf-to-htmlLayer               pdf-to-htmlLayer;
typedef struct _pdf-to-htmlPSFile              pdf-to-htmlPSFile;
typedef union  _pdf-to-htmlAction              pdf-to-htmlAction;
typedef struct _pdf-to-htmlDest                pdf-to-htmlDest;
typedef struct _pdf-to-htmlActionLayer         pdf-to-htmlActionLayer;
typedef struct _pdf-to-htmlFormField           pdf-to-htmlFormField;
typedef struct _pdf-to-htmlAttachment          pdf-to-htmlAttachment;
typedef struct _pdf-to-htmlMovie               pdf-to-htmlMovie;
typedef struct _pdf-to-htmlMedia               pdf-to-htmlMedia;
typedef struct _pdf-to-htmlAnnot               pdf-to-htmlAnnot;
typedef struct _pdf-to-htmlAnnotMarkup         pdf-to-htmlAnnotMarkup;
typedef struct _pdf-to-htmlAnnotText           pdf-to-htmlAnnotText;
typedef struct _pdf-to-htmlAnnotTextMarkup     pdf-to-htmlAnnotTextMarkup;
typedef struct _pdf-to-htmlAnnotFreeText       pdf-to-htmlAnnotFreeText;
typedef struct _pdf-to-htmlAnnotFileAttachment pdf-to-htmlAnnotFileAttachment;
typedef struct _pdf-to-htmlAnnotMovie          pdf-to-htmlAnnotMovie;
typedef struct _pdf-to-htmlAnnotScreen         pdf-to-htmlAnnotScreen;
typedef struct _pdf-to-htmlAnnotCalloutLine    pdf-to-htmlAnnotCalloutLine;
typedef struct _pdf-to-htmlAnnotLine           pdf-to-htmlAnnotLine;
typedef struct _pdf-to-htmlAnnotCircle         pdf-to-htmlAnnotCircle;
typedef struct _pdf-to-htmlAnnotSquare         pdf-to-htmlAnnotSquare;
typedef struct _pdf-to-htmlQuadrilateral       pdf-to-htmlQuadrilateral;
typedef struct _pdf-to-htmlStructureElement    pdf-to-htmlStructureElement;
typedef struct _pdf-to-htmlStructureElementIter pdf-to-htmlStructureElementIter;
typedef struct _pdf-to-htmlTextSpan            pdf-to-htmlTextSpan;

/**
 * pdf-to-htmlBackend:
 * @pdf-to-html_BACKEND_UNKNOWN: Unknown backend
 * @pdf-to-html_BACKEND_SPLASH: Splash backend
 * @pdf-to-html_BACKEND_CAIRO: Cairo backend
 *
 * Backend codes returned by pdf-to-html_get_backend().
 */
typedef enum
{
  pdf-to-html_BACKEND_UNKNOWN,
  pdf-to-html_BACKEND_SPLASH,
  pdf-to-html_BACKEND_CAIRO
} pdf-to-htmlBackend;

pdf-to-htmlBackend pdf-to-html_get_backend (void);
const char *   pdf-to-html_get_version (void);

G_END_DECLS

#include "pdf-to-html-features.h"
#include "pdf-to-html-document.h"
#include "pdf-to-html-page.h"
#include "pdf-to-html-layer.h"
#include "pdf-to-html-action.h"
#include "pdf-to-html-form-field.h"
#include "pdf-to-html-enums.h"
#include "pdf-to-html-attachment.h"
#include "pdf-to-html-annot.h"
#include "pdf-to-html-date.h"
#include "pdf-to-html-movie.h"
#include "pdf-to-html-media.h"
#include "pdf-to-html-structure-element.h"

#endif /* __pdf-to-html_GLIB_H__ */
