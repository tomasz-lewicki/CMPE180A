#include "OwnStack.h"

template<class T>
Stack<T>::Stack(int maxSize)
{
    this->arr = new T[maxSize];
    this->size = 0;
    this->maxSize = maxSize;
}

template<class T>
Stack<T>::~Stack()
{
    delete[] arr;
}

template<class T>
bool Stack<T>::empty()
{
    if(size == 0) return true;
    else return false;
}

template<class T>
void Stack<T>::push(T item)
{
    if(size == maxSize) throw 1; //stack is full
    else arr[size++] = item;
}

template<class T>
void Stack<T>::pop()
{
    if(size == 0) throw 1; //cannot pop from an empty stack
    else size--;
}

template<class T>
T Stack<T>::top()
{
    if(size == 0) throw 1; //Cannot check top of an empty stack
    else return arr[size-1];
}