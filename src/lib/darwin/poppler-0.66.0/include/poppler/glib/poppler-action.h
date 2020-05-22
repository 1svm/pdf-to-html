/* pdf-to-html-action.h: glib interface to pdf-to-html
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

#ifndef __pdf-to-html_ACTION_H__
#define __pdf-to-html_ACTION_H__

#include <glib-object.h>
#include "pdf-to-html.h"

G_BEGIN_DECLS

/**
 * pdf-to-htmlActionType:
 * @pdf-to-html_ACTION_UNKNOWN: unknown action
 * @pdf-to-html_ACTION_NONE: no action specified
 * @pdf-to-html_ACTION_GOTO_DEST: go to destination
 * @pdf-to-html_ACTION_GOTO_REMOTE: go to destination in another document
 * @pdf-to-html_ACTION_LAUNCH: launch app (or open document
 * @pdf-to-html_ACTION_URI: URI
 * @pdf-to-html_ACTION_NAMED: predefined action
 * @pdf-to-html_ACTION_MOVIE: play movies. Since 0.14
 * @pdf-to-html_ACTION_RENDITION: play multimedia content. Since 0.14
 * @pdf-to-html_ACTION_OCG_STATE: state of layer. Since 0.14
 * @pdf-to-html_ACTION_JAVASCRIPT: Javascript. Since 0.18
 *
 * Action types
 */
typedef enum
{
	pdf-to-html_ACTION_UNKNOWN,		/* unknown action */
	pdf-to-html_ACTION_NONE,            /* no action specified */
	pdf-to-html_ACTION_GOTO_DEST,	/* go to destination */
	pdf-to-html_ACTION_GOTO_REMOTE,	/* go to destination in new file */
	pdf-to-html_ACTION_LAUNCH,		/* launch app (or open document) */
	pdf-to-html_ACTION_URI,		/* URI */
	pdf-to-html_ACTION_NAMED,		/* named action*/
	pdf-to-html_ACTION_MOVIE,		/* movie action */
	pdf-to-html_ACTION_RENDITION,       /* rendition action */
	pdf-to-html_ACTION_OCG_STATE,       /* Set-OCG-State action */
	pdf-to-html_ACTION_JAVASCRIPT	/* Javascript action */
} pdf-to-htmlActionType;

/**
 * pdf-to-htmlDestType:
 * @pdf-to-html_DEST_UNKNOWN: unknown destination
 * @pdf-to-html_DEST_XYZ: go to page with coordinates (left, top)
 * positioned at the upper-left corner of the window and the contents of
 * the page magnified by the factor zoom
 * @pdf-to-html_DEST_FIT: go to page with its contents magnified just
 * enough to fit the entire page within the window both horizontally and
 * vertically
 * @pdf-to-html_DEST_FITH: go to page with the vertical coordinate top
 * positioned at the top edge of the window and the contents of the page
 * magnified just enough to fit the entire width of the page within the window
 * @pdf-to-html_DEST_FITV: go to page with the horizontal coordinate
 * left positioned at the left edge of the window and the contents of the
 * page magnified just enough to fit the entire height of the page within the window
 * @pdf-to-html_DEST_FITR: go to page with its contents magnified just
 * enough to fit the rectangle specified by the coordinates left, bottom,
 * right, and top entirely within the window both horizontally and vertically
 * @pdf-to-html_DEST_FITB: go to page with its contents magnified just enough to fit
 * its bounding box entirely within the window both horizontally and vertically
 * @pdf-to-html_DEST_FITBH: go to page with the vertical
 * coordinate top positioned at the top edge of the window and the
 * contents of the page magnified just enough to fit the entire width of its
 * bounding box within the window
 * @pdf-to-html_DEST_FITBV: go to page with the horizontal
 * coordinate left positioned at the left edge of the window and the
 * contents of the page magnified just enough to fit the entire height of its
 * bounding box within the window
 * @pdf-to-html_DEST_NAMED: got to page specified by a name. See pdf-to-html_document_find_dest()
 *
 * Destination types
 */
typedef enum
{
	pdf-to-html_DEST_UNKNOWN,
	pdf-to-html_DEST_XYZ,
	pdf-to-html_DEST_FIT,
	pdf-to-html_DEST_FITH,
	pdf-to-html_DEST_FITV,
	pdf-to-html_DEST_FITR,
	pdf-to-html_DEST_FITB,
	pdf-to-html_DEST_FITBH,
	pdf-to-html_DEST_FITBV,
	pdf-to-html_DEST_NAMED
} pdf-to-htmlDestType;

/**
 * pdf-to-htmlActionMovieOperation:
 * @pdf-to-html_ACTION_MOVIE_PLAY: play movie
 * @pdf-to-html_ACTION_MOVIE_PAUSE: pause playing movie
 * @pdf-to-html_ACTION_MOVIE_RESUME: resume paused movie
 * @pdf-to-html_ACTION_MOVIE_STOP: stop playing movie
 *
 * Movie operations
 *
 * Since: 0.14
 */
typedef enum
{
        pdf-to-html_ACTION_MOVIE_PLAY,
	pdf-to-html_ACTION_MOVIE_PAUSE,
	pdf-to-html_ACTION_MOVIE_RESUME,
	pdf-to-html_ACTION_MOVIE_STOP
} pdf-to-htmlActionMovieOperation;

/**
 * pdf-to-htmlActionLayerAction:
 * @pdf-to-html_ACTION_LAYER_ON: set layer visibility on
 * @pdf-to-html_ACTION_LAYER_OFF: set layer visibility off
 * @pdf-to-html_ACTION_LAYER_TOGGLE: reverse the layer visibility state
 *
 * Layer actions
 *
 * Since: 0.14
 */
typedef enum
{
	pdf-to-html_ACTION_LAYER_ON,
	pdf-to-html_ACTION_LAYER_OFF,
	pdf-to-html_ACTION_LAYER_TOGGLE
} pdf-to-htmlActionLayerAction;

/* Define the pdf-to-htmlAction types */
typedef struct _pdf-to-htmlActionAny        pdf-to-htmlActionAny;
typedef struct _pdf-to-htmlActionGotoDest   pdf-to-htmlActionGotoDest;
typedef struct _pdf-to-htmlActionGotoRemote pdf-to-htmlActionGotoRemote;
typedef struct _pdf-to-htmlActionLaunch     pdf-to-htmlActionLaunch;
typedef struct _pdf-to-htmlActionUri        pdf-to-htmlActionUri;
typedef struct _pdf-to-htmlActionNamed      pdf-to-htmlActionNamed;
typedef struct _pdf-to-htmlActionMovie      pdf-to-htmlActionMovie;
typedef struct _pdf-to-htmlActionRendition  pdf-to-htmlActionRendition;
typedef struct _pdf-to-htmlActionOCGState   pdf-to-htmlActionOCGState;
typedef struct _pdf-to-htmlActionJavascript pdf-to-htmlActionJavascript;

/**
 * pdf-to-htmlDest:
 * @type: type of destination
 * @page_num: page number
 * @left: left coordinate
 * @bottom: bottom coordinate
 * @right: right coordinate
 * @top: top coordinate
 * @zoom: scale factor
 * @named_dest: name of the destination (#pdf-to-html_DEST_NAMED only)
 * @change_left: whether left coordinate should be changed
 * @change_top: whether top coordinate should be changed
 * @change_zoom: whether scale factor should be changed
 *
 * Data structure for holding a destination
 */
struct _pdf-to-htmlDest
{
	pdf-to-htmlDestType type;

	int page_num;
	double left;
	double bottom;
	double right;
	double top;
	double zoom;
	gchar *named_dest;
	guint change_left : 1;
	guint change_top : 1;
	guint change_zoom : 1;
};

/**
 * pdf-to-htmlActionLayer:
 * @action: a #pdf-to-htmlActionLayerAction
 * @layers: list of #pdf-to-htmlLayer<!-- -->s
 *
 * Action to perform over a list of layers
 */
struct _pdf-to-htmlActionLayer
{
	pdf-to-htmlActionLayerAction action;
	GList *layers;
};

struct _pdf-to-htmlActionAny
{
	pdf-to-htmlActionType type;
	gchar *title;
};

struct _pdf-to-htmlActionGotoDest
{
	pdf-to-htmlActionType type;
	gchar *title;

	pdf-to-htmlDest *dest;
};

struct _pdf-to-htmlActionGotoRemote
{
	pdf-to-htmlActionType type;
	gchar *title;

	gchar *file_name;
	pdf-to-htmlDest *dest;
};

struct _pdf-to-htmlActionLaunch
{
	pdf-to-htmlActionType type;
	gchar *title;

	gchar *file_name;
	gchar *params;
};

struct _pdf-to-htmlActionUri
{
	pdf-to-htmlActionType type;
	gchar *title;

	char *uri;
};

struct _pdf-to-htmlActionNamed
{
	pdf-to-htmlActionType type;
	gchar *title;

	gchar *named_dest;
};

struct _pdf-to-htmlActionMovie
{
        pdf-to-htmlActionType           type;
        gchar                      *title;

        pdf-to-htmlActionMovieOperation operation;
	pdf-to-htmlMovie               *movie;
};

struct _pdf-to-htmlActionRendition
{
	pdf-to-htmlActionType type;
	gchar            *title;

	gint               op;
	pdf-to-htmlMedia      *media;
};

struct _pdf-to-htmlActionOCGState
{
	pdf-to-htmlActionType type;
	gchar            *title;

	GList            *state_list;
};

struct _pdf-to-htmlActionJavascript
{
	pdf-to-htmlActionType  type;
	gchar 		  *title;

	gchar		  *script;
};

/**
 * pdf-to-htmlAction:
 *
 * A data structure for holding actions
 */
union _pdf-to-htmlAction
{
	pdf-to-htmlActionType type;
	pdf-to-htmlActionAny any;
	pdf-to-htmlActionGotoDest goto_dest;
	pdf-to-htmlActionGotoRemote goto_remote;
	pdf-to-htmlActionLaunch launch;
	pdf-to-htmlActionUri uri;
	pdf-to-htmlActionNamed named;
	pdf-to-htmlActionMovie movie;
	pdf-to-htmlActionRendition rendition;
	pdf-to-htmlActionOCGState ocg_state;
	pdf-to-htmlActionJavascript javascript;
};

#define pdf-to-html_TYPE_ACTION             (pdf-to-html_action_get_type ())
#define pdf-to-html_ACTION(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), pdf-to-html_TYPE_ACTION, pdf-to-htmlAction))

GType          pdf-to-html_action_get_type (void) G_GNUC_CONST;

void           pdf-to-html_action_free     (pdf-to-htmlAction *action);
pdf-to-htmlAction *pdf-to-html_action_copy     (pdf-to-htmlAction *action);


#define pdf-to-html_TYPE_DEST              (pdf-to-html_dest_get_type ())
GType          pdf-to-html_dest_get_type   (void) G_GNUC_CONST;

void           pdf-to-html_dest_free       (pdf-to-htmlDest   *dest);
pdf-to-htmlDest   *pdf-to-html_dest_copy       (pdf-to-htmlDest   *dest);

G_END_DECLS

#endif /* __pdf-to-html_GLIB_H__ */
