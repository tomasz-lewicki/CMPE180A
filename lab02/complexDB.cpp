#include <fstream>
#include <string>
#include <algorithm>
#include "complex.h"
#include "ComplexDB.h"
#include <regex>

using namespace std;

ComplexDB::ComplexDB()
{
    real_regex = regex("^[+-]?[0-9]+(?:[.][0-9]+)?(?!i)");
    imag_regex = regex("[-+]?[0-9][.]?[0-9]?(?=i)");
}

void ComplexDB::load(string filename)
{
    ifstream myfile (filename);

    string line;
    double re, im;

    smatch re_mtch;
    smatch im_mtch;


    while(myfile.good())
    {
        myfile >> line;
        regex_search(line, re_mtch, real_regex);
        regex_search(line, im_mtch, imag_regex);

        if (*re_mtch.begin() == "") re = 0;
        else re = stod(*re_mtch.begin());

        if (*im_mtch.begin() == "") im = 0;
        else im = stod(*im_mtch.begin());
        
        numVec.push_back(Complex(re, im));

    }
    myfile.close();
}

int ComplexDB::loadOne(string line)
{
    if(line.find_first_not_of("0123456789+-i.") <= line.length()) return -1; //bad characters
    if(line.find_first_of("i") != line.find_last_of("i")) return -1; //more than one i
    
    double re, im;
    smatch re_mtch, im_mtch;

    regex_search(line, re_mtch, real_regex);
    regex_search(line, im_mtch, imag_regex);

    if (*re_mtch.begin() == "") re = 0;
    else re = stod(*re_mtch.begin());

    if (*im_mtch.begin() == "") im = 0;
    else im = stod(*im_mtch.begin());
    
    numVec.push_back(Complex(re, im));

    return 0;
}

void ComplexDB::saveToFile(string filename) const
{
    ofstream myoutputfile(filename, ios::out);

    for(Complex i : *getSortedVector())
    {
        myoutputfile << i << endl;
    }
    
    myoutputfile.close();

}

void ComplexDB::add(const Complex num)
{
    numVec.push_back(num);
}

std::vector<Complex>* ComplexDB::getSortedVector() const
{
    std::vector<Complex>* sorted = new vector<Complex>;
    *sorted = numVec;

    sort(sorted->begin(), sorted->end());

    return sorted;
}

void ComplexDB::list() const
{
    std::vector<Complex>* sorted = this->getSortedVector();
    for(Complex i : *sorted)
    {
        cout << i << endl;
    }
    delete sorted;
}
//Create a menu to allow console add / delete / list and save functions.



        //
        
        // else 
        // {
        //     size_t im_sign_idx = data.find_last_of("+-");
        //     // cout << data.substr(0,im_sign_idx) << endl;
        //     if(data.find("i") > data.length()) //no 'i' -> real number
        //     {
        //         re = stod(data);
        //         im = 0;
        //     }
        //     else if () // no 
        //     {
        //         /* code */
        //     }

        //     else
        //     {
        //         re = stod(data.substr(0,im_sign_idx));
        //         im = stod(data.substr(im_sign_idx, data.length() - im_sign_idx -1));
        //     }

        //     cout << "re: " << re << " ";
        //     cout << "im: " << im << " " << endl;
        //     /*

        //     //([-+]?\d\.?\d?i)

        //     numVec.push_back(Complex(re, im));
        //     */
        // }

