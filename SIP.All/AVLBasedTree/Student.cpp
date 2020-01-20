#include "pch.h"
#include "Student.h"


Student::Student()
{
	FirstName = NULL;
	LastName = NULL;
	MiddleName = NULL;
	Birthday = 0;
	MidGrade = 0;
}

Student::Student(LPCTSTR fname,
				 LPCTSTR lname,
				 LPCTSTR mname,
				 unsigned short bday,
	double mgrade)
{
	this->SetLastName(lname);
	this->SetFirstName(fname);
	this->SetMiddleName(mname);
	Birthday = bday;
	MidGrade = mgrade;
}

Student::Student(const Student& othStud)
{
	*this = othStud;
}

Student::~Student()
{
	LastName = NULL;
	FirstName = NULL;
	MiddleName = NULL;
}

LPCTSTR Student::GetFirstName()
{
	return FirstName;
}

LPCTSTR Student::GetLastName()
{
	return LastName;
}

LPCTSTR Student::GetMiddleName()
{
	return MiddleName;
}

unsigned short Student::GetBirthday()
{
	return Birthday;
}

double Student::GetMidGrade()
{
	return MidGrade;
}

void Student::SetField(LPTSTR* dest, LPCTSTR source)
{
	if (source) {
		delete[] * dest;
		*dest = new TCHAR[_tcslen(source) + 1];
		_tcscpy(*dest, source);
	}
	else {
		*dest = nullptr;
	}
}

void Student::SetFirstName(LPCTSTR fname)
{
	SetField(&FirstName, fname);
}

void Student::SetLastName(LPCTSTR lname)
{
	SetField(&LastName, lname);
}

void Student::SetMiddleName(LPCTSTR mname)
{
	SetField(&MiddleName, mname);
}

void Student::SetBirthday(unsigned short bday)
{
	Birthday = bday;
}

void Student::SetMidGrade(double mgrade)
{
	MidGrade = mgrade;
}

tostream &operator << (tostream &out, Student& student)
{
	if (&student != NULL)
	{
		out << student.GetLastName() << " "
			<< student.GetFirstName() << " "
			<< student.GetMiddleName() << " "
			<< student.GetBirthday() << " "
			<< student.GetMidGrade() << std::endl;
	}
	return out;
}

tistream &operator >> (tistream &in, Student& student)
{
	if (&student != NULL)
	{
		TCHAR* buffer = new TCHAR[255];
		in >> buffer;
		student.SetLastName(buffer);
		in >> buffer;
		student.SetFirstName(buffer);
		in >> buffer;
		student.SetMiddleName(buffer);
		in >> student.Birthday;
		in >> student.MidGrade;
		delete[] buffer;
	}
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
	if (tscmp(first.LastName, second.LastName) < 0)
	{
		if (tscmp(first.MiddleName, second.MiddleName) < 0)
		{
			return tscmp(first.FirstName, second.FirstName);
		}
		else if(tscmp(first.MiddleName, second.MiddleName) > 0)
			return 1;
	}
	else if (tscmp(first.LastName, second.LastName) > 0)
		return 1;
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
	tcout << "Student" << *this;
	/*#ifdef UNICODE
		std::wcout << L"\nStudent: " << *this;
	#else
		std::cout << "\nStudent: " << *this;
	#endif // UNICODE*/
}