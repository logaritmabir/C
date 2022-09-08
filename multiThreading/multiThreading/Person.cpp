#include "Person.h"
#include <string>
using namespace std;

Person::Person(string name, string surname, string address, string phoneNumber, string birthday, string country) {
	setName(name);
	setSurname(surname);
	setAddress(address);
	setPhoneNumber(phoneNumber);
	setBirthday(birthday);
	setCountry(country);
}
Person::Person() {

}
void Person::setName(string name) {
	this->name = name;
}
void Person::setSurname(string surname) {
	this->surname = surname;
}
void Person::setAddress(string address) {
	this->address = address;
}
void Person::setPhoneNumber(string number) {
	this->phoneNumber = number;
}
void Person::setBirthday(string birth) {
	this->birthday = birth;
}
void Person::setCountry(string country) {
	this->country = country;
}

string Person::getName()const {
	return this->name;
}
string Person::getSurname()const {
	return this->surname;
}
string Person::getAddress()const {
	return this->address;
}
string Person::getPhoneNumber()const {
	return this->phoneNumber;
}
string Person::getBirthday()const {
	return this->birthday;
}
string Person::getCountry()const {
	return this->country;
}