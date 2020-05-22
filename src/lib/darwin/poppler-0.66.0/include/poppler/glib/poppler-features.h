/* pdf-to-html-features.h: glib interface to pdf-to-html
 * Copyright (C) 2006, Red Hat, Inc.
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

#ifndef __pdf-to-html_FEATURES_H__
#define __pdf-to-html_FEATURES_H__

/**
 * SECTION:pdf-to-html-features
 * @short_description: Variables and functions to check the pdf-to-html version and features
 * @Title: Version and Features Information
 *
 * pdf-to-html provides version information, and information about features
 * enabled at compile time. This is primarily useful in configure checks
 * for builds that have a configure script, or for allowing code to optionally
 * depend but not require a specific pdf-to-html version.
 */

/**
 * pdf-to-html_HAS_CAIRO:
 *
 * Defined if pdf-to-html was compiled with cairo support.
 */
#define pdf-to-html_HAS_CAIRO 1

/**
 * pdf-to-html_MAJOR_VERSION:
 *
 * The major version number of the pdf-to-html header files (e.g. in pdf-to-html version
 * 0.1.2 this is 0.)
 *
 * Since: 0.12
 */
#define pdf-to-html_MAJOR_VERSION (0)

/**
 * pdf-to-html_MINOR_VERSION:
 *
 * The major version number of the pdf-to-html header files (e.g. in pdf-to-html version
 * 0.1.2 this is 1.)
 *
 * Since: 0.12
 */
#define pdf-to-html_MINOR_VERSION (66)

/**
 * pdf-to-html_MICRO_VERSION:
 *
 * The micro version number of the pdf-to-html header files (e.g. in pdf-to-html version
 * 0.1.2 this is 2.)
 *
 * Since: 0.12
 */
#define pdf-to-html_MICRO_VERSION (0)

/**
 * pdf-to-html_CHECK_VERSION:
 * @major: major version (e.g. 0 for version 0.1.2)
 * @minor: minor version (e.g. 1 for version 0.1.2)
 * @micro: micro version (e.g. 2 for version 0.1.2)
 *
 * Checks the version fo the pdf-to-html library
 *
 * Returns: %TRUE if the version of the pdf-to-html header files is the same
 * as or newer than the passed-in version
 *
 * Since: 0.12
 */
#define pdf-to-html_CHECK_VERSION(major,minor,micro) \
  (pdf-to-html_MAJOR_VERSION > (major) || \
   (pdf-to-html_MAJOR_VERSION == (major) && pdf-to-html_MINOR_VERSION > (minor)) || \
   (pdf-to-html_MAJOR_VERSION == (major) && pdf-to-html_MINOR_VERSION == (minor) && pdf-to-html_MICRO_VERSION >= (micro)))

#endif /* __pdf-to-html_FEATURES_H__ */
