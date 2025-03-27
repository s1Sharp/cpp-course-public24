#pragma once
#include "template_iterator.hpp"

template <class T>
class Vector
{
public: 
    static const size_t reserve_miltiply_ = 2;
    static const size_t empty_vector_size_ = 8;
public:
    using iterator = Iterator<T>;
    using value_type = /* ? */;
    using pointer = /* ? */;
    using reference = /* ? */;
    using size_type = /* ? */;

    Vector()
    {
        throw std::runtime_error("not implemented");
    }

    ~Vector()
    {
        throw std::runtime_error("not implemented");
    }

    reference operator[] (size_type n) {
        throw std::runtime_error("not implemented");
    }

    const reference operator[] (size_type n) const {
        throw std::runtime_error("not implemented");
    }

    void push_back(const T & value) {
        throw std::runtime_error("not implemented");
    }

    void push_back(T && value) {
        throw std::runtime_error("not implemented");
    }

    void pop_back() {
        throw std::runtime_error("not implemented");
    }

    void clear() {
        throw std::runtime_error("not implemented");
    }

    void reserve(size_type new_size) {
        throw std::runtime_error("not implemented");
    }

    void resize(size_type new_size) {
        throw std::runtime_error("not implemented");
    }

    iterator begin() const noexcept {
        throw std::runtime_error("not implemented");
    }

    iterator end() const noexcept {
        throw std::runtime_error("not implemented");
    }

    size_type size() const noexcept {
        throw std::runtime_error("not implemented");
    }

    size_type capacity() const noexcept {
        throw std::runtime_error("not implemented");
    }

    bool empty() const noexcept {
        throw std::runtime_error("not implemented");
    }

private:
    pointer data_;
    size_type size_;
    size_type capacity_;
};
