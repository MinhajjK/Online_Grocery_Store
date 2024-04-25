#include "admin.h"
#include "manager.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool admin::verifyAdmin()
{
	bool success = 0;
	string correct_u, correct_pass;
	ifstream read;
	read.open("admin_info.dat", ios::binary);
	read >> correct_u;
	read >> correct_pass;

	int userCheck, passCheck;
	userCheck = username.compare(correct_u);
	passCheck = password.compare(correct_pass);

	if (userCheck == 0 && passCheck == 0)
	{
		success = 1;
		return success;
	}
	else
	{
		return success;
	}
}

void admin::managerRegistration()
{
	string id;
	string loc;
	string pass;
	manager m;
	cout << "Enter ID: ";
	cin >> id;
	cin.ignore();
	cout << "Enter Location: ";
	getline(cin, loc);
	cout << "Enter Password: ";
	getline(cin, pass);

	m.setID(id);
	m.setLocation(loc);
	m.setPassword(pass);

	ofstream fout;
	fout.open("manager" + id + ".dat", ios::binary);
	if (fout.is_open())
	{
		fout << m.getID() << endl << m.getPassword() << endl << m.getLocation() << endl;
		cout << "Manager Registered Successfully!" << endl;
		system("PAUSE");
		system("cls");
	}
	else
	{
		cout << "Can't Register Manager!" << endl;
		system("PAUSE");
		system("cls");
	}
}
