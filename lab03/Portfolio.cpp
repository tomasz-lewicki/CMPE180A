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
    this->head->next = NULL;

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
    ListNode* it = head;

    while(it != nullptr)
    {
        cout << it->shares << " shares of " << it->s << endl;
        it = it->next;
    }
}

void Portfolio::add(Stock s, int shares)
{
    //get to the end
    ListNode* it = head;

    //this step results in complexity O(n) in number of nodes.
    //it could be easily avoided but keeping track of the tail of the list
    while(it->next != nullptr) it=it->next;

    it->next = new ListNode;
    it = it->next;
    it->s = s;
    it->shares = shares;
    it->next = nullptr;
    ++length;

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

size_t Portfolio::getSize()
{
    return length;
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


void Portfolio::splitInHalf(Portfolio*& firstHalf, Portfolio*& secondHalf)
{
    //this is not ideal as it allocates & frees memory on different level of abstraction
    firstHalf = new Portfolio(head->s, head->shares);

    ListNode* it = head->next;

    for(int i=0; i < length/2; ++i)
    {
        firstHalf->add(it->s, it->shares);
        it=it->next;
    }

    secondHalf = new Portfolio(it->s, it->shares);

    while(it != nullptr)
    {
        secondHalf->add(it->s, it->shares);
        it=it->next;
    }
}

