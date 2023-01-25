//Name :Kuldeepsinh Sandipsinh Mahida
//Student ID# :167547215
//email : kmahida1@myseneca.ca
//date of completion 1/10/2022
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider.This submitted
//piece of work is entirely of my own creation.
#ifndef _SDDS_CC_H_
#define _SDDS_CC_H_
namespace sdds
{
	class CC
	{
        private:
            char ccName[71];
            short c_verNum;
            short monOfExp;
            short yearOfExp;
            unsigned long long cardNum;
            bool validate(const char* ccName, unsigned long long cardNo, short cardVerificationNum, short monthOfExpiry, short yearOfExpiry)const;
            void prnNumber()const;
        public:
            void set();
            void display(int rowNum = 0) const;
            void cleanUp();
            bool isEmpty() const;
            void set(const char* cc_name, unsigned long long cc_no, short cardVerificationNum, short monthOfExpiry, short yearOfExpiry);
            bool read();
            ~CC();
	};
}
#endif // !_SDDS_CC_H_
