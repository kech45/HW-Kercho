#pragma once
#include <iostream>
#include "Reservation.h"
#include "Room.h"
#include "UniqueVector.h"
#include "Time.h"

class Hotel {
private:
	UniqueVector<Room> rooms;
	UniqueVector<Reservation> reservations;
	void copy(const Hotel& other);
	void destroy();
public:
	const int getRooms()const { return rooms.getSize(); }
	const int getReservations()const { return reservations.getSize(); }
	const int getRoomsCap()const { return rooms.getCapacity(); }
	const int getReservationsCap()const { return rooms.getCapacity(); }
	Hotel();
	Hotel(const Hotel& other);
	Hotel(int roomCap, int resCap);
	~Hotel();
	void addRoom(const Room& other);
	void addReservation(const Reservation& other);
	void removeReservation(int n);
	const bool isRoomFreeToRes(const Time& begin, const Time& end, int roomNum);
	void freeRoomsInPeriod(const Time& begin, const Time& end);
	const int ProfitsUntilDate(const Time& date);
	void reservationsMadeByGuest(std::ostream& os, const char* name);
	friend std::ostream& operator <<(std::ostream& os, const Hotel& obj);
};