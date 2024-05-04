#include "doubly_linked_list.hpp"
#include <gtest/gtest.h>

using IBusko::DoublyLinkedList;

TEST(Test, Base) {
    DoublyLinkedList<int> list;
    EXPECT_EQ(list.size(), 0);
}

TEST(Test, Push) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    EXPECT_EQ(list.size(), 2);
}

TEST(Test, CheckItem) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    EXPECT_TRUE(list.has_item(1));
    EXPECT_FALSE(list.has_item(4));
}