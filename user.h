#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User {
protected:
	string username;
	string password;
public:
	User()
	{
		username = "";
		password = "";
	}
	void Login()
	{
	}

};

#endif
