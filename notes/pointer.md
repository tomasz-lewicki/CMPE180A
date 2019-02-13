# Pointer notes & gotchas

## 0. Pointer declaration is not memory allocation

<p style="color:red">The easiest way to segfault:</p>

```C++
int* a; //this only declares a pointer
*a = 10; //here we're dereferencing a null
```
It should be instead:

```C++
int* a;
a = new int; //allocate the f-ing memory
*a = 10;
```

## 1. Arrow operator (->)

```C++
Human* tommy; //creating object of Human class with default constructor

int h = tommy->height; //is equivalent to:
int h = (*tommy).height;
```

## 2. Declaring multiple pointers

```C++
int* p, q; //p is of int* type, but q is of int type!
```

Because of that, it might be preferable to declare multiple pointers as follows:

```C++
int *p, *q; //now both p and q are of int* type;
```

## 3. Dynamic memory allocation
```C++
string *str; // str doesn't point to a valid region of memory
str = new string; // now str point somewhere reasonable
*str = "Ala ma kota"; //now *str has value
```

## 4. Passing pointers by value/reference
```C++
using namespace std;

void dummyFunc(int* &a, int* b) 
//a is passed by reference, b is passed by value
{
    cout << &a << endl; //this is the adress of the actual pointer
    cout << &b << endl; //this is the address of a copy of the actual pointer 
    cout << (a == b) << endl; //they both have the same value however
}

int main()
{
    int* a = new int;
    *a = 10;
    
    dummyFunc(a, a);
    delete a;
    return 0;
}
```

this code snippet will return:

```
0x7ffe4bf42898
0x7ffe4bf42870
1
```

## 5. Pointer arithmetic.
Arithmetic operations on pointers:
- ++ (incrementation),
- -- (decrementation),
- \+ ```int``` (integer addition)
- \- ```int``` (integer substraction)
- substraction of pointer from another pointer
integer from a pointer variable, and subtraction of a pointer from another pointer of __compatible type__ 

Pointer arithmetic works different to integer or floating-point arithmetic.

E.g. ```++``` does not increment by 1, but rather by ```sizeof(<type>)```

Pointers can be compared and assigned __witin compatible types__

## 6. Dangling pointer and memory leak

_memory leak_ - allocated memory we have no reference to. There's __unreachable__ memory

_dangling pointer_ - pointer pointing to an invalid memory location.

## 7. Return value of & operator

The return value of the & operator is pointer to a type. _(somehow I didn't realize that)_.
 
```C++
[cling]$ int i =5;
[cling]$ &i
(int *) 0x7fb97f7d1010
```