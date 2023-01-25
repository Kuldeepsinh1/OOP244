/////////////////////////////////////////////////////
// Name -           Kuldeepsinh Sandipsinh Mahida ///
// college id -     167547215                     ///
// college e-mail - kmahida1@myseneca.ca          ///
/////////////////////////////////////////////////////
#ifndef sdds_ShoppingRec_H // replace with relevant names
#define sdds_ShoppingRec_H 

namespace sdds
{

    const int MAX_TITLE_LENGTH = 50;
    const int MAX_QUANTITY_VALUE = 50;
    struct ShoppingRec
    {
        char m_title[MAX_TITLE_LENGTH + 1];
        int m_quantity;
        bool m_bought;
    };
    ShoppingRec getShoppingRec();
    void displayShoppingRec(const ShoppingRec* shp);
    void toggleBoughtFlag(ShoppingRec* rec);
    bool isShoppingRecEmpty(const ShoppingRec* shp);
}
#endif
