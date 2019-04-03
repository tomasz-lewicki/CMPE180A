#include <iostream>
#include "IntArray.h"

IntArray::IntArray(size_t max_size)
    {
        this->max_size = max_size;
        arr = new int[max_size];
    }

IntArray::~IntArray()
{
    delete[] arr;
}

void IntArray::print()
{
    for(size_t i=0; i<curr_size; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}

int IntArray::insertAt(size_t idx, int value)
{
    if(curr_size++ == max_size) return 1;
    if(idx > curr_size) return 2;
    else
    {
        for(size_t i=curr_size-1; i!=idx; --i)
        {
            arr[i] = arr[i-1];
        }

        arr[idx] = value;
    }
    return 0;
}

int IntArray::deleteAt(size_t idx)
{
    if(idx >= max_size) return 1;
    else
    {
        for(size_t i=idx; i<max_size; ++i)
        {
            arr[i] = arr[i+1];
        }
        curr_size--;
    }
}