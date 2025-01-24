#include <cstdlib>
#include <algorithm>
#include <vector>

#include "utils.h"

int int_comp(const void* lhs, const void* rhs) {
    int a = *static_cast<const int*>(lhs);
    int b = *static_cast<const int*>(rhs);
    if (a < b)
        return -1;
    else if (a == b)
        return 0;
    else // a > b
        return 1; // <=> <, <=, == , >, >=
}

void find_demo(){
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> vec{0, 5, 2, 22, 5, 8, 22, 4, 79, 2, 65, 17, 23, 91 };

    auto it = std::find(vec.begin(), vec.end(), 22); //O(n) [begin; end)
    std::cout << *it << " - " << std::distance(vec.begin(), it) << std::endl; 

    it = std::find(vec.begin(), vec.end(), 131);
    std::cout << (it == vec.end()) << std::endl;

    it = std::find_if(vec.begin(), vec.end(), [](auto p){ return p > 30;});
    std::cout << *it << " - " << std::distance(vec.begin(), it) << std::endl; 

    it = std::find_if_not(vec.begin(), vec.end(), [](auto p){ return p > 30;});
    std::cout << *it << " - " << std::distance(vec.begin(), it) << std::endl;
}

void search_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> seq{3, 4, 5};

    auto it = std::search(vec.begin(), vec.end(), seq.begin(), seq.end());
    std::cout << *it << " - " << std::distance(vec.begin(), it) << std::endl;
}

void bsearch_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> vec{0, 1, 2, 3, 3, 3, 3, 3, 4, 5, 6, 7, 8, 9};

    int target = 3;
    // void* std::bsearch(const void*, const void*, size_t, size_t, int(cont void*))
    void* ptr = std::bsearch(&target, vec.data(), vec.size(), sizeof(int), int_comp);
    PRETTY_COUT(*static_cast<int*>(ptr));

    target = 42;
    ptr = std::bsearch(&target, vec.data(), vec.size(), sizeof(int), int_comp);
    PRETTY_COUT(ptr == nullptr);
}

void binary_search_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << std::binary_search(vec.begin(), vec.end(), 5)  << std::endl;
    std::cout << std::binary_search(vec.begin(), vec.end(), 42) << std::endl; // O(log(N))
}

void lower_upper_bound_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> vec{0, 1, 2, 3, 3, 3, 3, 3, 3, 4, 5, 6, 7, 8, 9};

    auto lo = std::lower_bound(vec.cbegin(), vec.cend(), 3);
    auto hi = std::upper_bound(vec.cbegin(), vec.cend(), 3);
    std::cout << "3 seq: ";
    for (auto it = lo; it != hi; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    PRETTY_COUT(*lo);
    PRETTY_COUT(*hi);
}

void equal_range_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> vec{0, 1, 2, 3, 3, 3, 3, 3, 3, 4, 5, 6, 7, 8, 9};

    std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator> borders = std::equal_range(vec.cbegin(), vec.cend(), 3);
    std::cout << "3 seq: ";
    for (auto it = borders.first; it != borders.second; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void bad_binary_search_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> vec{1, 0, 7, 3, 4, 5, 6, 7, 8, 9}; //not sorted

    std::cout << std::binary_search(vec.begin(), vec.end(), 5)  << std::endl;
    std::cout << std::binary_search(vec.begin(), vec.end(), 4) << std::endl; 
}

int main() {

    find_demo();
    search_demo();
    bsearch_demo();
    binary_search_demo();
    lower_upper_bound_demo();
    equal_range_demo();
    //bad_binary_search_demo();

    return 0;
}