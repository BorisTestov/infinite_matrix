#pragma once
#include "matrix_element.h"
#include "matrix_iterator.h"
#include "matrix_row.h"

#include <map>
#include <tuple>

using coordinate = std::tuple<size_t, size_t>;

/**
 * @brief Бесконечная матрица
 * @tparam T Тип хранящихся данных
 * @tparam default_value значение по умолчанию
 */
template<typename T, T default_value>
class InfiniteMatrix
{
public:
    typedef ::MatrixIterator<T, default_value> iterator;
    size_t size()
    {
        return data.size();
    };
    MatrixRow<T, default_value> operator[](size_t index)
    {
        return MatrixRow<T, default_value>(data, index);
    };
    InfiniteMatrix::iterator begin()
    {
        return data.begin();
    };
    InfiniteMatrix::iterator end()
    {
        return data.end();
    };

private:
    std::map<coordinate, T> data;
};