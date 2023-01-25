/*
                                          Workshop 10
                                            Part 1

Name:- Kuldeepsinh Sandipsinh Mahida
Student ID:- 167547215
E-mail:- kmahida1@myseneca.ca
Course:- OOP 244
Submission Date:- 02/12/2022
Submission Time:- 11:18
*/

#include <iostream>
#ifndef SDDS_SEARCH_H_
#define SDDS_SEARCH_H_
#include "Collection.h"


namespace sdds 
{
    using namespace std;
        class Search
        {
        public:
            template<typename T>
            bool search(const T array[], int arrlength, const char* key, Collection<T>& collection);
        };

       
        template<typename T>
        bool Search::search(const T array[], int array_length, const char* key, Collection<T>& collection)
        {
            bool Key = false;
            for (int k = 0; k < array_length; k++) 
            {
               if (array[k] == key) 
               {
                   collection.add(array[k]);
                   Key = true;
               }
            }
            return Key;
        }

}
#endif // !SDDS_SEARCH_H_