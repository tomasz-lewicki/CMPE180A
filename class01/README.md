# 1. You do need a constructor (why?).  Under what usage scenario, you don't need any.

The default constructor wouln't match ```clockType clockType(int, int, int)```. Therefore, you need another constructor to support the following syntax:

```
clockType c1(23, 59, 59);
```

# 2. But, do you really need two constructors?  Can you do it with one?

You don't need two constructors, because the following syntax support:
```
clockType c1(23, 59);
```
can be provided by using default parameters

# 3. What's the difference between supporting cout << c1 << c2; versus two separate cout?

To support chained operations you need to make sure you 

# 4. Do we need assignment operator overloading?

No, since this is a class with no dynamically allocated memory. The default assignment will do fine.