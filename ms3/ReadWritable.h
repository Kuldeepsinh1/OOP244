/*
Name:- Kuldeepsinh Sandipsinh Mahida
Student ID:- 167547215
submission date  - 27 november 2022
time - 7:18 pm
*/


#ifndef SDDS_READWRITABLE_H__
#define SDDS_READWRITABLE_H__ 
#include <iostream> 

using namespace std; 
namespace sdds { 
	class ReadWritable {
		bool flag;
	public:
		ReadWritable();
		virtual ~ReadWritable();
		virtual std::istream& read(std::istream&) = 0;
		virtual  std::ostream& write(std::ostream&) const = 0;
		bool isCsv() const;
		void setCsv(bool);
		friend std::istream& operator >> (std::istream&, ReadWritable&);
		friend std::ostream& operator << (std::ostream&, const ReadWritable&);


	};
}
#endif
