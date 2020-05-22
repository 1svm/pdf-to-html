/* pdf-to-html-attachment.h: glib interface to pdf-to-html
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

#ifndef __pdf-to-html_ATTACHMENT_H__
#define __pdf-to-html_ATTACHMENT_H__

#include <glib.h>
#include <glib-object.h>

#include "pdf-to-html.h"

G_BEGIN_DECLS


#define pdf-to-html_TYPE_ATTACHMENT             (pdf-to-html_attachment_get_type ())
#define pdf-to-html_ATTACHMENT(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), pdf-to-html_TYPE_ATTACHMENT, pdf-to-htmlAttachment))
#define pdf-to-html_IS_ATTACHMENT(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), pdf-to-html_TYPE_ATTACHMENT))


/**
 * pdf-to-htmlAttachmentSaveFunc:
 * @buf: (array length=count) (element-type guint8): buffer containing
 *   bytes to be written.
 * @count: number of bytes in @buf.
 * @data: (closure): user data passed to pdf-to-html_attachment_save_to_callback()
 * @error: GError to set on error, or %NULL
 *
 * Specifies the type of the function passed to
 * pdf-to-html_attachment_save_to_callback().  It is called once for each block of
 * bytes that is "written" by pdf-to-html_attachment_save_to_callback().  If
 * successful it should return %TRUE.  If an error occurs it should set
 * @error and return %FALSE, in which case pdf-to-html_attachment_save_to_callback()
 * will fail with the same error.
 *
 * Returns: %TRUE if successful, %FALSE (with @error set) if failed.
 */
typedef gboolean (*pdf-to-htmlAttachmentSaveFunc) (const gchar  *buf,
					       gsize         count,
					       gpointer      data,
					       GError      **error);

struct _pdf-to-htmlAttachment
{
  GObject parent;

  gchar *name;
  gchar *description;
  gsize size;
  GTime mtime;
  GTime ctime;
  GString *checksum;
};

typedef struct _pdf-to-htmlAttachmentClass
{
  GObjectClass parent_class;
} pdf-to-htmlAttachmentClass;


GType     pdf-to-html_attachment_get_type         (void) G_GNUC_CONST;
gboolean  pdf-to-html_attachment_save             (pdf-to-htmlAttachment          *attachment,
					       const char                 *filename,
					       GError                    **error);
gboolean  pdf-to-html_attachment_save_to_callback (pdf-to-htmlAttachment          *attachment,
					       pdf-to-htmlAttachmentSaveFunc   save_func,
					       gpointer                    user_data,
					       GError                    **error);


G_END_DECLS

#endif /* __pdf-to-html_ATTACHMENT_H__ */
