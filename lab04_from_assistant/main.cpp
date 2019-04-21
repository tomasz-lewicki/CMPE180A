#include <string>
#include <iostream>
#include "StudentDB_DLL.h"

using namespace std;

int main()
{
    StudentDB db;

    for(int i=1; i<10; ++i)
    {
        db.insertBack(Student("Mike", i));

    }
    db.insertFront(Student("Mike", 0));
    db.insertMiddle(Student("Mike", 999));
    db.print();

    // db.deleteBack();
    // db.deleteBack();
    // db.deleteBack();
    // db.deleteBack();
    
    return 0;
}