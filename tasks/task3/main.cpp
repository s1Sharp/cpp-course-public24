#include "bin_search.hpp"
#include <iostream>

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int* first = arr;
    int* last = arr + 5;

    
    int* result1 = LowerBound(first, last, 5);
    std::cout << "LowerBound(5): " << (result1 - first) << " (value: " << *result1 << ")\n";

    
    int* result2 = LowerBound(first, last, 4);
    std::cout << "LowerBound(4): " << (result2 - first) << " (value: " << *result2 << ")\n";

    
    int* result3 = LowerBound(first, last, 0);
    std::cout << "LowerBound(0): " << (result3 - first) << " (value: " << *result3 << ")\n";

    
    int* result4 = LowerBound(first, last, 10);
    if (result4 == last) {
        std::cout << "LowerBound(10): out of range (returned last)\n";
    }

    
    int* result5 = LowerBound(nullptr, nullptr, 10);
    if (result5 == nullptr) {
        std::cout << "LowerBound(nullptr): returned nullptr\n";
    }

    return 0;
}
