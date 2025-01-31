#include "bin_search.hpp"
#include <iostream>
#include <array>

int main()
{
    std::array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int value = 5;
    
    int* result = LowerBound(arr.data(), arr.data() + arr.size(), value);

    std::ptrdiff_t index = std::distance(arr.data(), result);

    if (result != arr.data() + arr.size()) {
        std::cout << "i found ! index : " << index << std::endl;
    } else {
        std::cout << "error : not found ." << std::endl;
    }

    return 0;
}

