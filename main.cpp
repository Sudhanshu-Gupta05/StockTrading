#include "ClientMarketHolders.h"


/*Design Pattern : I have used here Builder Design Pattern
ClientMarketHolders is our Director class
MarketPrice is AbstarctBaseClass which can be extended in future and can be changed
StandardMarketPrice class is derived from MarketPrice 
OrderBook is class for each product containing Bida and offers
Order is class for placing the orders*/

int main()
{
	ClientMarketHolders start;
	StandardMarketPrice marketPrice;
	int operationResult = start.CreateMarketPrice(marketPrice);

	if (operationResult)
		return 1;
	else
		return 0;
}