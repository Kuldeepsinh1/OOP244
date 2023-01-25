/*
Name:- Kuldeepsinh Sandipsinh Mahida
Student ID:- 167547215
submission date  - 27 november 2022
time - 7:18 pm
*/


#define _CRT_SECURE_NO_WARNINGS
#include "ReadWritable.h" 
using namespace std; 
namespace sdds { 
	ReadWritable::ReadWritable() {
		flag = false;
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