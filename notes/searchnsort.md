# Searching and sorting

# Sequential search

```C++
int seqSearch(T arr[], T what)
{
    int i =0;
    for(i; i<100; ++i)
    {
        if(arr[i] == what) return i;
    }
    return i;
}
```

# Binary search

```C++
int binSearch(T arr[], T key, int start, int end)
{
    if(start < end)
    {
        int mid = start + (end - start)/2;
        if(arr[mid] == key) return mid;
        if(key < arr[mid]) return binSearch(arr, key, start, mid);
        if(key > arr[mid]) return binSearch(arr, key, mid, end);
    }else return -1;
}
```

# Hashing

For example, for a string it could be (sum of ASCII characters)%HTSize.
Simplest hashing function: idx = sum % HTSize;

You can handle collisions by trying idx = (sum++) % HTSize (basically just try the next one);
You can also chain collisions in a linked lists to whom HT elements point.

# Selection sort

Find the smallest, move to arr[0],
Find the second smallest, move to arr[1],
Find the third smallest, move to arr [2],
etc.

# Insertion sort

Finds the first out of order element and moves it to the right place.
Has to move the entire array up when doing so`