//========================================================================
//
// pdf-to-htmlCache.h
//
// This file is licensed under the GPLv2 or later
//
// Copyright (C) 2009 Koji Otani <sho@bbr.jp>
// Copyright (C) 2009, 2010, 2017, 2018 Albert Astals Cid <aacid@kde.org>
// Copyright (C) 2010 Carlos Garcia Campos <carlosgc@gnome.org>
//
//========================================================================

#ifndef pdf-to-html_CACHE_H
#define pdf-to-html_CACHE_H

#include "Object.h"

class pdf-to-htmlCacheItem
{
  public:
   pdf-to-htmlCacheItem() = default;
   virtual ~pdf-to-htmlCacheItem();

   pdf-to-htmlCacheItem(const pdf-to-htmlCacheItem &) = delete;
   pdf-to-htmlCacheItem& operator=(const pdf-to-htmlCacheItem &other) = delete;
};

class pdf-to-htmlCacheKey
{
  public:
    pdf-to-htmlCacheKey() = default;
    virtual ~pdf-to-htmlCacheKey();
    virtual bool operator==(const pdf-to-htmlCacheKey &key) const = 0;

    pdf-to-htmlCacheKey(const pdf-to-htmlCacheKey &) = delete;
    pdf-to-htmlCacheKey& operator=(const pdf-to-htmlCacheKey &other) = delete;
};

class pdf-to-htmlCache
{
  public:
    pdf-to-htmlCache(int cacheSizeA);
    ~pdf-to-htmlCache();

    pdf-to-htmlCache(const pdf-to-htmlCache &) = delete;
    pdf-to-htmlCache& operator=(const pdf-to-htmlCache &other) = delete;

    /* The item returned is owned by the cache */
    pdf-to-htmlCacheItem *lookup(const pdf-to-htmlCacheKey &key);

    /* The key and item pointers ownership is taken by the cache */
    void put(pdf-to-htmlCacheKey *key, pdf-to-htmlCacheItem *item);

    /* The max size of the cache */
    int size();

    /* The number of items in the cache */
    int numberOfItems();

    /* The n-th item in the cache */
    pdf-to-htmlCacheItem *item(int index);

    /* The n-th key in the cache */
    pdf-to-htmlCacheKey *key(int index);

  private:
    pdf-to-htmlCacheKey **keys;
    pdf-to-htmlCacheItem **items;
    int lastValidCacheIndex;
    int cacheSize;
};

class pdf-to-htmlObjectCache
{
  public:
    pdf-to-htmlObjectCache (int cacheSizeA, XRef *xrefA);
    ~pdf-to-htmlObjectCache();

    pdf-to-htmlObjectCache(const pdf-to-htmlObjectCache &) = delete;
    pdf-to-htmlObjectCache& operator=(const pdf-to-htmlObjectCache &other) = delete;

    Object *put(const Ref &ref);
    Object lookup(const Ref &ref);

  private:
    XRef *xref;
    pdf-to-htmlCache *cache;
};

#endif
