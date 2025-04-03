#include <iostream>
#include "bin_search.hpp"
int main() {

    int arr[] = {1, 3, 5, 7, 9, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    int value = 6;

    int* pos = LowerLimit(arr, arr + size, value);

    std::cout << "Позиция для вставки значения " << value << " : " << (pos - arr) << std::endl;
    if (pos != arr + size) {
        std::cout << "На этой позиции элемент: " << *pos << std::endl;
    } else {
        std::cout << "В массиве нет элементов, которые не менее " << value << std::endl;
    }

    return 0;
}