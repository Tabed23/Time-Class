#include "Time.h"
#include<iomanip>

Time::Time(int s,int m,int h)
{
	if (s >= 60)
	{
		cout << "you have enter a invalid time of seconds";
		sec = 0;
	}
	else
	{
		sec = s;
		if (m > 60)
		{
			cout << "you have enter a invalid time of seconds";
			mint = 0;
		}
		else
		{
			mint = m;
			if (h > 24)
			{
				cout << "you have enter a invalid time of seconds";
				hr = 0;
			}
			else
			{
				hr = h;
			}
		}

	}
}


Time::~Time()
{
}
void  Time::set_seconds(int s)
{
	if (s > 60)
	{
		cout << "invalid value" << endl;
		sec = 0;
	}
	else
	{
		sec = s;
	}

}
void Time::set_minutes(int m)
{
	if (m > 60)
	{
		cout << "you have enter a invalid time of minutes";
		mint = 0;
	}
	else
	{
		mint = m;
	}

}
void Time::set_hours(int h)
{
	if (h > 24)
	{
		cout << "you have enter a invalid time of hours";
		hr = 0;
	}
	else
	{
		hr = h;
	}
}
int Time::get_seconds()const
{
	return sec;
}
int Time::get_minutes()const
{
	return mint;

}
int Time::get_hours()const
{
	return hr;
}
Time Time::operator+(const Time& T)
{ 
	Time Tcopy;
	Tcopy.sec = sec + T.sec;
	Tcopy.mint = mint + T.mint + (sec / 60);
	Tcopy.hr = hr + T.hr + (mint / 60);
	Tcopy.mint = mint % 60;
	Tcopy.sec = sec % 60;
	return Tcopy;
}
Time Time:: operator-(const Time &T)
{
	Time Tcopy;
	Tcopy.sec = sec - T.sec;
	Tcopy.mint = mint - T.mint + (sec / 60);
	Tcopy.hr = hr - T.hr + (mint / 60);
	Tcopy.mint = mint % 60;
	Tcopy.sec = sec % 60;
	return Tcopy;
}
Time  Time::operator=(const Time & T)
{
	sec = T.sec;
	mint = T.mint;
	hr = T.hr;
}
ostream& operator<<(ostream & out , const Time& T)
{
	out.fill('0');
	out << T.hr << ":" << setw(2) << T.mint <<
		":" << setw(2) << T.sec;
	out.fill(' ');
	return out;
}
istream& operator>>(istream & in, Time & T)
{
	cout << "Enter Time" << endl;
	int s, m, h;
	in >> s >> m >> h;
	if (s >= 60)
	{
		cout << "you have enter a invalid time of seconds";
		T.sec = 0;
	}
	else
	{
		T.sec = s;
		if (m > 60)
		{
			cout << "you have enter a invalid time of seconds";
			T.mint = 0;
		}
		else
		{
			T.mint = m;
			if (h > 24)
			{
				cout << "you have enter a invalid time of seconds";
				T.hr = 0;
			}
			else
			{
				T.hr = h;
			}
		}

	}

	return in;
}
bool Time:: operator==(const Time& T)
{
	if (sec == T.sec)
	{
		if (mint == T.mint)
		{
			if (hr == T.hr)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	return false;
}
Time& Time:: operator++()
{
	sec++;
	if (sec > 60)
	{
		mint++;
		sec = 0;
		if (mint > 60)
		{
			hr++;
			mint = 0;
			if (hr > 24)
			{
				hr = 0;
			}
		}
	}
}
Time& Time::operator--()
{
	sec--;
	if (sec == 0)
	{
		mint--;
		sec = 0;
		if (mint == 0)
		{
			hr--;
			mint = 0;
			if (hr == 0)
			{
				hr = 0;
			}
		}
	}
}
Time &Time::operator++(int)
{
	Time Tcopy = (*this);
	sec++;
	if (sec > 60)
	{
		mint++;
		sec = 0;
		if (mint > 60)
		{
			hr++;
			mint = 0;
			if (hr > 24)
			{
				hr = 0;
			}
		}
	}
	return Tcopy;
}
Time &Time::operator--(int)
{
	Time Tcopy = (*this);
	sec--;
	if (sec == 0)
	{
		mint--;
		sec = 0;
		if (mint == 0)
		{
			hr--;
			mint = 0;
			if (hr == 0)
			{
				hr = 0;
			}
		}
	}
	return Tcopy;

}