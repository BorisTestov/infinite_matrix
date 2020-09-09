#pragma once
#include <map>
#include <tuple>

using coordinate = std::tuple<size_t, size_t>;

template<typename T, T default_value>
class MatrixElement
{
public:
    MatrixElement(std::map<coordinate, T>& data, size_t row, size_t col) :
        data(data), row(row), col(col) {};

    operator T()
    {
        if (data.count({ row, col }) > 0)
        {
            return data[{ row, col }];
        }
        else
        {
            return default_value;
        }
    };

    MatrixElement& operator=(T element)
    {
        if (element != default_value)
        {
            data[{ row, col }] = element;
        }
        else
        {
            data.erase({ row, col });
        }
        return *this;
    };

private:
    std::map<coordinate, T>& data;
    size_t row, col;
};