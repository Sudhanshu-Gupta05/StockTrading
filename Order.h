#include <memory>
#include<string>
#include <cstring>

//tetsing

using namespace std;

class Order {

public:	
	Order(char *ProductId, char *OrderId, int BidOrOffer, int Price) : _productId(new char[100]), _orderId(new char[100]),
		_bidOrOffer(BidOrOffer), _price(Price)
	{	
		strncpy(_productId.get(), ProductId,100);
		strncpy(_orderId.get(), OrderId, 100);
	}

	char* GetOrderID () { return _orderId.get(); }
	int GetPrice() { return _price;  }

private:
	shared_ptr<char> _productId;
	shared_ptr<char>  _orderId;
	int _bidOrOffer;
	int _price;
};