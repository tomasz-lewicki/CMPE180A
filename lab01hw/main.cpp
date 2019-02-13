#include <iostream>
#include <fstream>
#include <vector>
#include "complex.h"

using namespace std;

vector <Complex> numbers;

int main()
{
    //2. input from file and parse
    ifstream myfile ("complex.txt");

    while(myfile.good())
    {
        string data;
        myfile >> data;

        if(data.find_first_not_of("0123456789+-i") <= data.length()) continue; //bad characters
        if(data.find_first_of("i") != data.find_last_of("i")) continue; //more than one i
        
        else 
        {
            size_t im_sign_idx = data.find_last_of("+-");
            double re = stod(data.substr(0,im_sign_idx));
            double im = stod(data.substr(im_sign_idx, data.length() - im_sign_idx -1));

            numbers.push_back(Complex(re, im));
        }
    }
    myfile.close();

    //3. dump to another file
    ofstream myoutputfile("complexObj.txt", ios::trunc);

    for(Complex i : numbers)
    {
        myoutputfile << i << endl;
    }
    myoutputfile.close();

    //4. sum all numbers
    Complex result;

    for(Complex i: numbers)
    {
        result = i + result;
    }

    cout << "result of all complex numbers equals:" << result << endl;

    //5. append the result to file
    myoutputfile.open("complexObj.txt", ios::app);

    myoutputfile << "result equals:" << endl;
    myoutputfile << result;

}