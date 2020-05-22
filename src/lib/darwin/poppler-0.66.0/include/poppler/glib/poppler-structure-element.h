/* pdf-to-html-structure-element.h: glib interface to pdf-to-html
 *
 * Copyright (C) 2013 Igalia S.L.
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

#ifndef __pdf-to-html_STRUCTURE_ELEMENT_H__
#define __pdf-to-html_STRUCTURE_ELEMENT_H__

#include <glib-object.h>
#include "pdf-to-html.h"

G_BEGIN_DECLS

#define pdf-to-html_TYPE_STRUCTURE_ELEMENT    (pdf-to-html_structure_element_get_type ())
#define pdf-to-html_STRUCTURE_ELEMENT(obj)    (G_TYPE_CHECK_INSTANCE_CAST ((obj), pdf-to-html_TYPE_STRUCTURE_ELEMENT, pdf-to-htmlStructureElement))
#define pdf-to-html_IS_STRUCTURE_ELEMENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), pdf-to-html_TYPE_STRUCTURE_ELEMENT))

/**
 * pdf-to-htmlStructureElementKind:
 */
typedef enum {
  pdf-to-html_STRUCTURE_ELEMENT_CONTENT,
  pdf-to-html_STRUCTURE_ELEMENT_OBJECT_REFERENCE,
  pdf-to-html_STRUCTURE_ELEMENT_DOCUMENT,
  pdf-to-html_STRUCTURE_ELEMENT_PART,
  pdf-to-html_STRUCTURE_ELEMENT_ARTICLE,
  pdf-to-html_STRUCTURE_ELEMENT_SECTION,
  pdf-to-html_STRUCTURE_ELEMENT_DIV,
  pdf-to-html_STRUCTURE_ELEMENT_SPAN,
  pdf-to-html_STRUCTURE_ELEMENT_QUOTE,
  pdf-to-html_STRUCTURE_ELEMENT_NOTE,
  pdf-to-html_STRUCTURE_ELEMENT_REFERENCE,
  pdf-to-html_STRUCTURE_ELEMENT_BIBENTRY,
  pdf-to-html_STRUCTURE_ELEMENT_CODE,
  pdf-to-html_STRUCTURE_ELEMENT_LINK,
  pdf-to-html_STRUCTURE_ELEMENT_ANNOT,
  pdf-to-html_STRUCTURE_ELEMENT_BLOCKQUOTE,
  pdf-to-html_STRUCTURE_ELEMENT_CAPTION,
  pdf-to-html_STRUCTURE_ELEMENT_NONSTRUCT,
  pdf-to-html_STRUCTURE_ELEMENT_TOC,
  pdf-to-html_STRUCTURE_ELEMENT_TOC_ITEM,
  pdf-to-html_STRUCTURE_ELEMENT_INDEX,
  pdf-to-html_STRUCTURE_ELEMENT_PRIVATE,
  pdf-to-html_STRUCTURE_ELEMENT_PARAGRAPH,
  pdf-to-html_STRUCTURE_ELEMENT_HEADING,
  pdf-to-html_STRUCTURE_ELEMENT_HEADING_1,
  pdf-to-html_STRUCTURE_ELEMENT_HEADING_2,
  pdf-to-html_STRUCTURE_ELEMENT_HEADING_3,
  pdf-to-html_STRUCTURE_ELEMENT_HEADING_4,
  pdf-to-html_STRUCTURE_ELEMENT_HEADING_5,
  pdf-to-html_STRUCTURE_ELEMENT_HEADING_6,
  pdf-to-html_STRUCTURE_ELEMENT_LIST,
  pdf-to-html_STRUCTURE_ELEMENT_LIST_ITEM,
  pdf-to-html_STRUCTURE_ELEMENT_LIST_LABEL,
  pdf-to-html_STRUCTURE_ELEMENT_LIST_BODY,
  pdf-to-html_STRUCTURE_ELEMENT_TABLE,
  pdf-to-html_STRUCTURE_ELEMENT_TABLE_ROW,
  pdf-to-html_STRUCTURE_ELEMENT_TABLE_HEADING,
  pdf-to-html_STRUCTURE_ELEMENT_TABLE_DATA,
  pdf-to-html_STRUCTURE_ELEMENT_TABLE_HEADER,
  pdf-to-html_STRUCTURE_ELEMENT_TABLE_FOOTER,
  pdf-to-html_STRUCTURE_ELEMENT_TABLE_BODY,
  pdf-to-html_STRUCTURE_ELEMENT_RUBY,
  pdf-to-html_STRUCTURE_ELEMENT_RUBY_BASE_TEXT,
  pdf-to-html_STRUCTURE_ELEMENT_RUBY_ANNOT_TEXT,
  pdf-to-html_STRUCTURE_ELEMENT_RUBY_PUNCTUATION,
  pdf-to-html_STRUCTURE_ELEMENT_WARICHU,
  pdf-to-html_STRUCTURE_ELEMENT_WARICHU_TEXT,
  pdf-to-html_STRUCTURE_ELEMENT_WARICHU_PUNCTUATION,
  pdf-to-html_STRUCTURE_ELEMENT_FIGURE,
  pdf-to-html_STRUCTURE_ELEMENT_FORMULA,
  pdf-to-html_STRUCTURE_ELEMENT_FORM,
} pdf-to-htmlStructureElementKind;

/**
 * pdf-to-htmlStructureGetTextFlags:
 * @pdf-to-html_STRUCTURE_GET_TEXT_NONE: No flags.
 * @pdf-to-html_STRUCTURE_GET_TEXT_RECURSIVE: For non-leaf, non-content
 *    elements, recursively obtain the text from all the elements
 *    enclosed in the subtree.
 */
typedef enum {
  pdf-to-html_STRUCTURE_GET_TEXT_NONE      = 0,
  pdf-to-html_STRUCTURE_GET_TEXT_RECURSIVE = (1 << 0),
} pdf-to-htmlStructureGetTextFlags;

/**
 * pdf-to-htmlStructurePlacement:
 */
typedef enum {
  pdf-to-html_STRUCTURE_PLACEMENT_BLOCK,
  pdf-to-html_STRUCTURE_PLACEMENT_INLINE,
  pdf-to-html_STRUCTURE_PLACEMENT_BEFORE,
  pdf-to-html_STRUCTURE_PLACEMENT_START,
  pdf-to-html_STRUCTURE_PLACEMENT_END,
} pdf-to-htmlStructurePlacement;

/**
 * pdf-to-htmlStructureWritingMode:
 */
typedef enum {
  pdf-to-html_STRUCTURE_WRITING_MODE_LR_TB,
  pdf-to-html_STRUCTURE_WRITING_MODE_RL_TB,
  pdf-to-html_STRUCTURE_WRITING_MODE_TB_RL,
} pdf-to-htmlStructureWritingMode;

/**
 * pdf-to-htmlStructureBorderStyle:
 */
typedef enum {
  pdf-to-html_STRUCTURE_BORDER_STYLE_NONE,
  pdf-to-html_STRUCTURE_BORDER_STYLE_HIDDEN,
  pdf-to-html_STRUCTURE_BORDER_STYLE_DOTTED,
  pdf-to-html_STRUCTURE_BORDER_STYLE_DASHED,
  pdf-to-html_STRUCTURE_BORDER_STYLE_SOLID,
  pdf-to-html_STRUCTURE_BORDER_STYLE_DOUBLE,
  pdf-to-html_STRUCTURE_BORDER_STYLE_GROOVE,
  pdf-to-html_STRUCTURE_BORDER_STYLE_INSET,
  pdf-to-html_STRUCTURE_BORDER_STYLE_OUTSET,
} pdf-to-htmlStructureBorderStyle;

/**
 * pdf-to-htmlStructureTextAlign:
 */
typedef enum {
  pdf-to-html_STRUCTURE_TEXT_ALIGN_START,
  pdf-to-html_STRUCTURE_TEXT_ALIGN_CENTER,
  pdf-to-html_STRUCTURE_TEXT_ALIGN_END,
  pdf-to-html_STRUCTURE_TEXT_ALIGN_JUSTIFY,
} pdf-to-htmlStructureTextAlign;

/**
 * pdf-to-htmlStructureBlockAlign:
 */
typedef enum {
  pdf-to-html_STRUCTURE_BLOCK_ALIGN_BEFORE,
  pdf-to-html_STRUCTURE_BLOCK_ALIGN_MIDDLE,
  pdf-to-html_STRUCTURE_BLOCK_ALIGN_AFTER,
  pdf-to-html_STRUCTURE_BLOCK_ALIGN_JUSTIFY,
} pdf-to-htmlStructureBlockAlign;

/**
 * pdf-to-htmlStructureInlineAlign:
 */
typedef enum {
  pdf-to-html_STRUCTURE_INLINE_ALIGN_START,
  pdf-to-html_STRUCTURE_INLINE_ALIGN_CENTER,
  pdf-to-html_STRUCTURE_INLINE_ALIGN_END,
} pdf-to-htmlStructureInlineAlign;

/**
 * pdf-to-htmlStructureTextDecoration:
 */
typedef enum {
  pdf-to-html_STRUCTURE_TEXT_DECORATION_NONE,
  pdf-to-html_STRUCTURE_TEXT_DECORATION_UNDERLINE,
  pdf-to-html_STRUCTURE_TEXT_DECORATION_OVERLINE,
  pdf-to-html_STRUCTURE_TEXT_DECORATION_LINETHROUGH,
} pdf-to-htmlStructureTextDecoration;

/**
 * pdf-to-htmlStructureRubyAlign:
 */
typedef enum
{
  pdf-to-html_STRUCTURE_RUBY_ALIGN_START,
  pdf-to-html_STRUCTURE_RUBY_ALIGN_CENTER,
  pdf-to-html_STRUCTURE_RUBY_ALIGN_END,
  pdf-to-html_STRUCTURE_RUBY_ALIGN_JUSTIFY,
  pdf-to-html_STRUCTURE_RUBY_ALIGN_DISTRIBUTE,
} pdf-to-htmlStructureRubyAlign;

/**
 * pdf-to-htmlStructureRubyPosition:
 */
typedef enum {
  pdf-to-html_STRUCTURE_RUBY_POSITION_BEFORE,
  pdf-to-html_STRUCTURE_RUBY_POSITION_AFTER,
  pdf-to-html_STRUCTURE_RUBY_POSITION_WARICHU,
  pdf-to-html_STRUCTURE_RUBY_POSITION_INLINE,
} pdf-to-htmlStructureRubyPosition;

/**
 * pdf-to-htmlStructureGlyphOrientation:
 */
typedef enum {
  pdf-to-html_STRUCTURE_GLYPH_ORIENTATION_AUTO,
  pdf-to-html_STRUCTURE_GLYPH_ORIENTATION_0 = pdf-to-html_STRUCTURE_GLYPH_ORIENTATION_AUTO,
  pdf-to-html_STRUCTURE_GLYPH_ORIENTATION_90,
  pdf-to-html_STRUCTURE_GLYPH_ORIENTATION_180,
  pdf-to-html_STRUCTURE_GLYPH_ORIENTATION_270,
} pdf-to-htmlStructureGlyphOrientation;

/**
 * pdf-to-htmlStructureListNumbering:
 */
typedef enum {
  pdf-to-html_STRUCTURE_LIST_NUMBERING_NONE,
  pdf-to-html_STRUCTURE_LIST_NUMBERING_DISC,
  pdf-to-html_STRUCTURE_LIST_NUMBERING_CIRCLE,
  pdf-to-html_STRUCTURE_LIST_NUMBERING_SQUARE,
  pdf-to-html_STRUCTURE_LIST_NUMBERING_DECIMAL,
  pdf-to-html_STRUCTURE_LIST_NUMBERING_UPPER_ROMAN,
  pdf-to-html_STRUCTURE_LIST_NUMBERING_LOWER_ROMAN,
  pdf-to-html_STRUCTURE_LIST_NUMBERING_UPPER_ALPHA,
  pdf-to-html_STRUCTURE_LIST_NUMBERING_LOWER_ALPHA,
} pdf-to-htmlStructureListNumbering;

/**
 * pdf-to-htmlStructureFormRole:
 */
typedef enum {
  pdf-to-html_STRUCTURE_FORM_ROLE_UNDEFINED,
  pdf-to-html_STRUCTURE_FORM_ROLE_RADIO_BUTTON,
  pdf-to-html_STRUCTURE_FORM_ROLE_PUSH_BUTTON,
  pdf-to-html_STRUCTURE_FORM_ROLE_TEXT_VALUE,
  pdf-to-html_STRUCTURE_FORM_ROLE_CHECKBOX,
} pdf-to-htmlStructureFormRole;

/**
 * pdf-to-htmlStructureFormState:
 */
typedef enum {
  pdf-to-html_STRUCTURE_FORM_STATE_ON,
  pdf-to-html_STRUCTURE_FORM_STATE_OFF,
  pdf-to-html_STRUCTURE_FORM_STATE_NEUTRAL,
} pdf-to-htmlStructureFormState;

/**
 * pdf-to-htmlStructureTableScope:
 */
typedef enum {
  pdf-to-html_STRUCTURE_TABLE_SCOPE_ROW,
  pdf-to-html_STRUCTURE_TABLE_SCOPE_COLUMN,
  pdf-to-html_STRUCTURE_TABLE_SCOPE_BOTH,
} pdf-to-htmlStructureTableScope;


GType                            pdf-to-html_structure_element_get_type               (void) G_GNUC_CONST;
pdf-to-htmlStructureElementKind      pdf-to-html_structure_element_get_kind               (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
gint                             pdf-to-html_structure_element_get_page               (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
gboolean                         pdf-to-html_structure_element_is_content             (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
gboolean                         pdf-to-html_structure_element_is_inline              (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
gboolean                         pdf-to-html_structure_element_is_block               (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
gboolean                         pdf-to-html_structure_element_is_grouping            (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
gchar                           *pdf-to-html_structure_element_get_id                 (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
gchar                           *pdf-to-html_structure_element_get_title              (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
gchar                           *pdf-to-html_structure_element_get_abbreviation       (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
gchar                           *pdf-to-html_structure_element_get_language           (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
gchar                           *pdf-to-html_structure_element_get_text               (pdf-to-htmlStructureElement     *pdf-to-html_structure_element,
                                                                                   pdf-to-htmlStructureGetTextFlags flags);
gchar                           *pdf-to-html_structure_element_get_alt_text           (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
gchar                           *pdf-to-html_structure_element_get_actual_text        (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
pdf-to-htmlTextSpan                **pdf-to-html_structure_element_get_text_spans         (pdf-to-htmlStructureElement     *pdf-to-html_structure_element,
                                                                                   guint                       *n_text_spans);

pdf-to-htmlStructurePlacement        pdf-to-html_structure_element_get_placement          (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
pdf-to-htmlStructureWritingMode      pdf-to-html_structure_element_get_writing_mode       (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
gboolean                         pdf-to-html_structure_element_get_background_color   (pdf-to-htmlStructureElement     *pdf-to-html_structure_element,
                                                                                   pdf-to-htmlColor                *color);
gboolean                         pdf-to-html_structure_element_get_border_color       (pdf-to-htmlStructureElement     *pdf-to-html_structure_element,
                                                                                   pdf-to-htmlColor                *colors);
void                             pdf-to-html_structure_element_get_border_style       (pdf-to-htmlStructureElement     *pdf-to-html_structure_element,
                                                                                   pdf-to-htmlStructureBorderStyle *border_styles);
gboolean                         pdf-to-html_structure_element_get_border_thickness   (pdf-to-htmlStructureElement     *pdf-to-html_structure_element,
                                                                                   gdouble                     *border_thicknesses);
void                             pdf-to-html_structure_element_get_padding            (pdf-to-htmlStructureElement     *pdf-to-html_structure_element,
                                                                                   gdouble                     *paddings);
gboolean                         pdf-to-html_structure_element_get_color              (pdf-to-htmlStructureElement     *pdf-to-html_structure_element,
                                                                                   pdf-to-htmlColor                *color);

gdouble                          pdf-to-html_structure_element_get_space_before       (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
gdouble                          pdf-to-html_structure_element_get_space_after        (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
gdouble                          pdf-to-html_structure_element_get_start_indent       (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
gdouble                          pdf-to-html_structure_element_get_end_indent         (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
gdouble                          pdf-to-html_structure_element_get_text_indent        (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
pdf-to-htmlStructureTextAlign        pdf-to-html_structure_element_get_text_align         (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
gboolean                         pdf-to-html_structure_element_get_bounding_box       (pdf-to-htmlStructureElement     *pdf-to-html_structure_element,
                                                                                   pdf-to-htmlRectangle            *bounding_box);
gdouble                          pdf-to-html_structure_element_get_width              (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
gdouble                          pdf-to-html_structure_element_get_height             (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
pdf-to-htmlStructureBlockAlign       pdf-to-html_structure_element_get_block_align        (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
pdf-to-htmlStructureInlineAlign      pdf-to-html_structure_element_get_inline_align       (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
void                             pdf-to-html_structure_element_get_table_border_style (pdf-to-htmlStructureElement     *pdf-to-html_structure_element,
                                                                                   pdf-to-htmlStructureBorderStyle *border_styles);
void                             pdf-to-html_structure_element_get_table_padding      (pdf-to-htmlStructureElement     *pdf-to-html_structure_element,
                                                                                   gdouble                     *paddings);

gdouble                          pdf-to-html_structure_element_get_baseline_shift     (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
gdouble                          pdf-to-html_structure_element_get_line_height        (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
gboolean                         pdf-to-html_structure_element_get_text_decoration_color
                                                                                  (pdf-to-htmlStructureElement     *pdf-to-html_structure_element,
                                                                                   pdf-to-htmlColor                *color);
gdouble                          pdf-to-html_structure_element_get_text_decoration_thickness
                                                                                  (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
pdf-to-htmlStructureTextDecoration   pdf-to-html_structure_element_get_text_decoration_type
                                                                                  (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
pdf-to-htmlStructureRubyAlign        pdf-to-html_structure_element_get_ruby_align         (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
pdf-to-htmlStructureRubyPosition     pdf-to-html_structure_element_get_ruby_position      (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
pdf-to-htmlStructureGlyphOrientation pdf-to-html_structure_element_get_glyph_orientation  (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);

guint                            pdf-to-html_structure_element_get_column_count       (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
gdouble                         *pdf-to-html_structure_element_get_column_gaps        (pdf-to-htmlStructureElement     *pdf-to-html_structure_element,
                                                                                   guint                       *n_values);
gdouble                         *pdf-to-html_structure_element_get_column_widths      (pdf-to-htmlStructureElement     *pdf-to-html_structure_element,
                                                                                   guint                       *n_values);

pdf-to-htmlStructureListNumbering    pdf-to-html_structure_element_get_list_numbering     (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);

pdf-to-htmlStructureFormRole         pdf-to-html_structure_element_get_form_role          (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
pdf-to-htmlStructureFormState        pdf-to-html_structure_element_get_form_state         (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
gchar                           *pdf-to-html_structure_element_get_form_description   (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);

guint                            pdf-to-html_structure_element_get_table_row_span     (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
guint                            pdf-to-html_structure_element_get_table_column_span  (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
gchar                          **pdf-to-html_structure_element_get_table_headers      (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
pdf-to-htmlStructureTableScope       pdf-to-html_structure_element_get_table_scope        (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);
gchar                           *pdf-to-html_structure_element_get_table_summary      (pdf-to-htmlStructureElement     *pdf-to-html_structure_element);

#define pdf-to-html_TYPE_STRUCTURE_ELEMENT_ITER                                       (pdf-to-html_structure_element_iter_get_type ())
GType                        pdf-to-html_structure_element_iter_get_type              (void) G_GNUC_CONST;
pdf-to-htmlStructureElementIter *pdf-to-html_structure_element_iter_new                   (pdf-to-htmlDocument             *pdf-to-html_document);
pdf-to-htmlStructureElementIter *pdf-to-html_structure_element_iter_get_child             (pdf-to-htmlStructureElementIter *parent);
pdf-to-htmlStructureElementIter *pdf-to-html_structure_element_iter_copy                  (pdf-to-htmlStructureElementIter *iter);
pdf-to-htmlStructureElement     *pdf-to-html_structure_element_iter_get_element           (pdf-to-htmlStructureElementIter *iter);
gboolean                     pdf-to-html_structure_element_iter_next                  (pdf-to-htmlStructureElementIter *iter);
void                         pdf-to-html_structure_element_iter_free                  (pdf-to-htmlStructureElementIter *iter);

#define pdf-to-html_TYPE_TEXT_SPAN                                                    (pdf-to-html_text_span_get_type ())
GType                        pdf-to-html_text_span_get_type                           (void) G_GNUC_CONST;
pdf-to-htmlTextSpan             *pdf-to-html_text_span_copy                               (pdf-to-htmlTextSpan *pdf-to-html_text_span);
void                         pdf-to-html_text_span_free                               (pdf-to-htmlTextSpan *pdf-to-html_text_span);
gboolean                     pdf-to-html_text_span_is_fixed_width_font                (pdf-to-htmlTextSpan *pdf-to-html_text_span);
gboolean                     pdf-to-html_text_span_is_serif_font                      (pdf-to-htmlTextSpan *pdf-to-html_text_span);
gboolean                     pdf-to-html_text_span_is_bold_font                       (pdf-to-htmlTextSpan *pdf-to-html_text_span);
void                         pdf-to-html_text_span_get_color                          (pdf-to-htmlTextSpan *pdf-to-html_text_span,
                                                                                   pdf-to-htmlColor    *color);
const gchar                 *pdf-to-html_text_span_get_text                           (pdf-to-htmlTextSpan *pdf-to-html_text_span);
const gchar                 *pdf-to-html_text_span_get_font_name                      (pdf-to-htmlTextSpan *pdf-to-html_text_span);

G_END_DECLS

#endif /* !__pdf-to-html_STRUCTURE_ELEMENT_H__ */
