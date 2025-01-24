#include <algorithm>
#include <vector>
#include <cstdlib>

#include "utils.h"

void min_and_max_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::cout << "max: " << std::max(1, 2) << std::endl;
    std::cout << "min: " << std::min(1, 2) << std::endl;
    std::cout << "max: " << std::max({1, 2, 3, 4, 5}) << std::endl;
    std::cout << "min: " << std::min({1, 2, 3, 4, 5}) << std::endl;
}

void min_and_max_element_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> vec(10);
    std::generate(vec.begin(), vec.end(), [](){ return std::rand() % 100; });
    PRETTY_COUT(vec);
    auto it = std::max_element(vec.cbegin(), vec.cend());
    PRETTY_COUT(*it, it - vec.cbegin());
    it = std::min_element(vec.cbegin(), vec.cend());
    PRETTY_COUT(*it, it - vec.cbegin());
}

void minmax_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    auto pair1 = std::minmax(1, 2);
    PRETTY_COUT(pair1.first, pair1.second);
    auto pair2 = std::minmax({1, 2, 3, 4, 5});
    PRETTY_COUT(pair2.first, pair2.second);
}

void minmax_element_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> vec(10);
    std::generate(vec.begin(), vec.end(), [](){ return std::rand() % 100; });
    
    PRETTY_COUT(vec);
    auto pair = std::minmax_element(vec.begin(), vec.end());
    PRETTY_COUT(*pair.first, *pair.second);
}

int main() {

    min_and_max_demo();
    min_and_max_element_demo();
    minmax_demo();
    minmax_element_demo();

    return 0;
}