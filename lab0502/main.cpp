#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include "Stock.h"
#include "Portfolio.h"
using namespace std;

//I override the class from lab03 so I don't brake code in lab03
class PortfolioRecursive : public Portfolio
{
    public:
    PortfolioRecursive(Stock firstStock, int shares);
    void printReverse();
    static void recursivePrint(ListNode* it);
};

PortfolioRecursive::PortfolioRecursive(Stock firstStock, int shares) : Portfolio(firstStock, shares){}

void PortfolioRecursive::printReverse()
{

    ListNode* it = head;

    recursivePrint(it);
}

void PortfolioRecursive::recursivePrint(ListNode* it)
{
    if(it->next != nullptr) recursivePrint(it->next);
    cout << it->shares << " of stock named: " << it->s << endl;

}

int main()
{
    //create a stock priced at 420
    Stock tomsCompany("TOM", 420);

    //create a portfolio with 100 shares of tomsCompany stock
    PortfolioRecursive myStocks(tomsCompany, 100);
    
    myStocks.LoadFromCSV("companylist.csv");
    
    myStocks.printAll();

    myStocks.printReverse();

}
