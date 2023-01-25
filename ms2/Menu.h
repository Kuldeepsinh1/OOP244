/*
Name:- Kuldeepsinh Sandipsinh Mahida
Student ID:- 167547215
submission date  - 14 november 2022
time - 8:00 pm
*/

#ifndef __SDDS_MENU_H__
#define __SDDS_MENU_H__

namespace sdds
{
    class Menu;

    class MenuItem
    {
        char contents[51];
        friend class Menu;
        MenuItem(const char *content = nullptr);
        std::ostream &display(std::ostream &os = std::cout) const;
        MenuItem(const MenuItem &src) = delete;
        MenuItem &operator=(const MenuItem &src) = delete;
    };

    const int MAX_NO_OF_ITEMS = 10;

    class Menu
    {
        char titles[51];
        MenuItem m_menuItems[MAX_NO_OF_ITEMS];
        int itemsCount;
        int indentation;

    public:
        Menu(const char *title = nullptr, int indentation = 0);
        Menu(const Menu &src) = delete;
        Menu &operator=(const Menu &src) = delete;
        operator bool() const;
        bool isEmpty() const;
        std::ostream &display(std::ostream &os = std::cout) const;
        Menu &operator=(const char *title);
        void add(const char *content);
        Menu &operator<<(const char *content);
        int run() const;
        operator int() const;
        void clear();
    };
}

#endif