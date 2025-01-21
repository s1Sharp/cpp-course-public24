#include <algorithm>
#include <vector>
#include <cstdlib>
#include "utils.h"

void partition_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> vec(10);
    vec[0] = 50;
    std::generate(std::next(vec.begin()), vec.end(), [](){ return std::rand() % 100; });

    PRETTY_COUT(vec);
    auto lam = [](int val){ return val < 50; };
    std::cout << "partitioned? " << std::is_partitioned(vec.begin(), vec.end(), lam) << std::endl;
    auto it = std::partition(vec.begin(), vec.end(), lam);
    PRETTY_COUT(vec);
    std::cout << "middle: " << std::distance(vec.begin(), it) << std::endl;
}

template <class ForwardIt>
void quicksort(ForwardIt first, ForwardIt last)
{
    if(first == last) 
        return;
    auto pivot = *std::next(first, std::distance(first,last)/2);
    ForwardIt middle1 = std::partition(first, last, 
                            [pivot](const auto& em){ return em < pivot; });
    ForwardIt middle2 = std::partition(middle1, last, 
                            [pivot](const auto& em){ return !(pivot < em); });
    quicksort(first, middle1);
    quicksort(middle2, last);
}

void quicksort_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> vec(10);
    std::generate(vec.begin(), vec.end(), [](){ return std::rand() % 100; });

    PRETTY_COUT(vec);
    quicksort(vec.begin(), vec.end());
    PRETTY_COUT(vec);
}

void stable_partition_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> vec(10);
    vec[0] = 50;
    std::generate(std::next(vec.begin()), vec.end(), [](){ return std::rand() % 100; });

    PRETTY_COUT(vec);
    auto lam = [](int val){ return val < 50; };
    std::cout << "partitioned? " << std::is_partitioned(vec.begin(), vec.end(), lam) << std::endl;
    auto it = std::stable_partition(vec.begin(), vec.end(), lam);
    PRETTY_COUT(vec);
    std::cout << "middle: " << std::distance(vec.begin(), it) << std::endl;
}

int main() {

    partition_demo();
    quicksort_demo();
    stable_partition_demo();

    return 0;
}