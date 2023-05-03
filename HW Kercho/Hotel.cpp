#include <iostream>
#include "Hotel.h"


//Zad2 HotelManagementSystem
void Hotel::copy(const Hotel& other) {
		reservations = other.reservations;
		rooms = other.rooms;
	}

void Hotel::destroy() {
		delete[] &rooms;
		delete[] &reservations;
	}

Hotel::Hotel() {
		rooms = *(new UniqueVector<Room>[0]);
		reservations = *(new UniqueVector<Reservation>[0]);
	}

Hotel::Hotel(const Hotel& other) {
		copy(other);
	}

Hotel::Hotel(int roomCap, int resCap) {
		rooms = *(new UniqueVector<Room>[roomCap]);
		reservations = *(new UniqueVector<Reservation>[resCap]);
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
		reservations.removeElemByIndex(n);
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

void Hotel::reservationsMadeByGuest(std::ostream os, const char* name) {
		for (int i = 0; i < reservations.getSize(); i++)
		{
			if (reservations[i].getName() == name) {
				std::cout << reservations[i] << std::endl;
			}
		}
	}

std::ostream& operator <<(std::ostream os, const Hotel& obj) {
		os << "Rooms: ";
		for (int i = 0; i < obj.rooms.getSize(); i++)
		{
			os << obj.rooms[i] << "\n";
		}
		os << "Reservations: ";
		for (int i = 0; i < obj.reservations.getSize(); i++)
		{
			os << obj.reservations[i] << "\n";
		}
		return os;
	}



