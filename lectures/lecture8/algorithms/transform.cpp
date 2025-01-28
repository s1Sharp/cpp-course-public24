#include <algorithm>
#include <vector>
#include <string>
#include <map>

#include "utils.h"

void transform_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> src{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<std::string> dst(src.size());

    std::transform(src.begin(), src.end(), dst.begin(), 
                   [](int val) -> std::string { return std::to_string(val) + "_val"; });

    PRETTY_COUT(src, dst);

    std::transform(src.begin(), src.end(), src.begin(), 
                   [](int val) -> int { return ++val; });
    PRETTY_COUT(src);
}

void transform2_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> src1{0, 1, 2, 3};
    std::vector<std::string> src2{"zero", "one", "two", "three"};
    std::vector<std::pair<int, std::string>> dst;

    std::transform(src1.begin(), src1.end(), src2.begin(), std::back_inserter(dst), 
                   [](const auto key, const auto value) { return make_pair(key, value); });
    PRETTY_COUT(src1);
    PRETTY_COUT(src2);

    for(const auto& it : dst)
        PRETTY_COUT(it.first, it.second);
}

int main() {

    transform_demo();
    transform2_demo();
    return 0;
}