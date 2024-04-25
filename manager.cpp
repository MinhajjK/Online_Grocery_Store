#include "manager.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string manager::Login()
{
	string corr_id, corr_pass, corr_loc;
	ifstream fin;
	fin.open("manager" + ID + ".dat", ios::binary);
	if (fin.is_open())
	{
		fin >> corr_id;
		fin >> corr_pass;
		fin >> corr_loc;
	}
	else
	{
		cout << "Manager ID does not exists!\n";
	}

	int userCheck, passCheck;
	userCheck = getID().compare(corr_id);
	passCheck = pass.compare(corr_pass);

	if (userCheck == 0 && passCheck == 0)
	{
		cout << "Successfully Logged in!" << endl;
		return location;
	}
	else
	{
		cout << "Login Failed! Enter Correct Username and Password!" << endl;
		system("PAUSE");
		system("cls");
	}
}
