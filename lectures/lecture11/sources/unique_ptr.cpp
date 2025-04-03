#include "pretty.h"
#include "utils.h"

#include <functional>
#include <memory>

template <typename T>
class unique_ptr {
    T *ptr;

  public:
    unique_ptr(T *ptr_) : ptr{ptr_} {}
    ~unique_ptr() { delete ptr; }

    unique_ptr(const unique_ptr<T> &) = delete;
    unique_ptr<T> &operator=(const unique_ptr<T> &) = delete;

    unique_ptr(unique_ptr<T> &&other) : ptr{other.ptr} { other.ptr = nullptr; }
    unique_ptr<T> &operator=(unique_ptr<T> &&other) {
        ptr       = other.ptr;
        other.ptr = nullptr;
        return *this;
    };

    T *get() { return ptr; }

    T *operator->() { return ptr; }
    T& operator*() { return *ptr; }
};

template <typename T>
unique_ptr<T> foo(unique_ptr<T> ptr) {
    ++(*ptr);
    return ptr;
}

void unique_ptr_example() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    unique_ptr<int> ptr1(new int{41});
    // unique_ptr<int> ptr2(ptr1);
    unique_ptr<int> ptr2(std::move(ptr1));
    // std::cout << *ptr1 << std::endl;
    std::cout << *ptr2 << std::endl;

    ptr2 = foo(std::move(ptr2));
    std::cout << *ptr2 << std::endl;
}

class A {
  public:
    A() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~A() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

struct deleter {
    void operator()(A *ptr) { delete ptr; }
};

void delete_A(A *ptr) { delete ptr; }

void size_of() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    A *row_ptr = nullptr;
    std::unique_ptr<A> ptr1(new A);
    std::unique_ptr<A, deleter> ptr2;
    std::unique_ptr<A, std::function<void(A *)>> ptr3(new A, delete_A);

    auto lam = [](A *ptr) { delete ptr; };
    std::unique_ptr<A, decltype(lam)> ptr4(new A, lam);

    int some_value = 42;
    auto lam2      = [&some_value](A *ptr) { delete ptr; };
    std::unique_ptr<A, decltype(lam2)> ptr5(new A, lam2);

    PRETTY_COUT(sizeof(row_ptr), sizeof(ptr1), sizeof(ptr2), sizeof(ptr3),
                sizeof(ptr4), sizeof(ptr5));
}

class B {};
class C {};

void foo(std::unique_ptr<B>, std::unique_ptr<C>) {}

void make_unique_example() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    auto ptr = std::make_unique<A>();
    foo(std::unique_ptr<B>(new B), std::unique_ptr<C>(new C));
    foo(std::make_unique<B>(), std::make_unique<C>());
}

int main(int argc, char *argv[]) {

    // unique_ptr_example();
    size_of();
    // make_unique_example();

    return 0;
}