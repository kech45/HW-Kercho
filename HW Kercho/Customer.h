#pragma once
#include <iostream>

class Customer {
private:
	char* _name;
	char* _address;
	char* _telNum;
	void copy(const Customer& other);
	void destroy();
	void setName(char* n);
	void setAddress(char* a);
	void setNum(const char* tn);
public:
	Customer();
	Customer(const Customer& other);
	Customer(char* name, char* address, char* telNum);
	~Customer();
	const char* getName()const;
	const char* getAddress()const;
	const char* getNum()const;
	bool operator==(const Customer& other);
	Customer& operator =(const Customer& other);
	friend std::ostream& operator <<(std::ostream& os, const Customer& obj);

};
