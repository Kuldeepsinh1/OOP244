// name - kuldeepsinh sandipsinh mahida
// college id - 167547215
// collegemail - kmahida1@myseneca.ca
// completion date - 23/9/2022 (23 th september)
// completion time - 8:48 pm
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<cstdio>
#include "Assessment.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
	
	//Reads one integer from the fptr file into the value reference and returns true if it was successful, 
	//otherwise, it will return false
	bool read(int& value, FILE* fptr)
	{
		int input = fscanf(fptr, "%d", &value);
		if (input == 1)
		{
			return 1;
		}
		else
		{
			return 0;
		}

	}

	//Reads one double from the fptr file into the value reference and returns true if it was successful, 
	//otherwise, it will return false
	
	bool read(double& value, FILE* fptr)
	{
		int input = fscanf(fptr, "%lf", &value);
		if (input == 1)
		{
			return 1;
		}
		else
		{
			return 0;
		}

	}

	//Skips a comma and then reads a cstring no longer than 60 characters from the fptr file into the address, 
	//cstr and returns true if it was successful, otherwise, it will return false
	
	bool read(char* cstr, FILE* fptr)
	{
		int input = fscanf(fptr, ",%60[^\n]\n", cstr);
		if (input == 1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	//First it will try to read a double value for the mark and a string for title into a temporary local double 
	//variable and a 60 character lone cString (+1 for null).
	
	bool read(Assessment& asmnt, FILE* fptr)
	{
		double mark = 0;
		bool input = read(mark, fptr);
		char title[61];
		bool input_2 = read(title, fptr);
		if (input && input_2)
		{
			asmnt.m_mark = new double;
			*asmnt.m_mark = mark;

			int length = strlen(title);
			asmnt.m_title = new char[length + 1];
			strcpy(asmnt.m_title, title, length);
			return true;
		}
		else
		{
			return false;
		}
	}
	
	//This function will receive a reference of a dynamic Assessment array and its size. 
	//The function then will delete the dynamic Assessment array as follows:
	
	void freeMem(Assessment*& aptr, int size)
	{
		int i = 0;
		for (i = 0; i < size; i++)
		{
			delete aptr[i].m_mark;
			aptr[i].m_mark = nullptr;
			delete[] aptr[i].m_title;
			aptr[i].m_title = nullptr;
		}
		delete[] aptr;
		aptr = nullptr;

	}
	
	//This read function receives a reference of an Assessment pointer (to hold a dynamic array) 
	//and a file pointer from which it will read the assessment records into a newly allocated 
	//dynamic array.
	
	int read(Assessment*& aptr, FILE* fptr)
	{
		int size = 0;
		bool input = read(size, fptr);
		if (input)
		{
			aptr = new Assessment[size];
			int i = 0;
			for (i = 0; i < size; i++)
			{
				aptr[i].m_mark = nullptr;
				aptr[i].m_title = nullptr;
			}
			for (i = 0; i < size; i++)
			{
				bool input_2 = read(aptr[i], fptr);
				if (!input_2)
				{
					freeMem(aptr, size);
					return 0;
				}
			}
			return size;
		}
		else
		{
			return 0;
		}
	}
}