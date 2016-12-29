/*************************************
 * Kendrick Kwok
 * 912351666
 * kendrick.j.kwok@gmail.com
 * Dev-C++ 5.7.1
 *************************************/

#ifndef BUDGET_H
#define BUDGET_H

#include <iostream>
#include <string>
#include <vector>  
#include "account.h"
#include "envelope.h"
#include "envelope_file.h"
#include <iomanip>
using namespace std;

//Creating class budget
class Budget
{
public:
  int month;
  int year;
  string user_name;
  string title;
  vector<Account> accounts;
  vector<Envelope> envelopes;
  Account a;
  EnvelopeFile envelope_file;
  
  Budget();
  void spend_account();
  void add_account();
  void show_envelopes();
  void add_account_info();
  void account_addtransaction(int, double);
  void account_subtractTransaction(int,double);
  void envelope_transferTransaction(int, int, double);
  void envelope_spendtransaction(int, double);
  void set_current_date(int, int);
  
  void show_monthly_envelopes();
  void close_monthly_envelopes();
  void spend_from_envelope (int, double);
  void deposit_to_envelope (int, int, double);
};

ifstream& operator>> (ifstream&, Budget&);
ofstream& operator<< (ofstream&, const Budget&); 
ostream & operator<< (ostream&, const Budget&); 

#endif
