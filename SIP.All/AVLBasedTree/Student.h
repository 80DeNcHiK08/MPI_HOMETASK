#pragma once
#include <iostream>
#include <windows.h>
#include <tchar.h>

class Student
{
private:
	const TCHAR* FirstName;
	LPCTSTR LastName;
	LPCTSTR MiddleName;
	unsigned short Birthday;
	double MidGrade;
	int compareStudents(Student, Student);
public:
	Student();
	Student(const Student&);
	Student(const TCHAR* fname,
			LPCTSTR lname,
			LPCTSTR mname, 
			unsigned short bday,
			double mgrade);
	~Student();

	LPCTSTR GetFirstName();
	LPCTSTR GetLastName();
	LPCTSTR GetMiddleName();
	LPCTSTR GetFullName();
	unsigned short GetBirthday();
	double GetMidGrade();

	void SetFirstName(LPCTSTR fname);
	void SetLastName(LPCTSTR lname);
	void SetMiddleName(LPCTSTR mname);
	void SetBirthday(unsigned short bday);
	void SetMidGrade(double mgrade);

	Student& operator = (const Student& othstud);
	bool operator == (Student &othstud);
	bool operator != (Student &othstud);
	bool operator >= (Student &othstud);
	bool operator <= (Student &othstud);
	bool operator < (Student &othstud);
	bool operator > (Student &othstud);

	friend std::basic_ostream<TCHAR> &operator << (std::basic_ostream<TCHAR> &out, Student&);
	friend std::basic_istream<TCHAR> &operator >> (std::basic_istream<TCHAR> &in, Student&);

	void PrintAllInfo();
};

