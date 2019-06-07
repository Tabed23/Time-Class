#pragma once
#include<iostream>
using namespace std;

class Time
{
private:
	int sec;
	int mint;
	int hr;
public:
	Time(int s=0, int m=0,int h=0);
	~Time();
	void set_seconds(int);
	void set_minutes(int);
	void set_hours(int);
	int get_seconds()const;
	int get_minutes()const;
	int get_hours()const;
	Time operator+(const Time&);
	Time operator-(const Time &);
	Time operator=(const Time &);
	friend ostream& operator<<(ostream &, const Time&);
	friend istream& operator>>(istream &, Time&);
	bool operator==(const Time&);
	Time& operator++();
	Time &operator--();
	Time & operator++(int);
	Time & operator--(int);
};

