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
	FirstName = NULL;
	LastName = NULL;
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

LPCTSTR Student::GetFullName()
{
	LPCTSTR result = NULL;
	TCHAR buff[255] = { '\0' };
	result = lstrcat(buff, LastName);
	result = lstrcat(buff, _T(" "));
	result = lstrcat(buff, (LPTSTR)FirstName);
	result = lstrcat(buff, _T(" "));
	result = lstrcat(buff, (LPTSTR)MiddleName);
	return result;
}

unsigned short Student::GetBirthday()
{
	return Birthday;
}

double Student::GetMidGrade()
{
	return MidGrade;
}

void Student::SetFirstName(LPCTSTR fname)
{
	FirstName = fname;
}

void Student::SetLastName(LPCTSTR lname)
{
	LastName = lname;
}

void Student::SetMiddleName(LPCTSTR mname)
{
	MiddleName = mname;
}

void Student::SetBirthday(unsigned short bday)
{
	Birthday = bday;
}

void Student::SetMidGrade(double mgrade)
{
	MidGrade = mgrade;
}

std::basic_ostream<TCHAR> &operator << (std::basic_ostream<TCHAR> &out, Student& student)
{
	LPCTSTR result = NULL;
	TCHAR buff[255] = { '\0' };
	result = lstrcat(buff, _T("\n"));
	result = lstrcat(buff, student.FirstName);
	result = lstrcat(buff, _T(" "));
	result = lstrcat(buff, student.FirstName);
	result = lstrcat(buff, _T(" "));
	result = lstrcat(buff, student.MiddleName);
	result = lstrcat(buff, _T(" Birthday: "));
	TCHAR szBuff1[8] = { '\0' };
	_tprintf(szBuff1, "%f", student.Birthday);
	result = lstrcat(buff, szBuff1);
	result = lstrcat(buff, _T(" Middle grade: "));
	TCHAR szBuff[32] = {'\0'};
	_tprintf(szBuff, "%f", student.MidGrade);
	result = lstrcat(buff, szBuff);
	return out << result;
}

std::basic_istream<TCHAR> &operator >> (std::basic_istream<TCHAR> &in, Student& student)
{
	TCHAR* s = NULL;
	in >> s;
	student.LastName = s;
	in >> s;
	student.FirstName = s;
	in >> s;
	student.MiddleName = s;
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
	LPCTSTR _compiledfirst = NULL;
	TCHAR szBuff[255] = {'\0'};
	_compiledfirst = lstrcat(szBuff, first.LastName);
	_compiledfirst = lstrcat(szBuff, first.MiddleName);
	_compiledfirst = lstrcat(szBuff, first.FirstName);
	LPCTSTR _compiledsecond = NULL;
	TCHAR szBuff2[255] = { '\0' };
	_compiledsecond = lstrcat(szBuff2, second.LastName);
	_compiledsecond = lstrcat(szBuff2, second.MiddleName);
	_compiledsecond = lstrcat(szBuff2, second.FirstName);
	#ifdef UNICODE
	if (wcscmp(_compiledfirst, _compiledsecond) > 0)
		return 1;
	else if (wcscmp(_compiledfirst, _compiledsecond) < 0)
		return -1;
	else
		return 0;
	#else
	if (strcmp(_compiledfirst, _compiledsecond) > 0)
		return 1;
	else if (strcmp(_compiledfirst, _compiledsecond) < 0)
		return -1;
	else
		return 0;
	#endif // UNICODE
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
	#ifdef UNICODE
		std::wcout << L"\nStudent: " << *this;
	#else
		std::cout << "\nStudent: " << *this;
	#endif // UNICODE
}