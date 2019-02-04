# Lab 1: Refresh IDE and C++


## Overview
Use Eclipse to create a clockType with hr, min, sec as private members.  
You shall have 3 files: clock.h clock.cpp and lab1main.cpp

lab1main.cpp shall support the following statements:

```C++
clockType c1(15, 45, 30), c2(3, 20);  // hour, min, sec
cout << c1;   // add whatever to beautify it
cout << c2;
cout << c1+c2;
c2 = c1+c1;
cout << c2;
```

### Input Format: 

```text
none
```

### Output Format:

```
Enhance the sample main and display the output accordingly.
```

### Note: 

You do need a constructor (why?).  Under what usage scenario, you don't need any.
But, do you really need two constructors?  Can you do it with one?
What's the difference between supporting cout << c1 << c2; versus two separate cout?
Do we need assignment operator overloading?
There are many sample code out there.  Try to get "minimum" to support your user functionalities.  By doing so, you will get better understanding of object programming.

### Homework: 

Read in a file (complex.txt) which has a number of complex numbers in the form of a+bi (e.g. 3+5i  2-3i etc).  

Create a complex class to store data
Input each line in complex.txt(one complex object per line)
Output all complex objects to an output file named "complexObj.txt"
Compute sum of all complex objects by overloading + operator and save value into result object
Append the result object to the end of "complexObj.txt"
Turn in a .zip file containing:

main.cpp
complex.cpp
complex.h
output file named "complexObj.txt"
Files should be in a runnable state.

#### Note: If the complex.txt file is too complex for you, you can change it a bit (e.g. take out the dummy line) to get your program going.