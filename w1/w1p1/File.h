/////////////////////////////////////////////////////
// Name -           Kuldeepsinh Sandipsinh Mahida ///
// college id -     167547215                     ///
// college e-mail - kmahida1@myseneca.ca          ///
/////////////////////////////////////////////////////
#ifndef sdds_File_H // replace with relevant names
#define sdds_File_H 
#include"ShoppingRec.h"

namespace sdds
{
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}

#endif