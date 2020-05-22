/* pdf-to-html-form-field.h: glib interface to pdf-to-html
 *
 * Copyright (C) 2007 Carlos Garcia Campos <carlosgc@gnome.org>
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

#ifndef __pdf-to-html_FORM_FIELD_H__
#define __pdf-to-html_FORM_FIELD_H__

#include <glib-object.h>
#include "pdf-to-html.h"

G_BEGIN_DECLS

#define pdf-to-html_TYPE_FORM_FIELD             (pdf-to-html_form_field_get_type ())
#define pdf-to-html_FORM_FIELD(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), pdf-to-html_TYPE_FORM_FIELD, pdf-to-htmlFormField))
#define pdf-to-html_IS_FORM_FIELD(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), pdf-to-html_TYPE_FORM_FIELD))

typedef enum
{
  pdf-to-html_FORM_FIELD_UNKNOWN,
  pdf-to-html_FORM_FIELD_BUTTON,
  pdf-to-html_FORM_FIELD_TEXT,
  pdf-to-html_FORM_FIELD_CHOICE,
  pdf-to-html_FORM_FIELD_SIGNATURE
} pdf-to-htmlFormFieldType;

typedef enum
{
  pdf-to-html_FORM_BUTTON_PUSH,
  pdf-to-html_FORM_BUTTON_CHECK,
  pdf-to-html_FORM_BUTTON_RADIO
} pdf-to-htmlFormButtonType;

typedef enum
{
  pdf-to-html_FORM_TEXT_NORMAL,
  pdf-to-html_FORM_TEXT_MULTILINE,
  pdf-to-html_FORM_TEXT_FILE_SELECT
} pdf-to-htmlFormTextType;

typedef enum
{
  pdf-to-html_FORM_CHOICE_COMBO,
  pdf-to-html_FORM_CHOICE_LIST
} pdf-to-htmlFormChoiceType;

GType                 pdf-to-html_form_field_get_type                (void) G_GNUC_CONST;

pdf-to-htmlFormFieldType  pdf-to-html_form_field_get_field_type          (pdf-to-htmlFormField *field);
gint                  pdf-to-html_form_field_get_id                  (pdf-to-htmlFormField *field);
gdouble               pdf-to-html_form_field_get_font_size           (pdf-to-htmlFormField *field);
gboolean              pdf-to-html_form_field_is_read_only            (pdf-to-htmlFormField *field);
gchar                *pdf-to-html_form_field_get_partial_name        (pdf-to-htmlFormField *field);
gchar                *pdf-to-html_form_field_get_mapping_name        (pdf-to-htmlFormField *field);
gchar                *pdf-to-html_form_field_get_name                (pdf-to-htmlFormField *field);
pdf-to-htmlAction        *pdf-to-html_form_field_get_action              (pdf-to-htmlFormField *field);

/* Button Field */
pdf-to-htmlFormButtonType pdf-to-html_form_field_button_get_button_type  (pdf-to-htmlFormField *field);
gboolean              pdf-to-html_form_field_button_get_state        (pdf-to-htmlFormField *field);
void                  pdf-to-html_form_field_button_set_state        (pdf-to-htmlFormField *field,
								  gboolean          state);

/* Text Field */
pdf-to-htmlFormTextType   pdf-to-html_form_field_text_get_text_type      (pdf-to-htmlFormField *field);
gchar                *pdf-to-html_form_field_text_get_text           (pdf-to-htmlFormField *field);
void                  pdf-to-html_form_field_text_set_text           (pdf-to-htmlFormField *field,
								  const gchar      *text);
gint                  pdf-to-html_form_field_text_get_max_len        (pdf-to-htmlFormField *field);
gboolean              pdf-to-html_form_field_text_do_spell_check     (pdf-to-htmlFormField *field);
gboolean              pdf-to-html_form_field_text_do_scroll          (pdf-to-htmlFormField *field);
gboolean              pdf-to-html_form_field_text_is_rich_text       (pdf-to-htmlFormField *field);
gboolean              pdf-to-html_form_field_text_is_password        (pdf-to-htmlFormField *field);

/* Choice Field */
pdf-to-htmlFormChoiceType pdf-to-html_form_field_choice_get_choice_type  (pdf-to-htmlFormField *field);
gboolean              pdf-to-html_form_field_choice_is_editable      (pdf-to-htmlFormField *field);
gboolean           pdf-to-html_form_field_choice_can_select_multiple (pdf-to-htmlFormField *field);
gboolean              pdf-to-html_form_field_choice_do_spell_check   (pdf-to-htmlFormField *field);
gboolean              pdf-to-html_form_field_choice_commit_on_change (pdf-to-htmlFormField *field);
gint                  pdf-to-html_form_field_choice_get_n_items      (pdf-to-htmlFormField *field);
gchar                *pdf-to-html_form_field_choice_get_item         (pdf-to-htmlFormField *field,
								  gint              index);
gboolean              pdf-to-html_form_field_choice_is_item_selected (pdf-to-htmlFormField *field,
								  gint              index);
void                  pdf-to-html_form_field_choice_select_item      (pdf-to-htmlFormField *field,
								  gint              index);
void                  pdf-to-html_form_field_choice_unselect_all     (pdf-to-htmlFormField *field);
void                  pdf-to-html_form_field_choice_toggle_item      (pdf-to-htmlFormField *field,
								  gint              index);
void                  pdf-to-html_form_field_choice_set_text         (pdf-to-htmlFormField *field,
								  const gchar      *text);
gchar                *pdf-to-html_form_field_choice_get_text         (pdf-to-htmlFormField *field);

G_END_DECLS

#endif /* __pdf-to-html_FORM_FIELD_H__ */
