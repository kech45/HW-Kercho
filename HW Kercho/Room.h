#pragma once
#include <iostream>

class Room {
private:
	int _room;
	char* _type;
	char* _desc;
	void copy(const Room& other);
	void destroy();
	void setRoomNumber(int n);
	void setType(char* type);
	void setDesc(char* desc);
public:
	Room();
	Room(const Room& other);
	Room(int r, char* t, char* d);
	~Room();
	const int getRoom()const;
	const char* getType()const;
	const char* getDesc()const;
	const int getPrice(int n=0)const;
	bool operator==(const Room& other);
	Room& operator =(const Room& other);
	friend std::ostream& operator <<(std::ostream& os, const Room& obj);
};
