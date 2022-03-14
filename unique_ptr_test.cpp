#include "unique_ptr.hpp"
#include <gtest/gtest.h>

// 1
TEST(UniquePtrTest, DefaultConstructor) {
    unique_ptr<int> u_ptr;
    ASSERT_EQ(u_ptr.get(), nullptr);
}

// 2
TEST(UniquePtrTest, Constructor) {
    int i = 10;
    unique_ptr<int> u_ptr(&i);
    ASSERT_EQ(u_ptr.get(), &i);
}

// 3
TEST(UniquePtrTest, MoveCostructor) {
    int i = 10;
    unique_ptr<int> u_ptr1(&i);
    ASSERT_EQ(u_ptr1.get(), &i);
    unique_ptr<int> u_ptr2(std::move(u_ptr1));
    ASSERT_EQ(u_ptr1.get(), nullptr);
    ASSERT_EQ(u_ptr2.get(), &i);
}

// 4
TEST(UniquePtrTest, ReleaseTest) {
    int i = 10;
    unique_ptr<int> u_ptr(&i);
    ASSERT_EQ(u_ptr.release(), &i);
    ASSERT_FALSE(u_ptr);
}

// 5
TEST(UniquePtrTest, ResetTest) {
    int i = 10;
    int j = 20;
    unique_ptr<int> u_ptr(&i);
    u_ptr.reset();
    ASSERT_EQ(u_ptr.get(), nullptr);
    u_ptr.reset(&j);
    ASSERT_EQ(u_ptr.get(), &j);
}

// 6
TEST(UniquePtrTest, MoveAssign) {
    int i = 10;
    unique_ptr<int> u_ptr1(&i);
    unique_ptr<int> u_ptr2 = std::move(u_ptr1);
    ASSERT_EQ(u_ptr1.get(), nullptr);
    ASSERT_EQ(u_ptr2.get(), &i);
}

// 7
TEST(UniquePtrTest, BoolConversion) {
    int i = 10;
    unique_ptr<int> u_ptr1;
    unique_ptr<int> u_ptr2(&i);
    ASSERT_FALSE(u_ptr1);
    ASSERT_FALSE(!u_ptr2);
}

// 8
TEST(UniquePtrTest, StarOperator) {
    int i = 10;
    unique_ptr<int> u_ptr(&i);
    ASSERT_EQ(*u_ptr, 10);
}
