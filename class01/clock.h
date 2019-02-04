#include <iostream>

class clockType
{
    public:
        clockType(int h=0, int m=0, int s=0);
        clockType operator+(const clockType& otherClock) const;

    private:
        unsigned int hr;
        unsigned int min;
        unsigned int sec;
        
        void incrementHr(int h);
        void incrementMin(int m);
        void incrementSec(int s);

        void setHr(int h);
        void setMin(int m);
        void setSec(int s);

    friend std::ostream& operator<<(std::ostream& out, const clockType& c);
};