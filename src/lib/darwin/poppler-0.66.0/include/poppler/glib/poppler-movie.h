/* pdf-to-html-movie.h: glib interface to Movie
 *
 * Copyright (C) 2010 Carlos Garcia Campos <carlosgc@gnome.org>
 * Copyright (C) 2008 Hugo Mercier <hmercier31[@]gmail.com>
 * Copyright (C) 2017 Francesco Poli <invernomuto@paranoici.org>
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

#ifndef __pdf-to-html_MOVIE_H__
#define __pdf-to-html_MOVIE_H__

#include <glib-object.h>
#include "pdf-to-html.h"

G_BEGIN_DECLS

#define pdf-to-html_TYPE_MOVIE                   (pdf-to-html_movie_get_type ())
#define pdf-to-html_MOVIE(obj)                   (G_TYPE_CHECK_INSTANCE_CAST ((obj), pdf-to-html_TYPE_MOVIE, pdf-to-htmlMovie))
#define pdf-to-html_IS_MOVIE(obj)                (G_TYPE_CHECK_INSTANCE_TYPE ((obj), pdf-to-html_TYPE_MOVIE))

/**
 * pdf-to-htmlMoviePlayMode:
 * @pdf-to-html_MOVIE_PLAY_MODE_ONCE: the movie should be played once and controls should be closed at the end.
 * @pdf-to-html_MOVIE_PLAY_MODE_OPEN: the movie should be played once, but controls should be left open.
 * @pdf-to-html_MOVIE_PLAY_MODE_REPEAT: the movie should be played in loop, until manually stopped.
 * @pdf-to-html_MOVIE_PLAY_MODE_PALINDROME: the movie should be played forward and backward, forward and backward,
 *   and so forth, until manually stopped.
 *
 * Play mode enum values.
 *
 * Since: 0.54
 */
typedef enum
{
  pdf-to-html_MOVIE_PLAY_MODE_ONCE,
  pdf-to-html_MOVIE_PLAY_MODE_OPEN,
  pdf-to-html_MOVIE_PLAY_MODE_REPEAT,
  pdf-to-html_MOVIE_PLAY_MODE_PALINDROME
} pdf-to-htmlMoviePlayMode;

GType                pdf-to-html_movie_get_type      (void) G_GNUC_CONST;
const gchar         *pdf-to-html_movie_get_filename  (pdf-to-htmlMovie *pdf-to-html_movie);
gboolean             pdf-to-html_movie_need_poster   (pdf-to-htmlMovie *pdf-to-html_movie);
gboolean             pdf-to-html_movie_show_controls (pdf-to-htmlMovie *pdf-to-html_movie);
pdf-to-htmlMoviePlayMode pdf-to-html_movie_get_play_mode (pdf-to-htmlMovie *pdf-to-html_movie);

G_END_DECLS

#endif /* __pdf-to-html_MOVIE_H__ */

