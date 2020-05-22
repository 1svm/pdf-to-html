/* pdf-to-html-document.h: glib interface to pdf-to-html
 * Copyright (C) 2004, Red Hat, Inc.
 *
 * Copyright (C) 2016 Jakub Alba <jakubalba@gmail.com>
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

#ifndef __pdf-to-html_DOCUMENT_H__
#define __pdf-to-html_DOCUMENT_H__

#include <glib-object.h>
#include <gio/gio.h>
#include "pdf-to-html.h"

G_BEGIN_DECLS

#define pdf-to-html_TYPE_DOCUMENT             (pdf-to-html_document_get_type ())
#define pdf-to-html_DOCUMENT(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), pdf-to-html_TYPE_DOCUMENT, pdf-to-htmlDocument))
#define pdf-to-html_IS_DOCUMENT(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), pdf-to-html_TYPE_DOCUMENT))

/**
 * pdf-to-htmlPageLayout:
 * @pdf-to-html_PAGE_LAYOUT_UNSET: no specific layout set
 * @pdf-to-html_PAGE_LAYOUT_SINGLE_PAGE: one page at a time
 * @pdf-to-html_PAGE_LAYOUT_ONE_COLUMN: pages in one column
 * @pdf-to-html_PAGE_LAYOUT_TWO_COLUMN_LEFT: pages in two columns with odd numbered pages on the left
 * @pdf-to-html_PAGE_LAYOUT_TWO_COLUMN_RIGHT: pages in two columns with odd numbered pages on the right
 * @pdf-to-html_PAGE_LAYOUT_TWO_PAGE_LEFT: two pages at a time with odd numbered pages on the left
 * @pdf-to-html_PAGE_LAYOUT_TWO_PAGE_RIGHT: two pages at a time with odd numbered pages on the right
 *
 * Page layout types
 */
typedef enum
{
  pdf-to-html_PAGE_LAYOUT_UNSET,
  pdf-to-html_PAGE_LAYOUT_SINGLE_PAGE,
  pdf-to-html_PAGE_LAYOUT_ONE_COLUMN,
  pdf-to-html_PAGE_LAYOUT_TWO_COLUMN_LEFT,
  pdf-to-html_PAGE_LAYOUT_TWO_COLUMN_RIGHT,
  pdf-to-html_PAGE_LAYOUT_TWO_PAGE_LEFT,
  pdf-to-html_PAGE_LAYOUT_TWO_PAGE_RIGHT
} pdf-to-htmlPageLayout;

/**
 * pdf-to-htmlPageMode:
 * @pdf-to-html_PAGE_MODE_UNSET: no specific mode set
 * @pdf-to-html_PAGE_MODE_NONE: neither document outline nor thumbnails visible
 * @pdf-to-html_PAGE_MODE_USE_OUTLINES: document outline visible
 * @pdf-to-html_PAGE_MODE_USE_THUMBS: thumbnails visible
 * @pdf-to-html_PAGE_MODE_FULL_SCREEN: full-screen mode
 * @pdf-to-html_PAGE_MODE_USE_OC: layers panel visible
 * @pdf-to-html_PAGE_MODE_USE_ATTACHMENTS: attachments panel visible
 *
 * Page modes
 */
typedef enum
{
  pdf-to-html_PAGE_MODE_UNSET,
  pdf-to-html_PAGE_MODE_NONE,
  pdf-to-html_PAGE_MODE_USE_OUTLINES,
  pdf-to-html_PAGE_MODE_USE_THUMBS,
  pdf-to-html_PAGE_MODE_FULL_SCREEN,
  pdf-to-html_PAGE_MODE_USE_OC,
  pdf-to-html_PAGE_MODE_USE_ATTACHMENTS
} pdf-to-htmlPageMode;

/**
 * pdf-to-htmlFontType:
 * @pdf-to-html_FONT_TYPE_UNKNOWN: unknown font type
 * @pdf-to-html_FONT_TYPE_TYPE1: Type 1 font type
 * @pdf-to-html_FONT_TYPE_TYPE1C: Type 1 font type embedded in Compact Font Format (CFF) font program
 * @pdf-to-html_FONT_TYPE_TYPE1COT: Type 1 font type embedded in OpenType font program
 * @pdf-to-html_FONT_TYPE_TYPE3: A font type that is defined with PDF graphics operators
 * @pdf-to-html_FONT_TYPE_TRUETYPE: TrueType font type
 * @pdf-to-html_FONT_TYPE_TRUETYPEOT: TrueType font type embedded in OpenType font program
 * @pdf-to-html_FONT_TYPE_CID_TYPE0: CIDFont type based on Type 1 font technology
 * @pdf-to-html_FONT_TYPE_CID_TYPE0C: CIDFont type based on Type 1 font technology embedded in CFF font program
 * @pdf-to-html_FONT_TYPE_CID_TYPE0COT: CIDFont type based on Type 1 font technology embedded in OpenType font program
 * @pdf-to-html_FONT_TYPE_CID_TYPE2: CIDFont type based on TrueType font technology
 * @pdf-to-html_FONT_TYPE_CID_TYPE2OT: CIDFont type based on TrueType font technology embedded in OpenType font program
 *
 * Font types
 */
typedef enum
{
  pdf-to-html_FONT_TYPE_UNKNOWN,
  pdf-to-html_FONT_TYPE_TYPE1,
  pdf-to-html_FONT_TYPE_TYPE1C,
  pdf-to-html_FONT_TYPE_TYPE1COT,
  pdf-to-html_FONT_TYPE_TYPE3,
  pdf-to-html_FONT_TYPE_TRUETYPE,
  pdf-to-html_FONT_TYPE_TRUETYPEOT,
  pdf-to-html_FONT_TYPE_CID_TYPE0,
  pdf-to-html_FONT_TYPE_CID_TYPE0C,
  pdf-to-html_FONT_TYPE_CID_TYPE0COT,
  pdf-to-html_FONT_TYPE_CID_TYPE2,
  pdf-to-html_FONT_TYPE_CID_TYPE2OT
} pdf-to-htmlFontType;

/**
 * pdf-to-htmlViewerPreferences:
 * @pdf-to-html_VIEWER_PREFERENCES_UNSET: no preferences set
 * @pdf-to-html_VIEWER_PREFERENCES_HIDE_TOOLBAR: hider toolbars when document is active
 * @pdf-to-html_VIEWER_PREFERENCES_HIDE_MENUBAR: hide menu bar when document is active
 * @pdf-to-html_VIEWER_PREFERENCES_HIDE_WINDOWUI: hide UI elements in document's window
 * @pdf-to-html_VIEWER_PREFERENCES_FIT_WINDOW: resize document's window to fit the size of the first displayed page
 * @pdf-to-html_VIEWER_PREFERENCES_CENTER_WINDOW: position the document's window in the center of the screen
 * @pdf-to-html_VIEWER_PREFERENCES_DISPLAY_DOC_TITLE: display document title in window's title bar
 * @pdf-to-html_VIEWER_PREFERENCES_DIRECTION_RTL: the predominant reading order for text is right to left
 *
 * Viewer preferences
 */
typedef enum /*< flags >*/
{
  pdf-to-html_VIEWER_PREFERENCES_UNSET = 0,
  pdf-to-html_VIEWER_PREFERENCES_HIDE_TOOLBAR = 1 << 0,
  pdf-to-html_VIEWER_PREFERENCES_HIDE_MENUBAR = 1 << 1,
  pdf-to-html_VIEWER_PREFERENCES_HIDE_WINDOWUI = 1 << 2,
  pdf-to-html_VIEWER_PREFERENCES_FIT_WINDOW = 1 << 3,
  pdf-to-html_VIEWER_PREFERENCES_CENTER_WINDOW = 1 << 4,
  pdf-to-html_VIEWER_PREFERENCES_DISPLAY_DOC_TITLE = 1 << 5,
  pdf-to-html_VIEWER_PREFERENCES_DIRECTION_RTL = 1 << 6
} pdf-to-htmlViewerPreferences;

/**
 * pdf-to-htmlPermissions:
 * @pdf-to-html_PERMISSIONS_OK_TO_PRINT: document can be printer
 * @pdf-to-html_PERMISSIONS_OK_TO_MODIFY: document contents can be modified
 * @pdf-to-html_PERMISSIONS_OK_TO_COPY: document can be copied
 * @pdf-to-html_PERMISSIONS_OK_TO_ADD_NOTES: annotations can added to the document
 * @pdf-to-html_PERMISSIONS_OK_TO_FILL_FORM: interactive form fields can be filled in
 * @pdf-to-html_PERMISSIONS_OK_TO_EXTRACT_CONTENTS: extract text and graphics
 * (in support of accessibility to users with disabilities or for other purposes). Since 0.18
 * @pdf-to-html_PERMISSIONS_OK_TO_ASSEMBLE: assemble the document (insert, rotate, or delete pages and create
 * bookmarks or thumbnail images). Since 0.18
 * @pdf-to-html_PERMISSIONS_OK_TO_PRINT_HIGH_RESOLUTION: document can be printer at high resolution. Since 0.18
 * @pdf-to-html_PERMISSIONS_FULL: document permits all operations
 *
 * Permissions
 */
typedef enum /*< flags >*/
{
  pdf-to-html_PERMISSIONS_OK_TO_PRINT = 1 << 0,
  pdf-to-html_PERMISSIONS_OK_TO_MODIFY = 1 << 1,
  pdf-to-html_PERMISSIONS_OK_TO_COPY = 1 << 2,
  pdf-to-html_PERMISSIONS_OK_TO_ADD_NOTES = 1 << 3,
  pdf-to-html_PERMISSIONS_OK_TO_FILL_FORM = 1 << 4,
  pdf-to-html_PERMISSIONS_OK_TO_EXTRACT_CONTENTS = 1 << 5,
  pdf-to-html_PERMISSIONS_OK_TO_ASSEMBLE = 1 << 6,
  pdf-to-html_PERMISSIONS_OK_TO_PRINT_HIGH_RESOLUTION = 1 << 7,
  pdf-to-html_PERMISSIONS_FULL = (pdf-to-html_PERMISSIONS_OK_TO_PRINT | pdf-to-html_PERMISSIONS_OK_TO_MODIFY | pdf-to-html_PERMISSIONS_OK_TO_COPY | pdf-to-html_PERMISSIONS_OK_TO_ADD_NOTES | pdf-to-html_PERMISSIONS_OK_TO_FILL_FORM | pdf-to-html_PERMISSIONS_OK_TO_EXTRACT_CONTENTS | pdf-to-html_PERMISSIONS_OK_TO_ASSEMBLE | pdf-to-html_PERMISSIONS_OK_TO_PRINT_HIGH_RESOLUTION)

} pdf-to-htmlPermissions;



GType              pdf-to-html_document_get_type               (void) G_GNUC_CONST;
pdf-to-htmlDocument   *pdf-to-html_document_new_from_file          (const char      *uri,
							    const char      *password,
							    GError         **error);
pdf-to-htmlDocument   *pdf-to-html_document_new_from_data          (char            *data,
							    int              length,
							    const char      *password,
							    GError         **error);
pdf-to-htmlDocument   *pdf-to-html_document_new_from_stream        (GInputStream    *stream,
                                                            goffset          length,
                                                            const char      *password,
                                                            GCancellable    *cancellable,
                                                            GError         **error);
pdf-to-htmlDocument   *pdf-to-html_document_new_from_gfile         (GFile           *file,
                                                            const char      *password,
                                                            GCancellable    *cancellable,
                                                            GError         **error);
gboolean           pdf-to-html_document_save                   (pdf-to-htmlDocument *document,
							    const char      *uri,
							    GError         **error);
gboolean           pdf-to-html_document_save_a_copy            (pdf-to-htmlDocument *document,
							    const char      *uri,
							    GError         **error);
gboolean           pdf-to-html_document_get_id                 (pdf-to-htmlDocument *document,
							    gchar          **permanent_id,
							    gchar          **update_id);
int                pdf-to-html_document_get_n_pages            (pdf-to-htmlDocument *document);
pdf-to-htmlPage       *pdf-to-html_document_get_page               (pdf-to-htmlDocument *document,
							    int              index);
pdf-to-htmlPage       *pdf-to-html_document_get_page_by_label      (pdf-to-htmlDocument *document,
							    const char      *label);
gchar             *pdf-to-html_document_get_pdf_version_string (pdf-to-htmlDocument *document);
void               pdf-to-html_document_get_pdf_version        (pdf-to-htmlDocument *document,
							    guint           *major_version,
							    guint           *minor_version);
gchar             *pdf-to-html_document_get_title              (pdf-to-htmlDocument *document);
void               pdf-to-html_document_set_title              (pdf-to-htmlDocument *document,
							    const gchar     *title);
gchar             *pdf-to-html_document_get_author             (pdf-to-htmlDocument *document);
void               pdf-to-html_document_set_author             (pdf-to-htmlDocument *document,
							    const gchar     *author);
gchar             *pdf-to-html_document_get_subject            (pdf-to-htmlDocument *document);
void               pdf-to-html_document_set_subject            (pdf-to-htmlDocument *document,
							    const gchar     *subject);
gchar             *pdf-to-html_document_get_keywords           (pdf-to-htmlDocument *document);
void               pdf-to-html_document_set_keywords           (pdf-to-htmlDocument *document,
                                                            const gchar     *keywords);
gchar             *pdf-to-html_document_get_creator            (pdf-to-htmlDocument *document);
void               pdf-to-html_document_set_creator            (pdf-to-htmlDocument *document,
                                                            const gchar     *creator);
gchar             *pdf-to-html_document_get_producer           (pdf-to-htmlDocument *document);
void               pdf-to-html_document_set_producer           (pdf-to-htmlDocument *document,
                                                            const gchar     *producer);
time_t             pdf-to-html_document_get_creation_date      (pdf-to-htmlDocument *document);
void               pdf-to-html_document_set_creation_date      (pdf-to-htmlDocument *document,
                                                            time_t           creation_date);
time_t             pdf-to-html_document_get_modification_date  (pdf-to-htmlDocument *document);
void               pdf-to-html_document_set_modification_date  (pdf-to-htmlDocument *document,
                                                            time_t           modification_date);
gboolean           pdf-to-html_document_is_linearized          (pdf-to-htmlDocument *document);
pdf-to-htmlPageLayout  pdf-to-html_document_get_page_layout        (pdf-to-htmlDocument *document);
pdf-to-htmlPageMode    pdf-to-html_document_get_page_mode          (pdf-to-htmlDocument *document);
pdf-to-htmlPermissions pdf-to-html_document_get_permissions        (pdf-to-htmlDocument *document);
gchar             *pdf-to-html_document_get_metadata           (pdf-to-htmlDocument *document);

/* Attachments */
guint              pdf-to-html_document_get_n_attachments      (pdf-to-htmlDocument  *document);
gboolean           pdf-to-html_document_has_attachments        (pdf-to-htmlDocument  *document);
GList             *pdf-to-html_document_get_attachments        (pdf-to-htmlDocument  *document);

/* Links */
pdf-to-htmlDest       *pdf-to-html_document_find_dest              (pdf-to-htmlDocument  *document,
							    const gchar      *link_name);

/* Form */
pdf-to-htmlFormField  *pdf-to-html_document_get_form_field         (pdf-to-htmlDocument  *document,
							    gint              id);

/* Interface for getting the Index of a pdf-to-html_document */
#define pdf-to-html_TYPE_INDEX_ITER                 (pdf-to-html_index_iter_get_type ())
GType             pdf-to-html_index_iter_get_type   (void) G_GNUC_CONST;
pdf-to-htmlIndexIter *pdf-to-html_index_iter_new        (pdf-to-htmlDocument   *document);
pdf-to-htmlIndexIter *pdf-to-html_index_iter_copy       (pdf-to-htmlIndexIter  *iter);
void              pdf-to-html_index_iter_free       (pdf-to-htmlIndexIter  *iter);

pdf-to-htmlIndexIter *pdf-to-html_index_iter_get_child  (pdf-to-htmlIndexIter  *parent);
gboolean	  pdf-to-html_index_iter_is_open    (pdf-to-htmlIndexIter  *iter);
pdf-to-htmlAction    *pdf-to-html_index_iter_get_action (pdf-to-htmlIndexIter  *iter);
gboolean          pdf-to-html_index_iter_next       (pdf-to-htmlIndexIter  *iter);

/* Interface for getting the Fonts of a pdf-to-html_document */
#define pdf-to-html_TYPE_FONT_INFO             (pdf-to-html_font_info_get_type ())
#define pdf-to-html_FONT_INFO(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), pdf-to-html_TYPE_FONT_INFO, pdf-to-htmlFontInfo))
#define pdf-to-html_IS_FONT_INFO(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), pdf-to-html_TYPE_FONT_INFO))
GType             pdf-to-html_font_info_get_type       (void) G_GNUC_CONST;
pdf-to-htmlFontInfo  *pdf-to-html_font_info_new            (pdf-to-htmlDocument   *document);
gboolean          pdf-to-html_font_info_scan           (pdf-to-htmlFontInfo   *font_info,
						    int                n_pages,
						    pdf-to-htmlFontsIter **iter);
void             pdf-to-html_font_info_free            (pdf-to-htmlFontInfo   *font_info);

#define pdf-to-html_TYPE_FONTS_ITER                    (pdf-to-html_fonts_iter_get_type ())
GType             pdf-to-html_fonts_iter_get_type      (void) G_GNUC_CONST;
pdf-to-htmlFontsIter *pdf-to-html_fonts_iter_copy          (pdf-to-htmlFontsIter  *iter);
void              pdf-to-html_fonts_iter_free          (pdf-to-htmlFontsIter  *iter);
const char       *pdf-to-html_fonts_iter_get_name      (pdf-to-htmlFontsIter  *iter);
const char       *pdf-to-html_fonts_iter_get_full_name (pdf-to-htmlFontsIter  *iter);
const char       *pdf-to-html_fonts_iter_get_substitute_name (pdf-to-htmlFontsIter *iter);
const char       *pdf-to-html_fonts_iter_get_file_name (pdf-to-htmlFontsIter  *iter);
pdf-to-htmlFontType   pdf-to-html_fonts_iter_get_font_type (pdf-to-htmlFontsIter  *iter);
const char       *pdf-to-html_fonts_iter_get_encoding  (pdf-to-htmlFontsIter *iter);
gboolean	  pdf-to-html_fonts_iter_is_embedded   (pdf-to-htmlFontsIter  *iter);
gboolean	  pdf-to-html_fonts_iter_is_subset     (pdf-to-htmlFontsIter  *iter);
gboolean          pdf-to-html_fonts_iter_next          (pdf-to-htmlFontsIter  *iter);

/* Interface for getting the Layers of a pdf-to-html_document */
#define pdf-to-html_TYPE_LAYERS_ITER                   (pdf-to-html_layers_iter_get_type ())
GType              pdf-to-html_layers_iter_get_type    (void) G_GNUC_CONST;
pdf-to-htmlLayersIter *pdf-to-html_layers_iter_new         (pdf-to-htmlDocument   *document);
pdf-to-htmlLayersIter *pdf-to-html_layers_iter_copy        (pdf-to-htmlLayersIter *iter);
void               pdf-to-html_layers_iter_free        (pdf-to-htmlLayersIter *iter);

pdf-to-htmlLayersIter *pdf-to-html_layers_iter_get_child   (pdf-to-htmlLayersIter *parent);
gchar             *pdf-to-html_layers_iter_get_title   (pdf-to-htmlLayersIter *iter);
pdf-to-htmlLayer      *pdf-to-html_layers_iter_get_layer   (pdf-to-htmlLayersIter *iter);
gboolean           pdf-to-html_layers_iter_next        (pdf-to-htmlLayersIter *iter);

/* Export to ps */
#define pdf-to-html_TYPE_PS_FILE             (pdf-to-html_ps_file_get_type ())
#define pdf-to-html_PS_FILE(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), pdf-to-html_TYPE_PS_FILE, pdf-to-htmlPSFile))
#define pdf-to-html_IS_PS_FILE(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), pdf-to-html_TYPE_PS_FILE))
GType          pdf-to-html_ps_file_get_type       (void) G_GNUC_CONST;
pdf-to-htmlPSFile *pdf-to-html_ps_file_new            (pdf-to-htmlDocument *document,
                                               const char      *filename,
                                               int              first_page,
                                               int              n_pages);
void           pdf-to-html_ps_file_set_paper_size (pdf-to-htmlPSFile   *ps_file,
                                               double           width,
                                               double           height);
void           pdf-to-html_ps_file_set_duplex     (pdf-to-htmlPSFile   *ps_file,
                                               gboolean         duplex);
void           pdf-to-html_ps_file_free           (pdf-to-htmlPSFile   *ps_file);



G_END_DECLS

#endif /* __pdf-to-html_DOCUMENT_H__ */
