/*
Name:- Kuldeepsinh Sandipsinh Mahida
Date:- 14/11/2022
Student ID:- 167547215
Course:- OOP244 NCC
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <iomanip>
#include "Menu.h"
using namespace std;

namespace sdds
{
    MenuItem::MenuItem(const char *content)
    {
        if (content == nullptr)
        {
            contents[0] = '\0';
        }
        else
        {
            strncpy(contents, content, 50);
            contents[50] = '\0';
        }
    }
    std::ostream &MenuItem::display(std::ostream &os) const
    {
        os << contents;
        return os;
    }
    Menu::Menu(const char *title, int indent)
    {
        if (title == nullptr)
        {
            titles[0] = '\0';
        }
        else
        {
            strncpy(titles, title, 50);
            titles[50] = '\0';
        }
        indentation = indent;
        itemsCount = 0;
    }
    Menu::operator bool() const
    {
        return titles[0] != '\0';
    }
    bool Menu::isEmpty() const
    {
        return titles[0] == '\0';
    }

    std::ostream &Menu::display(std::ostream &os) const
    {
        if (isEmpty())
        {
            os << "Invalid Menu!" << endl;
        }
        else if (itemsCount == 0)
        {
            os << titles << endl;
            os << "No Items to display!" << endl;
        }
        else
        {
            for (int j = 0; j < 4 * indentation; j++)
            {
                os << " ";
            }
            os << titles << endl;
            for (int loop1 = 0; loop1 < itemsCount; loop1++)
            {
                for (int loop2 = 0; loop2 < 4 * indentation; loop2++)
                {
                    os << " ";
                }
                os << loop1 + 1 << "- ";
                m_menuItems[loop1].display();
                cout << endl;
            }
            for (int i = 0; i < 4 * indentation; i++)
            {
                os << " ";
            }
            os << "> ";
        }
        return os;
    }

    Menu &Menu::operator=(const char *title)
    {
        if (title == nullptr)
        {
            titles[0] = '\0';
        }
        else
        {
            strncpy(titles, title, 50);
            titles[50] = '\0';
        }
        return *this;
    }

    void Menu::add(const char *content)
    {
        if (content == nullptr)
        {
            titles[0] = '\0';
        }
        else if (itemsCount < MAX_NO_OF_ITEMS)
        {
            strncpy(m_menuItems[itemsCount].contents, content, 50);
            m_menuItems[itemsCount].contents[50] = '\0';
            itemsCount++;
        }
    }

    Menu &Menu::operator<<(const char *content)
    {
        add(content);
        return *this;
    }
    int Menu::run() const
    {
        int selection = 0;

        display();
        if (itemsCount == 0)
        {
            return 0;
        }
        if (isEmpty())
        {
            return 0;
        }
        else
        {
            while (selection < 1 || selection > itemsCount)
            {
                cin >> selection;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid Integer, try again: ";
                }
                else if (selection < 1 || selection > itemsCount)
                {
                    cout << "Invalid selection, try again: ";
                }
            }
            cin.ignore(1000, '\n');
        }
        return selection;
    }
    Menu::operator int() const
    {
        return run();
    }
    void Menu::clear()
    {
        titles[0] = '\0';
        indentation = 0;
        itemsCount = 0;
    }
}
