#include <iostream>
#include "clock.h"

using namespace std;

int main()
{
    clockType c1(23, 59, 59), c2(3, 10, 12);  // hour, min, sec
    cout << c1 << endl;   // add whatever to beautify it
    cout << c2 << endl;
    cout << c1+c2 << endl;
    c2 = c1+c1;
    cout << c2 << endl;
    return 0;
}