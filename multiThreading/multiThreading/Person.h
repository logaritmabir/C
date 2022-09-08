#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person {
private:
	string name;
	string surname;
	string address;
	string phoneNumber;
	string birthday;
	string country;
public:
	Person(string, string, string, string, string, string);
	Person();
	void setName(string);
	void setSurname(string);
	void setAddress(string);
	void setPhoneNumber(string);
	void setBirthday(string);
	void setCountry(string);
	
	string getName()const;
	string getSurname()const;
	string getAddress()const;
	string getPhoneNumber()const;
	string getBirthday()const;
	string getCountry()const;
};

#endif // !PERSON_H
