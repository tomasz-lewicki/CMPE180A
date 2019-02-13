# Classes

# 1. Constructors

**default constructor** - a constructor that doesn't take parameters (or has all default parameters).

a class can have more than one constructor. In this case constructors have to differ with either number of parameters or type of parameters.

### Calling default constructor


You can instantiate an object using with default constructor in two equivalent ways:
```C++
//calls the default constructor
clockType zegarek;
clockType zegarek2 = clockType();

```

In general non-default constructors are called as follows

```C++
//calls a non-default constructor
clockType zegarek(15, 59, 30);
```

# 2. Member functions

### Private members access
Because ```hr``` is a private member of ```clockType``` class means that you can access it from any ```clockType``` member function!
```C++
bool clockType::equalTime(const clockType& otherClock) const
{
    return (hr == otherClock.hr
            && min == otherClock.min
            && sec == otherClock.sec);
}
```

### Const modifier in function declaration
```C++
bool clockType::equalTime(const clockType& otherClock) const{
    return (hr == otherClock.hr
            && min == otherClock.min
            && sec == otherClock.sec);
}
```

By the way:
    
1. const modifier for the otherClock parameter will make it impossible to modify otherClock object through this reference.

    I.e. the following would be illegal in function's body:
    ```C++
    otherClock.hr = 10;
    ```
2. const modifier __after__ the function means that the implicit _this_ pointer will become const.

    I.e. the following statements would be illegal:
    ```C++
    this.hr = 10;
    hr = 10;
    ```

    Good explanation can be found [here](https://stackoverflow.com/questions/15999123/const-before-parameter-vs-const-after-function-name-c)


### Formal parameter list (in functions in general)

Names of formal parameters in function declaration is optional! Meaning that
```C++
clockType(int hrs=0, int min=0, int sec=0);
```
is just as good as:

```C++
clockType(int = 0, int = 0, int = 0;
```