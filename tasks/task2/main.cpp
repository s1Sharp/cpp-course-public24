#include "matrix.h"

#include "iostream"

int main()
{
    Matrix m(5, 7);
    std::cout << m[4][6] << std::endl;
    return 0;
}
