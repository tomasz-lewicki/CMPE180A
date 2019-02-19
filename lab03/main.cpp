#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include "Stock.h"
#include "Portfolio.h"
using namespace std;


int main()
{
    //create a stock priced at 420
    Stock tomsCompany("TOM", 420);

    //create a portfolio with 100 shares of first stock
    Portfolio myStocks(tomsCompany, 100);
    
    cout << "duze";
    myStocks.LoadFromCSV("companylist.csv");
    myStocks.printAll();
    cout << "cycki";

    Stock* middle = new Stock;
    cout << "middle index is: " << myStocks.middleList(middle) << endl;
    cout << "middle stock is: " << *middle << endl;

    Portfolio* firstHalf=nullptr;
    Portfolio* secondHalf=nullptr;

    myStocks.splitInHalf(firstHalf, secondHalf);

    firstHalf->printAll();
    secondHalf->printAll();

    delete middle;
    delete firstHalf;
    delete secondHalf;

}
