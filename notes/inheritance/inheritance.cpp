#include <iostream>

class Shape
{
    public:
        virtual void draw()=0;
        virtual double area()=0;
        void move(double x, double y){}
    private:
        void heheszki(){std::cout << "hehe";}
};

class Square : Shape
{
    public:
        void draw(){std::cout<< "drawing a Square";}
        double area(){std::cout<< "a^2";return 2.0;}
};

class Mammal
{
    public:
        int size;
        int weight;
        Mammal(int ide=666)
        {
            id = ide;
        }
    private:
        int id;

};

class Dog : private Mammal
{
    public:
        bool isFriendly;
        int breedNo;

    //how you pass parameters to default constructor
    Dog(int id, bool friendly=true, int breed=0) : Mammal(id) 
    {
        isFriendly = friendly;
        breedNo = breed;
    }
};

using namespace std;

int main()
{
    Dog rafik(123);

    // the line below is now illegal. Were that public inheritance, that'd work
    //std::cout << rafik.size;

    return 0;
}