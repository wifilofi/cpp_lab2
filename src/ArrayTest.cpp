//
// Created by gfn on 12/12/2025.
//

#include "../include/ArrayTest.h"
#include "../include/Array.h"
#include "gtest/gtest.h"


int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(ArrayTest, DefaultConstructor)
{
    Array<int> arr;
    EXPECT_EQ(arr.size(), 0);
}

TEST(ArrayTest, CapacityConstructor)
{
    Array<int> arr(10);
    EXPECT_EQ(arr.size(), 0);
}

TEST(ArrayTest, CopyConstructor)
{
    Array<int> arr1;
    for (int i = 0; i < 3; i++)
    {
        arr1.insert(i * 10);
    }


    Array<int> arr2(arr1);
    EXPECT_EQ(arr2.size(), 3);
    EXPECT_EQ(arr2[1], 10);
}

TEST(ArrayTest, MoveConstructor)
{
    Array<std::string> arr1;
    arr1.insert("cool string 1337");

    Array<std::string> arr2(std::move(arr1));
    EXPECT_EQ(arr2.size(), 1);
    EXPECT_EQ(arr2[0], "cool string 1337");
    EXPECT_EQ(arr1.size(), 0);
}

// insert at end
// insert at index
// remove
// assignment
// iterator
// reverse iterator
// const iterator
// subscript iterator
// capacity iterator

// EDGES cases
// remove from empty
// insert index out of bounsd
//
