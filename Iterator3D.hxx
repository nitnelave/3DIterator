#include <tuple>



template <typename Image>
Iterator3D<Image>::Iterator3D(Image& im) :
    _im(im)
{}

template <typename Image>
Iterator3D<Image>::Iterator3D(Image& im, int x, int y, int z) :
    _im(im),
    _ind(x + im.width() * (y + im.height() * z)),
    _x(x),
    _y(y),
    _z(z)
{}

template <typename Image>
bool
operator==(const Iterator3D<Image>& a, const Iterator3D<Image>& b)
{
    return std::make_tuple(a.z(), a.y(), a.x()) == std::make_tuple(b.z(), b.y(), b.x());
}

template <typename Image>
bool
operator!=(const Iterator3D<Image>& a, const Iterator3D<Image>& b)
{
    return !(a == b);
}

template <typename Image>
bool
operator<(const Iterator3D<Image>& a, const Iterator3D<Image>& b)
{
    return std::make_tuple(a.z(), a.y(), a.x()) < std::make_tuple(b.z(), b.y(), b.x());
}

template <typename Image>
bool
operator>(const Iterator3D<Image>& a, const Iterator3D<Image>& b)
{
    return b < a;
}

template <typename Image>
bool
operator<=(const Iterator3D<Image>& a, const Iterator3D<Image>& b)
{
    return !(b < a);
}


template <typename Image>
bool
operator>=(const Iterator3D<Image>& a, const Iterator3D<Image>& b)
{
    return !(a < b);
}

template <typename Image>
Iterator3D<Image>&
Iterator3D<Image>::operator++()
{
    _increment();
    return *this;
}

template <typename Image>
Iterator3D<Image>
Iterator3D<Image>::operator++(int)
{
    Iterator3D ret = *this;
    operator++();
    return ret;
}

template <typename Image>
Iterator3D<Image>&
Iterator3D<Image>::operator+=(int n)
{
    _increment(n);
    return *this;
}

template <typename Image>
Iterator3D<Image>&
Iterator3D<Image>::operator-=(int n)
{
    return operator+=(-n);
}

template <typename Image>
typename Iterator3D<Image>::data_t
Iterator3D<Image>::operator*() const
{
    //return std::make_tuple(_x, _y, _z, _im.pixel_at(_x, _y, _z));
    return  _im.pixel_at(_ind);
}

template <typename Image>
int
Iterator3D<Image>::x() const
{
    return _x;
}

template <typename Image>
int
Iterator3D<Image>::y() const
{
    return _y;
}

template <typename Image>
int
Iterator3D<Image>::z() const
{
    return _z;
}

template <typename Image>
void Iterator3D<Image>::_increment()
{
    _ind++;
    _x++;
    if (_x == _im.width())
    {
        _x = 0;
        _y++;
        if (_y == _im.height())
        {
            _y = 0;
            _z++;
        }
    }
}

template <typename Image>
void Iterator3D<Image>::_decrement()
{
    _x--;
    if (_x < 0)
    {
        _x = _im.width() - 1;
        _y--;
        if (_y < 0)
        {
            _y = _im.height() - 1;
            _z--;
        }
    }
}

namespace {
    int pos_mod(int i, int n)
    {
        return (i % n + n) % n;
    }
    int pos_div(int i, int n)
    {
        return (i - pos_mod(i, n)) / n;
    }
}

template <typename Image>
void Iterator3D<Image>::_increment(int n)
{
    _x += n;
    if (_x < 0 ||_x >= _im.width())
    {
        int ny = pos_div(_x, _im.width());
        _x = pos_mod(_x, _im.width());
        _y += ny;
        if (_y < 0 || _y >= _im.height())
        {
            int nz = pos_div(_y, _im.height());
            _y = pos_mod(_y, _im.height());
            _z += nz;
        }
    }
}

