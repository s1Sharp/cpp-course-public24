#include <stdexcept>
#include <cstring>

#include "matrix.h"

#include <gtest/gtest.h>


TEST(CustomMatrix, CheckEmptyMatrix) {
    Matrix m{};
    EXPECT_EQ(m.cols(), 0);
    EXPECT_EQ(m.rows(), 0);
}


TEST(CustomMatrix, CheckEmptyAssignment) {
    Matrix m{};
    EXPECT_EQ(m.cols(), 0);
    EXPECT_EQ(m.rows(), 0);

    Matrix p{};

    p = m;
    EXPECT_EQ(p.cols(), 0);
    EXPECT_EQ(p.rows(), 0);
}


TEST(CustomMatrixProxyClass, CheckEmptyMatrixProxy) {
    {
        Matrix m{};
        EXPECT_EQ(m.cols(), 0);
        EXPECT_EQ(m.rows(), 0);

        EXPECT_THROW(m[0], std::out_of_range);
    }
    {
        Matrix m(2, 2);
        EXPECT_EQ(m.cols(), 2);
        EXPECT_EQ(m.rows(), 2);

        Matrix::RowMatrix r = m[0];

        EXPECT_NO_THROW(r[0]);
        EXPECT_THROW(r[100], std::out_of_range);
    }
}


TEST(CustomMatrixProxyClass, CheckEmptyMatrixProxyConst) {
    {
        const Matrix m{};
        EXPECT_EQ(m.cols(), 0);
        EXPECT_EQ(m.rows(), 0);

        EXPECT_THROW(m[0], std::out_of_range);
    }
    {
        const Matrix m(2, 2);
        EXPECT_EQ(m.cols(), 2);
        EXPECT_EQ(m.rows(), 2);

        const Matrix::RowMatrix r = m[0];

        EXPECT_NO_THROW(r[0]);
        EXPECT_THROW(r[100], std::out_of_range);
    }
}


TEST(CustomMatrix, CheckOutOfRange) {
    Matrix m(5, 5);
    EXPECT_THROW(m[100][100], std::out_of_range);
}


TEST(CustomMatrix, CheckOutOfRangeConst) {
    const Matrix m(5, 5);
    EXPECT_THROW(m[100][100], std::out_of_range);
}


TEST(CustomMatrixProxyClass, CheckMultiplyByNumber) {
    {
        Matrix m(2, 2);
        m[0][0] = 1;
        m[0][1] = 2;
        m[1][0] = 3;
        m[1][1] = 4;

        EXPECT_EQ(m[0][0], 1);
        EXPECT_EQ(m[0][1], 2);
        EXPECT_EQ(m[1][0], 3);
        EXPECT_EQ(m[1][1], 4);

        m *= 5;

        EXPECT_EQ(m[0][0], 5);
        EXPECT_EQ(m[0][1], 10);
        EXPECT_EQ(m[1][0], 15);
        EXPECT_EQ(m[1][1], 20);
    }
    {
        Matrix m(2, 2);
        m[0][0] = 1;
        m[0][1] = 2;
        m[1][0] = 3;
        m[1][1] = 4;

        EXPECT_EQ(m[0][0], 1);
        EXPECT_EQ(m[0][1], 2);
        EXPECT_EQ(m[1][0], 3);
        EXPECT_EQ(m[1][1], 4);

        Matrix result = m * 5;

        // old matrix stay the same
        EXPECT_EQ(m[0][0], 1);
        EXPECT_EQ(m[0][1], 2);
        EXPECT_EQ(m[1][0], 3);
        EXPECT_EQ(m[1][1], 4);

        // only new matrix changed
        EXPECT_EQ(result[0][0], 5);
        EXPECT_EQ(result[0][1], 10);
        EXPECT_EQ(result[1][0], 15);
        EXPECT_EQ(result[1][1], 20);
    }
}


TEST(CustomMatrix, CheckAssignment) {
    {
        Matrix m(2, 2);
        m[0][0] = 1;
        m[0][1] = 2;
        m[1][0] = 3;
        m[1][1] = 4;

        EXPECT_EQ(m[0][0], 1);
        EXPECT_EQ(m[0][1], 2);
        EXPECT_EQ(m[1][0], 3);
        EXPECT_EQ(m[1][1], 4);

        Matrix p{};

        p = m;
        EXPECT_EQ(p.cols(), 2);
        EXPECT_EQ(p.rows(), 2);
        EXPECT_EQ(p[0][0], 1);
        EXPECT_EQ(p[0][1], 2);
        EXPECT_EQ(p[1][0], 3);
        EXPECT_EQ(p[1][1], 4);
    }
    // check old matrix non null after assigment
    {
        Matrix m(2, 2);
        m[0][0] = 1;
        m[0][1] = 2;
        m[1][0] = 3;
        m[1][1] = 4;
        Matrix p{};

        p = m;
        EXPECT_EQ(m[0][0], 1);
        EXPECT_EQ(m[0][1], 2);
        EXPECT_EQ(m[1][0], 3);
        EXPECT_EQ(m[1][1], 4);
    }
}


TEST(CustomMatrix, CheckCopyConstructor) {
    {
        Matrix m(2, 2);
        m[0][0] = 1;
        m[0][1] = 2;
        m[1][0] = 3;
        m[1][1] = 4;

        EXPECT_EQ(m[0][0], 1);
        EXPECT_EQ(m[0][1], 2);
        EXPECT_EQ(m[1][0], 3);
        EXPECT_EQ(m[1][1], 4);

        Matrix p{m};

        p = m;
        EXPECT_EQ(p.cols(), 2);
        EXPECT_EQ(p.rows(), 2);
        EXPECT_EQ(p[0][0], 1);
        EXPECT_EQ(p[0][1], 2);
        EXPECT_EQ(p[1][0], 3);
        EXPECT_EQ(p[1][1], 4);
    }
    // check old matrix non null after assigment
    {
        Matrix m(2, 2);
        m[0][0] = 1;
        m[0][1] = 2;
        m[1][0] = 3;
        m[1][1] = 4;
        Matrix p{m};

        p = m;
        EXPECT_EQ(m[0][0], 1);
        EXPECT_EQ(m[0][1], 2);
        EXPECT_EQ(m[1][0], 3);
        EXPECT_EQ(m[1][1], 4);
    }
    {
        Matrix m(2, 2);
        m[0][0] = 1;
        m[0][1] = 2;
        m[1][0] = 3;
        m[1][1] = 4;

        Matrix p{m};

        p = m;
        p *= 5;

        EXPECT_EQ(m[0][0], 1);
        EXPECT_EQ(m[0][1], 2);
        EXPECT_EQ(m[1][0], 3);
        EXPECT_EQ(m[1][1], 4);
    }
}


TEST(CustomMatrix, CheckDefaultMatrix) {
    Matrix m(5, 7);

    m[2][3] = 123;
    EXPECT_EQ(m[2][3], 123);
    EXPECT_NE(m[3][2], 123);

    double x = m[2][3];
    EXPECT_EQ(x, 123.0);
    x = m[3][2];
    EXPECT_NE(x, 123.0);
}


TEST(CustomMatrix, CheckCompareMatrix) {
    Matrix p(2, 2);
    p[0][0] = 1;
    p[0][1] = 2;
    p[1][0] = 3;
    p[1][1] = 4;

    Matrix p_copy(2, 2);
    p_copy[0][0] = 1;
    p_copy[0][1] = 2;
    p_copy[1][0] = 3;
    p_copy[1][1] = 4;

    Matrix m(5, 7);

    EXPECT_TRUE(p == p_copy);
    EXPECT_TRUE(p != m);

    EXPECT_TRUE(p_copy == p);
    EXPECT_TRUE(m != p);
}
