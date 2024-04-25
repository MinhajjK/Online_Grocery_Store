#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include "user.h"
using namespace std;

class admin : public User {
private:

public:
	void setUsername(string n) { username = n; }
	void setPassword(string p) { password = p; }
	string getUsername() { return username; }
	string getPassword() { return username; }
	inline bool verifyAdmin();
	inline void managerRegistration();
};

#endif
