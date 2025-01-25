#include "matrix.h"

#include "iostream"

int main()
{
    Matrix m(5, 7);
    m[4][6] = 3.14;
    std::cout << m[4][6] << std::endl;
    Matrix m2 = m * 2;
    std::cout << m2[4][6] << std::endl;
    if (m == m2) {
        std::cout << "Матрицы равны" << std::endl;
    } else {
        std::cout << "Матрицы не равны" << std::endl;
    }
    return 0;
}
