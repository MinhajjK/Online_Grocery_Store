#ifndef Inventory_H
#define Inventory_H

#include<string>
using namespace std;

class Inventory {
private:
	string item[100];
	int price[100];
	string unit[100];
	int quantity[100];
public:
	inline int populateItems(string l);
	inline void viewItems(int size, string l);
	inline void AddItems(string n, string u, int p, int q, string l);
	inline void deleteItems(string n, string l);
	inline void updateItems(string* i, string* u, int* p, int* q, int s, string loc);
	inline void searchItems(string n, string loc);
	inline string* getItem() { return item; }
	inline string* getUnit() { return unit; }
	inline int* getPrice() { return price; }
	inline int* getQuantity() { return quantity; }
};

#endif
