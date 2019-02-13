# Const qualifier

```C++
int a = 10;
int b = 50;
const int *p = &a;
```

const int* is a pointer to a const int rather than a constant pointer to int. (see below for that)
Therefore:
1. the value of a can change through a different refrence
```C++
a = 15;
```

2. pointer p can be reassigned to a different address
```C++
p = &b;
cout << *p << endl;
```

out: ```50```

This is how you could make a constant pointer to a
```C++
int * const q = &a;
//q = &b; would be then illegal
```

And this is how you would make a constant pointer to a constant value

```C++
const int * const r = &a;
//*r = 50; would be illegal, hovever
```
//you can still change the value, simply not by this const reference.

```C++
a = 60;
cout << *r << endl;
```

output:

```
60
```

Note: const generally binds to the left (except when it has nothing to bind to on the left).

The following comes from:
https://en.wikipedia.org/wiki/Const_(computer_programming)#C++_convention

Thus, everything to the left of the star can be identified as the pointee type and everything to the right of the star are the pointer properties. For instance, in our example above, 
```C++
int const *c
```
can be read as a writable pointer that refers to a non-writable integer, and 
```c++
int * const
```
 can be read as a non-writable pointer that refers to a writable integer.

# Const keyword in return type

Const in return type decides of the type of the intermediate value

```C++
const CarType& CarType::operator=(const CarType& otherCarObject)
{
    param = otherCarObject.param; //etc.
    return *this;
}
```
In this case we could:
1. return value (```CarType```)
    - return stuff to a temporary object
    - calls copy constructor (possibly expensive)
2. return reference (```CarType&```)
    - returns a reference to the actual object
    - This is what you should return from some unary oprators like prefix ++ and --, and * (dereference) as you usually want to have the ability to modify returned object. [(from stackoverflow)](https://stackoverflow.com/questions/21778045/c-return-value-reference-const-reference)

    - permits doing funky stuff like below (assuming all those functions return ```*this```)
        ```C++
        car.run().turnRight().turnLeft().stop()
        
        ```
    - doesn't support chain assignment

3. return const reference as in the example
    - returns a const reference to the actual object (```CarType& ```)
    - supports chain assignment (hence usually it is used as the return type of ```operator=```)
        ```C++
        car1 = car2 = car3;
        ```
    - prevents stuff like in 2.