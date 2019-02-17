#ifndef COMPLEXDB_H
#define COMPLEXDB_H

#include <vector>
#include <string>
#include <regex>
#include "complex.h"

using namespace std;

class ComplexDB
{
    public:
        ComplexDB();
        int loadOne(string line);
        void load(string filename);
        void saveToFile(string filename) const;
        void add(Complex num);
        void list() const;

    private:
        vector<Complex> numVec;
        vector<Complex>* getSortedVector() const;
        regex real_regex;
        regex imag_regex;

};
#endif