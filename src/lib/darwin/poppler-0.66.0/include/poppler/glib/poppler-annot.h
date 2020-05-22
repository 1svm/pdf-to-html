/* pdf-to-html-annot.h: glib interface to pdf-to-html
 *
 * Copyright (C) 2007 Inigo Martinez <inigomartinez@gmail.com>
 * Copyright (C) 2009 Carlos Garcia Campos <carlosgc@gnome.org>
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

#ifndef __pdf-to-html_ANNOT_H__
#define __pdf-to-html_ANNOT_H__

#include <glib-object.h>
#include "pdf-to-html.h"

G_BEGIN_DECLS

#define pdf-to-html_TYPE_ANNOT                   (pdf-to-html_annot_get_type ())
#define pdf-to-html_ANNOT(obj)                   (G_TYPE_CHECK_INSTANCE_CAST ((obj), pdf-to-html_TYPE_ANNOT, pdf-to-htmlAnnot))
#define pdf-to-html_IS_ANNOT(obj)                (G_TYPE_CHECK_INSTANCE_TYPE ((obj), pdf-to-html_TYPE_ANNOT))

#define pdf-to-html_TYPE_ANNOT_MARKUP            (pdf-to-html_annot_markup_get_type ())
#define pdf-to-html_ANNOT_MARKUP(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), pdf-to-html_TYPE_ANNOT_MARKUP, pdf-to-htmlAnnotMarkup))
#define pdf-to-html_IS_ANNOT_MARKUP(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), pdf-to-html_TYPE_ANNOT_MARKUP))

#define pdf-to-html_TYPE_ANNOT_TEXT              (pdf-to-html_annot_text_get_type ())
#define pdf-to-html_ANNOT_TEXT(obj)              (G_TYPE_CHECK_INSTANCE_CAST ((obj), pdf-to-html_TYPE_ANNOT_TEXT, pdf-to-htmlAnnotText))
#define pdf-to-html_IS_ANNOT_TEXT(obj)           (G_TYPE_CHECK_INSTANCE_TYPE ((obj), pdf-to-html_TYPE_ANNOT_TEXT))

#define pdf-to-html_TYPE_ANNOT_TEXT_MARKUP       (pdf-to-html_annot_text_markup_get_type ())
#define pdf-to-html_ANNOT_TEXT_MARKUP(obj)       (G_TYPE_CHECK_INSTANCE_CAST ((obj), pdf-to-html_TYPE_ANNOT_TEXT_MARKUP, pdf-to-htmlAnnotTextMarkup))
#define pdf-to-html_IS_ANNOT_TEXT_MARKUP(obj)    (G_TYPE_CHECK_INSTANCE_TYPE ((obj), pdf-to-html_TYPE_ANNOT_TEXT_MARKUP))


#define pdf-to-html_TYPE_ANNOT_FREE_TEXT         (pdf-to-html_annot_free_text_get_type ())
#define pdf-to-html_ANNOT_FREE_TEXT(obj)         (G_TYPE_CHECK_INSTANCE_CAST ((obj), pdf-to-html_TYPE_ANNOT_FREE_TEXT, pdf-to-htmlAnnotFreeText))
#define pdf-to-html_IS_ANNOT_FREE_TEXT(obj)      (G_TYPE_CHECK_INSTANCE_TYPE ((obj), pdf-to-html_TYPE_ANNOT_FREE_TEXT))

#define pdf-to-html_TYPE_ANNOT_FILE_ATTACHMENT   (pdf-to-html_annot_file_attachment_get_type ())
#define pdf-to-html_ANNOT_FILE_ATTACHMENT(obj)   (G_TYPE_CHECK_INSTANCE_CAST ((obj), pdf-to-html_TYPE_ANNOT_MARKUP, pdf-to-htmlAnnotFileAttachment))
#define pdf-to-html_IS_ANNOT_FILE_ATTACHMENT(obj)(G_TYPE_CHECK_INSTANCE_TYPE ((obj), pdf-to-html_TYPE_ANNOT_FILE_ATTACHMENT))

#define pdf-to-html_TYPE_ANNOT_MOVIE             (pdf-to-html_annot_movie_get_type ())
#define pdf-to-html_ANNOT_MOVIE(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), pdf-to-html_TYPE_ANNOT_MOVIE, pdf-to-htmlAnnotMovie))
#define pdf-to-html_IS_ANNOT_MOVIE(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), pdf-to-html_TYPE_ANNOT_MOVIE))

#define pdf-to-html_TYPE_ANNOT_SCREEN            (pdf-to-html_annot_screen_get_type ())
#define pdf-to-html_ANNOT_SCREEN(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), pdf-to-html_TYPE_ANNOT_SCREEN, pdf-to-htmlAnnotScreen))
#define pdf-to-html_IS_ANNOT_SCREEN(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), pdf-to-html_TYPE_ANNOT_SCREEN))

#define pdf-to-html_TYPE_ANNOT_LINE              (pdf-to-html_annot_line_get_type ())
#define pdf-to-html_ANNOT_LINE(obj)              (G_TYPE_CHECK_INSTANCE_CAST ((obj), pdf-to-html_TYPE_ANNOT_LINE, pdf-to-htmlAnnotLine))
#define pdf-to-html_IS_ANNOT_LINE(obj)           (G_TYPE_CHECK_INSTANCE_TYPE ((obj), pdf-to-html_TYPE_ANNOT_LINE))

#define pdf-to-html_TYPE_ANNOT_CALLOUT_LINE      (pdf-to-html_annot_callout_line_get_type ())

#define pdf-to-html_TYPE_ANNOT_CIRCLE            (pdf-to-html_annot_circle_get_type ())
#define pdf-to-html_ANNOT_CIRCLE(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), pdf-to-html_TYPE_ANNOT_CIRCLE, pdf-to-htmlAnnotCircle))
#define pdf-to-html_IS_ANNOT_CIRCLE(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), pdf-to-html_TYPE_ANNOT_CIRCLE))

#define pdf-to-html_TYPE_ANNOT_SQUARE            (pdf-to-html_annot_square_get_type ())
#define pdf-to-html_ANNOT_SQUARE(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), pdf-to-html_TYPE_ANNOT_SQUARE, pdf-to-htmlAnnotSquare))
#define pdf-to-html_IS_ANNOT_SQUARE(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), pdf-to-html_TYPE_ANNOT_SQUARE))

typedef enum
{
  pdf-to-html_ANNOT_UNKNOWN,
  pdf-to-html_ANNOT_TEXT,
  pdf-to-html_ANNOT_LINK,
  pdf-to-html_ANNOT_FREE_TEXT,
  pdf-to-html_ANNOT_LINE,
  pdf-to-html_ANNOT_SQUARE,
  pdf-to-html_ANNOT_CIRCLE,
  pdf-to-html_ANNOT_POLYGON,
  pdf-to-html_ANNOT_POLY_LINE,
  pdf-to-html_ANNOT_HIGHLIGHT,
  pdf-to-html_ANNOT_UNDERLINE,
  pdf-to-html_ANNOT_SQUIGGLY,
  pdf-to-html_ANNOT_STRIKE_OUT,
  pdf-to-html_ANNOT_STAMP,
  pdf-to-html_ANNOT_CARET,
  pdf-to-html_ANNOT_INK,
  pdf-to-html_ANNOT_POPUP,
  pdf-to-html_ANNOT_FILE_ATTACHMENT,
  pdf-to-html_ANNOT_SOUND,
  pdf-to-html_ANNOT_MOVIE,
  pdf-to-html_ANNOT_WIDGET,
  pdf-to-html_ANNOT_SCREEN,
  pdf-to-html_ANNOT_PRINTER_MARK,
  pdf-to-html_ANNOT_TRAP_NET,
  pdf-to-html_ANNOT_WATERMARK,
  pdf-to-html_ANNOT_3D
} pdf-to-htmlAnnotType;

typedef enum /*< flags >*/
{
  pdf-to-html_ANNOT_FLAG_UNKNOWN = 0,
  pdf-to-html_ANNOT_FLAG_INVISIBLE = 1 << 0,
  pdf-to-html_ANNOT_FLAG_HIDDEN = 1 << 1,
  pdf-to-html_ANNOT_FLAG_PRINT = 1 << 2,
  pdf-to-html_ANNOT_FLAG_NO_ZOOM = 1 << 3,
  pdf-to-html_ANNOT_FLAG_NO_ROTATE = 1 << 4,
  pdf-to-html_ANNOT_FLAG_NO_VIEW = 1 << 5,
  pdf-to-html_ANNOT_FLAG_READ_ONLY = 1 << 6,
  pdf-to-html_ANNOT_FLAG_LOCKED = 1 << 7,
  pdf-to-html_ANNOT_FLAG_TOGGLE_NO_VIEW = 1 << 8,
  pdf-to-html_ANNOT_FLAG_LOCKED_CONTENTS = 1 << 9
} pdf-to-htmlAnnotFlag;

typedef enum
{
  pdf-to-html_ANNOT_MARKUP_REPLY_TYPE_R,
  pdf-to-html_ANNOT_MARKUP_REPLY_TYPE_GROUP
} pdf-to-htmlAnnotMarkupReplyType;

typedef enum
{
  pdf-to-html_ANNOT_EXTERNAL_DATA_MARKUP_3D,
  pdf-to-html_ANNOT_EXTERNAL_DATA_MARKUP_UNKNOWN
} pdf-to-htmlAnnotExternalDataType;

#define pdf-to-html_ANNOT_TEXT_ICON_NOTE          "Note"
#define pdf-to-html_ANNOT_TEXT_ICON_COMMENT       "Comment"
#define pdf-to-html_ANNOT_TEXT_ICON_KEY           "Key"
#define pdf-to-html_ANNOT_TEXT_ICON_HELP          "Help"
#define pdf-to-html_ANNOT_TEXT_ICON_NEW_PARAGRAPH "NewParagraph"
#define pdf-to-html_ANNOT_TEXT_ICON_PARAGRAPH     "Paragraph"
#define pdf-to-html_ANNOT_TEXT_ICON_INSERT        "Insert"
#define pdf-to-html_ANNOT_TEXT_ICON_CROSS         "Cross"
#define pdf-to-html_ANNOT_TEXT_ICON_CIRCLE        "Circle"

typedef enum
{
  pdf-to-html_ANNOT_TEXT_STATE_MARKED,
  pdf-to-html_ANNOT_TEXT_STATE_UNMARKED,
  pdf-to-html_ANNOT_TEXT_STATE_ACCEPTED,
  pdf-to-html_ANNOT_TEXT_STATE_REJECTED,
  pdf-to-html_ANNOT_TEXT_STATE_CANCELLED,
  pdf-to-html_ANNOT_TEXT_STATE_COMPLETED,
  pdf-to-html_ANNOT_TEXT_STATE_NONE,
  pdf-to-html_ANNOT_TEXT_STATE_UNKNOWN
} pdf-to-htmlAnnotTextState;

typedef enum
{
  pdf-to-html_ANNOT_FREE_TEXT_QUADDING_LEFT_JUSTIFIED,
  pdf-to-html_ANNOT_FREE_TEXT_QUADDING_CENTERED,
  pdf-to-html_ANNOT_FREE_TEXT_QUADDING_RIGHT_JUSTIFIED
} pdf-to-htmlAnnotFreeTextQuadding;

struct _pdf-to-htmlAnnotCalloutLine
{
  gboolean multiline;
  gdouble  x1;
  gdouble  y1;
  gdouble  x2;
  gdouble  y2;
  gdouble  x3;
  gdouble  y3;
};

GType                         pdf-to-html_annot_get_type                           (void) G_GNUC_CONST;
pdf-to-htmlAnnotType              pdf-to-html_annot_get_annot_type                     (pdf-to-htmlAnnot *pdf-to-html_annot);
gchar                        *pdf-to-html_annot_get_contents                       (pdf-to-htmlAnnot *pdf-to-html_annot);
void                          pdf-to-html_annot_set_contents                       (pdf-to-htmlAnnot *pdf-to-html_annot,
										const gchar  *contents);
gchar                        *pdf-to-html_annot_get_name                           (pdf-to-htmlAnnot *pdf-to-html_annot);
gchar                        *pdf-to-html_annot_get_modified                       (pdf-to-htmlAnnot *pdf-to-html_annot);
pdf-to-htmlAnnotFlag              pdf-to-html_annot_get_flags                          (pdf-to-htmlAnnot *pdf-to-html_annot);
void                          pdf-to-html_annot_set_flags                          (pdf-to-htmlAnnot *pdf-to-html_annot,
										pdf-to-htmlAnnotFlag flags);
pdf-to-htmlColor                 *pdf-to-html_annot_get_color                          (pdf-to-htmlAnnot *pdf-to-html_annot);
void                          pdf-to-html_annot_set_color                          (pdf-to-htmlAnnot *pdf-to-html_annot,
										pdf-to-htmlColor *pdf-to-html_color);
gint                          pdf-to-html_annot_get_page_index                     (pdf-to-htmlAnnot *pdf-to-html_annot);
void                          pdf-to-html_annot_get_rectangle                      (pdf-to-htmlAnnot     *pdf-to-html_annot,
										pdf-to-htmlRectangle *pdf-to-html_rect);
void                          pdf-to-html_annot_set_rectangle                      (pdf-to-htmlAnnot     *pdf-to-html_annot,
										pdf-to-htmlRectangle *pdf-to-html_rect);

/* pdf-to-htmlAnnotMarkup */
GType                         pdf-to-html_annot_markup_get_type                    (void) G_GNUC_CONST;
gchar                        *pdf-to-html_annot_markup_get_label                   (pdf-to-htmlAnnotMarkup *pdf-to-html_annot);
void                          pdf-to-html_annot_markup_set_label                   (pdf-to-htmlAnnotMarkup *pdf-to-html_annot,
										const gchar        *label);
gboolean                      pdf-to-html_annot_markup_has_popup                   (pdf-to-htmlAnnotMarkup *pdf-to-html_annot);
void                          pdf-to-html_annot_markup_set_popup                   (pdf-to-htmlAnnotMarkup *pdf-to-html_annot,
										pdf-to-htmlRectangle   *popup_rect);
gboolean                      pdf-to-html_annot_markup_get_popup_is_open           (pdf-to-htmlAnnotMarkup *pdf-to-html_annot);
void                          pdf-to-html_annot_markup_set_popup_is_open           (pdf-to-htmlAnnotMarkup *pdf-to-html_annot,
										gboolean            is_open);
gboolean                      pdf-to-html_annot_markup_get_popup_rectangle         (pdf-to-htmlAnnotMarkup *pdf-to-html_annot,
										pdf-to-htmlRectangle   *pdf-to-html_rect);
void                          pdf-to-html_annot_markup_set_popup_rectangle         (pdf-to-htmlAnnotMarkup *pdf-to-html_annot,
                                                                                pdf-to-htmlRectangle   *pdf-to-html_rect);
gdouble                       pdf-to-html_annot_markup_get_opacity                 (pdf-to-htmlAnnotMarkup *pdf-to-html_annot);
void                          pdf-to-html_annot_markup_set_opacity                 (pdf-to-htmlAnnotMarkup *pdf-to-html_annot,
										gdouble             opacity);
GDate                        *pdf-to-html_annot_markup_get_date                    (pdf-to-htmlAnnotMarkup *pdf-to-html_annot);
gchar                        *pdf-to-html_annot_markup_get_subject                 (pdf-to-htmlAnnotMarkup *pdf-to-html_annot);
pdf-to-htmlAnnotMarkupReplyType   pdf-to-html_annot_markup_get_reply_to                (pdf-to-htmlAnnotMarkup *pdf-to-html_annot);
pdf-to-htmlAnnotExternalDataType  pdf-to-html_annot_markup_get_external_data           (pdf-to-htmlAnnotMarkup *pdf-to-html_annot);

/* pdf-to-htmlAnnotText */
GType                         pdf-to-html_annot_text_get_type                      (void) G_GNUC_CONST;
pdf-to-htmlAnnot                 *pdf-to-html_annot_text_new                           (pdf-to-htmlDocument  *doc,
										pdf-to-htmlRectangle *rect);
gboolean                      pdf-to-html_annot_text_get_is_open                   (pdf-to-htmlAnnotText *pdf-to-html_annot);
void                          pdf-to-html_annot_text_set_is_open                   (pdf-to-htmlAnnotText *pdf-to-html_annot,
										gboolean          is_open);
gchar                        *pdf-to-html_annot_text_get_icon                      (pdf-to-htmlAnnotText *pdf-to-html_annot);
void                          pdf-to-html_annot_text_set_icon                      (pdf-to-htmlAnnotText *pdf-to-html_annot,
										const gchar      *icon);
pdf-to-htmlAnnotTextState         pdf-to-html_annot_text_get_state                     (pdf-to-htmlAnnotText *pdf-to-html_annot);

/* pdf-to-htmlAnnotTextMarkup */
GType                         pdf-to-html_annot_text_markup_get_type               (void) G_GNUC_CONST;
pdf-to-htmlAnnot                 *pdf-to-html_annot_text_markup_new_highlight          (pdf-to-htmlDocument  *doc,
                                                                                pdf-to-htmlRectangle *rect,
                                                                                GArray           *quadrilaterals);
pdf-to-htmlAnnot                 *pdf-to-html_annot_text_markup_new_squiggly           (pdf-to-htmlDocument  *doc,
                                                                                pdf-to-htmlRectangle *rect,
                                                                                GArray           *quadrilaterals);
pdf-to-htmlAnnot                 *pdf-to-html_annot_text_markup_new_strikeout          (pdf-to-htmlDocument  *doc,
                                                                                pdf-to-htmlRectangle *rect,
                                                                                GArray           *quadrilaterals);
pdf-to-htmlAnnot                 *pdf-to-html_annot_text_markup_new_underline          (pdf-to-htmlDocument  *doc,
                                                                                pdf-to-htmlRectangle *rect,
                                                                                GArray           *quadrilaterals);
void                          pdf-to-html_annot_text_markup_set_quadrilaterals     (pdf-to-htmlAnnotTextMarkup *pdf-to-html_annot,
										GArray                 *quadrilaterals);
GArray                       *pdf-to-html_annot_text_markup_get_quadrilaterals     (pdf-to-htmlAnnotTextMarkup *pdf-to-html_annot);

/* pdf-to-htmlAnnotFreeText */
GType                         pdf-to-html_annot_free_text_get_type                 (void) G_GNUC_CONST;
pdf-to-htmlAnnotFreeTextQuadding  pdf-to-html_annot_free_text_get_quadding             (pdf-to-htmlAnnotFreeText *pdf-to-html_annot);
pdf-to-htmlAnnotCalloutLine      *pdf-to-html_annot_free_text_get_callout_line         (pdf-to-htmlAnnotFreeText *pdf-to-html_annot);

/* pdf-to-htmlAnnotFileAttachment */
GType                         pdf-to-html_annot_file_attachment_get_type           (void) G_GNUC_CONST;
pdf-to-htmlAttachment            *pdf-to-html_annot_file_attachment_get_attachment     (pdf-to-htmlAnnotFileAttachment *pdf-to-html_annot);
gchar                        *pdf-to-html_annot_file_attachment_get_name           (pdf-to-htmlAnnotFileAttachment *pdf-to-html_annot);

/* pdf-to-htmlAnnotMovie */
GType                         pdf-to-html_annot_movie_get_type                     (void) G_GNUC_CONST;
gchar                        *pdf-to-html_annot_movie_get_title                    (pdf-to-htmlAnnotMovie *pdf-to-html_annot);
pdf-to-htmlMovie                 *pdf-to-html_annot_movie_get_movie                    (pdf-to-htmlAnnotMovie *pdf-to-html_annot);

/* pdf-to-htmlAnnotScreen */
GType                         pdf-to-html_annot_screen_get_type                    (void) G_GNUC_CONST;
pdf-to-htmlAction                *pdf-to-html_annot_screen_get_action                  (pdf-to-htmlAnnotScreen *pdf-to-html_annot);

/* pdf-to-htmlAnnotLine */
GType                         pdf-to-html_annot_line_get_type                      (void) G_GNUC_CONST;
pdf-to-htmlAnnot                 *pdf-to-html_annot_line_new                           (pdf-to-htmlDocument  *doc,
                                                                                pdf-to-htmlRectangle *rect,
                                                                                pdf-to-htmlPoint     *start,
                                                                                pdf-to-htmlPoint     *end);
void                          pdf-to-html_annot_line_set_vertices                  (pdf-to-htmlAnnotLine *pdf-to-html_annot,
										pdf-to-htmlPoint     *start,
										pdf-to-htmlPoint     *end);

/* pdf-to-htmlAnnotCalloutLine */
GType                         pdf-to-html_annot_callout_line_get_type              (void) G_GNUC_CONST;
pdf-to-htmlAnnotCalloutLine      *pdf-to-html_annot_callout_line_new                   (void);
pdf-to-htmlAnnotCalloutLine      *pdf-to-html_annot_callout_line_copy                  (pdf-to-htmlAnnotCalloutLine *callout);
void                          pdf-to-html_annot_callout_line_free                  (pdf-to-htmlAnnotCalloutLine *callout);

/* pdf-to-htmlAnnotCircle */
GType                         pdf-to-html_annot_circle_get_type                    (void) G_GNUC_CONST;
pdf-to-htmlAnnot                 *pdf-to-html_annot_circle_new                         (pdf-to-htmlDocument    *doc,
                                                                                pdf-to-htmlRectangle   *rect);
void                          pdf-to-html_annot_circle_set_interior_color          (pdf-to-htmlAnnotCircle *pdf-to-html_annot,
										pdf-to-htmlColor       *pdf-to-html_color);
pdf-to-htmlColor                 *pdf-to-html_annot_circle_get_interior_color          (pdf-to-htmlAnnotCircle *pdf-to-html_annot);

/* pdf-to-htmlAnnotGeometry */
GType                         pdf-to-html_annot_square_get_type                    (void) G_GNUC_CONST;
pdf-to-htmlAnnot                 *pdf-to-html_annot_square_new                         (pdf-to-htmlDocument    *doc,
                                                                                pdf-to-htmlRectangle   *rect);
void                          pdf-to-html_annot_square_set_interior_color          (pdf-to-htmlAnnotSquare *pdf-to-html_annot,
										pdf-to-htmlColor       *pdf-to-html_color);
pdf-to-htmlColor                 *pdf-to-html_annot_square_get_interior_color          (pdf-to-htmlAnnotSquare *pdf-to-html_annot);

G_END_DECLS

#endif /* __pdf-to-html_ANNOT_H__ */
