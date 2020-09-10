#pragma once
#include "matrix_element.h"

#include <map>
#include <tuple>

using coordinate = std::tuple<size_t, size_t>;

/**
 * @brief Ряд бесконечной матрицы
 * @tparam T Тип хранящихся данных
 * @tparam default_value значение по умолчанию
 */
template<typename T, T default_value>
class MatrixRow
{
public:
    /**
     * @brief Ряд с элементами матрицы
     * @param data Данные
     * @param row Индекс строки
     */
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