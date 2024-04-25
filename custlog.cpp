#include "custLog.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string custLog::Login()
{
	string correct_username, correct_password, dummy1;
	string dummy2;
	string userLocation;
	ifstream fin;
	fin.open("customer" + username + ".dat", ios::binary);
	if (!fin.is_open())
	{
		cout << "Username does not exist!" << endl;
	}
	else
	{
		getline(fin, correct_username);
		getline(fin, correct_password);
		getline(fin, dummy1);
		fin >> dummy2;
		fin >> userLocation;
	}

	int userCheck, passCheck;
	userCheck = username.compare(correct_username);
	passCheck = password.compare(correct_password);
	if (userCheck == 0 && passCheck == 0)
	{
		cout << "Successfully Logged in!" << endl;
		system("PAUSE");
		system("cls");
		return userLocation;
	}
	else
	{
		cout << "Login Failed! Enter Correct Username and Password!" << endl;
		system("PAUSE");
		system("cls");
	}
}
