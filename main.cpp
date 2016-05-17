#include <iostream>
#include "Image3D.h"
#include "ScopedTimer.h"

int main()
{
    Image3D im(200, 300, 200);

    int sum = 0;
    double time;

    {
        ScopedTimer t(time);
        for (int z = 0; z < 100; ++z)
            for (int k = 0; k < im.depth(); ++k)
                for (int j = 0; j < im.height(); ++j)
                    for (int i = 0; i < im.width(); ++i)
                        sum += im.pixel_at(i, j, k);
    }
    std::cout << "Computed " << sum << " in " << time / 1e9 << " s\n";
    sum = 0;
    {
        ScopedTimer t(time);
        for (int z = 0; z < 100; ++z)
            for (unsigned char c : im)
                sum += c;
    }
    std::cout << "Computed " << sum << " in " << time / 1e9 << " s\n";
    sum = 0;
    {
        ScopedTimer t(time);
        for (int i = 0; i < 100; ++i)
            for (const auto& c : im.indexes())
                sum += c;
    }
    std::cout << "Computed " << sum << " in " << time / 1e9 << " s\n";
    system("pause");
}