#include "pretty.h"
#include "utils.h"

#include <memory>

class A {
  public:
    A() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~A() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

template <typename T>
class shared_ptr {
    struct ctrl_block {
        std::size_t counter;
        std::size_t weak_counter;
        /* deleater and smth else */
        ctrl_block() : counter{1UL}, weak_counter{0UL} {}
    };
    ctrl_block *ctrl;
    T *ptr;

  public:
    shared_ptr(T *ptr_) : ctrl{new ctrl_block}, ptr{ptr_} {}

    shared_ptr(const shared_ptr &other) : ctrl{other.ctrl}, ptr{other.ptr} {
        ++ctrl->counter;
    }

    ~shared_ptr() {
        if (--ctrl->counter == 0) {
            delete (ptr);
            if (ctrl->weak_counter == 0)
                delete (ctrl);
        }
    }
};

void shared_ptr_example() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    shared_ptr<A> ptr1(new A);
    auto ptr2 = ptr1;
}

void delete_A(A *ptr) { delete ptr; }

void size_of() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    A *row_ptr = nullptr;
    std::shared_ptr<A> ptr1(new A);
    std::shared_ptr<A> ptr2(new A, delete_A);

    auto lam = [](A *ptr) { delete ptr; };
    std::shared_ptr<A> ptr3(new A, lam);

    int some_value = 42;
    auto lam2      = [&some_value](A *ptr) { delete ptr; };
    std::shared_ptr<A> ptr4(new A, lam2);

    PRETTY_COUT(sizeof(row_ptr), sizeof(ptr1), sizeof(ptr2), sizeof(ptr3),
                sizeof(ptr4));
}

// class SharableObj {
//   public:
//     SharableObj() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
//     ~SharableObj() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

//     auto getPtr() { return std::shared_ptr<SharableObj>(this); }
// };

class SharableObj : public std::enable_shared_from_this<SharableObj> {
  public:
    SharableObj() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~SharableObj() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    auto getPtr() { return shared_from_this(); }
};

void get_shared_ptr() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    auto obj      = std::make_shared<SharableObj>();
    auto same_obj = obj->getPtr();
}

class partnerA;
class partnerB;

class partnerA {
    std::shared_ptr<partnerB> partner_ptr;

  public:
    partnerA() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~partnerA() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    void setPartner(std::shared_ptr<partnerB> ptr) { partner_ptr = ptr; }
};

class partnerB {
    std::shared_ptr<partnerA> partner_ptr;

  public:
    partnerB() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~partnerB() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    void setPartner(std::shared_ptr<partnerA> ptr) { partner_ptr = ptr; }
};

void cyclik_links() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    auto first  = std::make_shared<partnerA>();
    auto second = std::make_shared<partnerB>();

    first->setPartner(second);
    second->setPartner(first);

    // first->usePatrner()
    // ...
    // 
}

int main(int argc, char *argv[]) {

    // shared_ptr_example();
    // size_of();
    // get_shared_ptr();
    cyclik_links();

    return 0;
}