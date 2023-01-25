
/*
   Name - Kuldeepsinh Sandipsinh Mahida
   Email - kmahida1@myseneca.ca
   StudentID - 167547215
   Date of Completion - 23 November 2022
   Time - 6:00 pm
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "HtmlText.h"

using namespace std;
namespace sdds
{
	HtmlText::HtmlText() : Text()
	{
		m_title = nullptr;
	}
	HtmlText::HtmlText(const char* title) : Text()
	{
		m_title = new char[strlen(title) + 1];
		strcpy(m_title, title);
	}
	HtmlText::~HtmlText() {
		if (m_title != nullptr) {
			delete[] m_title;
		}
	}
	HtmlText::HtmlText(const HtmlText* htmlText)
	{
		HtmlText::operator=(htmlText);
	}
	HtmlText& HtmlText::operator=(const HtmlText& htmlText)
	{
		if (m_title != nullptr) {
			delete[] m_title;
			m_title = nullptr;
		}
		m_title = new char[strlen(htmlText.m_title) + 1];
		strcpy(m_title, htmlText.m_title);
		Text::operator=(htmlText);
		return *this;
	}
	std::ostream& HtmlText::write(std::ostream& os) const
	{
		bool MS = false;
		os << "<html><head><title>";
		if (m_title != NULL) {
			os << m_title;
		}
		else {
			os << "No Title";
		}
		os << "</title></head>\n<body>\n";

		if (m_title != nullptr) {
			os << "<h1>" << m_title << "</h1>\n";
		}

		int i = 0;
		char ch;

		while (this->operator[](i) != '\0')
		{
			ch = this->operator[](i);
			if (ch == ' ')
			{
				if (MS == true)
				{
					os << "&nbsp;";
				}
				else
				{
					MS = true;
					os << ' ';
				}
			}
			else if (ch == '<')
			{
				MS = false;
				os << "&lt;";
			}
			else if (ch == '>')
			{
				MS = false;
				os << "&gt;";
			}
			else if (ch == '\n')
			{
				MS = false;
				os << "<br />\n";
			}
			else
			{
				MS = false;
				os << ch;
			}
			i++;
		}
		os << "</body>\n</html>";
		return os;
	}

	std::ostream& operator<<(std::ostream& os, const HtmlText& htmlText) {
		return htmlText.write(os);
	}
	std::istream& operator>>(std::istream& is, HtmlText& htmlText)
	{
		return htmlText.read(is);
	}

}
