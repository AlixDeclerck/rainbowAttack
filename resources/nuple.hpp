#ifndef NUPLE_HPP
#define NUPLE_HPP

#include <array>
#include <cstddef>
#include <iostream>

namespace rainbow {

template<std::size_t N, class T>
using Nuple = std::array<T,N>;

template<std::size_t N, class T>
std::ostream& operator<<(std::ostream& out, const Nuple<N,T>& n)
{
    out << "( ";
    for(unsigned i = 0; i < N - 1; i++)
        out << n[i] << " , ";
    out << n[N - 1] << " )";

    return out;
}

}
#endif // NUPLE_HPP
