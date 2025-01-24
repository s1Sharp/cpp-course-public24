#include <numeric>
#include <vector>
#include <string>

#include "utils.h"

void accumulate_demo() {
    std::vector<int> vec{1, 2, 3, 4, 5};

    float sum = std::accumulate(vec.begin(), vec.end(), 0.0);
 
    int product = std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>());
 
    auto dash_fold = [](std::string a, int b) {
                         return std::move(a) + '-' + std::to_string(b);
                     };
 
    std::string str = std::accumulate(std::next(vec.begin()), vec.end(),
                                      std::to_string(vec[0]), // start with first element
                                      dash_fold);
 
    // Right fold using reverse iterators
    std::string rstr = std::accumulate(std::next(vec.rbegin()), vec.rend(),
                                       std::to_string(vec.back()), // start with last element
                                       dash_fold);

    PRETTY_COUT(sum, product, str, rstr);
}

void partial_sum_demo() {
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::partial_sum(vec.begin(), vec.end(), vec.begin(), std::plus<int>());

    PRETTY_COUT(vec);
}

int main() {

    accumulate_demo();
    partial_sum_demo();
    
    return 0;
}