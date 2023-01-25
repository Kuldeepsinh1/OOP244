
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
#include "Text.h"

using namespace std;

namespace sdds
{
	Text::Text()
	{
		M_Content = nullptr;
	}

	Text::Text(const Text& text)
	{
		if (text.M_Content != nullptr) {
			M_Content = new char[strlen(text.M_Content) + 1];
			strcpy(M_Content, text.M_Content);
		}
	}

	Text::~Text() {
		delete[] M_Content;
	}

	Text& Text::operator=(const Text& text)
	{
		if (M_Content != nullptr) {
			delete[] M_Content;
			M_Content = nullptr;
		}
		M_Content = new char[strlen(text.M_Content) + 1];
		strcpy(M_Content, text.M_Content);
		return *this;
	}

	const char& Text::operator[](int index) const
	{
		return M_Content[index];
	}

	std::ostream& Text::write(std::ostream& os) const {
		if (M_Content != nullptr) {
			os << M_Content;
		}
		return os;
	}

	std::istream& Text::read(std::istream& is) {
		unsigned len = getFileLength(is);
		delete[] M_Content;
		M_Content = new char[len + 1];
		int i = 0;
		char ch;
		is.clear();
		is.seekg(0, ios::beg);
		while (is >> noskipws >> ch) {
			M_Content[i++] = ch;
		}
		M_Content[i] = '\0';
		return is;
	}

	std::istream& operator>>(std::istream& in, Text& text) {
		return text.read(in);
	}
	std::ostream& operator<<(std::ostream& os, const Text& text) {
		return text.write(os);
	}

	unsigned Text::getFileLength(istream& is)
	{
		unsigned len{};
		is.clear();
		is.seekg(0, ios::beg);
		if (is) {
			std::streampos cur = is.tellg();
			is.seekg(0, ios::end);
			len = unsigned(is.tellg());
			is.seekg(cur);
		}
		return len;
	}
}
