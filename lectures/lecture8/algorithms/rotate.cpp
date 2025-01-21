#include <algorithm>
#include <vector>

#include "utils.h"

void rotate_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    PRETTY_COUT(vec);

    std::rotate(vec.begin(), vec.begin() + 3, vec.end());
    PRETTY_COUT(vec);

    std::rotate(vec.rbegin(), vec.rbegin() + 3, vec.rend());
    PRETTY_COUT(vec);
}

int main() {

    rotate_demo();
    return 0;
}