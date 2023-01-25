// name - kuldeepsinh sandipsinh mahida
// student id - 167547215
// college mail - kmahida1@myseneca.ca
// completed 31 october
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
#include<iomanip>
using namespace std;
namespace sdds {
   Numbers::Numbers() {
      setEmpty();
      m_isOriginal = false;
   }

   Numbers::Numbers(const char* filename) {
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         deallocate();
         setEmpty();
         m_isOriginal = false;
      }
   }

   Numbers::Numbers(const Numbers& number){
       setEmpty();
       *this = number;
   }

   Numbers& Numbers::operator=(const Numbers& number){
       if (this != &number) {
           if (m_filename) {
               delete[] m_filename;
           }

           if (m_numbers) {
               delete[] m_numbers;
           }
           setEmpty();
           m_isOriginal = false;
           m_numCount = number.m_numCount;
           m_numbers = new double[m_numCount];
           for (int i = 0; i < m_numCount; i++){
               m_numbers[i] = number.m_numbers[i];
           }

       }
       return *this;
   }

   Numbers& Numbers::sort(bool ascending){
       int i, j, smallest;
       double temp;

       for (i = 0; i < m_numCount; i++)
       {
           smallest = i;

           for (j = i + 1; j < m_numCount; j++)
           {
               
               if ((ascending && m_numbers[j] < m_numbers[smallest]) || (!ascending && m_numbers[j] > m_numbers[smallest]))
               {
                   smallest = j;
               }
           }

           if (smallest != i)
           {
               temp = m_numbers[i];
               m_numbers[i] = m_numbers[smallest];
               m_numbers[smallest] = temp;
           }
       }
       return *this;
   }

   Numbers Numbers::operator-() const
   {
       Numbers number(*this);
       number.sort(false);
       return number;
   }

   Numbers Numbers::operator+() const
   {
       Numbers number(*this);
       number.sort(true);
       return number;
   }

   Numbers& Numbers::operator+=(const double d)
   {
       double* temp = new double[m_numCount + 1];
       for (int i = 0; i < m_numCount; i++){
           temp[i] = m_numbers[i];
       }
       temp[m_numCount] = d;
       if (m_numbers) {
           delete[] m_numbers;
       }
       m_numbers = temp;
       m_numCount++;
       return *this;
   }

   ostream& Numbers::display(ostream& ostr) const
   {
       if (isEmpty()) {
           ostr << "Empty list";
       }
       else {
           ostr << "=========================" << endl;
           if(m_isOriginal)
               ostr<< m_filename << endl;
           else
           ostr<<"*** COPY ***"<< endl;
           for (int i = 0; i < m_numCount; i++)
           {
               ostr << setprecision(2) << fixed << m_numbers[i];
               if(i != (m_numCount - 1))
                   ostr<<", ";
           }
           ostr << endl;
           ostr << "-------------------------" << endl;
           ostr << "Total of " << m_numCount << " number(s)" << endl;
           ostr << setw(17) << left << "Largest number: " << max() << endl;
           ostr << setw(17) << left << "Smallest number: " << min() << endl;
           ostr << setw(17) << left << "Average: " << average() << endl;
           ostr << "=========================";
       }
       return ostr;
   }


   int Numbers::numberCount()
   {
       int i= 0;
       ifstream out(m_filename);
       char c;
       while (out) {
           out.get(c);
           if(out)
           if (c == '\n') {
               i++;
           }
       }
       out.close();
       return i;
   }

   bool Numbers::load()
   {
       int read = 0;
       if (m_numCount > 0) {
           m_numbers = new double[m_numCount];
           ifstream out(m_filename);
           while (out) {
               out >>m_numbers[read];
               if (out) {
                   read++;
               }
           }
           out.close();
        }
       return read==m_numCount;
   }

   void Numbers::save(){
       if(m_isOriginal && !isEmpty()){
           ofstream out(m_filename);
           for (int i = 0; i < m_numCount; i++)
           {
               out<<setprecision(2) << fixed << m_numbers[i] << endl;
           }
           out.close();
       }
   }

   Numbers::~Numbers() {
      save();
      deallocate();
   }

   bool Numbers::isEmpty() const {
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() {
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }

   void Numbers::deallocate() {
      delete[] m_filename;
      delete[] m_numbers;
   }

   void Numbers::setFilename(const char* filename) {
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }

  

   double Numbers::average() const {
      double average = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            average += m_numbers[i];
         average = average / m_numCount;
      }
      return average;
   }

   double Numbers::min() const {
      double smallest = 0.0;
      if (!isEmpty()) {
         smallest = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (smallest > m_numbers[i]) smallest = m_numbers[i];
      }
      return smallest;
   }
   double Numbers::max() const {
      double largest = 0.0;
      if(!isEmpty()) {
         largest = m_numbers[0];
         for(int i = 1; i < m_numCount; i++)
            if(largest < m_numbers[i]) largest = m_numbers[i];
      }
      return largest;
   }
  

   ostream& operator<<(ostream& os, const Numbers& N)
   {
       return N.display(os);
   }

   istream& operator>>(istream& istr, Numbers& N)
   {
       double num;
       istr >> num;
       if (!istr.fail()) {
           N += num;
       }
       return istr;
   }

}
