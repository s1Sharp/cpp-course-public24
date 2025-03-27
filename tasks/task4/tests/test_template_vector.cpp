#include <vector>
#include <algorithm>
#include <array>

#include <gtest/gtest.h>

#include "template_vector.hpp"


static int Counter = 0;
struct Counterable
{
    Counterable() {
        ++Counter;
    }

    Counterable(const Counterable&) {
        ++Counter;
    }

    Counterable& operator=(const Counterable&) {
        ++Counter;
        return *this;
    }

    ~Counterable() {
        --Counter;
    }
};


TEST(CORRECTNESS, template_vector_as_int_is_empty) {
    Vector<int> v;
    ASSERT_TRUE(v.empty());
    ASSERT_EQ(v.size(), 0);
}


TEST(CORRECTNESS, template_vector_as_double_is_empty) {
    Vector<double> v;
    ASSERT_TRUE(v.empty());
    ASSERT_EQ(v.size(), 0);
}


TEST(COUNTERABLE, template_vector_as_counterable_is_empty) {
    Counter = 0;
    Vector<Counterable> v;
    ASSERT_TRUE(v.empty());
    ASSERT_EQ(v.size(), 0);

    const size_t expected_counter = Vector<Counterable>::empty_vector_size_;
    ASSERT_LE(Counter, expected_counter);
}


TEST(CORRECTNESS, template_vector_as_int_push_back) {
    Vector<int> v;

    v.push_back(1);

    ASSERT_TRUE(!v.empty());
    ASSERT_EQ(v.size(), 1);
    ASSERT_EQ(v[0], 1);
}


TEST(CORRECTNESS, template_vector_as_double_push_back) {
    Vector<double> v;

    v.push_back(1);

    ASSERT_TRUE(!v.empty());
    ASSERT_EQ(v.size(), 1);
    ASSERT_EQ(v[0], 1);
}


TEST(CORRECTNESS, template_vector_as_int_pop_back) {
    Vector<int> v;

    v.push_back(1);

    ASSERT_TRUE(!v.empty());

    v.pop_back();

    ASSERT_TRUE(v.empty());
    ASSERT_EQ(v.size(), 0);
}


TEST(CORRECTNESS, template_vector_as_double_pop_back) {
    Vector<double> v;

    v.push_back(1);

    ASSERT_TRUE(!v.empty());

    v.pop_back();

    ASSERT_TRUE(v.empty());
    ASSERT_EQ(v.size(), 0);
}


TEST(CORRECTNESS, template_vector_as_double_clear) {
    Vector<double> v;

    v.push_back(1);
    v.push_back(1);
    v.push_back(1);

    ASSERT_TRUE(!v.empty());

    v.clear();

    ASSERT_TRUE(v.empty());
    ASSERT_EQ(v.size(), 0);
}


TEST(CORRECTNESS, template_vector_as_int_pop_back_on_empty) {
    Vector<int> v;
    ASSERT_THROW(v.pop_back(), std::out_of_range);
}


TEST(CORRECTNESS, template_vector_as_int_random_access_on_empty) {
    Vector<int> v;

    for (auto i = v.begin(); i < v.end(); i++) {
        ASSERT_EQ(*i, 0);
    }
}


TEST(CORRECTNESS, template_vector_as_int_random_access_on_resize) {
    Vector<int> v;
    const size_t new_size = 20;
    v.resize(new_size);

    for (size_t i = 0; i < new_size; i++) {
        ASSERT_EQ(v[i], 0);
    }

    const size_t new_size_smallest = 20;
    v.resize(new_size_smallest);
    for (size_t i = 0; i < new_size_smallest; i++) {
        ASSERT_EQ(v[i], 0);
    }
}


TEST(CORRECTNESS, template_vector_as_int_random_access) {
    Vector<int> v;

    v.push_back(3);
    v.push_back(2);
    v.push_back(1);

    ASSERT_TRUE(!v.empty());

    ASSERT_EQ(v[0], 3);
    ASSERT_EQ(v[1], 2);
    ASSERT_EQ(v[2], 1);

    ASSERT_TRUE(!v.empty());
}


TEST(CORRECTNESS, template_vector_as_int_many_push_back) {
    Vector<int> v;

    v.push_back(1);

    ASSERT_TRUE(!v.empty());
    ASSERT_EQ(v.size(), 1);
    ASSERT_EQ(v[0], 1);

    v.pop_back();

    v.push_back(3);
    v.push_back(2);
    v.push_back(1);

    ASSERT_TRUE(!v.empty());
    ASSERT_EQ(v.size(), 3);
    ASSERT_EQ(v[0], 3);
    ASSERT_EQ(v[1], 2);
    ASSERT_EQ(v[2], 1);
}

TEST(CORRECTNESS, template_vector_as_int_many_pop_back) {
    Vector<int> v;

    v.push_back(3);
    v.push_back(2);
    v.push_back(1);

    ASSERT_TRUE(!v.empty());
    ASSERT_EQ(v.size(), 3);
    ASSERT_EQ(v[0], 3);
    ASSERT_EQ(v[1], 2);
    ASSERT_EQ(v[2], 1);

    v.pop_back();
    v.pop_back();
    v.pop_back();

    ASSERT_TRUE(v.empty());

    ASSERT_EQ(*(v.begin() + 0), 0);
    ASSERT_EQ(*(v.begin() + 1), 0);
    ASSERT_EQ(*(v.begin() + 2), 0);
}


TEST(CORRECTNESS, template_vector_as_int_iterable) {
    Vector<int> v;

    v.push_back(3);
    v.push_back(2);
    v.push_back(1);

    auto f = v.begin();
    ASSERT_TRUE(f != v.end());
    ASSERT_EQ(*f, 3);
    ++f;
    ASSERT_TRUE(f != v.end());
    ASSERT_EQ(*f, 2);
    ++f;
    ASSERT_TRUE(f != v.end());
    ASSERT_EQ(*f, 1);
    ++f;
    ASSERT_TRUE(f == v.end());
}


TEST(CORRECTNESS, template_vector_as_int_reserve_save_values) {
    Vector<int> v;

    v.push_back(3);
    v.push_back(2);
    v.push_back(1);

    v.reserve(10000);
    ASSERT_EQ(v.size(), 3);
    ASSERT_TRUE(v.capacity() >= 10000);
}


TEST(COUNTERABLE, template_vector_as_int_reserve_save_values) {
    Counter = 0;
    Vector<Counterable> v;

    v.push_back(Counterable());
    v.push_back(Counterable());
    v.push_back(Counterable());

    v.reserve(1024);
    ASSERT_EQ(v.size(), 3);
    ASSERT_TRUE(v.capacity() >= 1024);

    ASSERT_LE(Counter, 8 + 1024);
}


TEST(CORRECTNESS, template_vector_as_int_reserve) {
    Vector<int> v;

    v.push_back(3);
    v.push_back(2);
    v.push_back(1);

    v.reserve(10000);
    ASSERT_EQ(v.size(), 3);
    ASSERT_TRUE(v.capacity() >= 10000);

    const auto c = v.capacity();

    v.resize(2);
    ASSERT_EQ(v.size(), 2);
    ASSERT_EQ(v.capacity(), c);
    ASSERT_EQ(v[0], 3);
    ASSERT_EQ(v[1], 2);

    v.resize(3);
    ASSERT_EQ(v.size(), 3);
    ASSERT_EQ(v.capacity(), c);
    ASSERT_EQ(v[0], 3);
    ASSERT_EQ(v[1], 2);
    ASSERT_EQ(v[2], 0);

    v.resize(0);
    ASSERT_EQ(v.size(), 0);
    ASSERT_TRUE(v.begin() == v.end());

    v.resize(2);
    ASSERT_EQ(v.size(), 2);
    ASSERT_EQ(v[0], 0);
    ASSERT_EQ(v[1], 0);
}


TEST(COUNTERABLE, template_vector_as_int_counterable_realocations) {
    Counter = 0;
    Vector<Counterable> v;
    v.resize(100);

    ASSERT_LE(Counter, 200);

    for (int i = 0; i < 100; ++i){
        v.push_back(Counterable());
    }

    ASSERT_LE(Counter, 500);
}


TEST(CORNER, template_vector_as_int_iterator_distance_on_empty_reserve) {
    Vector<int> v;

    ASSERT_LE(std::distance(v.begin(), v.end()), 0);

    v.reserve(100);

    ASSERT_LE(std::distance(v.begin(), v.end()), 0);
}


TEST(CORNER, template_vector_as_int_iterator_distance_on_empty_resize) {
    Vector<int> v;

    ASSERT_LE(std::distance(v.begin(), v.end()), 0);

    v.resize(100);

    ASSERT_LE(std::distance(v.begin(), v.end()), 100);
}


TEST(CORNER, template_vector_as_int_iterator_distance_on_push_back) {
    Vector<int> v;

    for (int i = 0; i < 100; ++i){
        v.push_back(i);
    }

    ASSERT_LE(std::distance(v.begin(), v.end()), 100);
}


TEST(CORNER, template_vector_as_int_iterator_distance_on_clear) {
    Vector<int> v;

    for (int i = 0; i < 100; ++i){
        v.push_back(i);
    }

    ASSERT_LE(std::distance(v.begin(), v.end()), 100);

    v.clear();

    ASSERT_LE(std::distance(v.begin(), v.end()), 100);
}
