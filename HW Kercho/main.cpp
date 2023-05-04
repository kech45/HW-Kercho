#include <iostream>
#include <functional>
#include <cmath>
#include <ctime>
#include <cstring>
#include "Hotel.h"
#include "Customer.h"
#include "Reservation.h"
#include "Room.h"
#include "Time.h"
#include "UniqueVector.h"


int main() {
	Hotel* Hotel1 = new Hotel(20, 20);
	char* roomType1 = new char[20] {"Single"};
	char* roomType2 = new char[20] {"Double"};
	char* roomType3 = new char[20] {"Suite"};
	char* roomDesc1 = new char[20] {"Very Nice"};
	char* roomDesc2 = new char[20] {"Oh no bad"};
	char* roomDesc3 = new char[20] {"Incredible"};
	char* roomDesc4 = new char[20] {"Nicest"};
	char* roomDesc5 = new char[20] {"The worst frfr"};
	Room* room1 = new Room(101, roomType1, roomDesc1);
	Room* room2 = new Room(102, roomType2, roomDesc5);
	Room* room3 = new Room(103, roomType3, roomDesc2);
	Room* room4 = new Room(104, roomType1, roomDesc4);
	Room* room5 = new Room(105, roomType2, roomDesc3);
	char* Address1 = new char[20] {"Big 24 str"};
	char* Address2 = new char[20] {"veryBig 25 str"};
	char* Address3 = new char[20] {"small 34 str"};
	char* Name1 = new char[20] {"John"};
	char* Name2 = new char[20] {"Mark"};
	char* Name3 = new char[20] {"Hamill"};
	char* telNum1 = new char[20] {"0821223234"};
	char* telNum2 = new char[20] {"0821402353"};
	char* telNum3 = new char[20] {"0878523654"};
	Time* timebeg1 = new Time(2023, 5, 23, 12, 0, 30);
	Time* timeend1 = new Time(2023, 6, 1, 12, 0, 30);
	Time* timebeg2 = new Time(2023, 8, 12, 13, 30, 30);
	Time* timeend2 = new Time(2023, 8, 14, 17, 0, 12);
	Time* timebeg3 = new Time(2023, 10, 1, 20, 30, 0);
	Time* timeend3 = new Time(2023, 10, 8, 20, 0, 0);
	Customer* customer1 = new Customer(Name1, Address1, telNum1);
	Customer* customer2 = new Customer(Name2, Address2, telNum2);
	Customer* customer3 = new Customer(Name3, Address3, telNum3);
	Reservation* reservation1 = new Reservation(23, *customer1, *room1, *timebeg1, *timeend1);
	Reservation* reservation2 = new Reservation(49, *customer2, *room4, *timebeg2, *timeend2);
	Reservation* reservation3 = new Reservation(55, *customer3, *room5, *timebeg3, *timeend3);
	Hotel1->addReservation(*reservation1);
	Hotel1->addReservation(*reservation2);
	Hotel1->addReservation(*reservation3);
	std::cout << *Hotel1 << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	
	Hotel1->removeReservation(49);
	std::cout << *Hotel1 << std::endl;

	std::cout << "---------------------------------------------------------------" << std::endl;

	std::cout << std::boolalpha<<Hotel1->isRoomFreeToRes(Time(2022, 1, 1, 1, 1, 1), Time(2025, 4, 4, 4, 4, 4), 104);

	std::cout << "---------------------------------------------------------------" << std::endl;

	Hotel1->freeRoomsInPeriod(Time(2024, 1, 1, 1, 1, 1), Time(2025, 1, 1, 1, 1, 1));

	std::cout << "---------------------------------------------------------------" << std::endl;

	Hotel1->reservationsMadeByGuest(Name1);

	std::cout << "---------------------------------------------------------------" << std::endl;

	std::cout << "Profits until date are: " << Hotel1->ProfitsUntilDate(Time(2023, 6, 3, 3, 3, 3)) << std::endl;

	std::cout << "---------------------------------------------------------------" << std::endl;
	
}
