#include <vector>
#include <algorithm>
#include <array>

#include <gtest/gtest.h>

#include "bin_search.hpp"

TEST(CORRECTNESS, just_works) {
    std::array arr{1, 2, 3, 4, 5, 6, 7};
    const auto begin = std::begin(arr);
    const auto end   = std::end(arr);

    int* ptr = LowerBound(begin, end, 1);

    EXPECT_EQ(begin, std::begin(arr));
    EXPECT_EQ(begin + arr.size(), std::end(arr));
    EXPECT_EQ(*ptr, 1);
}

TEST(CORRECTNESS, simple_small_array) {
    std::array arr{1};
    const auto begin = std::begin(arr);
    const auto end   = std::end(arr);

    int* ptr = LowerBound(begin, end, 1);

    EXPECT_EQ(begin, std::begin(arr));
    EXPECT_EQ(begin + arr.size(), std::end(arr));
    EXPECT_EQ(*ptr, 1);
}

TEST(CORRECTNESS, simple_test) {
    std::array arr{1, 2};
    const auto begin = std::begin(arr);
    const auto end   = std::end(arr);

    int* ptr = LowerBound(begin, end, 2);

    EXPECT_EQ(begin, std::begin(arr));
    EXPECT_EQ(begin + arr.size(), std::end(arr));
    EXPECT_EQ(*ptr, 2);

    int* ptr2 = LowerBound(begin, end, 1);

    EXPECT_EQ(*ptr2, 1);
}

TEST(CORRECTNESS, with_no_value) {
    std::array arr{2, 5, 8, 13, 21, 34, 55};
    const auto begin = std::begin(arr);
    const auto end   = std::end(arr);

    int* ptr = LowerBound(begin, end, 15);

    EXPECT_EQ(begin, std::begin(arr));
    EXPECT_EQ(begin + arr.size(), std::end(arr));
    EXPECT_EQ(*ptr, 21);
}

TEST(CORNER, less_than_first) {
    std::array arr{2, 5, 8, 13, 21, 34, 55};
    const auto begin = std::begin(arr);
    const auto end   = std::end(arr);

    int* ptr = LowerBound(begin, end, -5);

    EXPECT_EQ(begin, std::begin(arr));
    EXPECT_EQ(begin + arr.size(), std::end(arr));
    EXPECT_EQ(*ptr, 2);
}

TEST(CORNER, greater_than_all) {
    std::array arr{2, 5, 8, 13, 21, 34, 55};
    const auto begin = std::begin(arr);
    const auto end   = std::end(arr);

    int* ptr = LowerBound(begin, end, 123);

    EXPECT_EQ(begin, std::begin(arr));
    EXPECT_EQ(begin + arr.size(), std::end(arr));
    EXPECT_EQ(ptr, end);
}

TEST(CORNER, nullptr_return_nullptr) {
    int* ptr = LowerBound(nullptr, nullptr, 0);
    EXPECT_EQ(ptr, nullptr);
}
