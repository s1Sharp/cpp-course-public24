#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
class auto_ptr {
    mutable T *ptr;

  public:
    auto_ptr(T *ptr_) : ptr{ptr_} {}
    ~auto_ptr() { delete ptr; }

    T *operator->() { return ptr; }
    T &operator*() { return *ptr; }

    auto_ptr(const auto_ptr &rhv) {
        ptr     = rhv.ptr;
        rhv.ptr = nullptr;
    }
    T &operator=(auto_ptr &rhv) {
        ptr     = rhv.ptr;
        rhv.ptr = nullptr;
        return *this;
    }
};

int main(int argc, const char *argv[]) {

    auto_ptr<int> ptr1(new int{5});
    auto_ptr<int> ptr2 = ptr1;

    std::cout << *ptr2 << std::endl;


    std::vector<auto_ptr<int>> vecAutoPtrs;

    vecAutoPtrs.push_back(auto_ptr<int>(new int{2}));
    vecAutoPtrs.push_back(auto_ptr<int>(new int{5}));
    vecAutoPtrs.push_back(auto_ptr<int>(new int{1}));
    vecAutoPtrs.push_back(auto_ptr<int>(new int{3}));
    vecAutoPtrs.push_back(auto_ptr<int>(new int{2}));
    vecAutoPtrs.push_back(auto_ptr<int>(new int{5}));
    vecAutoPtrs.push_back(auto_ptr<int>(new int{1}));
    vecAutoPtrs.push_back(auto_ptr<int>(new int{3}));
    vecAutoPtrs.push_back(auto_ptr<int>(new int{2}));
    vecAutoPtrs.push_back(auto_ptr<int>(new int{5}));
    vecAutoPtrs.push_back(auto_ptr<int>(new int{1}));
    vecAutoPtrs.push_back(auto_ptr<int>(new int{3}));

    std::vector<auto_ptr<int>> vec2 = vecAutoPtrs;
    // std::sort(vec2.begin(), vec2.end());

    return 0;
}
