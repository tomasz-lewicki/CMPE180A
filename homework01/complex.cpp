#include <cmath> //stod
#include "complex.h"

Complex::Complex(double re, double im)
{
    this->re = re;
    this->im = im;
}

std::ostream& operator<<(std::ostream& out, const Complex& number)
{
    out << number.re;
    if(number.im >= 0) out << "+";
    out << number.im;
    out << "i";
    return out;
}

Complex Complex::operator+(const Complex& otherNumber)
{
    Complex tmp;
    
    tmp.im = im + otherNumber.im;
    tmp.re = re + otherNumber.re;

    return tmp;
}

bool Complex::operator<(const Complex& otherNumber)
{
    if(sqrt(pow(re,2)+pow(im,2)) < sqrt(pow(otherNumber.re,2) + pow(otherNumber.im,2))) return true;
    else return false;
}

bool Complex::operator==(const Complex& otherNumber)
{
    if(re == otherNumber.re && im == otherNumber.im) return true;
    else return false;
}