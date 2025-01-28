#include <algorithm>
#include <vector>
#include <list>
#include <cstdlib>

#include "utils.h"

void sort_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    int counter = 0;
    std::vector<tracer> vec;
    vec.reserve(10);
    for (int k = 0; k < 10; k++) {
        vec.emplace_back(std::rand() % 100, counter);
    }

    PRETTY_COUT(vec);
    std::sort(vec.begin(), vec.end());
    PRETTY_COUT(vec);

    std::cout << "compare count: " << counter << std::endl;
}

void list_sort_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    int counter = 0;
    std::list<tracer> list;
    for (int k = 0; k < 10; k++) {
        list.emplace_back(std::rand() % 100, counter);
    }

    PRETTY_COUT(list);
    list.sort(); // N*log(N) stable (?)
    PRETTY_COUT(list);

    std::cout << "compare count: " << counter << std::endl;
}

struct A {
    int val;
    int mark;
};

bool operator < (const A& lhs, const A& rhs) {
    return lhs.val < rhs.val;
}

std::ostream& operator<<(std::ostream& os, const A& a) {
    os << "val: " << a.val << " mark: " <<  a.mark << std::endl;
    return os;
}

void sort_stability_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<A> vec;
    vec.reserve(100);
    for (int k = 0; k < 100; k++) {
        vec.emplace_back(A{k % 3, k});
    }

    std::cout << "\t" << vec << std::endl;
    std::cout << "================" << std::endl;
    std::sort(vec.begin(), vec.end()); // stable_sort
    std::cout << "\t" << vec << std::endl;
}

void partial_sort_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    int counter = 0;
    std::vector<tracer> vec;
    vec.reserve(10);
    for (int k = 0; k < 10; k++)
        vec.emplace_back(std::rand() % 100, counter);
    
    PRETTY_COUT(vec);
    std::partial_sort(vec.begin(), std::next(vec.begin(), 3), vec.end());
    PRETTY_COUT(vec);

    std::cout << "compare count: " << counter << std::endl;
}

void nth_element_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    int counter = 0;
    std::vector<tracer> vec;
    vec.reserve(10);
    for (int k = 0; k < 10; k++)
        vec.emplace_back(std::rand() % 100, counter);
    
    PRETTY_COUT(vec);
    std::nth_element(vec.begin(), vec.begin() + 3, vec.end());
    PRETTY_COUT(vec);

    std::cout << "compare count: " << counter << std::endl;
}

void median_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    int counter = 0;
    std::vector<int> vec(10);
    std::generate(vec.begin(), vec.end(), [](){ return std::rand() % 100; });

    PRETTY_COUT(vec);
    std::nth_element(vec.begin(), vec.begin() + vec.size()/2, vec.end());
    PRETTY_COUT(vec, vec[vec.size()/2]);

    std::cout << "compare count: " << counter << std::endl;
}

void is_sorted_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> vec(10);
    std::generate(vec.begin(), vec.end(), [](){ return std::rand() % 100; });

    std::cout << std::is_sorted(vec.begin(), vec.end()) << std::endl;
    std::sort(vec.begin(), vec.end());
    std::cout << std::is_sorted(vec.begin(), vec.end()) << std::endl;
}

void is_sorted_until_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> vec {0, 1, 2, 3, 4, 5, 7, 6, 3, 2, 1};
    auto it = std::is_sorted_until(vec.begin(), vec.end());
    std::cout << *it << " - " << std::distance(vec.begin(), it) << std::endl;
}

int main() {
    
    sort_demo();
    list_sort_demo();
    sort_stability_demo();
    partial_sort_demo();
    nth_element_demo();
    median_demo();
    is_sorted_demo();
    is_sorted_until_demo();

    return 0;
}