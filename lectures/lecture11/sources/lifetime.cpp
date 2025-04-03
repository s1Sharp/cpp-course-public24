#include <iostream>

int global_val = 0;

thread_local int thread_local_val;

int foo() {
    static int k = 0;
    return ++k;
}

int main() {
    int local_val = 42;

    std::cout << foo() << std::endl;

    auto heap_val = new int{10};
    
    // ...
    
    delete heap_val;

    return 0;
}