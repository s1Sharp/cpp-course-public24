#include <stdexcept>

#include "matrix.h"

using namespace std;
using RowMatrix = Matrix::RowMatrix;

RowMatrix::RowMatrix (double *array, size_t size) {

}

const double & RowMatrix::operator[] (size_t j) const {

}

double & RowMatrix::operator[] (size_t j) {

}

RowMatrix::~RowMatrix(){}



Matrix::Matrix() {

}

Matrix::Matrix(size_t r, size_t c): _rows(r), _cols(c) {

}

Matrix::Matrix(const Matrix & copy_from) {

}

Matrix& Matrix::operator=(const Matrix & move_from) {

}

const RowMatrix Matrix::operator[] (size_t row_num) const {

}

RowMatrix Matrix::operator[] (size_t row_num) {

}

Matrix& Matrix::operator*= (double k) {

}

Matrix Matrix::operator* (double k) {

}

bool Matrix::operator== (Matrix & matrix) {

}

bool Matrix::operator!= (Matrix & matrix) {

}

size_t Matrix::cols() const {

}

size_t Matrix::rows() const {

}

Matrix::~Matrix() {

}