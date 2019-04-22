#Write a recursive function that deletes every element of a linked list.

```C++
del(Node* head)
{
    if(head->next == nullptr) return 0;
    del(head->next)
    delete head;
}

#Can you turn any iterative function into a recursive one? Why or why not?

Yes. 


#Should you always (if possible) implement a function recursively? Why or why not?

No. Implement recursively only if it is easier to understand and maintain.

#Write the class declaration (.h file) for a stack class

this is for dynamic stack of ints
```C++
class Stack
{
    public:
        Stack(int maxSize);
        void pop();
        void top();
        void push(int el);

    private:
        int* arr;
};
```

This is for dynamic templated stack
```C++

template<T>
class Stack
{
    public:
        Stack(size_t maxSize);
        void push(T el);
        T pop();
        T top();

    private:
        T* arr;
}

```

#DBfwd uses StockNode.  Write the minimum StockNode definition for this purpose. (hint: StockNode is a Stock)

DBfwd:
```C++
class StockNode : Stock
{
    StockNode* next;
}
```

DBlink: (doubly linked)
```C++
class StockNode : Stock
{
    StockNode* next;
    StockNode* prev;
}
```

# Write a recursive reverse_print function for DBfwd

void DBfwd::reverse_print()
{

}

void rec_f(StockNode* head)
{
    if(StockNode == nullptr) return;
    else
    {
        rec_f(head->next);
        std::cout << *head;
    }
}

