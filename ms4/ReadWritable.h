/*
Name:- Kuldeepsinh Sandipsinh Mahida
Student ID:- 167547215
submission date  - 7 December 2022
time - 1:54pm
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
		ReadWritable(const ReadWritable& src);
		ReadWritable& operator=(const ReadWritable& src);
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
