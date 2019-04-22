#include <iostream>
#include "Stock.h"

struct StockNode
{
    Stock s;
    StockNode* prev;
    StockNode* next;
};

class StockDLL
{
    public:
        StockNode* head;
        StockNode* tail;

        StockDLL()
        {
            head = nullptr; 
            tail = nullptr;
        }

        bool isEmpty()
        {
            if(head == nullptr) return true;
            else return false;
        }

        void add(Stock s)
        {
            StockNode *newElem = new StockNode();
            newElem->s = s;
            newElem->next = nullptr;

            if(this->isEmpty())
            {
                head = newElem;
                head->prev = nullptr;
            }
            else
            {
                StockNode* it = head;
                while(it->next != nullptr)
                {
                    it = it->next;
                }

                newElem->prev=it;
                it->next = newElem;
                tail = newElem;
            }

        }

        void print()
        {
            StockNode* it = head;
            while(it != nullptr)
            {
                std::cout << it->s << std::endl;
                it = it->next;
            }
        }

        void printRev()
        {
            StockNode* it = tail;
            while(it != nullptr)
            {
                std::cout << it->s << std::endl;
                it = it->prev;
            }
        }
};

int main()
{
    StockDLL a;

    Stock g = Stock("APPL", 100);

    for(int i=0; i<100; ++i)
    {
        a.add(g);
    }

    a.printRev();
}