#include <string>
#include <iostream>

template<typename T>
class Optional {
private:
    T value_;
    bool has_value_;

public:
    Optional()
        : has_value_(false)
    {}

    Optional(const T& another_value)
        : value_(another_value)
        , has_value_(true)
    {}

    template<typename U>
    Optional(const U& source)
        : value_(source)
        , has_value_(true)
    {}

    Optional(const Optional&) = default;
    Optional(Optional&&) = default;
    Optional& operator = (const Optional&) = default;
    Optional& operator = (Optional&&) = default;
    ~Optional() = default;

    bool has_value() const { return has_value_; }

    T&       get_value()       { return value_; }
    const T& get_value() const { return value_; }

    T*       get_ptr()       { return has_value_ ? &value_ : nullptr; }    
    const T* get_ptr() const { return has_value_ ? &value_ : nullptr; }

    void reset() {
        value_ = T();
        has_value_ = false;
    }

    void reset(const T& another_value) {
        value_ = another_value;
        has_value_ = true;
    }

    void emplace() {
        value_ = T();
        has_value_ = true;
    }

    template<typename U>
    void emplace(const U& source) {
        value_ = T(source);
        has_value_ = true;
    }
};


std::string f() {
    Optional<std::string> opt;

    opt.emplace("hello");
    opt.emplace("C++");
    opt.emplace("world");        

    opt.emplace(std::string("-hello"));
    opt.emplace(std::string("-C++"));
    opt.emplace(std::string("-world"));

    return opt.get_value();
}


int main()
{
    std::cout << f() << std::endl;
    return 0;
}