#pragma once
#include <iostream>
#include "Room.h"
#include "Time.h"
#include "Customer.h"


class Reservation {
private:
	int id;
	Customer guest;
	Room room;
	Time resBegin;
	Time resEnd;
	void copy(const Reservation& other);
	void setId(int n);
public:
	const int getRoomNum() const ;
	const int getRoomPrice() const;
	const int getId() const;
	const Time getBegin() const;
	const Time getEnd() const;
	const char* getName() const;
	const char* getAddress() const;
	const char* getTelNumber() const;
	const Room getRoom()const;
	Reservation();
	Reservation(const Reservation& other);
	Reservation(int n, Customer g, Room r, Time b, Time e);
	Reservation& operator =(const Reservation& other);
	int PriceForPeriod();
	const bool isFreeToRes(Time otherBegin, Time otherEnd);
	bool operator==(const Reservation& other);
	friend std::ostream& operator <<(std::ostream& os, const Reservation& obj);
};