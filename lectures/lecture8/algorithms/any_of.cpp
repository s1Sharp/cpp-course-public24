#include <algorithm>
#include <vector>
#include <cstdlib>

#include "utils.h"

void any_of_demo() {
    std::vector<int> vec(10);
    std::generate(vec.begin(), vec.end(), [](){ return std::rand() % 100; });
    PRETTY_COUT(vec);

    PRETTY_COUT(std::any_of(vec.begin(), vec.end(), [](int val){ return val < 20; }));
}

void all_of_demo() {
    std::vector<int> vec(10);
    std::generate(vec.begin(), vec.end(), [](){ return std::rand() % 100; });
    PRETTY_COUT(vec);

    PRETTY_COUT(std::all_of(vec.begin(), vec.end(), [](int val){ return val > 50; }));
}

void none_of_demo() {
    std::vector<int> vec(10);
    std::generate(vec.begin(), vec.end(), [](){ return std::rand() % 100; });
    PRETTY_COUT(vec);

    PRETTY_COUT(std::none_of(vec.begin(), vec.end(), [](int val){ return val < 10; }));
}

int main() {

    any_of_demo();
    all_of_demo();
    none_of_demo();

    return 0;
}