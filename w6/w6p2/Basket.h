//Name - Kuldeepsinh Sandipsinh Mahida
//College ID - 167547215
//College mail - kmahida1@myseneca.ca
//completed date november 2
// completion time 11:20 pm
#ifndef __SDDS_BASKET_H__
#define __SDDS_BASKET_H__
#include <iostream>
#include <string.h>
#include <iomanip>
namespace sdds
{
    struct Fruit
    {
        char m_name[30 + 1];
        double m_qty;
    };
    class Basket
    {
        Fruit * fruits;
        int sizes;
        double cost;

    public:
        Basket();
        Basket(Fruit *, int , double );
        Basket(const Basket &);
        Basket &operator=(const Basket &);
        ~Basket();
        void setPrice(double price);
        operator bool() const;
        Basket &operator+=(Fruit fruit);
        friend std::ostream &operator<<(std::ostream &os, const Basket &basket);
    };

}
#endif
