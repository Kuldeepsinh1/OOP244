/////////////////////////////////////////////////////
// Name -           Kuldeepsinh Sandipsinh Mahida ///
// college id -     167547215                     ///
// college e-mail - kmahida1@myseneca.ca          ///
/////////////////////////////////////////////////////
#ifndef sdds_ShoppingList_H // replace with relevant names
#define sdds_ShoppingList_H 

namespace sdds
{
	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();
}

#endif
