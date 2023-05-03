#include <iostream>
#include "Time.h"

void Time::setTime(int y, int mo, int d, int h, int mi, int s) {
	year = y;
	if (mo > 0 && mo < 13) { month = mo; }
	else { throw std::exception{ "invalid time" }; }
	if (d > 0 && d < 32) { day = d; }
	else { throw std::exception{ "invalid time" }; }
	if (h >= 0 && h < 24) { hour = h; }
	else { throw std::exception{ "invalid time" }; }
	if (mi >= 0 && mi < 60) { minute = mi; }
	else { throw std::exception{ "invalid time" }; }
	if (s > 0 && s < 60) { second = d; }
	else { throw std::exception{ "invalid time" }; }
}

void Time::copy(const Time& other) {
	year = other.year;
	month = other.month;
	day = other.day;
	hour = other.hour;
	minute = other.minute;
	second = other.second;
}

int Time::daysInMonth(int m, int y)
{
	if (m == 2) {
		if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) { return 29; }
		else { return 28; }
	}

	else if (m == 4 || m == 6 || m == 9 || m == 11) {
		return 30;
	}
	return 31;
}

Time::Time() {
	year = 0;
	month = 0;
	day = 0;
	hour = 0;
	minute = 0;
	second = 0;
}

Time::Time(const Time& other) {
	copy(other);
}

Time& Time:: operator=(const Time& other) {
	if (this != &other) {
		year = other.year;
		month = other.month;
		day = other.day;
		hour = other.hour;
		minute = other.minute;
		second = other.second;
	}
	return *this;
}

Time::Time(int y, int mo, int d, int h, int mi, int s) {
	setTime(y, mo, d, h, mi, s);
}

const int Time::getYear()const { return year; }

const int Time::getMonth()const { return month; }

const int Time::getDay()const { return day; }

const int Time::getHour()const { return hour; }

const int Time::getMinute()const { return minute; }

const int Time::getSecond()const { return second; }

std::ostream& operator <<(std::ostream& os, const Time& obj) {
	os << "Year: " << obj.year << "Month: " << obj.month << "Day: " << obj.day
		<< "Time: " << obj.hour << ':'
		<< obj.minute << ':'
		<< obj.second;
}

const bool Time::operator <(const Time& other)const {
	if (year < other.year) { return true; }
	else if (year == other.year) {
		if (month < other.month) { return true; }
		else if (month == other.month) {
			if (day < other.day) { return true; }
			else if (day == other.day) {
				if (hour < other.hour) { return true; }
				else if (hour == other.hour) {
					if (minute < other.minute) { return true; }
					else if (minute == other.minute) {
						if (second < other.second) { return true; }
						else { return false; }
					}
				}
			}
		}
	}
	return false;
}

const bool Time::operator ==(const Time& other)const {
	if (second == other.second && minute == other.minute && hour == other.hour && day == other.day && month == other.month && year == other.year) {
		return true;
	}
	return false;
}

Time& Time::operator-(const Time& other) {
	Time result;
	int y = year - other.year;
	int mo = month - other.month;
	int d = day - other.day;
	int h = hour - other.hour;
	int mi = minute - other.minute;
	int s = second - other.second;
	if (s < 0) {
		s += 60;
		mi--;
	}
	if (mi < 0) {
		mi += 60;
		h--;
	}
	if (h < 0) {
		h += 24;
		d--;
	}
	if (d < 0) {
		d += daysInMonth(month, year);
		mo--;
	}
	if (mo < 0) {
		mo += 12;
		y--;
	}

	return result;
}

int Time::ConvertTimeintoDays()const {
	int days = 0;
	days += this->second / 86400;
	days += this->minute / 1440;
	days += this->hour / 24;
	days += this->day;
	days += this->month * 30;
	days += this->year * 365;
	return days;
}

void Time::setCurrentTime() {
	time_t now = time(0);
	struct tm* currentTime = localtime(&now);
	year = 1900 + currentTime->tm_year;
	month = 1 + currentTime->tm_mon;
	day = currentTime->tm_mday;
	hour = currentTime->tm_hour;
	minute = currentTime->tm_min;
	second = currentTime->tm_sec;
}
