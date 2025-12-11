#include <iostream>
#include "../include/Array.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main()
{
    using namespace std;
    Array<string> arr(5);
    for (int i = 0; i < arr.capacity(); i++)
    {
        arr.insert("element" + std::to_string(i));
    }

    std:: cout << "size = " << arr.size() << std::endl;
    std::cout << arr.to_string() << std::endl;
    arr.insert(3, "inserted element");
    std:: cout << "size = " << arr.size() << std::endl;
    std::cout << arr.to_string() << std::endl;
    arr.remove(5);
    std:: cout << "size = " << arr.size() << std::endl;
    std::cout << arr.to_string() << std::endl;

    return 0;
}
