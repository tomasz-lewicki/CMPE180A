#include <string> //string
#include <iostream> //cin, cout
#include <fstream> //for LoadFromCSV
#include "Stock.h"
#include "Portfolio.h"
using namespace std;

Portfolio::Portfolio(Stock firstStock, int shares)
{
    head = new ListNode;
    head->s = firstStock;
    head->shares = shares;
    head->next = nullptr;

    length = 1;
}

Portfolio::~Portfolio()
{
    while(head != nullptr)
    {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }

}

void Portfolio::printAll()
{
    ListNode* last = head;

    while(last != nullptr)
    {
        cout << last->shares << " shares of " << last->s << endl;
        last = last->next;
    }
}

void Portfolio::add(ListNode& tail, Stock s, int shares)
{
    tail.next = new ListNode;
    tail.shares = shares;
}

size_t Portfolio::middleList(Stock* middle)
{
    ListNode* it = head;
    size_t idx=0;

    for(idx; idx<length/2; ++idx)
    {
        it = it->next;
    }

    *middle = it->s;

    return idx;
}

void Portfolio::LoadFromCSV(string filename)
{
    fstream myfile(filename);
    ListNode* last = head;

    while(myfile.good())
    {
        string data;
        myfile >> data;

        if(data.find(",") > data.length()) continue;

        //get name of the stock
        string name = data.substr(0,data.find(","));

        //get the price of the stock

        string sprice = data.substr(data.find(",")+1, data.length());
        if(sprice == "n/a") continue;

        //add a new node
        ListNode *s = new ListNode;
        s->s = Stock(name, stod(sprice));
        s->shares = 100;
        s->next = nullptr;
        ++length;
        last->next=s;
        last = s;
    }

    myfile.close();
}
