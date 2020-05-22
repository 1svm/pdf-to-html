/* pdf-to-html-page.h: glib interface to pdf-to-html
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

#ifndef __pdf-to-html_PAGE_H__
#define __pdf-to-html_PAGE_H__

#include <glib-object.h>

#include "pdf-to-html.h"

#include <cairo.h>

G_BEGIN_DECLS

#define pdf-to-html_TYPE_PAGE             (pdf-to-html_page_get_type ())
#define pdf-to-html_PAGE(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), pdf-to-html_TYPE_PAGE, pdf-to-htmlPage))
#define pdf-to-html_IS_PAGE(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), pdf-to-html_TYPE_PAGE))


GType      	       pdf-to-html_page_get_type             (void) G_GNUC_CONST;

void                   pdf-to-html_page_render               (pdf-to-htmlPage        *page,
							  cairo_t            *cairo);
void                   pdf-to-html_page_render_for_printing  (pdf-to-htmlPage        *page,
							  cairo_t            *cairo);
void       pdf-to-html_page_render_for_printing_with_options (pdf-to-htmlPage        *page,
                                                          cairo_t            *cairo,
                                                          pdf-to-htmlPrintFlags   options);
cairo_surface_t       *pdf-to-html_page_get_thumbnail        (pdf-to-htmlPage        *page);
void                   pdf-to-html_page_render_selection     (pdf-to-htmlPage        *page,
							  cairo_t            *cairo,
							  pdf-to-htmlRectangle   *selection,
							  pdf-to-htmlRectangle   *old_selection,
							  pdf-to-htmlSelectionStyle style,
							  pdf-to-htmlColor       *glyph_color,
							  pdf-to-htmlColor       *background_color);

void                   pdf-to-html_page_get_size             (pdf-to-htmlPage        *page,
							  double             *width,
							  double             *height);
int                    pdf-to-html_page_get_index            (pdf-to-htmlPage        *page);
gchar                 *pdf-to-html_page_get_label            (pdf-to-htmlPage        *page);
double                 pdf-to-html_page_get_duration         (pdf-to-htmlPage        *page);
pdf-to-htmlPageTransition *pdf-to-html_page_get_transition       (pdf-to-htmlPage        *page);
gboolean               pdf-to-html_page_get_thumbnail_size   (pdf-to-htmlPage        *page,
							  int                *width,
							  int                *height);
GList             *pdf-to-html_page_find_text_with_options   (pdf-to-htmlPage        *page,
							  const  char        *text,
							  pdf-to-htmlFindFlags    options);
GList     	      *pdf-to-html_page_find_text            (pdf-to-htmlPage        *page,
							  const  char        *text);
void                   pdf-to-html_page_render_to_ps         (pdf-to-htmlPage        *page,
							  pdf-to-htmlPSFile      *ps_file);
char                  *pdf-to-html_page_get_text             (pdf-to-htmlPage        *page);
char                  *pdf-to-html_page_get_text_for_area    (pdf-to-htmlPage        *page,
                                                          pdf-to-htmlRectangle   *area);
char                  *pdf-to-html_page_get_selected_text    (pdf-to-htmlPage        *page,
							  pdf-to-htmlSelectionStyle style,
							  pdf-to-htmlRectangle   *selection);
cairo_region_t        *pdf-to-html_page_get_selected_region  (pdf-to-htmlPage        *page,
                                                          gdouble             scale,
                                                          pdf-to-htmlSelectionStyle  style,
                                                          pdf-to-htmlRectangle   *selection);
GList                 *pdf-to-html_page_get_selection_region (pdf-to-htmlPage        *page,
							  gdouble             scale,
							  pdf-to-htmlSelectionStyle style,
							  pdf-to-htmlRectangle   *selection);
void                   pdf-to-html_page_selection_region_free(GList              *region);
GList                 *pdf-to-html_page_get_link_mapping     (pdf-to-htmlPage        *page);
void                   pdf-to-html_page_free_link_mapping    (GList              *list);
GList                 *pdf-to-html_page_get_image_mapping    (pdf-to-htmlPage        *page);
void                   pdf-to-html_page_free_image_mapping   (GList              *list);
cairo_surface_t       *pdf-to-html_page_get_image            (pdf-to-htmlPage        *page,
							  gint                image_id);
GList              *pdf-to-html_page_get_form_field_mapping  (pdf-to-htmlPage        *page);
void                pdf-to-html_page_free_form_field_mapping (GList              *list);
GList                 *pdf-to-html_page_get_annot_mapping    (pdf-to-htmlPage        *page);
void                   pdf-to-html_page_free_annot_mapping   (GList              *list);
void                   pdf-to-html_page_add_annot            (pdf-to-htmlPage        *page,
							  pdf-to-htmlAnnot       *annot);
void                   pdf-to-html_page_remove_annot         (pdf-to-htmlPage        *page,
                                                          pdf-to-htmlAnnot       *annot);
void 		      pdf-to-html_page_get_crop_box 	 (pdf-to-htmlPage        *page,
							  pdf-to-htmlRectangle   *rect);
gboolean               pdf-to-html_page_get_text_layout      (pdf-to-htmlPage        *page,
                                                          pdf-to-htmlRectangle  **rectangles,
                                                          guint              *n_rectangles);
gboolean           pdf-to-html_page_get_text_layout_for_area (pdf-to-htmlPage        *page,
                                                          pdf-to-htmlRectangle   *area,
                                                          pdf-to-htmlRectangle  **rectangles,
                                                          guint              *n_rectangles);
GList                 *pdf-to-html_page_get_text_attributes  (pdf-to-htmlPage        *page);
void                   pdf-to-html_page_free_text_attributes (GList              *list);
GList *        pdf-to-html_page_get_text_attributes_for_area (pdf-to-htmlPage        *page,
                                                          pdf-to-htmlRectangle   *area);

/* A rectangle on a page, with coordinates in PDF points. */
#define pdf-to-html_TYPE_RECTANGLE             (pdf-to-html_rectangle_get_type ())
/**
 * pdf-to-htmlRectangle:
 * @x1: x coordinate of lower left corner
 * @y1: y coordinate of lower left corner
 * @x2: x coordinate of upper right corner
 * @y2: y coordinate of upper right corner
 *
 * A #pdf-to-htmlRectangle is used to describe
 * locations on a page and bounding boxes
 */
struct _pdf-to-htmlRectangle
{
  gdouble x1;
  gdouble y1;
  gdouble x2;
  gdouble y2;
};

GType             pdf-to-html_rectangle_get_type (void) G_GNUC_CONST;
pdf-to-htmlRectangle *pdf-to-html_rectangle_new      (void);
pdf-to-htmlRectangle *pdf-to-html_rectangle_copy     (pdf-to-htmlRectangle *rectangle);
void              pdf-to-html_rectangle_free     (pdf-to-htmlRectangle *rectangle);

/* A point on a page, with coordinates in PDF points. */
#define pdf-to-html_TYPE_POINT             (pdf-to-html_point_get_type ())
/**
 * pdf-to-htmlPoint:
 * @x: x coordinate
 * @y: y coordinate
 *
 * A #pdf-to-htmlPoint is used to describe a location point on a page
 */
struct _pdf-to-htmlPoint
{
  gdouble x;
  gdouble y;
};

GType             pdf-to-html_point_get_type (void) G_GNUC_CONST;
pdf-to-htmlPoint     *pdf-to-html_point_new      (void);
pdf-to-htmlPoint     *pdf-to-html_point_copy     (pdf-to-htmlPoint *point);
void              pdf-to-html_point_free     (pdf-to-htmlPoint *point);

/* pdf-to-htmlQuadrilateral */

/* A quadrilateral encompasses a word or group of contiguous words in the
 * text underlying the annotation. The coordinates for each quadrilateral are
 * given in the order x1 y1 x2 y2 x3 y3 x4 y4 specifying the quadrilateral’s four
 *  vertices in counterclockwise order */

#define pdf-to-html_TYPE_QUADRILATERAL             (pdf-to-html_quadrilateral_get_type ())
/**
 *  pdf-to-htmlQuadrilateral:
 *  @p1: a #pdf-to-htmlPoint with the first vertex coordinates
 *  @p2: a #pdf-to-htmlPoint with the second vertex coordinates
 *  @p3: a #pdf-to-htmlPoint with the third vertex coordinates
 *  @p4: a #pdf-to-htmlPoint with the fourth vertex coordinates
 *
 *  A #pdf-to-htmlQuadrilateral is used to describe rectangle-like polygon
 *  with arbitrary inclination on a page.
 *
 *  Since: 0.26
 **/
struct _pdf-to-htmlQuadrilateral
{
  pdf-to-htmlPoint p1;
  pdf-to-htmlPoint p2;
  pdf-to-htmlPoint p3;
  pdf-to-htmlPoint p4;
};

GType                 pdf-to-html_quadrilateral_get_type (void) G_GNUC_CONST;
pdf-to-htmlQuadrilateral *pdf-to-html_quadrilateral_new      (void);
pdf-to-htmlQuadrilateral *pdf-to-html_quadrilateral_copy     (pdf-to-htmlQuadrilateral *quad);
void                 pdf-to-html_quadrilateral_free     (pdf-to-htmlQuadrilateral *quad);

/* A color in RGB */
#define pdf-to-html_TYPE_COLOR                 (pdf-to-html_color_get_type ())

/**
 * pdf-to-htmlColor:
 * @red: the red componment of color
 * @green: the green component of color
 * @blue: the blue component of color
 *
 * A #pdf-to-htmlColor describes a RGB color. Color components
 * are values between 0 and 65535
 */
struct _pdf-to-htmlColor
{
  guint16 red;
  guint16 green;
  guint16 blue;
};

GType             pdf-to-html_color_get_type      (void) G_GNUC_CONST;
pdf-to-htmlColor     *pdf-to-html_color_new           (void);
pdf-to-htmlColor     *pdf-to-html_color_copy          (pdf-to-htmlColor *color);
void              pdf-to-html_color_free          (pdf-to-htmlColor *color);

/* Text attributes. */
#define pdf-to-html_TYPE_TEXT_ATTRIBUTES             (pdf-to-html_text_attributes_get_type ())
/**
 * pdf-to-htmlTextAttributes:
 * @font_name: font name
 * @font_size: font size
 * @is_underlined: if text is underlined
 * @color: a #pdf-to-htmlColor, the foreground color
 * @start_index: start position this text attributes apply
 * @end_index: end position this text text attributes apply
 *
 * A #pdf-to-htmlTextAttributes is used to describe text attributes of a range of text
 *
 * Since: 0.18
 */
struct _pdf-to-htmlTextAttributes
{
  gchar *font_name;
  gdouble font_size;
  gboolean is_underlined;
  pdf-to-htmlColor color;

  gint start_index;
  gint end_index;
};

GType                  pdf-to-html_text_attributes_get_type (void) G_GNUC_CONST;
pdf-to-htmlTextAttributes *pdf-to-html_text_attributes_new      (void);
pdf-to-htmlTextAttributes *pdf-to-html_text_attributes_copy     (pdf-to-htmlTextAttributes *text_attrs);
void                   pdf-to-html_text_attributes_free     (pdf-to-htmlTextAttributes *text_attrs);

/* Mapping between areas on the current page and pdf-to-htmlActions */
#define pdf-to-html_TYPE_LINK_MAPPING             (pdf-to-html_link_mapping_get_type ())

/**
 * pdf-to-htmlLinkMapping:
 * @area: a #pdf-to-htmlRectangle representing an area of the page
 * @action: a #pdf-to-htmlAction
 *
 * A #pdf-to-htmlLinkMapping structure represents the location
 * of @action on the page
 */
struct  _pdf-to-htmlLinkMapping
{
  pdf-to-htmlRectangle area;
  pdf-to-htmlAction *action;
};

GType               pdf-to-html_link_mapping_get_type (void) G_GNUC_CONST;
pdf-to-htmlLinkMapping *pdf-to-html_link_mapping_new      (void);
pdf-to-htmlLinkMapping *pdf-to-html_link_mapping_copy     (pdf-to-htmlLinkMapping *mapping);
void                pdf-to-html_link_mapping_free     (pdf-to-htmlLinkMapping *mapping);

/* Page Transition */
#define pdf-to-html_TYPE_PAGE_TRANSITION                (pdf-to-html_page_transition_get_type ())

/**
 * pdf-to-htmlPageTransition:
 * @type: the type of transtition
 * @alignment: the dimension in which the transition effect shall occur.
 * Only for #pdf-to-html_PAGE_TRANSITION_SPLIT and #pdf-to-html_PAGE_TRANSITION_BLINDS transition types
 * @direction: the direccion of motion for the transition effect.
 * Only for #pdf-to-html_PAGE_TRANSITION_SPLIT, #pdf-to-html_PAGE_TRANSITION_BOX and #pdf-to-html_PAGE_TRANSITION_FLY
 * transition types
 * @duration: the duration of the transition effect
 * @angle: the direction in which the specified transition effect shall moves,
 * expressed in degrees counterclockwise starting from a left-to-right direction.
 * Only for #pdf-to-html_PAGE_TRANSITION_WIPE, #pdf-to-html_PAGE_TRANSITION_GLITTER, #pdf-to-html_PAGE_TRANSITION_FLY,
 * #pdf-to-html_PAGE_TRANSITION_COVER, #pdf-to-html_PAGE_TRANSITION_UNCOVER and #pdf-to-html_PAGE_TRANSITION_PUSH
 * transition types
 * @scale: the starting or ending scale at which the changes shall be drawn.
 * Only for #pdf-to-html_PAGE_TRANSITION_FLY transition type
 * @rectangular: whether the area that will be flown is rectangular and opaque.
 * Only for #pdf-to-html_PAGE_TRANSITION_FLY transition type
 *
 * A #pdf-to-htmlPageTransition structures describes a visual transition
 * to use when moving between pages during a presentation
 */
struct _pdf-to-htmlPageTransition
{
  pdf-to-htmlPageTransitionType type;
  pdf-to-htmlPageTransitionAlignment alignment;
  pdf-to-htmlPageTransitionDirection direction;
  gint duration;
  gint angle;
  gdouble scale;
  gboolean rectangular;
  gdouble duration_real;
};

GType                  pdf-to-html_page_transition_get_type (void) G_GNUC_CONST;
pdf-to-htmlPageTransition *pdf-to-html_page_transition_new      (void);
pdf-to-htmlPageTransition *pdf-to-html_page_transition_copy     (pdf-to-htmlPageTransition *transition);
void                   pdf-to-html_page_transition_free     (pdf-to-htmlPageTransition *transition);

/* Mapping between areas on the current page and images */
#define pdf-to-html_TYPE_IMAGE_MAPPING             (pdf-to-html_image_mapping_get_type ())

/**
 * pdf-to-htmlImageMapping:
 * @area: a #pdf-to-htmlRectangle representing an area of the page
 * @image_id: an image identifier
 *
 * A #pdf-to-htmlImageMapping structure represents the location
 * of an image on the page
 */
struct  _pdf-to-htmlImageMapping
{
  pdf-to-htmlRectangle area;
  gint image_id;	
};

GType                  pdf-to-html_image_mapping_get_type (void) G_GNUC_CONST;
pdf-to-htmlImageMapping   *pdf-to-html_image_mapping_new      (void);
pdf-to-htmlImageMapping   *pdf-to-html_image_mapping_copy     (pdf-to-htmlImageMapping *mapping);
void                   pdf-to-html_image_mapping_free     (pdf-to-htmlImageMapping *mapping);

/* Mapping between areas on the current page and form fields */
#define pdf-to-html_TYPE_FORM_FIELD_MAPPING               (pdf-to-html_form_field_mapping_get_type ())

/**
 * pdf-to-htmlFormFieldMapping:
 * @area: a #pdf-to-htmlRectangle representing an area of the page
 * @field: a #pdf-to-htmlFormField
 *
 * A #pdf-to-htmlFormFieldMapping structure represents the location
 * of @field on the page
 */
struct  _pdf-to-htmlFormFieldMapping
{
  pdf-to-htmlRectangle area;
  pdf-to-htmlFormField *field;
};

GType                    pdf-to-html_form_field_mapping_get_type (void) G_GNUC_CONST;
pdf-to-htmlFormFieldMapping *pdf-to-html_form_field_mapping_new      (void);
pdf-to-htmlFormFieldMapping *pdf-to-html_form_field_mapping_copy     (pdf-to-htmlFormFieldMapping *mapping);
void                     pdf-to-html_form_field_mapping_free     (pdf-to-htmlFormFieldMapping *mapping);

/* Mapping between areas on the current page and annots */
#define pdf-to-html_TYPE_ANNOT_MAPPING                  (pdf-to-html_annot_mapping_get_type ())

/**
 * pdf-to-htmlAnnotMapping:
 * @area: a #pdf-to-htmlRectangle representing an area of the page
 * @annot: a #pdf-to-htmlAnnot
 *
 * A #pdf-to-htmlAnnotMapping structure represents the location
 * of @annot on the page
 */
struct _pdf-to-htmlAnnotMapping
{
  pdf-to-htmlRectangle area;
  pdf-to-htmlAnnot *annot;
};

GType                pdf-to-html_annot_mapping_get_type (void) G_GNUC_CONST;
pdf-to-htmlAnnotMapping *pdf-to-html_annot_mapping_new      (void);
pdf-to-htmlAnnotMapping *pdf-to-html_annot_mapping_copy     (pdf-to-htmlAnnotMapping *mapping);
void                 pdf-to-html_annot_mapping_free     (pdf-to-htmlAnnotMapping *mapping);

G_END_DECLS

#endif /* __pdf-to-html_PAGE_H__ */
