#include <cstddef>
#include <mutex>
#include <optional>
#include "queue"
#include "iostream"
#include "condition_variable"



template <typename T>
struct concurrent_queue {

    concurrent_queue(std::size_t max_size) : max_size(max_size) {};

    void push(T value) {
        std::unique_lock<std::mutex> ul(m);
        cv_full.wait(ul, [this]() { return max_size != q.size(); });

        q.push_back(std::move(value));
        cv_empty.notify_one();
        // --> th2
    }

    bool empty() const {
        std::lock_guard<std::mutex> lg(m);
        return q.empty();
    }

    T pop() {
        std::unique_lock<std::mutex> ul(m);
        m.lock();
// --> th1

        // q.size() == 3

        // --> ul.locked + !q.empty();

        cv_empty.wait(ul, [this]() { return !q.empty(); });
        // inside wait() call
        /*
        ul.unlock();
        real wain notify_all()|notify_one() command
        ul.lock();
        */

        T result = q.front();
        q.pop_front(); // 10 - 1 = 9
        cv_full.notify_one();

        return result;
    }

    std::optional<T> try_pop() {
        std::lock_guard<std::mutex> lg(m);
        T result = q.front();
        q.pop_front();
        return result;
    }
private:
    size_t max_size;
    mutable std::condition_variable cv_empty;
    mutable std::condition_variable cv_full;
    mutable std::mutex m;
    std::deque<T> q;
};



void ThreadProcess(concurrent_queue<int> q) {
    while (true) {
        if (!q.empty()) {
            auto pop_optimal = q.try_pop();
            if (pop_optimal) {
                std::cout << pop_optimal.value() << std::endl;
                break;
            }
        }
    }
    return
}