#include <iostream>
#include "../include/Array.h"

int main()
{
    Array<int> a;
    for (int i = 0; i < 10; ++i)
        a.insert(i + 1);


    for (int i = 0; i < a.size(); ++i)
        a[i] *= 2;

    std::cout << a.to_string() << std::endl;


    // ????
    /*for (auto it = a.iterator(); it.hasNext(); it.next())
    {
        std::cout << it.get() << std::endl;
    }*/

    for (auto it = a.iterator(); it.isValid(); it.next())
    {
        std::cout << it.get() << " ";
    }


    /*using namespace std;
    Array<string> arr(5);
    for (int i = 0; i < arr.capacity(); i++)
    {
        arr.insert("element" + std::to_string(i));
    }

    std::cout << "size = " << arr.size() << std::endl;
    std::cout << arr.to_string() << std::endl;
    arr.insert(3, "inserted element");
    std::cout << "size = " << arr.size() << std::endl;
    std::cout << arr.to_string() << std::endl;
    arr.remove(5);
    std::cout << "size = " << arr.size() << std::endl;
    std::cout << arr.to_string() << std::endl;*/

    return 0;
}
