# Inheritance & polymorphism

# 1. Inheritance and access modifiers

## Access to members with different modifiers (in general)
|Access         |public |protected  |private    |
|---	        |---	|---	    |---	    |
|Same class     |yes   	|yes   	    |yes   	    |
|Derived classes|yes   	|yes   	    |no   	    |
|outside classes|yes   	|no 	    |no   	    |

## What is inherited
Here's a good explanation:

![](https://www.bogotobogo.com/cplusplus/images/private_inheritance/class_inheritance_diagram.png)

source: https://www.bogotobogo.com/cplusplus/private_inheritance.php

A derived class inherits all non-private base class methods with the following exceptions:

1. Constructors, destructors and copy constructors of the base class.

2. Overloaded operators of the base class.

3. The friend functions of the base class.


# 2. Virtual functions

Virtual functions need to be used whenever the function is going to be overridden in the derived class.

Otherwise - in this case:

```C++
class Base
{
    public:
        void print();
        ~Base();
};

class Derived : public Base
{
    public:
        void print() //there's also print() in Base
        ~Derived(); // here we'll delete p
    private:
        int* p;
};
```

The following function will use Base's print due to static, compile-time function binding.
```C++
printFromObject(Base &obj)
{
    obj.print(); //<-- this is actually void Base::print()
}
```

If we want it to use dynamic runtime function binding, we have to declare the print function in Base as:

```c++
public:
    virtual void print();
    virtual ~Base();
```

If you have any dynamically allocated stuff in the Derived class, the Base class destructor also has to be virtual!

# 3. Abstract classes

__Abstract classes__ are the ones with one or more __pure virtual functions__.

__pure virtual function__ - function that has to be overriden in Derived class if it's not abstract. Their existence in class prevents from instantiating the class.

A good example of this concept is class shape:

```C++
class Shape
{
    public:
        void draw(){}
        void move(double x, double y){}
        double area(){}
};
```

Right now you could instantiate this class without a problem.
Would it make any sense? Certainly not.

Because Shape is an _abstract_ concept it is not meant to be instantiated directly. Thus, we will skip Shape's definition and settle for the follwing declaration:

```C++
class Shape
{
    public:
        void draw()=0;
        void move(double x, double y)=0;
        double area()=0;
};
```

Now, in order to instantiate a derived class of Shape, we need to override **all** of the virtual functions.

# 4. Constructors

Base class constructor is always implicitly executed before the Derived class constructor.

We can pass arguments to Base class constructor using the following synax:

```
Derived::Derived(int par1, int par2) : Base(par1)
{
    x = par1;
}
```