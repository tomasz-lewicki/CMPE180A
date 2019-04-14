#include <string>
#include <iostream>
#include "StudentDB.h"

using namespace std;

int main()
{
    StudentDB db;

    Student s1("Mike", 1000), s2("Bill", 2000), s3("Alex", 3000), s4("Grzegorz", 4001), s5("John Doe", 5555);
    db.insertBack(s1);
    db.insertBack(s2);
    db.insertBack(s3);

    db.insertFront(s4);
    db.insertMiddle(s5);
    db.insertMiddle(s2);


    db.deleteFront();


    db.print();

    db.deleteBack();
    db.deleteBack();
    db.deleteBack();
    db.deleteBack();
    db.deleteBack();
    
    return 0;
}