#include "../include/Array.h"
#include "gtest/gtest.h"
#include <string>


int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#pragma region Constructors


TEST(ArrayTest, DefaultConstructor)
{
    Array<int> arr;
    EXPECT_EQ(arr.size(), 0);
    EXPECT_GE(arr.capacity(), 8);
}

TEST(ArrayTest, DefaultConstructorCapacity)
{
    Array<int> arr;
    EXPECT_EQ(arr.capacity(), 8);
}

TEST(ArrayTest, CapacityConstructorWithElements)
{
    Array<int> arr(10);
    EXPECT_EQ(arr.capacity(), 10);
    EXPECT_EQ(arr.size(), 0);

    arr.insert(1337);
    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 1337);
}

TEST(ArrayTest, CapacityConstructor)
{
    Array<int> arr(10);
    EXPECT_EQ(arr.capacity(), 10);
    EXPECT_EQ(arr.size(), 0);
}

TEST(ArrayTest, CopyConstructorString)
{
    Array<std::string> a(5);
    for (int i = 0; i < 9; i++)
    {
        a.insert("good string" + std::to_string(i + 1));
    }

    Array<std::string> b(a);
    EXPECT_EQ(b[0], a[0]);
    EXPECT_EQ(b[8], a[8]);
}

TEST(CopyTest, CopyConstructorWithEmpty)
{
    Array<int> a(5);
    Array<int> b(a);
    EXPECT_EQ(a.capacity(), b.capacity());
    EXPECT_EQ(a.size(), b.size());
}

TEST(ArrayTest, MoveConstructorString)
{
    Array<std::string> a(5);
    for (int i = 0; i < 9; i++)
    {
        a.insert("cool string " + std::to_string(i + 1));
    }

    Array<std::string> b(std::move(a));
    EXPECT_EQ(a.capacity(), 0);
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(b[0], "cool string 1");
    EXPECT_EQ(b[8], "cool string 9");
}

TEST(CopyTest, MoveConstructorWithEmpty)
{
    Array<int> a(5);
    Array<int> b(std::move(a));

    EXPECT_EQ(a.capacity(), 0);
    EXPECT_EQ(a.size(), 0);
}

#pragma endregion


TEST(ArrayTest, MoveCopyAssigment)
{
    Array<int> a(5);
    for (int i = 0; i < 9; i++)
    {
        a.insert(i + 1);
    }

    Array<int> b = a;
    EXPECT_EQ(b[0], a[0]);
    EXPECT_EQ(a.capacity() > 0, true);
    Array<int> c = std::move(a);
    EXPECT_EQ(a.capacity(), 0);
    EXPECT_EQ(c[0], 1);

    Array<std::string> d(5);
    for (int i = 0; i < 9; i++)
    {
        d.insert("num " + std::to_string(i + 1));
    }

    Array<std::string> e = d;
    EXPECT_EQ(e[0], d[0]);
    EXPECT_EQ(d.capacity() > 0, true);
    Array<std::string> f = std::move(d);
    EXPECT_EQ(d.capacity(), 0);
    EXPECT_EQ(f[0], "num 1");
}


TEST(ArrayTest, InsertIntAtEnd)
{
    Array<int> arr;
    for (int i = 0; i < 5; i++)
    {
        arr.insert(i * 10);
    }
    EXPECT_EQ(arr.size(), 5);
    EXPECT_EQ(arr[4], 40);
}

TEST(ArrayTest, EndStringInsert)
{
    Array<std::string> a;
    for (int i = 0; i < 5; i++)
    {
        a.insert("text_" + std::to_string(i + 1));
    }
    EXPECT_EQ(a.size(), 5);
    EXPECT_EQ(a.capacity(), 8);
    EXPECT_EQ(a[0], "text_1");
    EXPECT_EQ(a[4], "text_5");
}

TEST(ArrayTest, InsertAtEndMoreThanCapacity)
{
    Array<int> a;
    for (int i = 0; i < 9; i++)
    {
        a.insert(i + 1);
    }
    EXPECT_EQ(a.size(), 9);
    // 8 * 1.6 = 12.8 >>> 12
    EXPECT_EQ(a.capacity(), 12);
    EXPECT_EQ(a[0], 1);
    EXPECT_EQ(a[8], 9);
}


TEST(ArrayTest, InsertAtIndex)
{
    Array<std::string> arr;
    arr.insert("first cat");
    arr.insert("third cat");
    arr.insert(1, "second cat");

    EXPECT_EQ(arr.size(), 3);
    EXPECT_EQ(arr[0], "first cat");
    EXPECT_EQ(arr[1], "second cat");
    EXPECT_EQ(arr[2], "third cat");
}

TEST(ArrayTest, InsertInvalidIndex)
{
    Array<int> arr;
    arr.insert(5);

    arr.insert(10, 99);
    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr[1], 99);
}

TEST(ArrayTest, Remove)
{
    Array<int> arr;
    for (int i = 0; i < 5; i++)
    {
        arr.insert(i);
    }
    arr.remove(2);

    EXPECT_EQ(arr.size(), 4);
    EXPECT_EQ(arr[2], 3);
}

TEST(ArrayTest, RemoveStringMiddle)
{
    Array<std::string> a(5);
    for (int i = 0; i < 9; i++)
    {
        a.insert(std::to_string(i));
    }
    a.remove(5);
    EXPECT_EQ(a.size(), 8);
    EXPECT_EQ(a[5], "6");
}

TEST(ArrayTest, InsertAfterRemoveString)
{
    Array<std::string> a(16);
    for (int i = 0; i < 16; i++)
    {
        a.insert(std::to_string(i));
    }

    a.remove(0);

    a.insert("string!!");

    EXPECT_EQ(a.size(), 16);
    EXPECT_EQ(a[15], "string!!");
}


//NEW TESTS
TEST(ArrayAssignmentTest, CopyAssignmentWorks)
{
    Array<int> arr1;
    arr1.insert(1);
    arr1.insert(2);
    arr1.insert(3);

    Array<int> arr2;
    arr2.insert(4);
    arr2.insert(5);

    arr2 = arr1;

    EXPECT_EQ(arr2.size(), 3);
    EXPECT_EQ(arr2[0], 1);
    EXPECT_EQ(arr2[1], 2);
    EXPECT_EQ(arr2[2], 3);

    EXPECT_EQ(arr1.size(), 3);
    EXPECT_EQ(arr1[0], 1);
}

TEST(ArrayAssignmentTest, MoveAssignmentWorks)
{
    Array<int> arr1;
    arr1.insert(1);
    arr1.insert(2);
    arr1.insert(3);

    Array<int> arr2;

    arr2 = std::move(arr1);

    EXPECT_EQ(arr2.size(), 3);
    EXPECT_EQ(arr2[0], 1);
    EXPECT_EQ(arr2[1], 2);
    EXPECT_EQ(arr2[2], 3);

    EXPECT_EQ(arr1.size(), 0);
    EXPECT_EQ(arr1.capacity(), 0);
}

TEST(ArrayAssignmentTest, SelfAssignmentWorks)
{
    Array<int> arr;
    arr.insert(1);
    arr.insert(2);
    arr.insert(3);

    arr = arr;

    EXPECT_EQ(arr.size(), 3);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
}

TEST(ArrayAssignmentTest, AssignmentChainWorks)
{
    Array<int> arr1;
    arr1.insert(1);

    Array<int> arr2;
    arr2.insert(2);

    Array<int> arr3;
    arr3.insert(3);

    // Цепочка присваиваний
    arr1 = arr2 = arr3;

    EXPECT_EQ(arr1.size(), 1);
    EXPECT_EQ(arr1[0], 3);
    EXPECT_EQ(arr2.size(), 1);
    EXPECT_EQ(arr2[0], 3);
    EXPECT_EQ(arr3.size(), 1);
    EXPECT_EQ(arr3[0], 3);
}

TEST(ArrayAssignmentTest, CopyAssignmentWithStrings)
{
    Array<std::string> arr1;
    arr1.insert("hello");
    arr1.insert("world");

    Array<std::string> arr2;
    arr2.insert("test");

    arr2 = arr1;

    EXPECT_EQ(arr2.size(), 2);
    EXPECT_EQ(arr2[0], "hello");
    EXPECT_EQ(arr2[1], "world");


    arr1[0] = "modified";
    EXPECT_EQ(arr2[0], "hello");
}

TEST(ArrayAssignmentTest, MoveAssignmentWithStrings)
{
    Array<std::string> arr1;
    arr1.insert("hello");
    arr1.insert("world");

    Array<std::string> arr2;

    arr2 = std::move(arr1);

    EXPECT_EQ(arr2.size(), 2);
    EXPECT_EQ(arr2[0], "hello");
    EXPECT_EQ(arr2[1], "world");

    EXPECT_EQ(arr1.size(), 0);
}

TEST(ArrayAssignmentTest, AssignmentUsesCopyAndSwap)
{
    Array<int> arr1(10);
    for (int i = 0; i < 8; ++i)
    {
        arr1.insert(i);
    }

    Array<int> arr2(5);


    arr2 = arr1;

    EXPECT_EQ(arr2.capacity(), 10);
    EXPECT_EQ(arr2.size(), 8);

    Array<int> arr3;
    arr3 = std::move(arr2);

    EXPECT_EQ(arr3.capacity(), 10);
    EXPECT_EQ(arr3.size(), 8);
    EXPECT_EQ(arr2.capacity(), 0);
}
