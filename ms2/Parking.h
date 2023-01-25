/*
Name:- Kuldeepsinh Sandipsinh Mahida
Student ID:- 167547215
submission date  - 20 november 2022
time - 5:42 pm
*/
#ifndef __SDDS_PARKING_H__
#define __SDDS_PARKING_H__

#include <iostream>
#include <string.h>
#include <iomanip>
#include "Menu.h"
namespace sdds
{
    class Parking
    {
        char* filesName;
        Menu parkMenu;
        Menu vehicleMenu;
        bool isEmpty() const;
        void parking_Status() const;
        void park_Vehicle();
        void return_Vehicle();
        void list_Parked_Vehicles() const;
        void find_Vehicle() const;
        bool close_Parking();
        bool exit_Parking_App() const;
        bool load_Data_File();
        void save_Data_File() const;

    public:
        Parking(const char* filename = nullptr);
        ~Parking();
        Parking(const Parking& src) = delete;
        Parking& operator=(const Parking& src) = delete;
        int run();
    };
}

#endif