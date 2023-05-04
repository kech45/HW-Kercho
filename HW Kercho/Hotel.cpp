#include <iostream>
#include "Hotel.h"
#include "UniqueVector.cpp"

//Zad2 HotelManagementSystem

void Hotel::copy(const Hotel& other) {
	this->rooms = UniqueVector<Room>(other.rooms.getCapacity());
	this->reservations = UniqueVector<Reservation>(other.reservations.getCapacity());
}

void Hotel::destroy() {
	delete[] & rooms;
	delete[] & reservations;
}

Hotel::Hotel() {
	this->rooms = UniqueVector<Room>();
	this->reservations = UniqueVector<Reservation>();
}

Hotel::Hotel(const Hotel& other) {
	copy(other);
}

Hotel::Hotel(int roomCap, int resCap) {
	rooms = UniqueVector<Room>(roomCap);
	reservations = UniqueVector<Reservation>(resCap);
}

Hotel::~Hotel() {
	destroy();
}

void Hotel::addRoom(const Room& other) {
	rooms.addNewElem(other);
}

void Hotel::addReservation(const Reservation& other) {
	reservations.addNewElem(other);
}

void Hotel::removeReservation(int n) {
	for (int i = 0; i < reservations.getSize(); i++)
	{
		if (reservations[i].getId() == n) {
			reservations.removeElemByIndex(i);
			return;
		}
	
	}
	throw "No such ID exists";
}

const bool Hotel::isRoomFreeToRes(const Time& begin, const Time& end, int roomNum) {
	for (int i = 0; i < reservations.getCapacity(); i++)
	{
		if (reservations[i].getRoomNum() == roomNum) {
			return reservations[i].isFreeToRes(begin, end);
		}
	}
	return false;
}

void Hotel::freeRoomsInPeriod(const Time& begin, const Time& end) {
	for (int i = 0; i < reservations.getCapacity(); i++)
	{
		if (reservations[i].isFreeToRes(begin, end)) {
			std::cout << "Room: " << reservations[i].getRoomNum() << " is free" << std::endl;
		}
	}
}

const int Hotel::ProfitsUntilDate(const Time& date) {
	int sum = 0;
	for (int i = 0; i < reservations.getSize(); i++)
	{
		if (reservations[i].getEnd() < date || reservations[i].getEnd() == date) {
			sum += reservations[i].PriceForPeriod();
		}
	}
	return sum;
}

void Hotel::reservationsMadeByGuest(std::ostream& os, const char* name) {
	for (int i = 0; i < reservations.getSize(); i++)
	{
		if (reservations[i].getName() == name) {
			std::cout << reservations[i] << std::endl;
		}
	}
}

std::ostream& operator <<(std::ostream& os, const Hotel& obj)
{

	os << "Rooms: ";
	for (int i = 0; i < obj.getRooms(); i++)
	{
		os << obj.rooms[i] << "\n";
	}
	os << "----------------------------------------------";

	os << "Reservations: " << "\n";

	for (int i = 0; i < obj.getReservations(); i++)
	{
		os << obj.reservations[i] << "\n";
	}
	return os;
}