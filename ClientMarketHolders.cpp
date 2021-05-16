#include "ClientMarketHolders.h"

int ClientMarketHolders::CreateMarketPrice(MarketPrice &marketOrder)
{
	int operationResult = 0;
	int menu = 1;
	int userChoice;
	//Refine this code
	while (menu)
	{
		cout << endl;
		cout << "1 : To enter a new Bid or Offer in the system." << endl;
		cout << "2:  To delete an existing order present in the orderbook" << endl;
		cout << "3:  To print all the bid and offer orders present in the orderbook for all products." << endl;
		cout << "Enter your choice to perform valid operation : ";
		cin >> userChoice;

		switch (userChoice)
		{

		case 1:
			char productID[100];
			char orderID[100];
			int bidOrOffer;
			int price;
			cout << endl;
			cout << "Enter Product ID :";
			cin >> productID;
			cout << "Enter Order ID : ";
			cin >> orderID;
			cout << "Enter 1:To Bid 2:offer :";
			cin >> bidOrOffer;
			cout << "Enter the price:";
			cin >> price;
			operationResult = marketOrder.OnOrderAdd(productID, orderID, bidOrOffer, price);
			break;
		case 2:
			char delProductID[100];
			char delOrderID[100];
			cout << endl;
			cout << "Enter Product ID :";
			cin >> delProductID;
			cout << "Enter Order ID : ";
			cin >> delOrderID;
			operationResult = marketOrder.OnOrderDel(delProductID, delOrderID);
			break;
		case 3:
			operationResult = marketOrder.Print();
			break;
		default:
			operationResult = 0;
		}

		if (operationResult == 0)
		{
			cout << "Desired operation could not succeed" << endl;			
		}

		cout << " Do you wish to perform any further operation: (1:Yes 0:No) :";
		cin >> menu;

	}

	return operationResult;

}
