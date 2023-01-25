// name - kuldeepsinh sandipsinh mahida
// college id - 167547215
// collegemail - kmahida1@myseneca.ca
// completion date - 20/9/2022 (20 th september)
// completion time - 9:00 pm
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "dictionary.h"

using namespace std;
namespace sdds
{
	struct dictionary dic = {0};
	struct dictionary dic1 ={0};
	int LoadDictionary(const char* filename)
	{
		
		FILE* file = fopen(filename, "r");
		if (file == NULL)
		{
			dic = dic1;
			return 1;
		}
		else
		{
			int i = 0;
			int j = 0;
			int l1 = 0;
			int j1 = 0;
			int i1 = 0;
			do
			{
				
				char k = fgetc(file);
				if ((k!='\n')&& (k != '\t'))
				{
					do
					{
						dic.w1[i].name[j] = k;
						k=fgetc(file);
						j++;
					} while (k != '\n');
					j = 0;
					i++;
			
				}
				k = fgetc(file);
				
				if (k == '\t')
				{
					do
					{
						k = fgetc(file);
						do
						{

							dic.w1[i1].wa1[l1].type[j1] = k;
							k = fgetc(file);
							j1++;
						} while (k != ':');
						j1 = 0;
						k = fgetc(file);
						k = fgetc(file);
						do
						{

							dic.w1[i1].wa1[l1].definition[j1] = k;
							k = fgetc(file);
							j1++;
						} while (k != '\n');
						j1 = 0;
						l1++;
						dic.w1[i1].numberofdefinitions++;
						k = fgetc(file);
					} while (k == '\t');
					i1++;
					l1 = 0;
				}
								
			} while (!(feof(file)));
			dic.numberofwords = i1;
			fclose(file);
			return 0;
		}
	}

	void SaveDictionary(const char* filename)
	{
		FILE* file2;
	    file2 = fopen(filename, "a");
		for (int i = 0; i < dic.numberofwords; i++)
		{
			fputs(dic.w1[i].name, file2);
			fputs("\n", file2);
			for (int j = 0;j< dic.w1[i].numberofdefinitions; j++)
			{
				
				fputs("\t", file2);
				fputs(dic.w1[i].wa1[j].type, file2);
				fputs(": ", file2);
				fputs(dic.w1[i].wa1[j].definition, file2);
				fputs("\n", file2);
				
			}
			fputs("\n", file2);
		}
		fputs("\n", file2);
		fclose(file2);

		
	
	}
	
	void DisplayWord(const char* word)
	{
		int check = 0;
		for (int i = 0; i < 8; i++)
		{
			if(strcmp(dic.w1[i].name,word) == 0)
			{
				check = 1;
				std::cout << "FOUND: [" << word << "] has [" << dic.w1[i].numberofdefinitions << "] definitions:\n";
				for (int j = 0; j < dic.w1[i].numberofdefinitions; j++)
				{
					std::cout << j + 1 << ". {" << dic.w1[i].wa1[j].type << "} " << dic.w1[i].wa1[j].definition<<"\n";
				}
			}
			
		}
		if (check == 0)
		{
			std::cout << "NOT FOUND: word [" << word << "] is not in the dictionary.\n";
		}
	}
	void AddWord(const char* word, const char* type, const char* definition)
	{

		int check = 0;
		for (int i = 0; i < 8; i++)
		{
			if (strcmp(dic.w1[i].name, word) == 0)
			{
				check = 1;
				strcpy(dic.w1[i].wa1[dic.w1[i].numberofdefinitions].type, type);
				strcpy(dic.w1[i].wa1[dic.w1[i].numberofdefinitions].definition, definition);
				dic.w1[i].numberofdefinitions++;
			}
		}
		if (check == 0)
		{
			strcpy(dic.w1[dic.numberofwords].name, word);
			strcpy(dic.w1[dic.numberofwords].wa1[0].definition, definition);
			strcpy(dic.w1[dic.numberofwords].wa1[0].type, type);
			dic.w1[dic.numberofwords].numberofdefinitions++;
			dic.numberofwords++;
			
		}
	}
	int UpdateDefinition(const char* word, const char* type, const char* definition)
	{
		int check = 0;
		int d;
		for (int i = 0; i < 8; i++)
		{
			if (strcmp(dic.w1[i].name, word) == 0)
			{
				if (dic.w1[i].numberofdefinitions>1)
				{
					check = 1;
					std::cout << "The word [" << word << "] has multiple definitions:\n";
					for (int j = 0; j < dic.w1[i].numberofdefinitions; j++)
					{
						std::cout << j + 1 << ". {" << dic.w1[i].wa1[j].type << "} " << dic.w1[i].wa1[j].definition << "\n";
					}
					std::cout << "Which one to update? ";
					std::cin>>d;
					//dic.w1[i].wa1[d].type = '\0';
					strcpy(dic.w1[i].wa1[d-1].type,type);
					strcpy(dic.w1[i].wa1[d-1].definition,definition);
				}
			}

		}
		if (check == 0)
		{
			std::cout << "NOT FOUND : word[" << word << "] is not in the dictionary.\n";
		}
		return 1;
	}

}