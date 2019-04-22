#include <string>
#include <iostream>
#include "StudentDB_DLL.h"

using namespace std;

int main()
{
    StudentDB db;

    //create 10 Johns
    for(int i=1; i<=11; ++i)
    {
        db.insertBack(Student("John", i));

    }
    db.insertFront(Student("Mike", 0));

    //insert in the middle and delete them all
    for(int i=0; i<10; ++i)
    {
        db.insertMiddle(Student("Middleman", 999));
        db.deleteMiddle();
    }
    
    db.insertMiddle(Student("Middleman", 999));
    
    //delete Mike from the front
    db.deleteFront();
    db.print();

    return 0;
}