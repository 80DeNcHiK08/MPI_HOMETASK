#include "pch.h"
#include "Student.h"


Student::Student()
{
	FirstName = "";
	LastName = "";
	MiddleName = "";
	Birthday = 0;
	MidGrade = 0;
}

Student::Student(std::string fname,
				 std::string lname,
				 std::string mname,
				 unsigned short bday,
				 float mgrade)
{
	FirstName = fname;
	LastName = lname;
	MiddleName = mname;
	Birthday = bday;
	MidGrade = mgrade;
}

Student::Student(const Student& othStud)
{
	*this = othStud;
}

Student::~Student()
{
	FirstName.clear();
	LastName.clear();
	MiddleName.clear();
}

std::string Student::GetFirstName()
{
	return FirstName;
}

std::string Student::GetLastName()
{
	return LastName;
}

std::string Student::GetMiddleName()
{
	return MiddleName;
}

std::string Student::GetFullName()
{
	return LastName + " " + FirstName + " " + MiddleName;
}

unsigned short Student::GetBirthday()
{
	return Birthday;
}

float Student::GetMidGrade()
{
	return MidGrade;
}

void Student::SetFirstName(std::string fname)
{
	FirstName = fname;
}

void Student::SetLastName(std::string lname)
{
	LastName = lname;
}

void Student::SetMiddleName(std::string mname)
{
	MiddleName = mname;
}

void Student::SetBirthday(unsigned short bday)
{
	Birthday = bday;
}

void Student::SetMidGrade(float mgrade)
{
	MidGrade = mgrade;
}

std::ostream& operator << (std::ostream& out, Student& student)
{
	out << "\n" << student.LastName + " " + student.FirstName + " " + student.MiddleName << "  Birthday: " << student.Birthday << "   Middle grade: " << student.MidGrade;
	return out;
}

std::istream& operator >> (std::istream& in, Student& student)
{
	in >> student.LastName;
	in >> student.FirstName;
	in >> student.MiddleName;
	in >> student.Birthday;
	in >> student.MidGrade;
	return in;
}

Student& Student::operator = (const Student& obj)
{
	if (this == &obj)
		return *this;
	MidGrade = obj.MidGrade;
	Birthday = obj.Birthday;
	FirstName = obj.FirstName;
	LastName = obj.LastName;
	MiddleName = obj.MiddleName;

	return *this;
}

int Student::compareStudents(const Student first, const Student second)
{
	return first.LastName.compare(second.LastName) > 0 ? 1 :
		(second.LastName.compare(first.LastName) > 0 ? -1 :
		(first.FirstName.compare(second.FirstName) > 0 ? 1 :
			(second.FirstName.compare(first.FirstName) > 0 ? -1 :
			(first.MiddleName.compare(second.MiddleName) > 0 ? 1 :
				(second.MiddleName.compare(first.MiddleName) > 0 ? -1 : 0)))));
}

bool Student::operator == (Student& obj)
{
	return compareStudents(*this, obj) == 0;
}

bool Student::operator != (Student& obj)
{
	return compareStudents(*this, obj) != 0;
}

bool Student::operator >= (Student& obj)
{
	return compareStudents(*this, obj) != -1;
}

bool Student::operator <= (Student& obj)
{
	return compareStudents(*this, obj) != 1;
}

bool Student::operator < (Student& obj)
{
	return compareStudents(*this, obj) == -1;
}

bool Student::operator > (Student& obj)
{
	return compareStudents(*this, obj) == 1;
}

void Student::PrintAllInfo()
{
	std::cout << "Student: " << this;
}