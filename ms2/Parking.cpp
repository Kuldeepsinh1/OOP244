/*
Name:- Kuldeepsinh Sandipsinh Mahida
Student ID:- 167547215
submission date  - 20 november 2022
time - 5:42 pm
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Parking.h"

using namespace std;

namespace sdds
{
    Parking::Parking(const char* filename) : parkMenu("Parking Menu, select an action:", 0),
        vehicleMenu("Select type of the vehicle:", 1)
    {
        if (filename == nullptr || filename[0] == '\0')
        {
            filesName = nullptr;
        }
        else
        {
            filesName = new char[strlen(filename) + 1];
            strcpy(filesName, filename);
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
    Parking::~Parking()
    {
        save_Data_File();
        delete[] filesName;
        filesName = nullptr;
    }
    bool Parking::isEmpty() const
    {
        return filesName == nullptr;
    }
    void Parking::parking_Status() const
    {
        cout << "****** Valet Parking ******" << endl;
    }
    void Parking::park_Vehicle()
    {
        int selection = vehicleMenu.run();
        if (selection == 1)
        {
            
            cout << "---------------------------------" << endl;
            cout << "Parking Car" << endl;
            cout << "---------------------------------" << endl
                << endl;
        }
        else if (selection == 2)
        {
            
            cout << "---------------------------------" << endl;
            cout << "Parking Motorcycle" << endl;
            cout << "---------------------------------" << endl
                << endl;
        }
        else
        {
            
            cout << "---------------------------------" << endl;
            cout << "Cancelled parking" << endl;
            cout << "---------------------------------" << endl
                << endl;
        }
    }
    void Parking::return_Vehicle()
    {
        cout << "---------------------------------" << endl;
        cout << "Returning Vehicle" << endl;
        cout << "---------------------------------" << endl
            << endl;
    }
    void Parking::list_Parked_Vehicles() const
    {
        cout << "---------------------------------" << endl;
        cout << "Listing Parked Vehicles" << endl;
        cout << "---------------------------------" << endl
            << endl;
    }
    void Parking::find_Vehicle() const
    {
        cout << "---------------------------------" << endl;
        cout << "Finding a Vehicle" << endl;
        cout << "---------------------------------" << endl
            << endl;
    }
    bool Parking::close_Parking()
    {
        char c;
        cout << "This will close the parking; All the vehicles will be removed!" << endl;
        cout << "Are you sure? (Y)es/(N)o: ";
        while (true)
        {
            cin >> c;
            if (c == 'Y' || c == 'y')
            {
                return true;
            }
            else if (c == 'N' || c == 'n')
            {
                return false;
            }
            else
            {
                cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            }
        }
    }
    bool Parking::exit_Parking_App() const
    {
        char c;
        cout << "This will terminate the application and save the data!" << endl;
        cout << "Are you sure? (Y)es/(N)o: ";
        while (true)
        {
            cin >> c;
            if (c == 'Y' || c == 'y')
            {
                return true;
            }
            else if (c == 'N' || c == 'n')
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
        if (filesName != nullptr)
        {
            cout << "---------------------------------" << endl;
            cout << "loading data from " << filesName << endl;
            cout << "---------------------------------" << endl
                << endl;

            flag = true;
        }
        return flag;
    }
    void Parking::save_Data_File() const
    {
        if (filesName != nullptr)
        {
            cout << "---------------------------------" << endl;
            cout << "Saving data into " << filesName << endl;
            cout << "---------------------------------" << endl
                << endl;
        }
    }
    int Parking::run()
    {
        bool flag = true;
        int selection = 0;
        if (!isEmpty())
        {
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
                        cout << "Ending application!" << endl;
                    }
                    break;
                default:
                    if (exit_Parking_App())
                    {
                        flag = false;
                        cout << "Exiting application!" << endl;
                    }
                    break;
                }
            } while (flag);
            return 0;
        }
        return 1;
    }

}
