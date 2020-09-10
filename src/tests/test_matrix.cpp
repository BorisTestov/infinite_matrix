#include "test_matrix.h"

void TestMatrix::Test()
{
    InfiniteMatrix<int, -1> matrix;   // бесконечная матрица int заполнена значениями -1
    QCOMPARE((int) matrix.size(), 0); // все ячейки свободны
    [[maybe_unused]] int a = matrix[0][0];
    QCOMPARE(a, -1);
    QCOMPARE((int) matrix.size(), 0);
    matrix[100][100] = 314;
    QCOMPARE((int) matrix[100][100], 314);
    QCOMPARE((int) matrix.size(), 1);
}