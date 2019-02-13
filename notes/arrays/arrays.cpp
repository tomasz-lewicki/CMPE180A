#include <iostream>
using namespace std;
void fun1(int* arr, int size)
{
    for(int i=0; i<size; ++i)
    {
    cout << arr[i];
    }
}

void fun2(int arr[], int size)
{
    for(int i=0; i<size; ++i)
    {
    cout << arr[i];
    }
}

int main()
{
    //1.
    // int a[10] = {0, 1, 2, 3, 4};
    // for(int i=0; i<10; ++i)
    // {
    //     cout << a[i]; 
    // }
    // cout << endl;

    //2.
    // int b[] = {0, 1, 2, 3, 4, 5};
    // cout << sizeof(b);


    //3.
    // int c[] = {0, 1, 2, 3, 4};

    // for(int i=0; i<100; ++i)
    // {
    //     cout << c[i];
    // }


    //4.
    // int n;
    // cin >> n;
    // int d[n];
    // cout << sizeof(d);

    //5.
    // int arr[5] = {0,1,2,3,4};
    // for(int i=0; i<5; ++i)
    // {
    //     cout << i[arr];
    //     cout << arr[i];
    // }

    //6.
    // fun1(arr, 5);
    // cout << endl;
    // fun2(arr, 5);

    //7.
    int f[100] = {0};
    for(size_t i=0; i<100; ++i)
    {
        f[i] = i;
    }
    cout << sizeof(size_t);

    return EXIT_SUCCESS;
}