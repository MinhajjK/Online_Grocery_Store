#ifndef MANAGER_H
#define MANAGER_H
#include "user.h"

class manager : public User {
public:
	string ID;
	string location;
	string pass;
public:

	inline void setID(string x) { ID = x; }
	inline void setLocation(string l) { location = l; }
	inline void setPassword(string p) { pass = p; }
	inline string getID() { return ID; }
	inline string getLocation() { return location; }
	inline string getPassword() { return pass; }
	inline string Login();
};

#endif
