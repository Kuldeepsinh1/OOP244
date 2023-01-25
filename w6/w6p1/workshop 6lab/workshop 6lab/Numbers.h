// name - kuldeepsinh sandipsinh mahida
// student id - 167547215
// college mail - kmahida1@myseneca.ca
// completed 31 october
#ifndef Numbers_hpp
#define Numbers_hpp

#include <stdio.h>
#include <iostream>
namespace sdds {
    class Numbers {
        double* m_numbers{};
        char* m_filename{};
        bool m_isOriginal;
        int m_numCount;
        bool isEmpty()const;
        void setEmpty();
        void deallocate();
        void setFilename(const char* filename);
    public:
        Numbers();
        Numbers(const char* filename);

        Numbers(const Numbers& number);
        double average()const;
        double max()const;
        int numberCount();
        double min()const;
        ~Numbers();
        Numbers& sort(bool ascending);
        Numbers& operator=(const Numbers& number);
        Numbers operator-() const;
        Numbers operator+() const;
        bool load();
        void save();
        Numbers& operator+=(double m);
	std::ostream& display(std::ostream& ostr) const;
        friend std::ostream& operator<<(std::ostream& os, const Numbers& N);
        friend std::istream& operator>>(std::istream& istr, Numbers& N);
    };
}
#endif // !SDDS_NUMBERS_H_

