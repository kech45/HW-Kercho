#include <iostream>
#include "Reservation.h"


void Reservation::copy(const Reservation& other) {
		this->id = other.id;
		this->guest = other.guest;
		this->resBegin = other.resBegin;
		this->resEnd = other.resEnd;
	}

void Reservation::setId(int n) {
		id = n;
	}

const int Reservation::getRoomNum() const { return room.getRoom(); }

const int Reservation::getRoomPrice() const { return room.getPrice(); }

const int Reservation::getId() const { return id; }

const Time Reservation::getBegin() const { return resBegin; }

const Time Reservation::getEnd() const { return resEnd; }

const char* Reservation::getName() const { return guest.getName(); }

const char* Reservation::getAddress() const { return guest.getAddress(); }

const char* Reservation::getTelNumber() const { return guest.getNum(); }

Reservation::Reservation() {
		id = 0;
	}

Reservation::Reservation(const Reservation& other) {
		copy(other);
	}

Reservation::Reservation(int n, Customer g, Room r, Time b, Time e) {
		setId(n);
		guest = g;
		room = r;
		resBegin = b;
		resEnd = e;
	}

Reservation& Reservation:: operator =(const Reservation& other) {
		if (this != &other) {
			delete[]this;
			copy(other);
		}
		return *this;
	}

int Reservation::PriceForPeriod() {
		return room.getPrice() * abs(resBegin.ConvertTimeintoDays() - resEnd.ConvertTimeintoDays());
	}

const bool Reservation::isFreeToRes(Time otherBegin, Time otherEnd) {
		if ((otherEnd < this->resBegin) || (this->resEnd < otherBegin)) {
			return true;
		}
		return false;
	}

bool Reservation::operator==(const Reservation& other) {
		if (this->id == other.getId()) {
			std::cout << "The reservations are the same";
			return true;
		}
		std::cout << "The reservations are not the same";
		return false;
	}

std::ostream& operator <<(std::ostream& os, const Reservation& obj) {
		os << "Room info: " << obj.room
			<< "Reservation period: " << obj.resBegin << obj.resEnd
			<< "Guest info: " << obj.guest << "Id: " << obj.id;

		return os;
	}
