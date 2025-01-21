#include <stdexcept>

#include "matrix.h"

using namespace std;
using RowMatrix = Matrix::RowMatrix;

RowMatrix::RowMatrix (double *array, size_t size): 
    _array(array),
    _size(size) {  
}

const double & RowMatrix::operator[] (size_t j) const {
    if (j >= _size) {
        throw std::out_of_range("");
    }
    return _array[j];
}

double & RowMatrix::operator[] (size_t j) {
    if (j >= _size) {
        throw std::out_of_range("");
    }
    return _array[j];
}

RowMatrix::~RowMatrix(){

}


Matrix::Matrix(): 
    _rows(0), 
    _cols(0), 
    _array(nullptr) {
}

Matrix::Matrix(size_t r, size_t c): 
    _rows(r), 
    _cols(c),
    _array(new double[r * c]()) {
}

Matrix::Matrix(const Matrix & copy_from): 
    _rows(copy_from._rows), 
    _cols(copy_from._cols), 
    _array(new double(copy_from._rows * copy_from._cols)){  
        std::copy(copy_from._array, copy_from._array + _rows * _cols, _array); 
}

Matrix& Matrix::operator=(const Matrix & move_from) {
    if (this != &move_from) {
        delete[] _array;
        _rows = move_from._rows;
        _cols = move_from._cols;
        _array = new double[_rows * _cols];
        std::copy(move_from._array, move_from._array + _rows * _cols, _array);
    }
    return *this;
}

const RowMatrix Matrix::operator[] (size_t row_num) const {
    if (row_num >= _rows) {
        throw std::out_of_range("");
    }
    return RowMatrix(_array + row_num * _cols, _cols);
}

RowMatrix Matrix::operator[] (size_t row_num) {
    if (row_num >= _rows) {
        throw std::out_of_range("");
    }
    return RowMatrix(_array + row_num * _cols, _cols);
}

Matrix& Matrix::operator*= (double k) {
    for (size_t i = 0; i < _rows * _cols; i++){
        _array[i] *= k;
    }
    return *this;   
}

Matrix Matrix::operator* (double k) {
    Matrix tmp = Matrix(*this);
    tmp *= k;
    return tmp;
}

bool Matrix::operator== (Matrix & matrix) {
    if (_cols != matrix._cols || _rows != matrix._rows) 
        return false;
    for (size_t i = 0; i < _rows * _cols; i++){
        if (_array[i] != matrix._array[i])
            return false;
    }
    return true;
}

bool Matrix::operator!= (Matrix & matrix) {
    return !(*this == matrix);
}

size_t Matrix::cols() const {
    return _cols;
}

size_t Matrix::rows() const {
    return _rows;
}

Matrix::~Matrix() {
    if (_array) {
        delete[] _array;
    }
}