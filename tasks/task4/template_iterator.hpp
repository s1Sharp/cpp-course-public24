#pragma once

#include <iterator>

/**
 * @brief
 * Класс итератора, представлен для возможности использовать в векторе
 * обаладает стандартными операциями с итераторами
 * @tparam T 
 */
template <class T>
class Iterator : public std::iterator<std::random_access_iterator_tag, T>
{
public:
    using value_type = T;
    using reference = T&;
    using pointer = T*;
    using iterator = Iterator<T>;

    Iterator(pointer ptr) noexcept
        : ptr_(ptr)
    {}

    reference operator * () const noexcept {
        return *ptr_;
    }

    bool operator == (const iterator & other) const noexcept {
        return ptr_ == other.ptr_;
    }

    bool operator != (const iterator & other) const noexcept {
        return ptr_ != other.ptr_;
    }

    bool operator < (const iterator & other) const noexcept {
        return ptr_ < other.ptr_;
    }

    bool operator > (const iterator & other) const noexcept {
        return ptr_ > other.ptr_;
    }

    bool operator <= (const iterator & other) const noexcept {
        return ptr_ <= other.ptr_;
    }

    bool operator >= (const iterator & other) const noexcept {
        return ptr_ >= other.ptr_;
    }

    iterator operator + (int n) const noexcept {
        throw std::runtime_error("not implemented");
    }

    iterator & operator += (int n) noexcept {
        throw std::runtime_error("not implemented");
    }

    iterator operator - (int n) const noexcept {
        throw std::runtime_error("not implemented");
    }

    iterator & operator -= (int n) noexcept {
        throw std::runtime_error("not implemented");
    }

    reference operator [] (int n) const noexcept {
        throw std::runtime_error("not implemented");
    }

    iterator & operator ++ () noexcept {
        throw std::runtime_error("not implemented");
    }

    iterator & operator -- () noexcept {
        throw std::runtime_error("not implemented");
    }

    iterator operator ++ (int) noexcept {
        throw std::runtime_error("not implemented");
    }

    iterator operator -- (int) noexcept {
        throw std::runtime_error("not implemented");
    }

    friend iterator& operator + (int n, const iterator & it) noexcept {
        throw std::runtime_error("not implemented");
    }

    friend iterator& operator - (int n, const iterator & it) noexcept {
        throw std::runtime_error("not implemented");
    }

    friend int operator - (const iterator & lhs, const iterator & rhs) noexcept {
        throw std::runtime_error("not implemented");
    }
private:
    pointer ptr_;
};
