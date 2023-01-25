//Name - Kuldeepsinh Sandipsinh Mahida
//College ID - 167547215
//College mail - kmahida1@myseneca.ca
//completed date november 2
// completion time 11:20 pm
#include "Basket.h"
using namespace std;
namespace sdds
{

    Basket::Basket()
    {
        fruits = nullptr;
        sizes = 0;
        cost = 0.0;
    }

    Basket::Basket(Fruit *fruit, int size, double price)
    {
        if (fruit != nullptr && size > 0 && price > 0)
        {
            fruits = new Fruit[size];
            for (int i = 0; i < size; i++)
            {
                fruits[i] = fruit[i];
            }
            sizes = size;
            cost = price;
        }
        else
        {
            fruits = nullptr;
            sizes = 0;
            cost = 0.0;
        }
    }

    Basket::Basket(const Basket &src)
    {
        fruits = new Fruit[src.sizes];
        for (int i = 0; i < src.sizes; i++)
        {
            fruits[i] = src.fruits[i];
        }
        sizes = src.sizes;
        cost = src.cost;
    }

    Basket &Basket::operator=(const Basket &src)
    {
        if (this != &src)
        {
            if (sizes > 0)
            {
                delete[] fruits;
            }
            if (src.sizes > 0)
            {
                fruits = new Fruit[src.sizes];
            }
            else
            {
                fruits = nullptr;
            }
            for (int i = 0; i < src.sizes; i++)
            {
                fruits[i] = src.fruits[i];
            }
            sizes = src.sizes;
            cost = src.cost;
        }
        return *this;
    }

    Basket::~Basket()
    {
        delete[] fruits;
    }

    void Basket::setPrice(double price)
    {
        cost = price;
    }

    Basket::operator bool() const
    {
        return sizes > 0;
    }

    Basket &Basket::operator+=(Fruit fruit)
    {
        Fruit *temp = new Fruit[sizes + 1];
        for (int i = 0; i < sizes; i++)
        {
            temp[i] = fruits[i];
        }
        temp[sizes] = fruit;
        delete[] fruits;
        fruits = temp;
        sizes++;
        return *this;
    }

    std::ostream &operator<<(std::ostream &os, const Basket &basket)
    {
        if (basket.sizes == 0)
        {
            os << "The basket is empty!" << endl;
        }
        else
        {
            os << "Basket Content:" << endl;
            for (int i = 0; i < basket.sizes; i++)
            {
                
                os << setw(10) << right << basket.fruits[i].m_name << left << ": " << setprecision(2) << fixed << basket.fruits[i].m_qty << "kg" << endl;
            }
            os << "Price: " << setprecision(2) << fixed << basket.cost << endl;
        }
        return os;
    }
}
