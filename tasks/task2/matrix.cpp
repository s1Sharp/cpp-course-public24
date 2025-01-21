#include <stdexcept>
#include <iostream> 
#include "matrix.h"

using namespace std;
using RowMatrix = Matrix::RowMatrix;

RowMatrix::RowMatrix (double *array, size_t size) : _array(array), _size(size) {}

const double & RowMatrix::operator[] (size_t j) const {
    if (j >= _size) {
        throw out_of_range("Индекс столбца находится вне диапазона");
    }
    return _array[j];
}

double & RowMatrix::operator[] (size_t j) {
if (j >= _size) {
        throw out_of_range("Индекс столбца находится вне диапазона");
    }
    return _array[j];
}

RowMatrix::~RowMatrix(){}



Matrix::Matrix() : _rows(0), _cols(0), _array(nullptr){}

Matrix::Matrix(size_t r, size_t c) : _rows(r), _cols(c) {
    _array = new double[r * c];
    for(size_t i=0; i < r * c; ++i)
        _array[i] = 0.0;
}

Matrix::Matrix(const Matrix & copy_from) : _rows(copy_from._rows), _cols(copy_from._cols){
    _array = new double[copy_from._rows * copy_from._cols];
    for(size_t i = 0; i < _rows * _cols; ++i){
         _array[i] = copy_from._array[i];
    }
}

Matrix& Matrix::operator=(const Matrix & move_from) {
    if(this == &move_from) return *this;

     delete[] _array;
    _rows = move_from._rows;
    _cols = move_from._cols;
    _array = new double[_rows * _cols];
     for(size_t i=0; i < _rows * _cols; ++i)
        _array[i] = move_from._array[i];
    return *this;
}

const RowMatrix Matrix::operator[] (size_t row_num) const {
    if (row_num >= _rows) {
        throw out_of_range("Индекс строки находится вне диапазона");
    }
    return RowMatrix(_array + row_num * _cols, _cols);

}

RowMatrix Matrix::operator[] (size_t row_num) {
    if (row_num >= _rows) {
        throw out_of_range("Индекс строки находится вне диапазона");
    }
    return RowMatrix(_array + row_num * _cols, _cols);
}
//Изменение текущей матрицы
Matrix& Matrix::operator*= (double k) {
    for (size_t i = 0; i < _rows * _cols; ++i) {
        _array[i] *= k;
    }
    return *this;
}
//Возвращает новую матрицу
Matrix Matrix::operator* (double k) {
    Matrix result(*this);
    for (size_t i = 0; i < _rows * _cols; ++i) {
      result._array[i] *= k;
    }
    return result;
}

bool Matrix::operator== (Matrix & matrix) {
    if(_rows != matrix._rows || _cols != matrix._cols) return false;
    for(size_t i=0; i < _rows * _cols; ++i) {
        if(_array[i] != matrix._array[i]) return false;
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
    delete[] _array;
}
