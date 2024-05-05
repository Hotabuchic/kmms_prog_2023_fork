#include "vector.hpp"
#include <gtest/gtest.h>

using IBusko::Vector;

TEST(Test, Base) {
    Vector<int> vector;
    EXPECT_EQ(vector.size(), 0);
}

TEST(Test, Push) {
    Vector<int> vector;
    vector.push_back(1);
    vector.push_back(2);
    EXPECT_EQ(vector.size(), 2);
}

TEST(Test, CheckItem) {
    Vector<int> vector;
    vector.push_back(1);
    EXPECT_TRUE(vector.has_item(1));
    EXPECT_FALSE(vector.has_item(4));
}