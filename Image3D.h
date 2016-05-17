#pragma once
#include <vector>
#include "Iterator3D.h"
#include "Image3DIndexes.h"

class Image3D
{
public:

    using data_t = unsigned char;
    using container_t = std::vector<data_t>;
    using named_iterator = Image3DIndexes<Image3D>;
    using const_named_iterator = Image3DIndexes<const Image3D>;
    using iterator = typename container_t::iterator;
    using const_iterator = typename container_t::const_iterator;

    Image3D(int width, int height, int depth);

    data_t
    pixel_at(int x, int y, int z) const;

    data_t
    pixel_at(int index) const;

    int
    width() const;

    int
    height() const;

    int
    depth() const;

    iterator
    begin();

    iterator
    end();

    const_iterator
    cbegin() const;

    const_iterator
    cend() const;

    named_iterator
    indexes();

    const_named_iterator
    const_indexes() const;


private:
    int _width;
    int _height;
    int _depth;
    container_t _pixels;
};

