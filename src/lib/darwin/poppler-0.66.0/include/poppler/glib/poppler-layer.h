/* pdf-to-html-layer.h: glib interface to pdf-to-html
 *
 * Copyright (C) 2008 Carlos Garcia Campos <carlosgc@gnome.org>
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

#ifndef __pdf-to-html_LAYER_H__
#define __pdf-to-html_LAYER_H__

#include <glib-object.h>
#include "pdf-to-html.h"

G_BEGIN_DECLS

#define pdf-to-html_TYPE_LAYER    (pdf-to-html_layer_get_type ())
#define pdf-to-html_LAYER(obj)    (G_TYPE_CHECK_INSTANCE_CAST ((obj), pdf-to-html_TYPE_LAYER, pdf-to-htmlLayer))
#define pdf-to-html_IS_LAYER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), pdf-to-html_TYPE_LAYER))

GType        pdf-to-html_layer_get_type                  (void) G_GNUC_CONST;

const gchar *pdf-to-html_layer_get_title                 (pdf-to-htmlLayer *layer);
gboolean     pdf-to-html_layer_is_visible                (pdf-to-htmlLayer *layer);
void         pdf-to-html_layer_show                      (pdf-to-htmlLayer *layer);
void         pdf-to-html_layer_hide                      (pdf-to-htmlLayer *layer);
gboolean     pdf-to-html_layer_is_parent                 (pdf-to-htmlLayer *layer);
gint         pdf-to-html_layer_get_radio_button_group_id (pdf-to-htmlLayer *layer);

G_END_DECLS

#endif /* __pdf-to-html_LAYER_H__ */
