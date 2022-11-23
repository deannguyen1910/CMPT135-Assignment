#include <iostream>
#include <string>
#include <ctime>
#include <cassert>
#include<SmarterArray.h>
#include<Map.h>
#include<Course.h>
#include<SchoolManagementSystem.h>
#include<Student.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	cout << "Welcome to Phantom College School Management System" << endl;
	cout << "===================================================" << endl;

	srand(1);
	const int STUDENT_SIZE = 10;
	const int COURSE_SIZE = 16;

	//Prepare the courses offered in the school
	Course course[] = {Course("CMPT120", 2), Course("CMPT130", 3), Course("CMPT135", 4),
		Course("MACM101", 2), Course("CALC151", 3), Course("CALC152", 4),
				  Course("MATH242", 4), Course("ECON101", 3), Course("ECON102", 4),
				  Course("ENGL100", 2), Course("HIST101", 3), Course("PHYS100", 2),
				  Course("PHYS101", 3), Course("PHYS102", 4), Course("CHEM101", 3),
				  Course("CHEM102", 4)};

	//Construct and print a school management system object
	SchoolManagementSystem sms;
	cout << sms << endl;

	//Add courses offered into the system
	for (int i = 0; i < COURSE_SIZE; i++)	//there are 16 courses initially
	{
		bool flag = sms.offerCourse(course[i]);
		if (flag)
			cout <<"Course offering successful." << endl;
		else
			cout << "Course offering failed. The same course already exists in the system." << endl;
	}
	cout << endl << "Some courses have been offered and added in to the system." << endl;
	cout << "The updated system information is..." << endl;
	cout << sms << endl;

	//See if CMPT135 course is offered in the school
	int courseIndex = sms.findCourse("CMPT225");
	if (courseIndex == -1)
		cout << "CMPT225 course is not offered in the school." << endl << endl;
	else
	{
		cout << "CMPT225 course is offered in the school. Details below..." << endl;
		cout << sms.getCourse(courseIndex) << endl;
	}

	//See if a randomly chosen course is offered in the school
	int randomCourseIndex = rand() % sms.getNumberOfCoursesOffered();
	Course c = sms.getCourse(randomCourseIndex);
	courseIndex = sms.findCourse(c.getCourseName());
	if (courseIndex == -1)
		cout << c.getCourseName() << " course is not offered in the school." << endl << endl;
	else
	{
		cout << c.getCourseName() << " course is offered in the school. Details below..." << endl;
		cout << sms.getCourse(courseIndex) << endl << endl;
	}

	//Register some new students into the system
	for (int i = 0; i < STUDENT_SIZE; i++)
	{
		bool flag = sms.registerStudent(Student(sms.generateRandomStudent()));
		if (flag)
			cout <<"Student registration successful." << endl;
		else
			cout << "Student registration failed. The same student already exists in the system." << endl;
	}
	cout << endl << "Some students have been registered in to the system." << endl;
	cout << "The updated system information is..." << endl;
	cout << sms << endl;

	//See if Yonas Weldeselassie is a student in the school
	int studentIndex = sms.findStudent("Yonas", "Weldeselassie");
	if (studentIndex == -1)
		cout << "Yonas Weldeselassie is not a student in the school." << endl << endl;
	else
	{
		cout << "Yonas Weldeselassie is a student in the school. Details below..." << endl;
		cout << sms.getStudent(studentIndex) << endl;
		cout << sms.getStudentMap(studentIndex) << endl;
		cout << "GPA = " << sms.getStudentGPA(studentIndex) << endl << endl;
	}

	//See if a randomly chosen student is a student in the school
	int randomStudentIndex = rand() % sms.getNumberOfRegisteredStudents();
	Student s = sms.getStudent(randomStudentIndex);
	studentIndex = sms.findStudent(s.getFirstName(), s.getLastName());
	if (studentIndex == -1)
		cout << s.getFirstName() << " " << s.getLastName() << " is not a student in the school." << endl << endl;
	else
	{
		cout << s.getFirstName() << " " << s.getLastName() << " is a student in the school. Details below..." << endl;
		cout << sms.getStudent(studentIndex) << endl;
		cout << sms.getStudentMap(studentIndex);
		cout << "GPA = " << sms.getStudentGPA(studentIndex) << endl << endl;
	}

	//Enroll students to some courses
	for (int studentIndex = 0; studentIndex < sms.getNumberOfRegisteredStudents(); studentIndex++)
	{
		int numberOfCourses = rand() % (sms.getNumberOfCoursesOffered()/2);
		for (int i = 0; i < numberOfCourses; i++)
		{
			int courseIndex = rand() % sms.getNumberOfCoursesOffered();
			sms.enrolStudent(studentIndex, courseIndex);
		}
	}
	cout << endl << "Some students have been enrolled in to some courses." << endl;
	cout << "The updated system information is..." << endl;
	cout << sms << endl;

	//Assign letter grades to the students
	for (int studentIndex = 0; studentIndex < sms.getNumberOfRegisteredStudents(); studentIndex++)
	{
		if (rand() % 4 == 0)
		{
			cout << "Skipping a student from letter grade assignments." << endl;
			continue;
		}
		int n = sms.getStudentMap(studentIndex).getSize(); //Assign letter grades to each course the student is enrolled in
		for (int j = 0; j < n; j++)
		{
			if (rand() % 5 == 0)
			{
				cout << "Skipping a course from letter grade assignment." << endl;
				continue;
			}
			int courseIndex = sms.getStudentMap(studentIndex).getKeyAtIndex(j);
			sms.assignLetterGrade(studentIndex, courseIndex, sms.generateRandomLetterGrade());
		}
	}
	cout << endl << "Students have been assigned letter grades." << endl;
	cout << "The updated system information is..." << endl;
	cout << sms << endl;

	//The operations below are performed several times in order to test our work rigorously.
	for (int i = 0; i < STUDENT_SIZE/2; i++)
	{
		if (sms.getNumberOfRegisteredStudents() == 0)
			continue;	//There is no any student in the system so we don't need to do anything

		//Remove a randomly chosen student from the system
		randomStudentIndex = rand() % sms.getNumberOfRegisteredStudents();
		sms.removeStudent(randomStudentIndex);
		cout << endl << "The student at index " << randomStudentIndex << " has been removed from the system." << endl;
		cout << "The updated system information is..." << endl;
		cout << sms << endl;

		if (sms.getNumberOfRegisteredStudents() == 0 || sms.getNumberOfCoursesOffered() == 0)
			continue;	//There is no any student or any course in the system so we don't need to do anything

		//Withdraw a student from a course
		randomStudentIndex = rand() % sms.getNumberOfRegisteredStudents();
		s = sms.getStudent(randomStudentIndex);
		studentIndex = sms.findStudent(s.getFirstName(), s.getLastName());
		if (studentIndex == -1)
			cout << s.getFirstName() << " " << s.getLastName() << " is not a student in the school." << endl << endl;
		else
		{
			cout << s.getFirstName() << " " << s.getLastName() << " is a student in the school. Details below..." << endl;
			cout << sms.getStudent(studentIndex) << endl;
			cout << sms.getStudentMap(studentIndex) << endl;

			if (sms.getStudentMap(studentIndex).getSize() == 0)
				continue; //The specified student is not enrolled in any course so nothing to do

			int randomCourseMapIndex = rand() % sms.getStudentMap(studentIndex).getSize();
			int courseIndex = sms.getStudentMap(studentIndex).getKeyAtIndex(randomCourseMapIndex);
			bool flag = sms.withdrawStudent(studentIndex, courseIndex);
			if (!flag)
				cout << "Withdrawing the student at index " << studentIndex << " from the course at index " << courseIndex << " failed." << endl << endl;
			else
			{
				cout << "Student at index " << studentIndex << " withdrawn from the course at index " << courseIndex << endl;
				cout << "The updated information for the student is now..." << endl;
				cout << sms.getStudent(studentIndex) << endl;
				cout << sms.getStudentMap(studentIndex) << endl;
			}
		}
	
		//Remove a randomly chosen course from the system
		randomCourseIndex = rand() % sms.getNumberOfCoursesOffered();
		c = sms.getCourse(randomCourseIndex);
		sms.removeCourse(randomCourseIndex);
		cout << c.getCourseName() << " has been removed from the system." << endl;
		cout << "The system has been updated. Below is the updated system information..." << endl;
		cout << sms << endl;

		//Compute and print the top student
		int topStudentIndex = sms.getTopStudentIndex();
		cout << "The top student is..." << endl;
		cout << sms.getStudent(topStudentIndex) << endl;
		cout << "GPA = " << sms.getStudentGPA(topStudentIndex) << endl << endl;
	}

	system("Pause");
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////