#include <iostream>
#include "Room.h"


//Zad2 HotelManagementSystem
void Room::copy(const Room& other) {
		_room = other._room;
		_type = new char[strlen(other._type) + 1];
		strcpy(_type, other._type);
		_desc = new char[strlen(other._desc) + 1];
		strcpy(_desc, other._desc);
	}

void Room::destroy() {
		if(_desc != nullptr ) { delete[]this->_desc; }
		if (_type != nullptr) { delete[]this->_type; }
	}

void Room::setRoomNumber(int n) {
		_room = n;
	}

void Room::setType(char* type) {
		_type = new char[strlen(type) + 1];
		this->_type = type;
	}

void Room::setDesc(char* desc) {
		_desc = new char[strlen(desc) + 1];
		this->_desc = desc;
	}

Room::Room() {
	std::cout << "ROom constructor" << std::endl;
		_room = 0;
		_type = new char[1];
		_type[0] = '\0';
		_desc = new char[1];
		_desc[0] = '\0';
	}

Room::Room(const Room& other) {
		copy(other);
	}

Room::Room(int r, char* t, char* d) {
		setRoomNumber(r);
		setType(t);
		setDesc(d);
	}

Room::~Room() {
		destroy();
	}

const int Room::getRoom()const { return _room; }

const char* Room::getType()const { return _type; }

const char* Room::getDesc()const { return _desc; }

const int Room::getPrice()const {
	int n = 0;
		if (_type == "Single")
		{
			n = 45;
		}
		else if (_type == "Double")
		{
			n = 65;
		}
		else
		{
			n = 90;
		}
		return n;
	}

bool Room::operator==(const Room& other) {
		if (this->_room == other._room) {
			return true;
		}
		return false;
	}

Room& Room::operator =(const Room& other) {
		if (this != &other) {
			
			copy(other);
		}
		return *this;
	}

std::ostream& operator <<(std::ostream& os, const Room& obj) {
	os << "Room Number: " << obj._room << "\n"
		<< "Type: " << obj._type << "\n"
		<< "Description: " << obj._desc << "\n";
		return os;
	}

