#ifndef CART_H
#define CART_H
#include "Inventory.h"
#include <string>
using namespace std;
class Cart {
private:
	string item[100];
	int price[100];
	int quantity[100];
	string userItems[100];
	string userPrice[100];
	string userQuantity[100];
public:
	inline int populateItems(string l);
	inline int UserOption(string sl, string ul);

	inline void updateInventory(Inventory , int, string, string);
	inline string* getItem() { return item; }
	inline int* getPrice() { return price; }
	inline int* getQuantity() { return quantity; }
	inline int totalPrice(int* p);
};

#endif

