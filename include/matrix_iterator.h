#pragma once

#include <map>
#include <tuple>

using coordinate = std::tuple<size_t, size_t>;

/**
 * @brief Итератор бесконечной матрицы
 * @tparam T Тип хранящихся данных
 * @tparam default_value значение по умолчанию
 */
template<typename T, T default_value>
class MatrixIterator
{
public:
    MatrixIterator(typename std::map<coordinate, T>::iterator iter) :
        iter(iter) {};

    bool operator==(MatrixIterator& rhs)
    {
        return iter == rhs.iter;
    }

    bool operator!=(MatrixIterator& rhs)
    {
        return iter != rhs.iter;
    }

    MatrixIterator& operator--()
    {
        --iter;
        return *this;
    }

    MatrixIterator& operator++()
    {
        ++iter;
        return *this;
    }

    std::tuple<size_t, size_t, T> operator*()
    {
        return { std::get<0>(iter->first), std::get<1>(iter->first), iter->second };
    }

protected:
    typename std::map<coordinate, T>::iterator iter;
};