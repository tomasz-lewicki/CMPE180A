#include "Stock.h"
#include <string>
#include <ostream>

using namespace std;

Stock::Stock(string sym, double pri)
{
    symbol = sym;
    price = pri;
}

Stock::Stock()
{

}
ostream& operator<<(ostream &out, Stock s)
{
    out << s.symbol;
    out << " stock priced at: " << s.price;
    return out;
}