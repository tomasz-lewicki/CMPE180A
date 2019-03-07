#include "complex.h"
#include <random>
#include <algorithm> //max
#include <cstdlib>
#include <iostream>

#define SIZE 30

Complex findMaxRecursive(Complex arr[], size_t n)
{
    if(n==1) return arr[0];
    else
    {
        Complex k = findMaxRecursive(arr, n-1);
        if(arr[n] > k) return arr[n];
        else return k;
    }
}

int main()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1.0, 10.0);
        
    Complex arr[SIZE];

    for(int i=0;i<SIZE;++i)
    {
        arr[i] = Complex(dist(mt), dist(mt));
    }

    std::cout << findMaxRecursive(arr, SIZE) << std::endl;
    std::cout << "is the biggest number in this array:" << std::endl;
    for(int i=0; i<SIZE; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}
