#include "unique_ptr.hpp"
#include <gtest/gtest.h>

// 1
TEST(UniquePtrTest, DefaultConstructor) {
    unique_ptr<int> u_ptr;
    ASSERT_EQ(u_ptr.get(), nullptr);
}

// 2
TEST(UniquePtrTest, Constructor) {
    int *ptr = new int(10);
    unique_ptr<int> u_ptr(ptr);
    ASSERT_EQ(u_ptr.get(), ptr);
}

// 3
TEST(UniquePtrTest, MoveCostructor) {
    unique_ptr<int> u_ptr1(new int(10));
    ASSERT_EQ(*u_ptr1.get(), 10);
    unique_ptr<int> u_ptr2(std::move(u_ptr1));
    ASSERT_EQ(u_ptr1.get(), nullptr);
    ASSERT_EQ(*u_ptr2.get(), 10);
}

// 4
TEST(UniquePtrTest, ReleaseTest) {
    int *ptr = new int(10);
    unique_ptr<int> u_ptr(ptr);
    ASSERT_EQ(u_ptr.release(), ptr);
    ASSERT_FALSE(u_ptr);
    delete ptr;
}

// 5
TEST(UniquePtrTest, ResetTest) {
    unique_ptr<int> u_ptr(new int(10));
    u_ptr.reset();
    ASSERT_EQ(u_ptr.get(), nullptr);
    u_ptr.reset(new int(20));
    ASSERT_EQ(*u_ptr.get(), 20);
}

// 6
TEST(UniquePtrTest, MoveAssign) {
    unique_ptr<int> u_ptr1(new int(10));
    unique_ptr<int> u_ptr2 = std::move(u_ptr1);
    ASSERT_EQ(u_ptr1.get(), nullptr);
    ASSERT_EQ(*u_ptr2.get(), 10);
}

// 7
TEST(UniquePtrTest, BoolConversion) {
    unique_ptr<int> u_ptr1;
    unique_ptr<int> u_ptr2(new int(10));
    ASSERT_FALSE(u_ptr1);
    ASSERT_TRUE(u_ptr2);
}

// 8
TEST(UniquePtrTest, StarOperator) {
    unique_ptr<int> u_ptr(new int(10));
    ASSERT_EQ(*u_ptr, 10);
}
