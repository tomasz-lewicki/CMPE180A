#include <iostream>
#include <fstream>
#include <vector>
#include "ComplexDB.h"

using namespace std;


int main()
{

    //TODO: Create a menu to allow console add / delete / list and save functions.  

    ComplexDB db;
    
    db.load("126import.txt");


    cout << "How many numbers would you like to add?" << endl;

    unsigned int no_inputs=0;
    cin >> no_inputs;

    for(unsigned i=0; i<no_inputs; ++i)
    {
        cout << "add a complex number" << endl;

        string input;
        cin >> input;
        if(db.loadOne(input)) cout << "problem reading your input" << endl;
    }

    db.saveToFile("complexObj.txt");

    db.list();

}