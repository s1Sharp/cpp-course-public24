#include <algorithm>
#include <vector>
#include <execution>

#include "utils.h"

void for_each_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    std::for_each(vec.cbegin(), vec.cend(), [](auto val){ std::cout << val << " "; });
    std::cout << std::endl;

    std::for_each_n(vec.cbegin(), 3, [](auto val){ std::cout << val << " "; });
    std::cout << std::endl;
}

void for_each_demo_cpp17() { //Since C++17
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    std::for_each(std::execution::seq, vec.cbegin(), vec.cend(), [](auto val){ std::cout << val << " "; }); 
    std::cout << std::endl;

    std::for_each(std::execution::par_unseq, vec.cbegin(), vec.cend(), [](auto val){ std::cout << val << " "; }); 
    std::cout << std::endl;
}


int main() {

    for_each_demo();    
    for_each_demo_cpp17();
    return 0;
}