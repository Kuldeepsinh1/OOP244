
/*
   Name - Kuldeepsinh Sandipsinh Mahida
   Email - kmahida1@myseneca.ca
   StudentID - 167547215
   Date of Completion - 23 November 2022
   Time - 6:00 pm
*/


#ifndef SDDS_HtmlText_H
#define SDDS_HtmlText_H
#include "Text.h"

namespace sdds
{
	class HtmlText : public Text {
	private:
		char* m_title{};
	public:
		HtmlText();
		HtmlText(const char* M_Content);
		~HtmlText();
		HtmlText(const HtmlText* ht_text);
		HtmlText& operator=(const HtmlText& ht_text);
		std::ostream& write(std::ostream& os) const override;
		friend std::ostream& operator<<(std::ostream& is, const HtmlText& ht_text);
		friend std::istream& operator>>(std::istream& is, HtmlText& ht_text);
	};
}

#endif