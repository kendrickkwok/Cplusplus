/*************************************
 * Kendrick Kwok
 * 912351666
 * kendrick.j.kwok@gmail.com
 * Dev-C++ 5.7.1
 *************************************/

#include <iostream>
#include <string>
#include <vector>  
#include <iomanip>
#include <fstream>  
#include <sstream>  
#include <cstring>

#include "budget.h"

using namespace std;

//Reading into the file, obtain budget_file
Budget::Budget()
{
}

//DIsplaying envelope information
void Budget::show_envelopes()
{
	cout << "***" << user_name << "|||" << title << "***" << endl;
	cout << envelopes.size() << " Envelopes:" << endl;
	for (int i=0; i < envelopes.size(); i++) {
		cout << envelopes[i];		
	}
	cout << endl;
}

//Display add account information
void Budget::add_account() 
{
	int account_id;
	double amount;
	
	cout << "Select Account you want to deposit" <<" ";
	cin >> account_id;
	cout <<"How much do you want to deposit?" <<" ";
	cin >> amount;
	account_addtransaction(account_id, amount );
	cout << endl;
}
//balance = balance + amount
void Budget::account_addtransaction( int account_id, double amount )
{ 
  for (int i=0; accounts.size() > i; i++)
  {
  	if (accounts[i].id == account_id) {
	  accounts[i].balance += amount;
  	}
  }
}

//add spend function to program 
void Budget::spend_account()
{
  int account_id;
  double amount;
	
  cout << "Which account do you want to take out from?" <<" ";
  cin >> account_id;
  cout << "How much do you want to take out?" <<" ";
  cin >> amount;
	
account_subtractTransaction(account_id, amount );
cout << endl;

}

//balance=balance-amount
void Budget::account_subtractTransaction(int account_id, double amount)
{
  for (int i=0; accounts.size() > i; i++)
  {
  	if (accounts[i].id == account_id) {
	  accounts[i].balance -= amount;
  	}
  }
}

void Budget::add_account_info()
{ 	
    Account a;

	cout << "Enter new account id: ";
	cin >> a.id;
	cout << "Enter new account name: "; 
	cin >> a.title;
	a.balance = 0.00;
  	accounts.push_back(a);

}


														                
void Budget::set_current_date(int mth, int yr)
{
	month = mth;
	year = yr;
}

void Budget::show_monthly_envelopes()
{
	//envelope_file use method to display month and year
	envelope_file.display(month, year); 
}

void Budget::close_monthly_envelopes()
{
	//envelope_file use close month method 
	envelope_file.close_month(month, year, envelopes);
}

void Budget::spend_from_envelope (int e_id, double amt)
{
	double spend_amt;
	
	//spend, so decrease the amount 
	spend_amt = amt * (-1);
	envelope_file.add_to_envelope(month, year, e_id, spend_amt);
}

void Budget::deposit_to_envelope (int a_id, int e_id, double amt)
{
 	account_subtractTransaction(a_id, amt);
	envelope_file.add_to_envelope(month, year, e_id, amt );
}

//input file stream for budget
ifstream& operator >> (ifstream& file, Budget& b)
{
	int num_of_accounts;
	int num_of_envelopes;
	Account a;
	Envelope e;

	getline(file, b.user_name);
	getline(file, b.title);
	file >> b.month >> b.year;
	file >> num_of_accounts;
		
	//Looping accounts, pushing back vector
	for (int x=0; num_of_accounts > x; x++) 
  	{
  		file >> a;
  		b.accounts.push_back(a);
  	}	
  	
  	file >> num_of_envelopes;
 	
	//Looping envelopes, pushing back vector
	for (int y=0; y < num_of_envelopes; y++)  
  	{
		file >> e;
   		b.envelopes.push_back(e);
  	}
  	
  	//included envelope_file function to end of vector envelopes
  	b.envelope_file.add_month(b.month, b.year, b.envelopes);
}

//outputfile stream in budget
ofstream& operator << (ofstream& ofs, const Budget& b)
{
	ofs << b.user_name<<endl;
	ofs << b.title << endl;
	ofs << b.month <<  " " << b.year << endl; 
	ofs << b.accounts.size() << endl;
	for (int i=0; i < b.accounts.size(); i++) {
		ofs << b.accounts[i];
	}
	ofs << b.envelopes.size() << endl;
	for (int j=0; j < b.envelopes.size(); j++) {
		ofs << b.envelopes[j];
	}
	return ofs;
}

//outstream to the display  menu
ostream & operator << (ostream& ost, const Budget& budg)
{
	ost << "------" << budg.user_name << " " <<  
	"|" << " " << budg.title << "------" << endl;
	ost<< "-----" << budg.month << " " << budg.year 
	<< "-----" <<  endl;
	return ost;  
}
