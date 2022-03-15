#include "unique_ptr.hpp"
#include <gtest/gtest.h>

TEST(PrimaryTemplateTest, DefaultConstructor) {
    unique_ptr<int> u_ptr;
    ASSERT_EQ(u_ptr.get(), nullptr);
}

TEST(PrimaryTemplateTest, Constructor) {
    unique_ptr<int> u_ptr(new int);
    ASSERT_NE(u_ptr.get(), nullptr);
}

TEST(PrimaryTemplateTest, MoveCostructor) {
    unique_ptr<int> u_ptr1(new int);
    ASSERT_NE(u_ptr1.get(), nullptr);
    unique_ptr<int> u_ptr2(std::move(u_ptr1));
    ASSERT_EQ(u_ptr1.get(), nullptr);
    ASSERT_NE(u_ptr2.get(), nullptr);
}

TEST(PrimaryTemplateTest, ReleaseTest) {
    unique_ptr<int> u_ptr(new int);
    int *ptr = u_ptr.release();
    ASSERT_EQ(u_ptr.get(), nullptr);
    delete ptr;
}

TEST(PrimaryTemplateTest, ResetTest) {
    unique_ptr<int> u_ptr(new int);
    u_ptr.reset();
    ASSERT_EQ(u_ptr.get(), nullptr);
    u_ptr.reset(new int);
    ASSERT_NE(u_ptr.get(), nullptr);
}

TEST(PrimaryTemplateTest, SwapTest) {
    unique_ptr<int> u_ptr1(new int(10));
    unique_ptr<int> u_ptr2(new int(20));
    u_ptr1.swap(u_ptr2);
    ASSERT_EQ(*u_ptr1.get(), 20);
    ASSERT_EQ(*u_ptr2.get(), 10);
}

TEST(PrimaryTemplateTest, MoveAssign) {
    unique_ptr<int> u_ptr1(new int);
    unique_ptr<int> u_ptr2(new int);
    u_ptr2 = std::move(u_ptr1);
    ASSERT_EQ(u_ptr1.get(), nullptr);
    ASSERT_NE(u_ptr2.get(), nullptr);
}

TEST(PrimaryTemplateTest, BoolConversion) {
    unique_ptr<int> u_ptr1;
    unique_ptr<int> u_ptr2(new int);
    ASSERT_FALSE(u_ptr1);
    ASSERT_TRUE(u_ptr2);
}

TEST(PrimaryTemplateTest, StarOperator) {
    unique_ptr<int> u_ptr(new int(10));
    ASSERT_EQ(*u_ptr, 10);
}

TEST(PrimaryTemplateTest, EqualOperator) {
    unique_ptr<int> u_ptr1;
    unique_ptr<int> u_ptr2(new int);
    ASSERT_NE(u_ptr1, u_ptr2);
}

TEST(SpecializationForArrays, Constructor) {
    unique_ptr<int[]> u_ptr(new int[10]);
    ASSERT_NE(u_ptr.get(), nullptr);
}

TEST(SpecializationForArrays, MoveCostructor) {
    unique_ptr<int[]> u_ptr1(new int[10]);
    ASSERT_NE(u_ptr1.get(), nullptr);
    unique_ptr<int[]> u_ptr2(std::move(u_ptr1));
    ASSERT_EQ(u_ptr1.get(), nullptr);
    ASSERT_NE(u_ptr2.get(), nullptr);
}

TEST(SpecializationForArrays, ReleaseTest) {
    unique_ptr<int[]> u_ptr(new int[10]);
    int *arr = u_ptr.release();
    ASSERT_EQ(u_ptr.get(), nullptr);
    delete[] arr;
}

TEST(SpecializationForArrays, ResetTest) {
    unique_ptr<int[]> u_ptr(new int[10]);
    u_ptr.reset();
    ASSERT_EQ(u_ptr.get(), nullptr);
    u_ptr.reset(new int[10]);
    ASSERT_NE(u_ptr.get(), nullptr);
}

TEST(SpecializationForArrays, SwapTest) {
    unique_ptr<int[]> u_ptr1(new int[10]);
    unique_ptr<int[]> u_ptr2;
    u_ptr1.swap(u_ptr2);
    ASSERT_EQ(u_ptr1.get(), nullptr);
    ASSERT_NE(u_ptr2.get(), nullptr);
}

TEST(SpecializationForArrays, MoveAssign) {
    unique_ptr<int[]> u_ptr1(new int[10]);
    unique_ptr<int[]> u_ptr2(new int[10]);
    u_ptr2 = std::move(u_ptr1);
    ASSERT_EQ(u_ptr1.get(), nullptr);
    ASSERT_NE(u_ptr2.get(), nullptr);
}

TEST(SpecializationForArrays, BoolConversion) {
    unique_ptr<int[]> u_ptr1;
    unique_ptr<int[]> u_ptr2(new int[10]);
    ASSERT_FALSE(u_ptr1);
    ASSERT_TRUE(u_ptr2);
}

TEST(SpecializationForArrays, BracketOperator) {
    unique_ptr<int[]> u_ptr(new int[10]);
    for (size_t i = 0; i < 10; i++)
        u_ptr[i] = i * i;
    for (size_t i = 0; i < 10; i++)
        ASSERT_EQ(u_ptr[i], i * i);
}

TEST(SpecializationForArrays, EqualOperator) {
    unique_ptr<int[]> u_ptr1;
    unique_ptr<int[]> u_ptr2(new int[10]);
    ASSERT_NE(u_ptr1, u_ptr2);
}