/*
Name:- Kuldeepsinh Sandipsinh Mahida
Student ID:- 167547215
submission date  - 9 december 2022
time - 10:42 pm
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Parking.h"
#include "Car.h"
#include "Motorcycle.h"

using namespace std;

namespace sdds
{
    Parking::Parking(const char* filename, int noOfSpots) : parkMenu("Parking Menu, select an action:", 0),
        vehicleMenu("Select type of the vehicle:", 1)
    {
        int i = 0;
        for (i = 0; i < MAXPARKSPOTS; i++)
        {
            v1[i] = nullptr;
        }
        if (noOfSpots < 10 || noOfSpots > MAXPARKSPOTS)
        {
            FilesName = nullptr;
            spotsavailable = 0;
            spotsutilized = 0;
        }
        else
        {
            spotsavailable = noOfSpots;
            spotsutilized = 0;
            if (filename == nullptr || filename[0] == '\0')
            {
                FilesName = nullptr;
            }
            else
            {
                FilesName = new char[strlen(filename) + 1];
                strcpy(FilesName, filename);
            }
            if (!load_Data_File())
            {
                cout << "Error in data file" << endl;
            }
            parkMenu << "Park Vehicle"
                << "Return Vehicle"
                << "List Parked Vehicles"
                << "Find Vehicle"
                << "Close Parking (End of day)"
                << "Exit Program";
            vehicleMenu << "Car"
                << "Motorcycle"
                << "Cancel";
        }
    }

    Parking::~Parking()
    {
        save_Data_File();
        delete[] FilesName;
        FilesName = nullptr;
        int i = 0;
        for (i = 0; i < spotsavailable; i++)
        {
            delete v1[i];
            v1[i] = nullptr;
        }
    }

    bool Parking::isEmpty() const
    {
        return FilesName == nullptr;
    }

    void Parking::parking_Status() const
    {
        cout << "****** Valet Parking ******" << endl;
        cout << "*****  Available spots: ";
        cout << setw(4) << left << (spotsavailable - spotsutilized);
        cout << " *****" << endl;
    }

    void Parking::park_Vehicle()
    {


        if (spotsutilized == spotsavailable)
        {
            cout << "Parking is full" << endl;
        }
        else
        {
            Vehicle* v = nullptr;
            int selection = vehicleMenu.run();
            if (selection == 1)
            {
                v = new Car;
            }
            else if (selection == 2)
            {
                v = new Motorcycle;
            }
            else
            {
                cout << "Parking cancelled" << endl;
                cout << "Press <ENTER> to continue....";
                cin.get();
                return;
            }
            v->setCsv(false);
            cin >> *v;
            for (int i = 0; i < spotsavailable; i++)
            {
                if (v1[i] == nullptr)
                {
                    v1[i] = v;
                    v1[i]->setParkingSpot(i + 1);
                    cout << endl
                        << "Parking Ticket" << endl;
                    v1[i]->write(cout);
                    cout << endl;
                    spotsutilized++;
                    break;
                }
            }
        }
        cout << "Press <ENTER> to continue....";
        cin.get();
    }

    void Parking::return_Vehicle()
    {
        cout << "Return Vehicle" << endl;
        cout << "Enter License Plate Number: ";
        string licencePlate;
        cin >> licencePlate;
        while (licencePlate.length() > 8 || licencePlate.length() < 1)
        {
            cout << "Invalid Licence Plate, try again: ";
            cin >> licencePlate;
        }

        for (size_t i = 0; i < licencePlate.length(); i++)
        {
            licencePlate[i] = toupper(licencePlate[i]);
        }

        cout << endl;
        int i;
        for (i = 0; i < spotsavailable; i++)
        {
            if (v1[i] != nullptr && *v1[i] == licencePlate.c_str())
            {
                v1[i]->setCsv(false);
                cout << "Returning:" << endl
                    << *v1[i] << endl;
                delete v1[i];
                v1[i] = nullptr;
                spotsutilized--;
                cout << "Press <ENTER> to continue....";
                cin.get();
                if (cin.peek() == '\n')
                {
                    cin.get();
                }
                return;
            }
        }
        cout << "License plate " << licencePlate << " Not found" << endl;
        cout << endl;
        cout << "Press <ENTER> to continue....";
        cin.get();
        if (cin.peek() == '\n')
        {
            cin.get();
        }
    }

    void Parking::list_Parked_Vehicles() const
    {
        cout << "*** List of parked vehicles ***" << endl;

        for (int i = 0; i < spotsavailable; i++)
        {
            if (v1[i] != nullptr)
            {
                v1[i]->setCsv(false);
                v1[i]->write(cout);
                cout << "-------------------------------";
                cout << endl;
            }
        }
        cout << "Press <ENTER> to continue....";
        cin.get();
    }

    void Parking::find_Vehicle() const
    {
        cout << "Vehicle Search" << endl;

        string licensePlate;
        cout << "Enter License Plate Number: ";
        getline(cin, licensePlate);
        while (licensePlate.length() < 1 || licensePlate.length() > 8)
        {
            cout << "Invalid License Plate, try again: ";
            getline(cin, licensePlate);
        }

        for (size_t i = 0; i < licensePlate.length(); i++)
        {
            licensePlate[i] = toupper(licensePlate[i]);
        }

        for (int i = 0; i < spotsavailable; i++)
        {
            if (v1[i] != nullptr)
            {
                if (*v1[i] == licensePlate.c_str())
                {
                    cout << endl
                        << "Vehicle found:" << endl;
                    v1[i]->setCsv(false);
                    v1[i]->write(cout);
                    cout << endl
                        << "Press <ENTER> to continue....";
                    cin.get();
                    return;
                }
            }
        }
        cout << endl
            << "License plate " << licensePlate << " Not found" << endl
            << endl;
        cout << "Press <ENTER> to continue....";
        cin.get();
    }

    bool Parking::close_Parking()
    {

        if (spotsutilized == 0)
        {
            cout << "Closing Parking" << endl;
            return true;
        }
        else
        {
            char response;
            cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
            cout << "Are you sure? (Y)es/(N)o: ";
            while (true)
            {
                cin >> response;
                if (response == 'Y' || response == 'y')
                {
                    cout << "Closing Parking" << endl;

                    for (int i = 0; i < spotsavailable; i++)
                    {
                        if (v1[i] != nullptr)
                        {
                            cout << endl
                                << "Towing request" << endl;
                            cout << "*********************" << endl;
                            v1[i]->setCsv(false);
                            cout << *v1[i];
                            delete v1[i];
                            v1[i] = nullptr;
                        }
                    }
                    return true;
                }
                else if (response == 'N' || response == 'n')
                {
                    return false;
                }
                else
                {
                    cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                }
            }
        }
    }

    bool Parking::exit_Parking_App() const
    {

        char response;
        cout << "This will terminate the program!" << endl;
        cout << "Are you sure? (Y)es/(N)o: ";
        while (true)
        {
            cin >> response;
            if (response == 'Y' || response == 'y')
            {
                return true;
            }
            else if (response == 'N' || response == 'n')
            {
                return false;
            }
            else
            {
                cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            }
        }
    }

    bool Parking::load_Data_File()
    {
        bool flag = false;
        if (FilesName != nullptr)
        {
            ifstream datafile(FilesName);

            if (!datafile.is_open())
            {
                if (spotsutilized == 0 && spotsavailable == 0)
                {
                    flag = true;
                }
            }
            else
            {
                char c;
                int i = 0;
                while (i < spotsavailable)
                {
                    datafile >> c;
                    datafile.ignore();
                    Vehicle* v = nullptr;
                    if (datafile.fail())
                    {
                        break;
                    }
                    if (c == 'M')
                    {
                        v = new Motorcycle;
                    }
                    else if (c == 'C')
                    {
                        v = new Car;
                    }
                    else
                    {
                        v = nullptr;
                    }
                    if (v != nullptr)
                    {
                        v->setCsv(true);
                        datafile >> *v;
                        if (datafile.fail())
                        {
                            flag = false;
                            delete v;
                            v = nullptr;
                            break;
                        }
                        else
                        {
                            v1[v->getParkingSpot() - 1] = v;
                            flag = true;
                            spotsutilized++;
                        }
                    }
                    i++;
                }
            }
        }
        return flag;
    }

    void Parking::save_Data_File() const
    {
        if (FilesName != nullptr)
        {
            ofstream datafile(FilesName);
            if (datafile.is_open())
            {
                for (int i = 0; i < spotsavailable; i++)
                {
                    if (v1[i] != nullptr)
                    {
                        v1[i]->setCsv(true);
                        datafile << *v1[i];
                    }
                }
            }
        }
    }

    int Parking::run()
    {
        int selection = 0;
        if (!isEmpty())
        {
            bool flag = true;
            do
            {
                parking_Status();
                selection = parkMenu.run();
                switch (selection)
                {
                case 1:
                    park_Vehicle();
                    break;
                case 2:
                    return_Vehicle();
                    break;
                case 3:
                    list_Parked_Vehicles();
                    break;
                case 4:
                    find_Vehicle();
                    break;
                case 5:
                    if (close_Parking())
                    {
                        flag = false;
                    }
                    break;
                default:
                    if (exit_Parking_App())
                    {
                        flag = false;
                        cout << "Exiting program!" << endl;
                    }
                    break;
                }
            } while (flag);
            if (cin.peek() == '\n')
            {
                cin.get();
            }
            return 0;
        }
        return 1;
    }

}