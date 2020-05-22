/* pdf-to-html-media.h: glib interface to MediaRendition
 *
 * Copyright (C) 2010 Carlos Garcia Campos <carlosgc@gnome.org>
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

#ifndef __pdf-to-html_MEDIA_H__
#define __pdf-to-html_MEDIA_H__

#include <glib-object.h>
#include "pdf-to-html.h"

G_BEGIN_DECLS

#define pdf-to-html_TYPE_MEDIA                   (pdf-to-html_media_get_type ())
#define pdf-to-html_MEDIA(obj)                   (G_TYPE_CHECK_INSTANCE_CAST ((obj), pdf-to-html_TYPE_MEDIA, pdf-to-htmlMedia))
#define pdf-to-html_IS_MEDIA(obj)                (G_TYPE_CHECK_INSTANCE_TYPE ((obj), pdf-to-html_TYPE_MEDIA))

/* FIXME: this should be generic (pdf-to-htmlSaveToCallbackFunc) */

/**
 * pdf-to-htmlMediaSaveFunc:
 * @buf: (array length=count) (element-type guint8): buffer containing
 *   bytes to be written.
 * @count: number of bytes in @buf.
 * @data: (closure): user data passed to pdf-to-html_media_save_to_callback()
 * @error: GError to set on error, or %NULL
 *
 * Specifies the type of the function passed to
 * pdf-to-html_media_save_to_callback().  It is called once for each block of
 * bytes that is "written" by pdf-to-html_media_save_to_callback().  If
 * successful it should return %TRUE.  If an error occurs it should set
 * @error and return %FALSE, in which case pdf-to-html_media_save_to_callback()
 * will fail with the same error.
 *
 * Returns: %TRUE if successful, %FALSE (with @error set) if failed.
 *
 * Since: 0.14
 */
typedef gboolean (*pdf-to-htmlMediaSaveFunc) (const gchar  *buf,
					  gsize         count,
					  gpointer      data,
					  GError      **error);

GType        pdf-to-html_media_get_type         (void) G_GNUC_CONST;
gboolean     pdf-to-html_media_is_embedded      (pdf-to-htmlMedia        *pdf-to-html_media);
const gchar *pdf-to-html_media_get_filename     (pdf-to-htmlMedia        *pdf-to-html_media);
const gchar *pdf-to-html_media_get_mime_type    (pdf-to-htmlMedia        *pdf-to-html_media);
gboolean     pdf-to-html_media_save             (pdf-to-htmlMedia        *pdf-to-html_media,
					     const char          *filename,
					     GError             **error);
gboolean     pdf-to-html_media_save_to_callback (pdf-to-htmlMedia        *pdf-to-html_media,
					     pdf-to-htmlMediaSaveFunc save_func,
					     gpointer             user_data,
					     GError             **error);

G_END_DECLS

#endif /* __pdf-to-html_MEDIA_H__ */

