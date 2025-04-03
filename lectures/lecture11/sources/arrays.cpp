#include <iostream>
#include <memory>

class A {
  public:
    A() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~A() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

int main() {

    // undefined behavior
    //std::unique_ptr<A> wrong{ new A[10] };

    
    // Good. Possible since C++11
    std::unique_ptr<A[]> ok{ new A[10]};

    // operator[]
    A value = ok[5];

    // Compilation error - no operator* for such instance
    // *ok;

    // undefined behavior
    // std::shared_ptr<A> wrong2{ new A[10] };

    // Impossible in C++11/C++14, but possible in C++17
    std::shared_ptr<A[]> ok2{ new A[10] };

    // operator[]
    A value2 = ok2[5];

    // Compilation error - no operator* for such instance
    // *ok2;

    return 0;
}