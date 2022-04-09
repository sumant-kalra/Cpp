#ifndef TEMPLATES_H
#define TEMPLATES_H

#include <stdexcept>

namespace templates
{
    // Problem2:
    // Implement std::array class on your own; getSize(); at(); overload[]; template specialization for size 0

    template <typename T, int N>
    class Array
    {
    private:
        T m_array[N];

    public:
        Array() = default;
        ~Array() = default;

        int getSize();
        T &at(int pos);
        T &operator[](int pos);
    };

    template <typename T, int N>
    int Array<T, N>::getSize()
    {
        return N;
    }

    template <typename T, int N>
    T &Array<T, N>::at(int pos)
    {
        if (pos >= N)
            throw std::out_of_range("Invalid Index");
        return m_array[pos];
    }

    template <typename T, int N>
    T &Array<T, N>::operator[](int pos)
    {
        return m_array[pos];
    }

    // Implement template specialization for size 0, print a warning message about dereferencing when an object is created
    template <typename T>
    class Array<T, 0>
    {
    private:
        T m_array[0];

    public:
        Array();
        ~Array() = default;
    };

    template <typename T>
    Array<T, 0>::Array()
    {
        std::cout << "An array object with size = 0 is created.\nThis object can not be dereferenced\n";
    }

}

#endif