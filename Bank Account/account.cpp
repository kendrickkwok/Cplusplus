/*************************************
 * Kendrick Kwok
 * 912351666
 * kendrick.j.kwok@gmail.com
 * Dev-C++ 5.7.1
 *************************************/

#include "account.h"


//pushing in inputfile, overloading >> operator
ifstream& operator >> (ifstream& ifs, Account& acc )
{
	ifs >> acc.id >> acc.is_budget_account >> acc.balance >> acc.title;
  	return ifs;             
}

  //pushing output file stream, overloading << operator
ofstream& operator << (ofstream& ofs, const Account& acc)
{
//setprecision(2) + fixed used to show decimal in program
  ofs << fixed << setprecision(2) << acc.id
  << " " << acc.is_budget_account << " " 
  << acc.balance  << " " << acc.title << endl;
									 
  return ofs;
}

//pushing everything into ostream operator, overloading <<
ostream& operator << (ostream& ost, const Account& acc )
{
//setprecision(2) + fixed used to show decimal in program
ost << fixed << setprecision(2) << acc.id;
if (acc.is_budget_account == 1) {
         ost << "*";
 }
ost << "  "  << acc.title << " $"  << acc.balance << endl;	 
	 return ost; 

  } 

