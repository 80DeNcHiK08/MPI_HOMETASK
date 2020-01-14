#pragma once
#include <iostream>
#include <string>

class Student
{
private:
	std::string FirstName;
	std::string LastName;
	std::string MiddleName;
	unsigned short Birthday;
	double MidGrade;
	int compareStudents(Student, Student);
public:
	Student();
	Student(const Student&);
	Student(std::string fname,
			std::string lname,
			std::string mname, 
			unsigned short bday,
			double mgrade);
	~Student();

	std::string GetFirstName();
	std::string GetLastName();
	std::string GetMiddleName();
	std::string GetFullName();
	unsigned short GetBirthday();
	double GetMidGrade();

	void SetFirstName(std::string fname);
	void SetLastName(std::string lname);
	void SetMiddleName(std::string mname);
	void SetBirthday(unsigned short bday);
	void SetMidGrade(double mgrade);

	Student& operator = (const Student& othstud);
	bool operator == (Student &othstud);
	bool operator != (Student &othstud);
	bool operator >= (Student &othstud);
	bool operator <= (Student &othstud);
	bool operator < (Student &othstud);
	bool operator > (Student &othstud);

	friend std::ostream &operator << (std::ostream&, Student&);
	friend std::istream &operator >> (std::istream&, Student&);

	void PrintAllInfo();
};
