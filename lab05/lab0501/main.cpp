#include "complex.h"
#include <random>
#include <algorithm> //max
#include <cstdlib>
#include <iostream>

#define SIZE 100

Complex findMaxRecursive(Complex arr[], size_t n)
{
    if(n==1) return arr[0];
    else
    {
        Complex maxOfTheRest = findMaxRecursive(arr, n-1);
        if(arr[n] > maxOfTheRest) return arr[n];
        else return maxOfTheRest;
    }
}

int main()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(-10.0, 10.0);
        
    Complex arr[SIZE];

    for(int i=0;i<SIZE;++i)
    {
        arr[i] = Complex(dist(mt), dist(mt));
    }

    for(int i=0; i<SIZE; ++i)
    {
        std::cout << arr[i] << std::endl;
    }

    std::cout << "The biggest complex number in the array above:" << std::endl;

    std::cout << findMaxRecursive(arr, SIZE) << std::endl;

}
