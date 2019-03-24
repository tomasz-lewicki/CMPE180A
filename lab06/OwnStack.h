#ifndef OWNSTACK_H
#define OWNSTACK_H

template <class T>
class Stack
{
    
    public:
        Stack();
        Stack(int maxSize);
        ~Stack();
        void pop();
        void push(T item);
        T top();

    private:
        int size;
        int maxSize;
        T* arr;
    
};


#endif
