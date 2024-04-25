#ifndef customerRegistration_H
#define customerRegistration_H

class customerRegistration {
private:
	string name;
	string cnic;
	string address;
	string password;
	char gender;
	int contactNo;
public:
	void setName(string n) { name = n; }
	string getName() { return name; }
	void setCnic(string c) { cnic = c; }
	string getCnic() { return cnic; }
	void setAddress(string a) { address = a; }
	string getAddress() { return address; }
	void setPassword(string p) { password = p; }
	string getPassword() { return password; }
	void setGender(char g) { gender = g; }
	char getGender() { return gender; }
	void setContact(int contact) { contactNo = contact; }
	int getContact() { return contactNo; }
};

#endif
