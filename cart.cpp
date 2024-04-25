#include "inventory.h"
#include "cart.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int Cart::populateItems(string loc)
{
	string val1, val2;
	int val3, val4;
	int  counter = 0;
	ifstream fin;
	fin.open(loc + "Inventory.dat", ios::binary);
	while (!fin.eof())
	{
		fin >> val1;
		item[counter] = val1;
		fin >> val2;
		fin >> val3;
		price[counter] = val3;
		fin >> val4;
		quantity[counter] = val4;
		counter++;
	}
	return counter;
}

int Cart::UserOption(string storeLoc, string userLoc)
{
	Cart c;
	Inventory I;
	int k = 0;
	string val1, val2, name;
	int val3, val4;
	string allItems[100];
	int allPrices[100];
	int allQuantity[100];
	int selectedItemsPrice[100];
	int counter = 0;
	char ch;
	ifstream fin;
	fin.open(storeLoc + "Inventory.dat", ios::binary);
	while (!fin.eof())
	{
		fin >> val1;
		allItems[counter] = val1;
		fin >> val2;
		fin >> val3;
		allPrices[counter] = val3;
		fin >> val4;
		allQuantity[counter] = val4;
		counter++;
	}
	cout << "Items Available are!\n";
	cout << "Name\tPrice\tQuantity\n";
	for (int i = 0; i < counter - 1; i++)
	{
		cout << allItems[i] << "(Rs." << allPrices[i] << ")//" << allQuantity[i] << endl;
	}
	do
	{
		cout << "\nDo you want to buy something(Y/n): ";
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			cin.ignore();
			cout << "Enter Item Name(Add '-' instead of spaces): ";
			getline(cin, name);
			do {
				if (name.find(' ') != string::npos)
				{
					cout << "Told you to not add spaces! Input name again: ";
					getline(cin, name);
				}
			} while (name.find(' ') != string::npos);

			for (int i = 0; i < counter; i++)
			{
				if (allItems[i] == name)
				{
					if (allQuantity[i] > 0)
					{
						int q;
						cout << "Quantity: ";
						cin >> q;
						selectedItemsPrice[k] = (allPrices[i] * q);
						c.updateInventory(I, q, storeLoc, allItems[i]);
						k++;
					}
					else if (allQuantity[i] <= 0)
					{
						cout << "Not Available!" << endl;
					}
				}
			}
		}
	} while (ch == 'Y' || ch == 'y');

	int totalPrice = 0;
	for (int i = 0; i < k; i++)
	{
		//cout << selectedItemsPrice[i] << " ";
		totalPrice += selectedItemsPrice[i];
	}

	return totalPrice;
}

void Cart::updateInventory(Inventory in, int q, string loc, string name)
{
	int size = in.populateItems(loc);
	string* item;
	string* unit;
	int* price;
	int* quantity;

	item = in.getItem();
	unit = in.getUnit();
	price = in.getPrice();
	quantity = in.getQuantity();

	cin.ignore();
	do {
		if (name.find(' ') != string::npos)
		{
			cout << "Told you to not add spaces! Input name again: ";
			getline(cin, name);
		}
	} while (name.find(' ') != string::npos);

	string new_unit;
	int new_price, new_quantity;

	for (int i = 0; i < size - 1; i++)
	{
		int exists = 1;
		exists = name.compare(item[i]);
		if (exists == 0)
		{
			quantity[i] = quantity[i] - q;
		}
	}
	in.updateItems(item, unit, price, quantity, size, loc);
}
