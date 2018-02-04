#include "MarketPrice.h"
#include "OrderBook.h"


class StandardMarketPrice : public MarketPrice
{
public:
	
	int OnOrderAdd(char *productId, char *OrderId, int BidOrOffer, int Price);
	int OnOrderDel(char *productId, char *OrderId);
	int Print();
	
private:	
	map<string, OrderBook> orderBookContainer;
};

