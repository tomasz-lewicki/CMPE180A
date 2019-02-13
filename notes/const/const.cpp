#include <iostream>
using namespace std;


int main()
{
    int a = 10;
    int b = 50;
    const int *p = &a;
    /*
    const int* is a pointer to a const int rather than a constant pointer to int. (see below for that)
    Therefore:
    1. the value of a can change through a different refrence
    */

    a = 15;
    
    /*
    2.pointer p can be reassigned to a different address
    */

    p = &b;
    cout << *p << endl;
    
    /*
    Side note: some other languages can have values that may never change
    through any reference. They can be declarated with immutable keyword
    */

    /*
    This is how you could make a constant pointer to a
    */
    int * const q = &a;
    //q = &b; would be then illegal

    /*
    And this is how you would make a constant pointer to a constant value
    */

    const int * const r = &a;
    //*r = 50; would be illegal, hovever
    //you can still change the value, simply not by this const reference.
    
    a = 60;
    cout << *r << endl;

}