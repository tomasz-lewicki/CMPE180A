#include <string>

#ifndef STOCK_H
#define STOCK_H

class Stock
{
    friend std::ostream& operator<<(std::ostream &out, Stock s);
    public:
        Stock();
        Stock(std::string sym, double price);
        std::string symbol;
    private:
        double price;

};
#endif