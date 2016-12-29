/*************************************
 * Kendrick Kwok
 * 912351666
 * kendrick.j.kwok@gmail.com
 * Dev-C++ 5.7.1
 *************************************/
#include <string>
#include <iostream>


#include "budget_application.h"

using namespace std;

//constructor/intialiazer, read in file
BudgetApplication::BudgetApplication()
{
ifstream file;
file.open("budget_file", ios::in);
	
	if (file.is_open())
	{
		//if file is open, input all of B contents into file
   		file >> b;
		file.close();
	} 
	else { 
		cout << file << " failed to open." << endl;
		//abort();
	}      
}

bool BudgetApplication::is_running(){
//if last selection exit program, return true, otherwise false	
	if (menu.last_selection() != EXIT_PROGRAM )
	    return 1;
	else		    
		return 0;
}

//prompt loop, if aplication running, do functions in correct order
void BudgetApplication::prompt_loop(){
	  if (is_running() == 1) { 
		cout << b;
		cout << b.accounts.size() << " Accounts:" << endl;
		for (int i=0; i < b.accounts.size(); i++) {
			cout << b.accounts[i];

		}
		menu.show_menu();
       	menu.user_response = menu.prompt_for_seletion();
       	process_menu_selection();
	}
}

//Processing user response to the program
void BudgetApplication::process_menu_selection()
{
	int mth, yr;
	int account_id, envelope_id;
	double amount;
	
 switch (menu.user_response) 
 	{   
    case EXIT_PROGRAM:
    break;
    case SHOW_BUDGET:
    break;
    case ADD_TO_ACCOUNT:
    b.add_account();
    break; 
    case SPEND_FROM_ACCOUNT:
    b.spend_account();
    break;
    case SHOW_ENVELOPES:
    b.show_envelopes();
    break;
    case ADD_ACCOUNT:
    b.add_account_info();	
    break;
    case CHANGE_DATE:
    cout <<"Enter month and year" << " ";
	cin >> mth >> yr;
    b.set_current_date(mth, yr);
    break;
    case SHOW_CURRENT_MONTH:
    b.show_monthly_envelopes();
	break;
	case CLOSE_CURRENT_MONTH:
		b.close_monthly_envelopes();
		break;
	case SPEND_FROM_ENVELOPE:
  		cout << "Select Envelope: " <<" ";
  		cin >> envelope_id;
  		cout <<"How much do you want to spend? " <<" ";
  		cin >> amount;
 		b.spend_from_envelope(envelope_id, amount);
		break;
	case DEPOSIT_TO_ENVELOPE:
		cout << "Select account: " <<" ";
  		cin >> account_id;
  		cout << "Select Envelope: " <<" ";
  		cin >> envelope_id;
  		cout <<"How much do you want to transfer? " <<" ";
  		cin >> amount;
 		b.deposit_to_envelope(account_id, envelope_id, amount);
		break; 
    default:
    	break;
	}
}

BudgetApplication::~BudgetApplication()
{
 //output budget file, replace file after finished
 ofstream outfile;
 outfile.open("budget_file", ios::trunc) ;
 outfile.setf( ios::fixed);
 outfile.setf( ios::showpoint);
 outfile.precision (2) ; 

 outfile << b;
 outfile.close();

}


