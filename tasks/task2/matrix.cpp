#include <stdexcept>
#include <cstring> // Для std::memcpy
#include "matrix.h"

// Реализация RowMatrix

Matrix::RowMatrix::RowMatrix(double *array, size_t size)
    : _array(array), _size(size) {}

const double &Matrix::RowMatrix::operator[](size_t j) const {
    if (j >= _size) {
        throw std::out_of_range("Column index out of range");
    }
    return _array[j];
}

double &Matrix::RowMatrix::operator[](size_t j) {
    if (j >= _size) {
        throw std::out_of_range("Column index out of range");
    }
    return _array[j];
}

Matrix::RowMatrix::~RowMatrix() {}

// Реализация Matrix

Matrix::Matrix() : _rows(0), _cols(0), _array(nullptr) {}

Matrix::Matrix(size_t r, size_t c) : _rows(r), _cols(c) {
    _array = new double[_rows * _cols]();
}

Matrix::Matrix(const Matrix &copy_from)
    : _rows(copy_from._rows), _cols(copy_from._cols) {
    _array = new double[_rows * _cols];
    std::memcpy(_array, copy_from._array, _rows * _cols * sizeof(double));
}

Matrix &Matrix::operator=(const Matrix &copy_from) {
    if (this == &copy_from) {
        return *this;
    }
    delete[] _array;
    _rows = copy_from._rows;
    _cols = copy_from._cols;
    _array = new double[_rows * _cols];
    std::memcpy(_array, copy_from._array, _rows * _cols * sizeof(double));
    return *this;
}

const Matrix::RowMatrix Matrix::operator[](size_t row_num) const {
    if (row_num >= _rows) {
        throw std::out_of_range("Row index out of range");
    }
    return RowMatrix(_array + row_num * _cols, _cols);
}

Matrix::RowMatrix Matrix::operator[](size_t row_num) {
    if (row_num >= _rows) {
        throw std::out_of_range("Row index out of range");
    }
    return RowMatrix(_array + row_num * _cols, _cols);
}

Matrix &Matrix::operator*=(double k) {
    for (size_t i = 0; i < _rows * _cols; ++i) {
        _array[i] *= k;
    }
    return *this;
}

Matrix Matrix::operator*(double k) {
    Matrix result(*this);
    result *= k;
    return result;
}

bool Matrix::operator==(Matrix &matrix) {
    if (_rows != matrix._rows || _cols != matrix._cols) {
        return false;
    }
    for (size_t i = 0; i < _rows * _cols; ++i) {
        if (_array[i] != matrix._array[i]) {
            return false;
        }
    }
    return true;
}

bool Matrix::operator!=(Matrix &matrix) {
    return !(*this == matrix);
}

size_t Matrix::cols() const {
    return _cols;
}

size_t Matrix::rows() const {
    return _rows;
}

Matrix::~Matrix() {
    delete[] _array;
}
