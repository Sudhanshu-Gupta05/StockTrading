#include "StandardMarketPrice.h"
#include <string>

typedef map<string, OrderBook>::iterator  OrderBookIterator;


int StandardMarketPrice::OnOrderAdd(char *productId, char *OrderId, int BidOrOffer, int Price)
{
	//Create new OrderBook if newProductID is entered in system else place order in existing orderBook
	OrderBook newOrderBook;	
	string productIdStr(productId);
	OrderBookIterator iterPostion = orderBookContainer.find(productIdStr);
	if (iterPostion == orderBookContainer.end())
	{
		//NewOrderBook Created
		newOrderBook.AddOrder(productId, OrderId, BidOrOffer,Price);
		orderBookContainer.insert(pair<string, OrderBook>(productIdStr, newOrderBook));
		return 1;
	}

	else
	{
		//Order is added in Existing OrderBook
		(*iterPostion).second.AddOrder(productId, OrderId, BidOrOffer, Price);
		return 1;
	}
	return 0;		
}

int StandardMarketPrice::OnOrderDel(char *productId, char *OrderId)
{
	string productIdStr(productId);
	//Check if productID exist in system
	OrderBookIterator iterPostion = orderBookContainer.find(productIdStr);
	if (iterPostion != orderBookContainer.end())
	{
		//Delete order entered if exist
		(*iterPostion).second.DelOrder(productId, OrderId);
		return 1;
	}
	return 0;
}

int StandardMarketPrice::Print()
{
	for (auto &obj : orderBookContainer)
	{
		cout << obj.first << " : " << endl;
		obj.second.PrintOrders();
		cout << endl;
	}
	return 1;
}