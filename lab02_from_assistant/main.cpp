#include <iostream> //cout, endl
#include "IntArray.h"

int main()
{
    IntArray arr = IntArray(10);
    
    arr.insertAt(0, 111);
    arr.insertAt(1, 222);
    arr.insertAt(2, 333);
    arr.insertAt(3, 444);
    arr.insertAt(4, 555);
    arr.insertAt(3, 33333);

    std::cout << "before deletion:" << std::endl;
    arr.print();

    arr.deleteAt(3);

    std::cout << "after deletion:" << std::endl;
    arr.print();

    return 0;
}