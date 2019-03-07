#include <iostream>
//1.Create a datatype for complex numbers
#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
    friend std::ostream& operator<<(std::ostream& out, const Complex& number);

    public:
        Complex(double re=0, double im=0);
        Complex operator+(const Complex& otherNumber);
        bool operator<(const Complex& otherNumber);
        bool operator>(const Complex& otherNumber);
        bool operator==(const Complex& otherNumber);

    private:
        double re;
        double im;
};

#endif 