#include <iostream>
#include <map>
#include <set>
#include <functional>
using namespace std;
// sudhanshu

class MarketPrice
{
public:
	virtual int OnOrderAdd(char *productId, char *OrderId, int BidOrOffer, int Price) = 0;
	virtual int OnOrderDel(char *productId, char *OrderId) = 0;
	virtual int Print() = 0;

};



