#include <string>
#include "Stock.h"

#ifndef PORTFOLIO_H
#define PORTFOLIO_H

class ListNode
{
    public:
        ListNode* next;
        Stock s;
        int shares;
};

class Portfolio
{
    protected:
        ListNode* head;
        size_t length;
    public:
        Portfolio(Stock firstStock, int shares);
        ~Portfolio();

        size_t getSize();
        void printAll();
        void add(Stock s, int shares);
        size_t middleList(Stock* middle);
        void LoadFromCSV(std::string filename);
        void splitInHalf(Portfolio*& firstHalf, Portfolio*& secondHalf);
};

#endif