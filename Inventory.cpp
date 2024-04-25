#include "Inventory.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int Inventory::populateItems(string loc)
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
		unit[counter] = val2;
		fin >> val3;
		price[counter] = val3;
		fin >> val4;
		quantity[counter] = val4;
		counter++;
	}
	return counter;
}

void Inventory::viewItems(int counter, string l)
{
	cout << "Inventory of store at " << l << ": " << endl;
	cout << "Name\t\tUnit\t\tPrice\t\tQuantity" << endl;
	for (int i = 0; i < counter - 1; i++)
	{
		cout << item[i] << "\t\t" << unit[i] << "\t\t" << price[i] << "\t\t" << quantity[i] << endl;
	}
}

void Inventory::AddItems(string n, string u, int p, int q, string loc)
{
	ofstream fout;
	fout.open(loc + "Inventory.dat", ios::app | ios::binary);
	fout << "\n" << n << "\t" << u << "\t" << p << "\t" << q << endl;
	system("PAUSE");
	system("cls");
}

void Inventory::deleteItems(string name, string loc)
{
	ifstream read;
	read.open(loc + "Inventory.dat", ios::binary);
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
	string filename = loc + "Inventory.dat";
	remove(filename.c_str());
	rename("tmp.dat", filename.c_str());
	cout << "Item Deleted!" << endl;
	system("PAUSE");
	system("cls");
}

void Inventory::updateItems(string* item, string* unit, int* price, int* quantity, int size, string loc)
{
	ofstream fout;
	fout.open(loc + "Inventory.dat", ios::binary);
	for (int i = 0; i < size - 1; i++)
	{
		fout << item[i] << "\t" << unit[i] << "\t" << price[i] << "\t" << quantity[i] << endl;
	}
	string filename = loc + "Inventory.dat";
	remove(filename.c_str());
	fout.close();
	int c = rename("test.dat", filename.c_str());
	cout << "Items Updated!" << endl;

}

void Inventory::searchItems(string name, string loc)
{
	ifstream read;
	read.open(loc + "Inventory.dat", ios::binary);
	if (read.is_open())
	{
		string line;
		while (getline(read, line))
		{
			if (line.find(name) != string::npos)
			{
				cout << "Name\tUnit\tPrice\tQuantity\n";
				cout << line << endl;
			}
			else
			{
				cout << "Item not found in the List!" << endl;
				break;
			}
		}
	}
}
