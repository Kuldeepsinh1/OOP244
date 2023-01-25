/*
Name:- Kuldeepsinh Sandipsinh Mahida
Student ID:- 167547215
submission date  - 7 December 2022
time - 1:54pm
*/


#define _CRT_SECURE_NO_WARNINGS
#include "ReadWritable.h" 
using namespace std; 
namespace sdds { 
	ReadWritable::ReadWritable() {
		flag = false;
	}
	ReadWritable::ReadWritable(const ReadWritable& src)
	{
		flag = src.flag;
	}

	ReadWritable& ReadWritable::operator=(const ReadWritable& src)
	{
		if (this != &src)
		{
			flag = src.flag;
		}
		return *this;
	}
	ReadWritable::~ReadWritable()
	{
	}
	bool ReadWritable::isCsv() const
	{
		return flag;
	}
	void ReadWritable::setCsv(bool value)
	{
		flag = value;
	}
	std::istream& operator>>(std::istream& istr, ReadWritable& readWritable)
	{
		return readWritable.read(istr);
	}
	std::ostream& operator<<(std::ostream& ostr, const ReadWritable& readWritable)
	{
		return readWritable.write(ostr);
	}
}