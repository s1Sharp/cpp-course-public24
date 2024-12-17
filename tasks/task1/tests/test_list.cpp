#include <gtest/gtest.h>

#include <cstring>
#include <list>

#include "list.h"



TEST(CustomList, CheckDefaultConstructor) {
    { // without stack corruption
        List l = List();
        EXPECT_EQ(l.first, nullptr);
        EXPECT_EQ(l.last, nullptr);
    }
    {
        char corrupt[4 * sizeof(List)];
        std::memset(corrupt, 0xf, 4 * sizeof(List));
    }
    { // with stack corruption
        List l = List();
        EXPECT_EQ(l.first, nullptr);
        EXPECT_EQ(l.last, nullptr);
    }
}


TEST(CustomList, Check_clear) {
    // test init
    auto make_not_empty_list = []() -> List {
        List l = List();
        for (int i=0; i<10; i++) {
            l.push_back(i);
        }
        return l;
    };
    // testing
    {
        List l = List();
        EXPECT_TRUE(l.is_empty());

        l.clear();
        EXPECT_TRUE(l.is_empty());
    }
    {
        List l = List();
        EXPECT_TRUE(l.is_empty());

        l.push_back(1);
        l.push_back(2);
        l.push_back(3);
        EXPECT_FALSE(l.is_empty());

        l.clear();
        EXPECT_TRUE(l.is_empty());
    }
    {
        List l = make_not_empty_list();
        EXPECT_FALSE(l.is_empty());

        l.clear();
        EXPECT_TRUE(l.is_empty());
    }
    {
        List l = make_not_empty_list();
        l.clear();
        EXPECT_EQ(l.first, nullptr);
        EXPECT_EQ(l.last, nullptr);
    }
}


TEST(CustomList, Check_is_empty) {
    {
        List l = List();
        EXPECT_TRUE(l.is_empty());

        l.push_front(1);
        EXPECT_FALSE(l.is_empty());
    }
    {
        List l = List();
        EXPECT_TRUE(l.is_empty());

        l.push_back(1);
        EXPECT_FALSE(l.is_empty());
    }
    {
        List l = List();
        EXPECT_TRUE(l.is_empty());

        l.push_front(1);
        EXPECT_FALSE(l.is_empty());

        l.remove_front();
        EXPECT_TRUE(l.is_empty());

        l.push_back(1);
        EXPECT_FALSE(l.is_empty());

        l.remove_back();
        EXPECT_TRUE(l.is_empty());
    }
    {
        List l = List();
        EXPECT_TRUE(l.is_empty());

        l.push_back(1);
        l.push_back(2);
        l.push_back(3);
        EXPECT_FALSE(l.is_empty());

        l.remove_back();
        l.remove_back();
        l.remove_back();
        EXPECT_TRUE(l.is_empty());
    }
}


TEST(CustomList, Check_find) {
    // test init
    auto make_not_empty_list = []() -> List {
        List l = List();
        for (int i=0; i<10; i++) {
            l.push_back(i);
        }
        return l;
    };
    // testing
    {
        List l = make_not_empty_list();

        for (int i=0; i<10; i++) {
            const Node* node = l.find(i);
            EXPECT_NE(node, nullptr);
            EXPECT_EQ(node->val, i);
            if (i == 9) {
                EXPECT_EQ(node->next, nullptr);
            } else {
                EXPECT_EQ(node->next, l[i + 1]);
            }
        }
    }
    // testing
    {
        List l = make_not_empty_list();
        // size 10+1
        l.push_back(1);

        Node* node = l.find(1);
        EXPECT_NE(node, nullptr);
        EXPECT_EQ(node->val, 1);
        EXPECT_EQ(node, l[1]);

        // size 11-1
        l.remove_front();
        node = l.find(1);

        EXPECT_NE(node, nullptr);
        EXPECT_EQ(node->val, 1);
        EXPECT_EQ(node, l[0]);

        // size 10-1
        l.remove_front();
        node = l.find(1);

        EXPECT_NE(node, nullptr);
        EXPECT_EQ(node->val, 1);
        EXPECT_EQ(node, l[8]);
    }
}


TEST(CustomList, Check_push_front) {
    // test init
    auto make_not_empty_list = []() -> List {
        List l = List();
        for (int i=0; i<10; i++) {
            l.push_front(i);
        }
        return l;
    };
    // testing
    {
        List l = make_not_empty_list();
        for (int i=0; i<10; i++) {
            int idx = 9-i;
            EXPECT_NE(l[idx], nullptr);
            EXPECT_EQ(l[idx]->val, i);
        }
        for (int i=0; i<10; i++) {
            l.remove_front();
        }
        EXPECT_TRUE(l.is_empty());
    }
    // testing
    {
        List l = make_not_empty_list();
        for (int i=0; i<10; i++) {
            int idx = 9-i;
            EXPECT_NE(l[idx], nullptr);
            EXPECT_EQ(l[idx]->val, i);
        }
        for (int i=0; i<10; i++) {
            l.remove_back();
        }
        EXPECT_TRUE(l.is_empty());
    }
}


TEST(CustomList, Check_push_back) {
    // test init
    auto make_not_empty_list = []() -> List {
        List l = List();
        for (int i=0; i<10; i++) {
            l.push_back(i);
        }
        return l;
    };
    // testing
    {
        List l = make_not_empty_list();
        for (int i=0; i<10; i++) {
            int idx = i;
            EXPECT_NE(l[idx], nullptr);
            EXPECT_EQ(l[idx]->val, i);
        }
        for (int i=0; i<10; i++) {
            l.remove_front();
        }
        EXPECT_TRUE(l.is_empty());
    }
    // testing
    {
        List l = make_not_empty_list();
        for (int i=0; i<10; i++) {
            int idx = i;
            EXPECT_NE(l[idx], nullptr);
            EXPECT_EQ(l[idx]->val, i);
        }
        for (int i=0; i<10; i++) {
            l.remove_back();
        }
        EXPECT_TRUE(l.is_empty());
    }
}


TEST(CustomList, Check_remove_front) {
    // testing
    {
        List l = List();

        l.push_back(1);
        l.push_front(2);
        l.push_front(3);

        ASSERT_EQ(l[0]->val, 3);
        ASSERT_EQ(l[1]->val, 2);
        ASSERT_EQ(l[2]->val, 1);

        l.remove_front();
        ASSERT_EQ(l[0]->val, 2);
        ASSERT_EQ(l[1]->val, 1);

        l.remove_front();
        ASSERT_EQ(l[0]->val, 1);

        l.remove_front();

        ASSERT_TRUE(l.is_empty());
    }
    // testing
    {
        List l = List();

        l.push_front(3);
        l.push_front(2);
        l.push_front(1);

        ASSERT_EQ(l[0]->val, 1);
        ASSERT_EQ(l[1]->val, 2);
        ASSERT_EQ(l[2]->val, 3);

        l.remove_front();
        l.remove_front();
        ASSERT_FALSE(l.is_empty());

        l.remove_front();
        ASSERT_TRUE(l.is_empty());
    }
    // testing
    {
        List l = List();

        ASSERT_TRUE(l.is_empty());
        l.remove_front();
        ASSERT_TRUE(l.is_empty());
    }
}


TEST(CustomList, Check_remove_back) {
    // testing
    {
        List l = List();

        l.push_front(1);
        l.push_back(2);
        l.push_back(3);

        ASSERT_EQ(l[0]->val, 1);
        ASSERT_EQ(l[1]->val, 2);
        ASSERT_EQ(l[2]->val, 3);

        l.remove_back();
        ASSERT_EQ(l[0]->val, 1);
        ASSERT_EQ(l[1]->val, 2);

        l.remove_back();
        ASSERT_EQ(l[0]->val, 1);

        l.remove_back();

        ASSERT_TRUE(l.is_empty());
    }
    // testing
    {
        List l = List();

        l.push_back(3);
        l.push_back(2);
        l.push_back(1);

        ASSERT_EQ(l[0]->val, 3);
        ASSERT_EQ(l[1]->val, 2);
        ASSERT_EQ(l[2]->val, 1);

        l.remove_back();
        l.remove_back();
        ASSERT_FALSE(l.is_empty());

        l.remove_back();
        ASSERT_TRUE(l.is_empty());
    }
    // testing
    {
        List l = List();

        ASSERT_TRUE(l.is_empty());
        l.remove_back();
        ASSERT_TRUE(l.is_empty());
    }
}


TEST(CustomList, Check_remove) {
    // testing
    {
        List l = List();

        l.push_back(1);
        l.push_back(2);
        l.push_back(3);

        Node* node = l.find(2);

        EXPECT_NE(node, nullptr);
        ASSERT_TRUE(l.remove(node));
        ASSERT_EQ(l[0]->val, 1);
        ASSERT_EQ(l[1]->val, 3); 
        ASSERT_FALSE(l.remove(nullptr));       

        Node t(-1);
        ASSERT_FALSE(l.remove(&t));
    }
    {
        List l = List();

        l.push_back(1);
        l.push_back(2);
        l.push_back(3);

        ASSERT_FALSE(l.is_empty());

        ASSERT_TRUE(l.remove(l.find(1)));
        ASSERT_TRUE(l.remove(l.find(2)));
        ASSERT_TRUE(l.remove(l.find(3)));

        ASSERT_TRUE(l.is_empty());
    }
}
