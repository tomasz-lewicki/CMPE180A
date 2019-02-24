# Member vs non-member (friend) functions 


## Member

```C++
s1 + s2
//gets translated into
s1.operator+(s2)
```

This won't work if s1 is a primitive data type

You **have to** declare overloaded operator as:
- **nonmember function** if the letfmost operand is of:
    + primitive type (```2.0 + complexTypeObj```)
    + type that we don't want to modify (``` cin >> complexTypeObj```)
- ```friend``` function whenever you want a nonmember function access private members
- member function for *assignment* (=), *subscript* ([]), *function call* (()), and *member selection* (->) operators

Misc notes:
- ```friend``` is a not allowed outside class declaration. (Compiler wouldn't know a friend to which function it is)
- member functions will have scope resolution in front of them in the implementation file (.cpp)
```C++
Complex Complex::operator+(...)
```