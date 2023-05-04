#pragma once
#include <functional>
#include <iostream>


class Time
{
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	void setTime(int y, int mo, int d, int h, int mi, int s);
	void copy(const Time& other);
	int daysInMonth(int m, int y);
public:
	Time();
	Time(const Time& other);
	Time& operator=(const Time& other);
	Time(int y, int mo, int d, int h, int mi, int s);
	const int getYear()const;
	const int getMonth()const;
	const int getDay()const;
	const int getHour()const;
	const int getMinute()const;
	const int getSecond()const;
	friend std::ostream& operator <<(std::ostream& os, const Time& obj);
	const bool operator <(const Time& other)const;
	const bool operator ==(const Time& other)const;
	Time operator-(const Time& other);
	int ConvertTimeintoDays()const;
	void setCurrentTime();
};