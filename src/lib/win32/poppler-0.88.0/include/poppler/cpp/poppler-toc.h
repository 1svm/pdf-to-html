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

#ifndef pdf-to-html_TOC_H
#define pdf-to-html_TOC_H

#include "pdf-to-html-global.h"

#include <vector>

namespace pdf-to-html
{

class toc_private;
class toc_item;
class toc_item_private;

class pdf-to-html_CPP_EXPORT toc : public pdf-to-html::noncopyable
{
public:
    ~toc();

    toc_item* root() const;

private:
    toc();

    toc_private *d;

    friend class toc_private;
};


class pdf-to-html_CPP_EXPORT toc_item : public pdf-to-html::noncopyable
{
public:
    typedef std::vector<toc_item *>::const_iterator iterator;

    ~toc_item();

    ustring title() const;
    bool is_open() const;

    std::vector<toc_item *> children() const;
    iterator children_begin() const;
    iterator children_end() const;

private:
    toc_item();

    toc_item_private *d;
    friend class toc;
    friend class toc_private;
    friend class toc_item_private;
};

}

#endif
