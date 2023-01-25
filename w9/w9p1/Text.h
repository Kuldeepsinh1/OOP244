
/*
   Name - Kuldeepsinh Sandipsinh Mahida
   Email - kmahida1@myseneca.ca
   StudentID - 167547215
   Date of Completion - 23 November 2022
   Time - 6:00 pm
*/


#ifndef SDDS_Text_H
#define SDDS_Text_H

namespace sdds {
	class Text
	{
	private:
		char* M_Content{};
	protected:
		const char& operator[](int index) const;
	public:
		Text();
		~Text();
		Text(const Text&);
		Text& operator=(const Text&);
		unsigned getFileLength(std::istream&);
		std::istream& read(std::istream&);
		virtual std::ostream& write(std::ostream&) const;
		friend std::istream& operator>>(std::istream&, Text&);
		friend std::ostream& operator<<(std::ostream&, const Text&);
	};
}
#endif