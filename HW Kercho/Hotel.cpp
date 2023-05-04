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
	this->rooms = *(new UniqueVector<Room>());
	this->reservations = *(new UniqueVector<Reservation>());
}

Hotel::Hotel(const Hotel& other) {
	copy(other);
}

Hotel::Hotel(int roomCap, int resCap) {
	rooms.setCapacity(roomCap);
	reservations.setCapacity(resCap);
	rooms = *(new UniqueVector<Room>(roomCap));
	reservations = *(new UniqueVector<Reservation>(resCap));
}

Hotel::~Hotel() {
	destroy();
}

const int Hotel::getRooms()const { return rooms.getSize(); }

const int Hotel::getReservations()const { return reservations.getSize(); }

const int Hotel::getRoomsCap()const { return rooms.getCapacity(); }

const int Hotel::getReservationsCap()const { return rooms.getCapacity(); }

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
	for (int i = 0; i < reservations.getSize(); i++)
	{
		if (reservations[i].getRoomNum() == roomNum) {
			return reservations[i].isFreeToRes(begin, end);
		}
	}
	return false;
}

void Hotel::freeRoomsInPeriod(const Time& begin, const Time& end) {
	for (int i = 0; i < reservations.getSize(); i++)
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

void Hotel::reservationsMadeByGuest(const char* name) {
	for (int i = 0; i < reservations.getSize(); i++)
	{
		if (*reservations[i].getName() == *name) {
			std::cout << reservations[i].getName() << "'s reservations:" <<"\n" 
					  << reservations[i] << std::endl;
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
	os << "\n";
	os << "----------------------------------------------" << "\n";

	os << "Reservations: " << "\n";

	for (int i = 0; i < obj.getReservations(); i++)
	{
		os << obj.reservations[i] << "\n";
	}
	return os;
}