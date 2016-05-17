#pragma once
#include <iterator>

template <typename Image>
class Iterator3D : public std::random_access_iterator_tag
{
public:
    //using data_t = std::tuple<int, int, int, typename Image::data_t>;
    using data_t =  typename Image::data_t;
    Iterator3D(Image& im);

    Iterator3D(Image& im, int x, int y, int z);

    Iterator3D&
    operator++();

    Iterator3D
    operator++(int);

    Iterator3D&
    operator+=(int n);

    Iterator3D&
    operator-=(int n);

    data_t
    operator*() const;

    int
    x() const;

    int
    y() const;

    int
    z() const;

private:
    void
    _increment();

    void
    _decrement();

    void
    _increment(int n);

    Image& _im;
    int _ind = 0;
    int _x = 0;
    int _y = 0;
    int _z = 0;
};

template <typename Image>
bool
operator==(const Iterator3D<Image>&, const Iterator3D<Image>&);

template <typename Image>
bool
operator!=(const Iterator3D<Image>&, const Iterator3D<Image>&);

template <typename Image>
bool
operator<(const Iterator3D<Image>&, const Iterator3D<Image>&);

template <typename Image>
bool
operator>(const Iterator3D<Image>&, const Iterator3D<Image>&);

template <typename Image>
bool
operator<=(const Iterator3D<Image>&, const Iterator3D<Image>&);

template <typename Image>
bool
operator>=(const Iterator3D<Image>&, const Iterator3D<Image>&);

#include "Iterator3D.hxx"
