/*
 * Copyright (C) 2009, Pino Toscano <pino@kde.org>
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

#ifndef pdf-to-html_VERSION_H
#define pdf-to-html_VERSION_H

#include "pdf-to-html-global.h"

#define pdf-to-html_VERSION "0.88.0"
#define pdf-to-html_VERSION_MAJOR 0
#define pdf-to-html_VERSION_MINOR 88
#define pdf-to-html_VERSION_MICRO 0

namespace pdf-to-html
{

pdf-to-html_CPP_EXPORT std::string version_string();
pdf-to-html_CPP_EXPORT unsigned int version_major();
pdf-to-html_CPP_EXPORT unsigned int version_minor();
pdf-to-html_CPP_EXPORT unsigned int version_micro();

}

#endif
