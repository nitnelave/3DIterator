

template <typename Image>
Image3DIndexes<Image>::Image3DIndexes(Image& im) :
    _im(im)
{}

template <typename Image>
typename Image3DIndexes<Image>::iterator
Image3DIndexes<Image>::begin()
{
    return iterator(_im);
}

template <typename Image>
typename Image3DIndexes<Image>::iterator
Image3DIndexes<Image>::end()
{
    return iterator(_im, 0, 0, _im.depth());
}
