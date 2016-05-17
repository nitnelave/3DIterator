#pragma once
#include "Iterator3D.h"

template <typename Image>
class Image3DIndexes
{
public:
    using iterator = Iterator3D<Image>;
    Image3DIndexes(Image& im);

    iterator
    begin();

    iterator
    end();
private:
    Image& _im;
};

#include "Image3DIndexes.hxx"