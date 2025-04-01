#include "bin_search.hpp"

#include "iostream"

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int testValues[] = {0, 5, 10, 15, 20};
    
    for (int value : testValues) {
        int* result = LowerBound(arr, arr + size, value);
        
        if (result != arr + size) {
            std::cout << "Первый элемент >= " << value << ": " << *result << '\n';
        } else {
            std::cout << "Элемента >= " << value << " не найдено\n";
        }
    }

    return 0;
}
