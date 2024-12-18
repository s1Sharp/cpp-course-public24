#pragma once
#include <cstdint>

using std::size_t;

// Основной класс матрицы
class Matrix{
public:
    // Прокси-класс для обращения к матрице по строкам
    class RowMatrix {
    public:
        RowMatrix (double*, size_t);

        // Вызов элемента по индексу
        const double & operator[] (size_t) const;
        double & operator[] (size_t);

        ~RowMatrix();
    private:
        size_t _size;
        double *_array;
    };

public:
    Matrix();

    Matrix(size_t, size_t);
    Matrix(const Matrix &);

    Matrix& operator=(const Matrix &);
    const RowMatrix operator[] (size_t) const;
    RowMatrix operator[] (size_t);

    // Умножение на число
    Matrix& operator*= (double);
    Matrix operator* (double);
    
    // Оператор сравнения
    bool operator== (Matrix &);
    bool operator!= (Matrix &);

    size_t cols() const;
    size_t rows() const;
    
    ~Matrix();

private:
    size_t _rows, _cols;
    double *_array;
};