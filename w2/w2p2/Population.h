// name - kuldeepsinh sandipsinh mahida
// college id - 167547215
// collegemail - kmahida1@myseneca.ca
// completion date - 26/9/2022 (26 th september)
// completion time - 11:13 pm
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {
	struct data
	{
		char *postal;
		int population;
	};
	bool load(const char filename[]);
	void sort();
	void display();
	void deallocateMemory();

}
#endif // SDDS_POPULATION_H_