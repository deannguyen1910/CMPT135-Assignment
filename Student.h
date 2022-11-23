#pragma once
#include<iostream>
#include<Map.h>
#include<string>
using namespace std;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct Date
{
	int y, m, d;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Student
{
private:
	string fn, ln; //first name and last name
	Date dob;
public:
	Student(); //Implemented for you
	Student(const string& firstName, const string& lastName, const Date&);
	string getFirstName() const;
	string getLastName() const;
	Date getDob() const;
	void setFirstName(const string&);
	void setLastName(const string&);
	void setDob(const Date&);
	bool operator == (const Student&) const; //Return true if all the first names, last names, and date of births are equal
	friend ostream& operator << (ostream&, const Student&); //Implemented for you
};
Student::Student()
{
	fn = "None";
	ln = "None";
	dob.y = 0;
	dob.m = 0;
	dob.d = 0;
}
ostream& operator << (ostream& out, const Student& s)
{
	out << "Full Name = " << s.fn << " " << s.ln << ": ";
	out << "DOB (d-m-y) = " << s.dob.d << "-" << s.dob.m << "-" << s.dob.y;
	return out;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef Map<int, char> StudentMap;
