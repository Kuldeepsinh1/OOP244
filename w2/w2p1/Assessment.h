// name - kuldeepsinh sandipsinh mahida
// college id - 167547215
// collegemail - kmahida1@myseneca.ca
// completion date - 23/9/2022 (23 th september)
// completion time - 8:48 pm
#ifndef SDDS_ASSESSMENT_H 
#define SDDS_ASSESSMENT_H
namespace sdds
{
	struct Assessment
	{
		double* m_mark;
		char* m_title;
	};
	
	bool read(int& value, FILE* fptr);
	
	bool read(double& value, FILE* fptr);
	
	bool read(char* cstr, FILE* fptr);
	
	bool read(Assessment& asmnt, FILE* fptr);
	
	void freeMem(Assessment*& aptr, int size);
	
	int read(Assessment*& aptr, FILE* fptr);
}
#endif
