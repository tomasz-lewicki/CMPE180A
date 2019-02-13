# Assignment operator and copy constructor overriding
Both assignment operator and copy constructors are constructs that allow avoiding shallow copying of class members whenever that's not what we want to achieve.

Generally, in classes with pointer type members we would do the following:
- override assignment operator
- override default copy constructor
- create a destructor 

# Assignment operator 

We use them because in the following scenario:
```c++
class Car
{
    private:
        Engine* engine;
    public:
        void turnRight();
        void turnLeft();
        Car();
};
int main()
{
    Car car2 = car1;
}
```

We would end up with those two cars sharing an engine.


# Copy constructor

General syntax for a copy constructor:
```C++
className(const className& otherObject);
```

## When it's used
Copy constructor is available by default on any object and is executed in the following situations:

- object is initialized by the value of another object, e.g.
```C++
Car car1(car2);
```
- when object is passed by value (rather than by refernece to a function)

```C++
void pimpMyRide(Car car1); //well, pimp the copy of my ride then...
```

- when the return value of a function is an object (rather than a reference)
```C++
Car createARide()
{
    Car tmp;
    return tmp;
}
```