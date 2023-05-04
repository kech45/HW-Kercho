#include <iostream>
#include "Customer.h"


//Zad2 HotelManagementSystem
void Customer::copy(const Customer& other) {
		_name = new char[strlen(other._name) + 1];
		strcpy(_name, other._name);
		_address = new char[strlen(other._address) + 1];
		strcpy(_address, other._address);
		_telNum = new char[strlen(other._telNum) + 1];
		strcpy(_telNum, other._telNum);

	}

void Customer::destroy() {
		delete[]_name;
		_name = nullptr;
		delete[]_address;
		_address = nullptr;
		delete[]_telNum;
		_telNum = nullptr;
	}

void Customer::setName(char* n) {
		_name = new char[strlen(n) + 1];
		strcpy(_name, n);
	}

void Customer::setAddress(char* a) {
		_address = new char[strlen(a) + 1];
		strcpy(_address, a);
	}

void Customer::setNum(char* tn) {
		if (tn[0] != '0' || tn[1] != '8' || strlen(tn) > 10) {
			throw ("Number is invalid");
		}
		_telNum = new char[strlen(tn) + 1];
		strcpy(_telNum, tn);
	}

Customer::Customer() {
		_name = new char[1];
		_name[0] = '\0';
		_address = new char[1];
		_address[0] = '\0';
		_telNum = new char[1];
		_telNum[0] = '\0';
	}

Customer::Customer(const Customer& other) {
		copy(other);
	}

Customer::Customer(char* name, char* address, char* telNum) {
		setAddress(address);
		setName(name);
		setNum(telNum);
	}

Customer::~Customer() {
		destroy();
	}

const char* Customer::getName()const { return _name; }

const char* Customer::getAddress()const { return _address; }

const char* Customer::getNum()const { return _telNum; }

bool Customer::operator==(const Customer& other) {
		if (strcmp(this->_name, other._name) == 0) {
			return true;
		}
		return false;
	}

Customer& Customer::operator =(const Customer& other) {
		if (this != &other) {
			copy(other);
		}
		return *this;
	}

std::ostream& operator <<(std::ostream& os, const Customer& obj) {
	os  << "Name: " << obj.getName() << "\n"
		<< "Address: " << obj.getAddress() << "\n"
		<< "Telephone number: " << obj.getNum() << "\n";
		return os;
	}

