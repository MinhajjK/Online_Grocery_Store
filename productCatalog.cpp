#include "productCatalog.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int productCatalog::populateItems()
{
	string val1, val2, line;
	int val3;
	int  counter = 0;
	ifstream fin;
	fin.open("items.dat", ios::binary);
	while (!fin.eof())
	{
		fin >> val1;
		item[counter] = val1;
		fin >> val2;
		unit[counter] = val2;
		fin >> val3;
		price[counter] = val3;
		counter++;
	}

	return counter;
}

void productCatalog::viewItems(int counter)
{
	cout << "Name(Unit)//Price" << endl;
	for (int i = 0; i < counter - 1; i++)
	{
		cout << item[i] << "(" << unit[i] << ") //Rs." << price[i] << endl;
	}

	system("PAUSE");
	system("cls");
}

void productCatalog::AddItems()
{
	cin.ignore();
	bool check = 0;
	string name, unit;
	int price;
	cout << "Enter Item Name(Add '-' instead of spaces): ";
	getline(cin, name);
	do {
		if (name.find(' ') != string::npos)
		{
			cout << "Told you to not add spaces! Input name again: ";
			getline(cin, name);
		}
	} while (name.find(' ') != string::npos);

	cout << "Enter unit of item: ";
	cin >> unit;
	cout << "Enter Price of item: ";
	cin >> price;

	ofstream fout;
	fout.open("items.dat", ios::app | ios::binary);
	fout << name << "\t" << unit << "\t" << price << endl;
	cout << "Item Added Successfully!" << endl;
	system("PAUSE");
	system("cls");
}

void productCatalog::deleteItems()
{
	string name;
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

	ifstream read("items.dat", ios::binary);
	ofstream write("tmp.dat", ios::binary);
	if (read.is_open())
	{
		string line;
		while (getline(read, line))
		{
			if (line.find(name) == string::npos)
				write << line << endl;
		}
	}
	else
	{
		cout << "Error: coudn't open file\n";
	}
	read.close();
	write.close();
	remove("items.dat");
	rename("tmp.dat", "items.dat");
	cout << "Item Deleted!" << endl;
	system("PAUSE");
	system("cls");
}

void productCatalog::updateItems(int size)
{
	populateItems();
	string* item;
	string* unit;
	int* price;

	item = getItem();
	unit = getUnit();
	price = getPrice();

	cin.ignore();
	string name;
	cout << "Enter Item Name(Add '-' instead of spaces): ";
	getline(cin, name);
	do {
		if (name.find(' ') != string::npos)
		{
			cout << "Told you to not add spaces! Input name again: ";
			getline(cin, name);
		}
	} while (name.find(' ') != string::npos);

	string new_unit;
	int new_price;

	for (int i = 0; i < size - 1; i++)
	{
		int exists = 1;
		exists = name.compare(item[i]);
		if (exists == 0)
		{
			cout << "Item does Exists! ";
			cout << "Enter new unit: ";
			cin >> new_unit;
			cout << "Enter New Price: ";
			cin >> new_price;
			cout << "Updating the record!" << endl;
			price[i] = new_price;
			unit[i] = new_unit;
		}
	}
	ofstream fout;
	fout.open("test.dat", ios::binary);
	for (int i = 0; i < size - 1; i++)
	{
		fout << item[i] << "\t" << unit[i] << "\t" << price[i] << endl;
	}
	remove("items.dat");
	fout.close();
	int c = rename("test.dat", "items.dat");
	if (c == -1)
	{
		cout << "File Error!" << endl;
	}
	cout << "Items Updated!" << endl;
	system("PAUSE");
	system("cls");
}
