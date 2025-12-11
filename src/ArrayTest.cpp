//
// Created by gfn on 12/12/2025.
//

#include "../include/ArrayTest.h"
#include "../include/Array.h"
#include "gtest/gtest.h"

TEST(ArrayTest, DefaultConstructor)
{
    Array<int> arr;
    EXPECT_EQ(arr.size(), 0);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}