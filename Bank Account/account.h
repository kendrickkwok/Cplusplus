/*************************************
 * Kendrick Kwok
 * 912351666
 * kendrick.j.kwok@gmail.com
 * Dev-C++ 5.7.1
 *************************************/
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <vector>  
#include "envelope.h"
#include <iomanip>

using namespace std;

class Account
{
 public:
 	
  int id;
  string title;
  double balance;
  bool is_budget_account; 
};

ifstream& operator >> (ifstream&, Account&);
ofstream& operator << (ofstream&, const Account&);
ostream& operator << (ostream&, const Account&);

#endif
