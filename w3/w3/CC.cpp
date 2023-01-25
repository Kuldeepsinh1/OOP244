  //Name :Kuldeepsinh Sandipsinh Mahida
//Student ID# :167547215
//email : kmahida1@myseneca.ca
//date of completion - 1/10/2022
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider.This submitted
//piece of work is entirely of my own creation.
//*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "string.h"
#include "CC.h"
#include "Utils.h"

using namespace std;

namespace sdds
{
	
	void CC::prnNumber()const
	{
		unsigned long long tempCardNumber = cardNum;
        unsigned long long div = 1000000000000000;
		int temp = 0;
		while (tempCardNumber >= 10)
		{
			if (temp == 4)
			{
				cout << " ";
				temp = 0;
			}
			cout << tempCardNumber / div;
			tempCardNumber = tempCardNumber%div;
			div /= 10;
			temp += 1;

		}
		cout << tempCardNumber;
		while (div >= 10)
		{
			cout << 0;
			div /= 10;
		}
	}
	void CC::set()
	{
		ccName[0] = '\0';
		c_verNum = 0;
		monOfExp = 0;
		yearOfExp = 0;
		cardNum = 0;

	}

	void CC::cleanUp()
	{
		set();
	}
	bool CC::isEmpty() const
	{
		return ccName[0] == '\0';
		
	}
	void CC::set(const char* cc_name, unsigned long long cc_no, short cvv1, short expMon1, short expYear1)
	{
		if (!(validate(cc_name, cc_no, cvv1, expMon1, expYear1)))
		{

			ccName[0] = '\0';
			return;
			
		}
		else
		{
			
			if (cc_name == nullptr)
			{
				ccName[0] = '\0';
			}
			else
			{
				strcpy(ccName, cc_name,71);
			}
			cardNum = cc_no;
			c_verNum = cvv1;
			monOfExp = expMon1;
			yearOfExp = expYear1;
		}
	}
	bool CC::validate(const char* ccName, unsigned long long cardNo1, short cardVerificationNum, short monthOfExpiry, short yearOfExpiry)const
	{
		if (ccName == nullptr)
		{
			return false;

		}
		else
		{
			if (ccName[0] == '\0' || ccName[1] == '\0' || ccName[2] == '\0')
			{
				return false;
			}
			else
			{
				if (!(cardNo1 >= 4000000000000000 && cardNo1 <= 4099999999999999))
				{
					return false;
				}
				else
				{
					if (!(cardVerificationNum >= 100 && cardVerificationNum <= 999))
					{
						return false;
					}
					else
					{
						if (!(monthOfExpiry >= 1 && monthOfExpiry <= 12))
						{
							return false;
						}
						else
						{
							if (!(yearOfExpiry >= 22 && yearOfExpiry <= 32))
							{
								return false;
							}
							else
							{
								return true;
							}
						}
					}
				}
			}
		}


	}
	bool CC::read()
	{
		
		cin.clear();
		//fflush(stdin);
		cout << "Card holder name: ";
		
		cin >> ccName;
		if (cin)
		{
			string num;
			cout << "Credit card number: "; 
			cin >> num;
			bool checkVal = true;
			for (int i = 0; num[i] != '\0'; i++)
			{
				if (!isdigit(num[i]))
				{
					checkVal = false; 
					break;
				}
			}
			if (checkVal)
			{
				cardNum = stoull(num);
			}
			else
			{
				return false;
			}
			if (cin)
			{
				cout << "Card Verification Value (CVV): "; 
				cin >> num;
				checkVal = true;
				for (int i = 0; num[i] != '\0'; i++)
				{
					if (!isdigit(num[i]))
					{
						checkVal = false;
						break;
					}
				}
				if (checkVal)
				{
					cardNum = stoi(num);
				}
				else
				{
					cin.clear();
					return false;
				}
			}
			else
			{
				cin.clear();
				return false;
			}
			if(cin)
			{
	
				cout << "Expiry month and year (MM/YY): ";
				cin >> monOfExp;
				cin.ignore();
				if (cin)
				{
					cin >> yearOfExp;
					if (cin)
					{
						if (monOfExp >= 1 && monOfExp <= 12 && yearOfExp >= 22 && yearOfExp <= 32)

						{
							cin.clear();
							return true;
						}
						else
						{
							cin.clear();
							cin.ignore(1000, '\n');
							return false;
						}
					}
					else
					{
						cin.clear();
						
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		return false;
	}
	void CC::display(int rowNum ) const
	{
		if (!isEmpty())
		{
			if (rowNum > 0)
			{


				cout << "| " << setw(3) << rowNum << " |";

				cout << " ";
				int i;
				for (i = 0; i < 30 && ccName[i] != '\0'; i++)
				{
					cout << ccName[i];
				}
				while (i < 30)
				{
					cout << " ";
					i++;
				}
				cout << " | ";
				prnNumber();
				cout << " | " << c_verNum << " | ";
				cout << setw(2) << monOfExp << "/" << yearOfExp << " |\n";

			}
			else
			{
				cout << "Name: " << ccName << "\n";
				cout << "Creditcard No: ";
				prnNumber();
				cout << "\nCard Verification Value: " << c_verNum << endl;
				cout << "Expiry Date: " << monOfExp << "/" << yearOfExp << endl;
			}
		}
		else
		{

			cout << "Invalid Credit Card Record\n";	
			return;
		}
	}

	CC::~CC()
	{
	}
}
