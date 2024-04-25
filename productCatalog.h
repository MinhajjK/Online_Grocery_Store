#ifndef PRODUCTCATALOG_H
#define PRODUCTCATALOG_H
#include <string>
using namespace std;
class productCatalog {
private:
	string item[100];
	int price[100];
	string unit[100];
public:
	inline int populateItems();
	inline void viewItems(int s);
	inline void AddItems();
	inline void deleteItems();
	inline void updateItems(int s);
	inline string* getItem() { return item; }
	inline string* getUnit() { return unit; }
	int* getPrice() { return price; }
};

#endif
