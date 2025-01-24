#include <algorithm>
#include <vector>

#include "utils.h"

void remove_demo() {   
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> vec{0, 1, 2, 3, 4, 5, 5, 5, 6, 7, 8, 9};
    PRETTY_COUT(vec);

    auto it = std::remove(vec.begin(), vec.end(), 5);
    PRETTY_COUT(vec);

    std::cout << std::distance(vec.begin(), it) << std::endl;

    vec.erase(it, vec.end());
    PRETTY_COUT(vec);
}

void remove_if_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    PRETTY_COUT(vec);

    auto it = std::remove_if(vec.begin(), vec.end(), [](auto val){ return val < 5; });
    PRETTY_COUT(vec);
    std::cout << std::distance(vec.begin(), it) << std::endl;

    vec.erase(it, vec.end());
    PRETTY_COUT(vec);
}

void remove_copy_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> src{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> dst{};

    auto it = std::remove_copy(src.begin(), src.end(), std::back_inserter(dst), 5);
    PRETTY_COUT(src, dst);
}

void remove_copy_if_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> src{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> dst{};

    auto it = std::remove_copy_if(src.begin(), src.end(), std::back_inserter(dst), 
                                  [](auto val) -> bool { return val < 5; });
    PRETTY_COUT(src, dst);
}

int main() {

    remove_demo();
    remove_if_demo();

    remove_copy_demo();
    remove_copy_if_demo();

    return 0;
}