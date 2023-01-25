// name - kuldeepsinh sandipsinh mahida
// college id - 167547215
// collegemail - kmahida1@myseneca.ca
// completion date - 20/9/2022 (20 th september)
// completion time - 9:00 pm
#ifndef SDDS_DICTIONARY_H // replace with relevant names
#define SDDS_DICTIONARY_H 

namespace sdds
{
	struct wordattributes
	{
		char type[20];
		char definition[1500];
		
	};
	struct word
	{
		int numberofdefinitions;
		char name[100];
		struct wordattributes wa1[8];
	};
	
	struct dictionary
	{
		int numberofwords;
		struct word w1[100];
		//as a file can only have 8 words.
	};
	// the function load dictionary is used to load any file whose nemw is passed in parameters. 
	int LoadDictionary(const char* filename);
	void SaveDictionary(const char* filename);
	void DisplayWord(const char* word);
	void AddWord(const char* word, const char* type, const char* definition);
	int UpdateDefinition(const char* word, const char* type, const char* definition);
}
#endif