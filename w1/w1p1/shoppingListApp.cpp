/////////////////////////////////////////////////////
// Name -           Kuldeepsinh Sandipsinh Mahida ///
// college id -     167547215                     ///
// college e-mail - kmahida1@myseneca.ca          ///
/////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include "Utils.h"
#include"ShoppingRec.h"
#include "File.h"
#include "ShoppingList.h"


using namespace std;
using namespace sdds;
const char* SHOPPING_DATA_FILE = "shoppinglist.csv";
// set to false when compling on Linux
const bool APP_OS_WINDOWS = false;
int listMenu();

    int main() {
        bool done = false;
        loadList();
        while (!done) {
            system(APP_OS_WINDOWS ? "cls" : "clear");
            switch (listMenu())
            {
            case 1:
                toggleBought();
                break;
            case 2:
                addItemToList();
                break;
            case 3:
                removeItemfromList();
                break;
            case 4:
                removeBoughtItems();
                break;
            case 5:
                clearList();
                break;
            default:
                done = true;
            }
        }
        saveList();
        return 0;
    }
       
        int listMenu() {
            cout << "-->>> My Shopping List <<<--" << endl;
            displayList();
            cout << "----------------------------" << endl
                << "1- Toggle bought Item" << endl
                << "2- Add Shopping Item" << endl
                << "3- Remove Shopping Item" << endl
                << "4- Remove bought Items" << endl
                << "5- Clear List" << endl
                << "0- Exit" << endl << "> ";
            return readInt(0, 5);
        }
    

