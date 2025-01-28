#include <algorithm>
#include <vector>

#include "utils.h"

void copy_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> src{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> dst(src.size());

    std::copy(src.begin(), src.end(), dst.begin());

    PRETTY_COUT(src, dst);
}

void copy_n_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> src{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> dst(4);

    std::copy_n(src.begin(), 4, dst.begin());

    PRETTY_COUT(src, dst);
}

void copy_backward_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> src{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> dst(10);

    std::copy_backward(src.begin(), src.end(), dst.end());

    PRETTY_COUT(src, dst);
}

void copy_if_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> src{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> dst;

    std::copy_if(src.begin(), src.end(), std::back_inserter(dst), [](auto val) -> bool { return val > 5;});

    PRETTY_COUT(src, dst, dst.size());
}

void fill_generate_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> vec(20);
    
    std::generate(vec.begin(), vec.end(), [](){ return std::rand() % 20; });
    PRETTY_COUT(vec);

    std::fill(vec.begin(), vec.end(), 1);
    PRETTY_COUT(vec);

    std::fill_n(vec.begin(), 20, 0);
    PRETTY_COUT(vec);

    std::generate_n(vec.begin(), 20, [](){ return std::rand() % 20; });
    PRETTY_COUT(vec);
}

int main() {

    copy_demo();
    copy_n_demo();
    copy_backward_demo();
    copy_if_demo();
    fill_generate_demo();

    return 0;
}