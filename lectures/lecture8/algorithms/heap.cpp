#include <algorithm>
#include <vector>
#include <queue>

#include "utils.h"

void heap_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    std::vector<int> heap{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "is heap: " << std::is_heap(heap.cbegin(), heap.cend()) << std::endl;
    std::cout << "values:  " << heap << std::endl;

    std::make_heap(heap.begin(), heap.end()); // O(N)
    std::cout << "is heap: " << std::is_heap(heap.cbegin(), heap.cend()) << std::endl;
    std::cout << "values:  " << heap << std::endl;

    heap.push_back(42);
    std::cout << "is heap: " << std::is_heap(heap.cbegin(), heap.cend()) << std::endl;
    std::cout << "values:  " << heap << std::endl;

    std::push_heap(heap.begin(), heap.end()); // swim
    std::cout << "is heap: " << std::is_heap(heap.cbegin(), heap.cend()) << std::endl;
    std::cout << "values:  " << heap << std::endl;

    std::pop_heap(heap.begin(), heap.end()); // sink
    std::cout << "is heap: " << std::is_heap(heap.cbegin(), heap.cend() - 1) << std::endl;
    std::cout << "values:  " << heap << std::endl;

    heap.pop_back();
    std::cout << "is heap: " << std::is_heap(heap.cbegin(), heap.cend()) << std::endl;
    std::cout << "values:  " << heap << std::endl;

    std::sort_heap(heap.begin(), heap.end());
    std::cout << "is sorted: " << std::is_sorted(heap.cbegin(), heap.cend()) << std::endl;
     std::cout << "is heap: " << std::is_heap(heap.cbegin(), heap.cend()) << std::endl;
    std::cout << "values:  " << heap << std::endl;
}

void priority_queue_demo() {
    std::cout << " =========== " << __FUNCTION__ << " ===========\n";
    const std::vector<int> data {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};
    std::cout << "values:  " << data << std::endl;
    std::priority_queue<int> q;
    for(auto& i : data)
        q.push(i);

    print_queue("Q", q);
}


int main() {

    heap_demo();
    priority_queue_demo();

    return 0;
}