#pragma once
#include "matrix_element.h"

#include <map>
#include <tuple>

using coordinate = std::tuple<size_t, size_t>;

template<typename T, T default_value>
class MatrixRow
{
public:
    MatrixRow(std::map<coordinate, T>& data, size_t row) :
        data(data), row(row) {};

    MatrixElement<T, default_value> operator[](size_t columnindex)
    {
        return MatrixElement<T, default_value>(data, row, columnindex);
    };

private:
    std::map<coordinate, T>& data;
    size_t row;
};