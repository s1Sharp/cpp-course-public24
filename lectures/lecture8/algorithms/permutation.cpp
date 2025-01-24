#include <algorithm>
#include <vector>

#include "utils.h"

void permutation_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> vec1{0, 1, 2};
    std::vector<int> vec2{2, 1, 0};

    PRETTY_COUT(std::is_permutation(vec1.begin(), vec1.end(), vec2.begin()));

    PRETTY_COUT(vec1);
    while(std::next_permutation(vec1.begin(), vec1.end())) {
        PRETTY_COUT(vec1);
    }
    PRETTY_COUT(vec1);

    std::cout << "===============\n";
    std::prev_permutation(vec1.begin(), vec1.end());
    PRETTY_COUT(vec1);
    while(std::prev_permutation(vec1.begin(), vec1.end())) {
        PRETTY_COUT(vec1);
    }
}

int main() {

    permutation_demo();

    return 0;
}