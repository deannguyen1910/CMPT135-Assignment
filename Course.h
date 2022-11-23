#pragma once
#include<iostream>
#include<string>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Course
{
private:
	string name;
	int creditHours;
public:
	Course();
	Course(const string&, const int&);
	string getCourseName() const;
	int getCreditHours() const;
	void setCourseName(const string&);
	void setCreditHours(const int&);
	bool operator == (const Course&) const; //Return true if course names are equal and credit hours are also equal.
	friend ostream& operator << (ostream&, const Course&);
};
Course::Course()
{
	name = "None";
	creditHours = 0;
}
ostream& operator << (ostream& out, const Course& c)
{
	out << "Course Name = " << c.name << ", Credit Hours = " << c.creditHours;
	return out;
}