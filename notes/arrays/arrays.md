## C/C++ arrays useful info

## 1. Automatic array zero-initialization

You can initialize an array with a smaller set. The rest will be simply initialized with zeros.

```C++
int a[10] = {0, 1, 2, 3, 4};

for(int i=0; i<10; ++i)
{
    cout << a[i];
}
```

Will output:

```
0123400000
```

This can be useful for zero-initializing big arrays
```
int a1[1000] = {0};
```
And you got yourself an entire array of zeros!

## 2. Blank array size
You don't need to explicitly give the size of an array if you initialize it with curly braces.
```C++
int b[] = {0, 1, 2, 3, 4, 5};
cout << sizeof(b);
```
outputs:
```
24
```
which is the size of the array in bytes

## 3. Getting out of array bounds
Any compiler will be more than happy to let you get out of the array bounds
```C++
int c[] = {0, 1, 2, 3, 4};

for(int i=0; i<100; ++i)
{
    cout << c[i];
}
```
You just never know what you gonna get!

output (in my case):
```shell
012340-3001968782184901234000001516279040-954742658-20853325763263900-30019769621849280148064327640000-30019684821849-209310218532639-112-128014807232764-1121-30019743021849001792948730-774030513-30019769621849280148064327640000-1109509638-20704936681147156986-2054037246000000-208533319732639-20854654163263920647970000000-3001976962184928014806432764-3001976542184928014805632764280102801502043276400280150258327642801502803276428015029432764
```

## 4. Variable-size array

It's a slippery topic. The code below __will__ work in most cases.
The compiler will just allocate memory on stack instead of heap.

```C++
int n;
cin >> n;
int d[n];
cout << sizeof(d);
```

However it'd be easy to allocate a very large array on the stack or cause stack overflow (n can be as large as 2^31)

Even though it is valid syntax accoring to ISO C99, it is not for C++ or anything before C99. Better just not to use it.

## 5. Array indexing trick
Because ```arr[i]``` evaluates to ``` *(arr+i) ``` And addition is 
commutative you can also acces the same thing by ```i[arr]```. It's more of a fun-fact than anything useful though.

```C++
int arr[5] = {0,1,2,3,4};
for(int i=0; i<5; ++i)
{
    cout << i[arr];
    cout << arr[i];
}
```

## 6. Passing arrays as parameters
Because the name under which you declare your array is a pointer to the first element of that array, you can do the following:
```C++
int f(int* arr, int size) {
  // do array stuff
}
```

You can also do this:

```C++
int f(int arr[], int size) {
  // do array stuff
}

```
 _(some people might argue that this is more explicit request for passing an array not just any random pointer to an int)_

## 7. size_t datatype
C programming language has a handy type size_t, which we can use for numbers that we would like to use as indexes of arrays.
```C++
int f[100] = {0};
for(size_t i=0; i<100; ++i)
{
    f[i] = i;
}
```
We can check the size of size_t
```C++
cout << sizeof(size_t);
```
On my 64-bit machine it outputs:
```
8
```
as 8b=64bits