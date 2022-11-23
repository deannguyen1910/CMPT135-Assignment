#pragma once
#include<iostream>
#include<SmarterArray.h>
#include<Student.h>
#include<Course.h>
#include<string>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
class SchoolManagementSystem
{
private:
	SmarterArray<Student> studentList; //A SmarterArray to store the students in the school
	SmarterArray<Course> courseList; //A SmarterArray to store the courses in the school
	SmarterArray<StudentMap> studentMapList; //A SmarterArray to store the students' maps

public:
	//Constructors
	SchoolManagementSystem();

	//Getters
	int getNumberOfRegisteredStudents() const;
	int getNumberOfCoursesOffered() const;
	int findStudent(const string &firstName, const string &lastName) const;
	Student getStudent(const int &studentIndex) const;
	StudentMap getStudentMap(const int &studentIndex) const;
	int findCourse(const string &courseName) const;
	Course getCourse(const int &courseIndex) const;
	double getStudentGPA(const int &studentIndex) const;
	int getTopStudentIndex() const;
	
	//Setters
	bool registerStudent(const Student &s);
	bool enrolStudent(const int &studentIndex, const int &courseIndex);
	bool assignLetterGrade(const int &studentIndex, const int &courseIndex, const char &letterGrade);
	bool offerCourse(const Course &course);
	void removeStudent(const int &studentIndex);
	bool withdrawStudent(const int &studentIndex, const int &courseIndex);
	void removeCourse(const int &courseIndex);

	//Static functions
	static Student generateRandomStudent();
	static char generateRandomLetterGrade();

	//Friend functions
	friend ostream& operator << (ostream &, const SchoolManagementSystem &);
};
SchoolManagementSystem::SchoolManagementSystem()
{}

ostream& operator << (ostream &out, const SchoolManagementSystem &sms)
{
	out << endl << "Students List" << endl;
	if (sms.studentList.getSize() == 0)
		out << "No student has been registered yet." << endl;
	for (int studentIndex = 0; studentIndex < sms.studentList.getSize(); studentIndex++)
		out << "Student at index " << studentIndex << ": " << sms.studentList[studentIndex] << endl;

	out << endl << "Courses List" << endl;
	if (sms.courseList.getSize() == 0)
		out << "No course has been offered yet." << endl;
	for (int courseIndex = 0; courseIndex < sms.courseList.getSize(); courseIndex++)
		out << "Course at index " << courseIndex << ": " << sms.courseList[courseIndex] << endl;

	cout << endl << "Students Map" << endl;
	if (sms.studentMapList.getSize() == 0)
		out << "No student is enrolled in any course yet." << endl;
	for (int studentIndex = 0; studentIndex < sms.studentMapList.getSize(); studentIndex++)
	{
		out << "Student at index " << studentIndex << endl;
		out << sms.studentMapList[studentIndex];
		out << "GPA = " << sms.getStudentGPA(studentIndex) << endl << endl;
	}
	return out;
}




















Student SchoolManagementSystem::generateRandomStudent()
{
	string fn, ln;
	Date dob;

	fn = rand() % 26 + 65;
	for (int i = 0; i < 9; i++)
		fn += char(rand() % 26 + 97);

	ln = rand() % 26 + 65;
	for (int i = 0; i < 9; i++)
		ln += char(rand() % 26 + 97);

	dob.y = 1998 + rand() % 5;
	dob.m = 1 + rand() % 12;
	dob.d = 1 + rand() % 30;

	return Student(fn, ln, dob);
}
char SchoolManagementSystem::generateRandomLetterGrade()
{
	int g = rand() % 11;
	if (g == 0)
		return 'A';
	else if (g <= 2)
		return'B';
	else if (g <= 5)
		return'C';
	else if (g <= 7)
		return 'D';
	else
		return 'F';
}