# Sorting

- for selection sort and bubble sort sort only the unsorted parts
- beware of ```a[i]>a[i+1]``` (iterate to ```n-1```)

# Dynamic arrays
- keep size! (independently from ```max_size```)

# Pointers
- a is const here!
```C++
int a = new int(5) {11,22,33,44,55};
```

# Declaration/definition

When Frank asks about .cpp file don't forget to add scope resolution to function name.

# Operator overloading

Stacking
```C++

cout << c1 << c2;
//leaves 
friend ostream& operator<<(ostream& os, const complexType& cplx);
//
friend ostream operator<<(ostream& os, const complexType& cplx);
```