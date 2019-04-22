
#Recursive solution

```C++
    f(n,A,C,Temp) // move n from A to C
    {
        if (n==0) return;

        f (n-1, A, Temp, C);  // move n-1 from A to Temp

        move the only remaining disc from A to C;

        f (n-1, Temp, C, A);  // move n-1 from Temp to C

    }

```

