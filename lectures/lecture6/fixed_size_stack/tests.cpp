#include "fixed_size_stack_sol.hpp"
#include <gtest/gtest.h>

TEST(BASIC_OPERATIONS, CONSTRUCT) {
    Stack stack(5);
}

TEST(BASIC_OPERATIONS, SINGLE_PUSH) {
    Stack stack(1);
    stack.Push(42);

    EXPECT_EQ(stack.Top(), 42);
}

TEST(BASIC_OPERATIONS, SINGLE_POP) {
    Stack stack(2);
    stack.Push(42);
    stack.Push(21);

    EXPECT_EQ(stack.Top(), 21);

    stack.Pop();

    EXPECT_EQ(stack.Top(), 42);
}

TEST(MULTIPLE_OPERATIONS, SEQ_PUSH_POP) {
    Stack stack(100);

    int arr[4] = {25, -1000, 2338, 551};

    stack.Push(arr[0]);
    stack.Push(arr[1]);
    stack.Push(arr[2]);
    stack.Push(arr[3]);

    for (int i = 0; i < 4; ++i) {
        EXPECT_EQ(stack.Top(), arr[3 - i]);

        stack.Pop();
    }
}

TEST(CORNER_CASES, POP_FROM_EMPTY) {
    Stack stack(1);

    stack.Pop();
}

TEST(CORNER_CASES, PUSH_TO_FULL) {
    Stack stack(1);

    stack.Push(2);
    stack.Push(3);

    EXPECT_EQ(stack.Top(), 2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}