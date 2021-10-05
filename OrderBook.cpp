#include "OrderBook.h"

//sudhanshu


int OrderBook::AddOrder(char *productId, char *OrderId, const int BidOrOffer, int Price)
{
	Order newOrder(productId, OrderId, BidOrOffer, Price);
	string orderIDStr(OrderId);

	switch (BidOrOffer)
	{
	case 1:
		if (_bid.find(Price) != _bid.end())
		{
			cout << "Order of same price cannot be placed " << endl;
			return 0;
		}
		_bid.insert(pair<int, Order>(Price, newOrder));
		_completeOrderList.insert(orderIDStr);
		break;
	case 2:
		if (_offer.find(Price) != _offer.end())
		{
			cout << "Order of same price cannot be placed " << endl;
			return 0;
		}
		_offer.insert(pair<int, Order>(Price, newOrder));
		_completeOrderList.insert(orderIDStr);
		break;
	default:
		return 0;
	}
	return 1;
}

// sudhanshu
// testing

void eraseBidContainer(map<int, Order, greater<int>> &order, char *OrderId)
{
	map<int, Order>::iterator itr;
	for (itr = order.begin(); itr != order.end();)
	{
		if (strcmp(itr->second.GetOrderID(), OrderId) == 0)
		{
			order.erase(itr++);
		}
		else
		{
			++itr;
		}
	}
}

void eraseOfferContainer(map<int, Order> &order, char *OrderId)
{
	map<int, Order>::iterator itr;
	for (itr = order.begin(); itr != order.end();)
	{
		if (strcmp(itr->second.GetOrderID(), OrderId) == 0)
		{
			order.erase(itr++);
		}
		else
		{
			++itr;
		}
	}
}

int OrderBook::DelOrder(char *productId, char *OrderId)
{
	string orederIDStr(OrderId);
	if (_completeOrderList.find(orederIDStr) != _completeOrderList.end())
	{
		_completeOrderList.erase(orederIDStr);
		eraseBidContainer(_bid, OrderId);
		eraseOfferContainer(_offer, OrderId);
		return 1;
	}

	return 0;
}

int OrderBook::PrintOrders()
{
	cout << "Buy" << endl;
	for (auto &elem : _bid)
	{
		cout << elem.second.GetOrderID() << " " << elem.first << endl;
	}
	cout << "Sell" << endl;
	for (auto &elem : _offer)
	{
		cout << elem.second.GetOrderID() << " " << elem.first << endl;
	}

	return 1;
}