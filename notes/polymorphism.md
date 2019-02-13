# Polymorphism

There's a lot of different contradicting definitions of polymorphism.

Generally _poylmorphism_ means having multiple different forms.
And in C++ there several different kinds of polymorphism:

1. parametric (genericity via templates),
2. inclusion (subtyping via virtual methods),
3. function overloading (including operator overloading)
    ```C++
    //depending on the argument type, one of these two functions will be called
    int fun(int a);
    int fun(string a);
    int main()
    {
        fun("hello");
        fun(5);
    }
    ```
4. coercion (implicit conversions)
    ```C++
    double a = 5 //here we're initializing a double with an integer
    ```

There's probably a more dogmatic definition somewhere, but this works fine for me. 
