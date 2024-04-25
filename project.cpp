#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <cstring>
#include "Inventory.h"
#include "Inventory.cpp"
#include "cart.h"
#include "cart.cpp"
#include "productCatalog.h"
#include "productCatalog.cpp"
#include "customerRegistration.h"
#include "user.h"
#include "custLog.h"
#include "custLog.cpp"
#include "admin.h"
#include "manager.h"
#include "manager.cpp"
#include "admin.cpp"
using namespace std;

void viewInventoryItems(Inventory, string);

int addtoCart(string sLocation, string cLocation)
{
	Cart C;
	int price = C.UserOption(sLocation, cLocation);
	return price;
}

void checkout(int amount, string storeLoc, string userLoc)
{

	int s1 = storeLoc.size();
	int s2 = userLoc.size();

	int finalAmount = amount;
	cout << "Select your checkout method: \n";
	cout << "1. Cash on Delievery\n";
	cout << "2. Debit/Credit Card\n";
	cout << "3. JazzCash\n";
	cout << "4. EasyPaisa\n";

	for (int i = 0; i < s1; i++)
	{
		storeLoc[i] = tolower(storeLoc[i]);
	}

	for (int i = 0; i < s2; i++)
	{
		userLoc[i] = tolower(userLoc[i]);
	}

	bool checkCity = true;
	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 1)
	{
		if (s1 != s2)
		{
			finalAmount = finalAmount + 50;
		}
		else if (s1 == s2)
		{
			for (int i = 0; i < s1; i++)
			{
				if (storeLoc[i] != userLoc[i])
				{
					checkCity = false;
				}
			}

			if (checkCity != false)
			{
				finalAmount = finalAmount + 30;
			}
			else
			{
				finalAmount = finalAmount + 30;
			}
		}
	}
	else
	{
		finalAmount += 0;
	}

	cout << "Your Total Bill is " << finalAmount << "\nPlease ready this amount, driver is on his way!" << endl;

}

void feedback()
{
	cin.ignore();
	string feedback, line;
	ofstream fout;
	fout.open("feedback.dat", ios::binary | ios::app);
	cout << "Enter Feedback: ";
	getline(cin, feedback);

	fout << feedback << endl;

	fout.close();
	ifstream fin;
	fin.open("feedback.dat", ios::binary);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			getline(fin, line);
			cout << line << endl;
		}
	}
}

void customerMenu(string location)
{
	Inventory I;
	string l;
	cout << "\nEnter the store of your choice: ";
	getline(cin, l);
	for (int i = 0; i < l.size(); i++)
	{
		l[i] = tolower(l[i]);
	}
	int price;
	cout << "Displaying Inventory" << endl;
	viewInventoryItems(I, l);
	system("PAUSE");
	system("cls");
	cout << "Add the items to the cart" << endl;
	price = addtoCart(l, location);
	system("PAUSE");
	system("cls");
	if (price > 0)
	{
		cout << "Checking-out" << endl;
		checkout(price, l, location);
	}
	feedback();
	system("PAUSE");
	system("cls");
}

void customerLogin(string Loc)
{
	string username, password;
	cout << "Welcome Back!" << endl;
	cout << "Enter your username: ";
	cin >> username;
	cin.ignore();
	cout << "Enter your password: ";
	getline(cin, password);

	custLog c;
	c.setUsername(username);
	c.setUserPass(password);

	string location = c.Login();
	customerMenu(location);
}

void createFile(string name, string cnic, string password, string address, int contactNo, char gender)
{
	string location = address;
	customerRegistration c;

	c.setName(name);
	c.setCnic(cnic);
	c.setAddress(address);
	c.setContact(contactNo);
	c.setGender(gender);
	c.setPassword(password);

	cout << "Your Account has been Registered!" << endl;

	ofstream fout;
	fout.open("customer" + cnic + ".dat", ios::binary);
	fout << c.getCnic() << endl;
	fout << c.getPassword() << endl;
	fout << c.getName() << endl;
	fout << c.getContact() << endl;
	fout << c.getAddress() << endl;
	fout << c.getGender() << endl;

	fout.close();
	cout << "Please log in to enter into the system: " << endl;
	system("PAUSE");
	system("cls");
	customerLogin(location);
}

void custPanel()
{
	customerRegistration c;
	system("cls");
	string name, cnic, password, address;
	int contactNo;
	char yes_no, gender;
	cout << "Welcome! Are you a new Customer? Sign up (Y/N): ";
	cin >> yes_no;
	cin.ignore();
	if (yes_no == 'Y' || yes_no == 'y')
	{
		cout << "Sign up Form!" << endl;
		cout << "Enter the following Credentials:\n ";
		cout << "Name: ";
		getline(cin, name);
		do {
			cout << "13-digit CNIC(this would be your username whenever you log in): ";
			getline(cin, cnic);
			if (cnic.length() != 13)
			{
				cout << "Invalid CNIC. Enter a 13 digit valid CNIC!" << endl;
			}
		} while (cnic.length() != 13);
		cout << "Password: ";
		getline(cin, password);
		cout << "Contact Number: ";
		cin >> contactNo;
		cin.ignore();
		cout << "Location: ";
		getline(cin, address);
		cout << "Gender: ";
		cin >> gender;
		createFile(name, cnic, password, address, contactNo, gender);
	}
	else if (yes_no == 'N' || yes_no == 'n')
	{
		cout << "Log In Form" << endl;
		customerLogin(address);
	}
}


void adminMenu(admin a)
{
	int choice;
	productCatalog p;
	cout << "Successfully Loggin in as admin!" << endl;
	system("PAUSE");
	system("cls");

	cout << "WELCOME ADMIN!" << endl;
	do {
		cout << "Select Operation: \n" << endl;
		cout << "1. Register Manager" << endl;
		cout << "2. View Product Catalog" << endl;
		cout << "3. Add Item to Product Catalog" << endl;
		cout << "4. Delete Item from Product Catalog" << endl;
		cout << "5. Update Item from Product Catalog" << endl;
		cout << "6. Log out" << endl;
		cout << "Enter Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "You selected to register a manager!" << endl;
			a.managerRegistration();
			break;
		case 2:
			cout << "You selected to view product catalog!" << endl;
			int s;
			s = p.populateItems();
			p.viewItems(s);
			break;
		case 3:
			cout << "You selected to add item to product catalog!" << endl;
			p.AddItems();
			break;
		case 4:
			cout << "You selected to delete item from product catalog!" << endl;
			p.deleteItems();
			s = p.populateItems();
			break;
		case 5:
			cout << "You selected to update item from product catalog!" << endl;
			p.updateItems(s);
			break;
		case 6:
			cout << "Logging out!" << endl;
			system("PAUSE");
			system("cls");
			break;
		default:
			cout << "Invalid option!" << endl;
			break;
		}
	} while (choice != 6);
}

void adminPanel()
{
	int choice;
	system("cls");
	string name, password;
	admin a;
	cout << "Welcome Admin!" << endl;
	cout << "Enter your credentials!\n";
	cout << "Username: ";
	getline(cin, name);
	cout << "Password: ";
	getline(cin, password);

	a.setUsername(name);
	a.setPassword(password);


	if (a.verifyAdmin())
	{
		adminMenu(a);
	}
	else
	{
		cout << "Login Failed!" << endl;
	}
}

void viewInventoryItems(Inventory in, string loc)
{
	int s = in.populateItems(loc);
	in.viewItems(s, loc);
}

void addItemsInventory(Inventory in, string loc)
{
	cin.ignore();
	bool check = 0;
	string name, unit;
	int price, quantity;
	cout << "Enter Item Name(Add '-' instead of spaces): ";
	getline(cin, name);
	do {
		if (name.find(' ') != string::npos)
		{
			cout << "Told you to not add spaces! Input name again: ";
			getline(cin, name);
		}
	} while (name.find(' ') != string::npos);

	//cin.ignore();
	cout << "Enter unit of item: ";
	cin >> unit;
	cout << "Enter Price of item: ";
	cin >> price;
	cout << "Enter quantity of item: ";
	cin >> quantity;
	in.AddItems(name, unit, price, quantity, loc);
	in.populateItems(loc);

}

void removeItemsInventory(Inventory in, string loc)
{
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
	in.deleteItems(name, loc);
	in.populateItems(loc);
}

void updateInventoryItems(Inventory in, string loc)
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
	int new_price, new_quantity;

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
			cout << "Enter new quantity: ";
			cin >> new_quantity;
			cout << "Updating the record!" << endl;
			price[i] = new_price;
			unit[i] = new_unit;
			quantity[i] = new_quantity;
		}
	}

	in.updateItems(item, unit, price, quantity, size, loc);
}

void searchInventoryItems(Inventory in, string location)
{
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
	in.searchItems(name, location);
}

void ManagerMenu(string location)
{
	Inventory I;
	system("PAUSE");
	system("cls");
	cout << "Welcome! You are manager of the store at " << location << endl;
	int choice;
	do {
		cout << "Select Operation: \n" << endl;
		cout << "1. Add Items to inventory" << endl;
		cout << "2. Remove Items from inventory" << endl;
		cout << "3. View Inventory" << endl;
		cout << "4. Search Item from inventory" << endl;
		cout << "5. Update Item from inventory" << endl;
		cout << "6. Log out" << endl;
		cout << "Enter Choice: ";
		cin >> choice;
		system("PAUSE");
		system("cls");
		switch (choice)
		{
		case 1:
			cout << "You selected to add items to inventory of store located in " << location << endl;
			addItemsInventory(I, location);
			system("PAUSE");
			system("cls");
			break;
		case 2:
			cout << "You selected to remove items from inventory of store located at " << location << endl;
			removeItemsInventory(I, location);
			system("PAUSE");
			system("cls");
			break;
		case 3:
			cout << "You decided to view the inventory list of store located at " << location << endl;
			viewInventoryItems(I, location);
			system("PAUSE");
			system("cls");
			break;
		case 4:
			cout << "You decided to search for a item in inventory list of store located at " << location << endl;
			searchInventoryItems(I, location);
			system("PAUSE");
			system("cls");
			break;
		case 5:
			cout << "You decided to update an item in inventory list of store located at " << location << endl;
			updateInventoryItems(I, location);
			system("PAUSE");
			system("cls");
			break;
		case 6:
			cout << "Logging out" << endl;
			system("PAUSE");
			system("cls");
			break;
		}
	} while (choice != 6);
}

void managerPanel()
{
	system("cls");
	int choice;
	string id, password, location;
	string corr_id, corr_pass, corr_loc;
	cout << "Hi, Manager.\nTo verify yourself, Enter Username(ID): ";
	cin >> id;
	cout << "Enter your location: ";
	cin >> location;
	for (int i = 0; i < location.size(); i++)
	{
		location[i] = tolower(location[i]);
	}
	cin.ignore();
	cout << "Enter Password: ";
	getline(cin, password);

	manager m;
	m.setID(id);
	m.setLocation(location);
	m.setPassword(password);

	string l = m.Login();
	ManagerMenu(l);
}

int main()
{
	int choice1;
	while (true)
	{
		cout << "You are: \n1. Admin\n2. Manager\n3. Customer\n";
		cout << "You identify yourself as ";
		cin >> choice1;
		cin.ignore();
		switch (choice1)
		{
		case 1:
			cout << "You identify yourself as admin!" << endl;
			system("PAUSE");
			adminPanel();
			break;
		case 2:
			cout << "You identify yourself as manager!" << endl;
			system("PAUSE");
			managerPanel();
			break;
		case 3:
			cout << "You identify yourself as customer!" << endl;
			system("PAUSE");
			custPanel();
			break;
		default:
			cout << "Invalid Input!" << endl;
			break;
		}
	}
}
