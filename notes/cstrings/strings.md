# C string gotchas

##1. == operator

```C
char char1[] = "The same";
char char2[] = "The same";
printf("%d", schar1 == char2);

```

would return 0.
== operator compares the pointers, not the content of the string you have to do:

```C
#include <string.h>
result = strcmp(char1, char2);
printf("%d", result);
```

##2. const char *
This is a non-mutable type and shall be used with strings in C.
The rationale behind this is that in a function declaration:
```C
compareStrings(const char* a, const char* b);
```

We explicitly include a promise that the function will not attempt to modify parameters.

##3. String conversion
You cannot implicitly convert stuff (e.g. string to int) with an assignment operator, because:
-string is an array of chars (1byte per cell, unknown length)
-int is usually 4 or 8 byte data type

