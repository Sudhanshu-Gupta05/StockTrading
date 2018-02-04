#include "Order.h"
#include <map>
#include <set>
#include <functional>
#include <iostream>
using namespace std;

class OrderBook
{
public:

	int AddOrder(char *productId, char *OrderId, int BidOrOffer, int Price) ;
	int DelOrder(char *productId, char *OrderId);
	int PrintOrders();

private:
	
	/*Container contains set of all OrderId's for each orderBook*/
	set<string> _completeOrderList; 

	/*Container contains set of Bid orders arranged in decresing order on Price */
	map<int, Order,greater<int>> _bid;

	/*Container contains set of Offer orders arranged in increasing order on Price */
	map<int, Order,less<int>> _offer;
};

