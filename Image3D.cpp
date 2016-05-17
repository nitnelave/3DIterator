#include "Image3D.h"
#include <cstdlib>
#include <time.h>




Image3D::Image3D(int width, int height, int depth) :
    _width(width),
    _height(height),
    _depth(depth),
    _pixels(height * width * depth)
{
    srand (time(NULL));
    for (auto& e : _pixels)
        e = rand();
}

Image3D::data_t Image3D::pixel_at(int x, int y, int z) const
{
    return _pixels[x + width() * (y + height() * z)];
}

Image3D::data_t Image3D::pixel_at(int index) const
{
    return _pixels[index];
}

int Image3D::height() const
{
    return _height;
}

int Image3D::width() const
{
    return _width;
}

int Image3D::depth() const
{
    return _depth;
}

Image3D::iterator Image3D::begin()
{
    return _pixels.begin();
}

Image3D::iterator Image3D::end()
{
    return _pixels.end();
}

Image3D::const_iterator Image3D::cbegin() const
{
    return _pixels.cbegin();
}

Image3D::const_iterator Image3D::cend() const
{
    return _pixels.cend();
}

Image3D::named_iterator Image3D::indexes()
{
    return named_iterator(*this);
}

Image3D::const_named_iterator Image3D::const_indexes() const
{
    return const_named_iterator(*this);
}


