#include <iostream>
#include <cassert>
#include "matrix.h"

int main() {
    const size_t rows = 5;
    const size_t cols = 3;

    Matrix m(rows, cols);

    assert(m.rows() == 5);
    assert(m.cols() == 3);

    m[1][2] = 5; // строка 1, колонка 2
    double x = m[4][1];

    m *= 3; // умножение на число
    Matrix m2 = m * 3; // умножение на число

    Matrix m1(rows, cols);

    if (m1 == m) {
        std::cout << "Matrices are equal" << std::endl;
    }

    if (m1 != m) {
        std::cout << "Matrices are not equal" << std::endl;
    }

    return 0;
}
