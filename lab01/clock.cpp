#include "clock.h"
#include <iostream>
#include <string>

// using namespace std;

clockType::clockType(int h, int m, int s)
{
    hr = h;
    min = m;
    sec = s;
}

std::ostream& operator<<(std::ostream& out, const clockType& c)
{ 
    if(c.hr<=9) out << 0;
    out << c.hr;
    out << ":";

    if(c.min<=9) out << 0;
    out << c.min;
    out << ":";

    if(c.sec<=9) out << 0;
    out << c.sec;

    return out; 
}

clockType clockType::operator+(const clockType& otherClock) const
{
    clockType tmp = *this;

    tmp.incrementHr(otherClock.hr);
    tmp.incrementMin(otherClock.min);
    tmp.incrementSec(otherClock.sec);

    return tmp;
}


void clockType::setHr(int h){hr = h;}
void clockType::setMin(int m){min = m;}
void clockType::setSec(int s){sec = s;}

void clockType::incrementHr(int h)
{
    if(hr+h > 24) setHr(hr+h-24);
    else
    {
        hr += h;
    }
}

void clockType::incrementMin(int m)
{
    if(min+m > 60)
    {
        incrementHr(1);
        incrementMin(m-60);
    }
    else
    {
        min += m;
    }
}

void clockType::incrementSec(int s)
{
    if(sec+s>60)
    {
        incrementMin(1);
        incrementSec(s-60);
    }
    else
    {
        sec += s;
    }
}

