#ifndef CUSTLOG_H
#define CUSTLOG_H 

#include <string>
#include "user.h"

class custLog : public User {
private:

public:
	void setUsername(string u) { username = u; }
	void setUserPass(string p) { password = p; }
	inline string Login();
};

#endif
