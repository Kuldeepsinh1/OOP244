// name - kuldeepsinh sandipsinh mahida
// college id - 167547215
// collegemail - kmahida1@myseneca.ca
// completion date - 26/9/2022 (26 th september)
// completion time - 11:13 pm
#define _CRT_SECURE_NO_WARNINGS
#include "Population.h"
#include "File.h"
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
namespace sdds {
	data* pointer;
	bool load(const char filename[])
	{


		if (openFile(filename) == 1)
		{

			int k = 0;
			int populationcount = noOfRecords();
			char postalcode[128];
			pointer = new data[populationcount];
			FILE* pop;
			pop = fopen(filename, "r");
			int i = 0;
			do
			{
				
				fscanf(pop, "%3s", postalcode);
				pointer[i].postal = new char((strlen(postalcode)) + 1);
				strcpy(pointer[i].postal, postalcode);
				fgetc(pop);
				fscanf(pop, "%d", &k);
				pointer[i].population = k;
				fgetc(pop);
				i++;
			} while (!(feof(pop)));
			fclose(pop);
			if (populationcount == (i - 1))

			{
				sort();
				return true;
			}
			else
			{
				std::cout << "Error: incorrect number of records read; the data is possibly corrupted!<ENDL>";
				return false;
			}
		}
		else
		{
			std::cout << "Could not open data file: FILENAME<ENDL>";
			return false;
		}
	}
	void sort()
	{
		int populationcount = noOfRecords();
		for (int i = 0; i < populationcount; i++)
		{
			for (int j = 0; j < populationcount - 1; j++)
			{
				if (pointer[j].population > pointer[j + 1].population)
				{
					int temp = pointer[j + 1].population;
					pointer[j + 1].population = pointer[j].population;
					pointer[j].population = temp;
					char temporary[4];
					strcpy(temporary, pointer[j + 1].postal);
					strcpy(pointer[j + 1].postal, pointer[j].postal);
					strcpy(pointer[j].postal, temporary);
				}
			}
		}
	}
	void display()
	{
		int populationcount = noOfRecords();
		int total = 0;
		std::cout << "Postal Code: population\n-------------------------\n";
		for (int i = 0; i < populationcount; i++)
		{
			std::cout << (i + 1) << "- " << pointer[i].postal << ":  " << pointer[i].population << "\n";
			total += pointer[i].population;
		}
		std::cout << "-------------------------\n";
		std::cout << "Population of Canada: " << total << "\n";
	}
	void deallocateMemory()
	{
		int populationcount = noOfRecords();
		for (int i = 0; i < populationcount; i++)
		{
			delete[] pointer[i].postal;
		}
		delete[] pointer;
	}
}