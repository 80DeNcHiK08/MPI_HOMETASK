#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
	string FirstName;
	string LastName;
	string MiddleName;
	unsigned short Birthday;
	float MidGrade;
	int compareStudents(Student, Student);
public:
	string getFirstName();
	string getLastName();
	string getMiddleName();
	string getFullName();
	unsigned short getBirthday();
	float getMidGrade();
	void setFirstName(string);
	void setLastName(string);
	void setMiddleName(string);
	void setBirthday(unsigned short);
	void setMidGrade(float);
	Student& operator= (const Student&);
	bool operator==(Student&);
	bool operator!=(Student&);
	bool operator>=(Student&);
	bool operator<=(Student&);
	bool operator<(Student&);
	bool operator>(Student&);
	friend ostream& operator<< (ostream&, Student&);
	friend istream& operator>> (istream&, Student&);
	void PrintAllInfo();
	Student();
	Student(const Student&);
	~Student();
};