/*
Name:- Kuldeepsinh Sandipsinh Mahida
Student ID:- 167547215
submission date  - 9 december 2022
time - 10:42 pm
*/
#ifndef __SDDS_PARKING_H__
#define __SDDS_PARKING_H__

#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include "Menu.h"
#include "Vehicle.h"

const int MAXPARKSPOTS = 100;
namespace sdds
{
    class Parking
    {
        char* FilesName;
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
        Parking(const char* filename ,int noOfSpots);
        ~Parking();
        Parking(const Parking& src) = delete;
        Parking& operator=(const Parking& src) = delete;
        int run();
        int spotsutilized;
        int spotsavailable;
        Vehicle* v1[MAXPARKSPOTS];
        //v1 = new vehicle [MAXPARKSPOTS];
    };
}

#endif