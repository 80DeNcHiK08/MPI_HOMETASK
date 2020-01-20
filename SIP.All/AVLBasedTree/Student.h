#pragma once
#include <iostream>
#include <windows.h>
#include <tchar.h>

#if defined(UNICODE) || defined(_UNICODE)
	#define tistream std::wistream
	#define tostream std::wostream
	#define tcin std::wcin
	#define tcout std::wcout
	#define tscmp std::wcscmp
#else
	#define tistream std::istream
	#define tostream std::ostream
	#define tcin std::cin
	#define tcout std::cout
	#define tscmp std::strcmp
#endif

class Student
{
private:
	LPTSTR FirstName;
	LPTSTR LastName;
	LPTSTR MiddleName;
	unsigned short Birthday;
	double MidGrade;
	int compareStudents(Student, Student);
public:
	Student();
	Student(const Student&);
	Student(LPCTSTR fname,
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
	void SetField(LPTSTR* dest, LPCTSTR source);
	void SetBirthday(unsigned short bday);
	void SetMidGrade(double mgrade);

	Student& operator = (const Student& othstud);
	bool operator == (Student &othstud);
	bool operator != (Student &othstud);
	bool operator >= (Student &othstud);
	bool operator <= (Student &othstud);
	bool operator < (Student &othstud);
	bool operator > (Student &othstud);

	friend tostream &operator << (tostream &out, Student&);
	friend tistream &operator >> (tistream &in, Student&);

	void PrintAllInfo();
};

