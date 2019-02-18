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
    private:
        ListNode* head;
        size_t length;
    public:
        Portfolio(Stock firstStock, int shares);
        ~Portfolio();

        void printAll();
        void add(ListNode& tail, Stock s, int shares);
        size_t middleList(Stock* middle);
        void LoadFromCSV(std::string filename);
};

#endif