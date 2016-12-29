/*************************************
 * Kendrick Kwok
 * 912351666
 * kendrick.j.kwok@gmail.com
 * Dev-C++ 5.7.1
 *************************************/

#include "menu.h"
#include <string>
#include <vector>

using namespace std;

Menu::Menu(){
	user_response=-1;
}

void Menu::show_menu(){
	
  cout << endl;
  cout <<"Select an Option:"<< endl 
  << "1. View Budget"<< endl
  << "2. Add Account" << endl
  << "3. Add to Account"<< endl
  << "4. Spend from Account"<< endl
  << "5. Show Envelopes" << endl 
  << "6. Change Date" << endl
  << "7. Show Current Month's Envelopes" << endl
  << "8. Close Current Month's Envelope" << endl
  << "9. Spend from Envelope" << endl
  << "10. Deposit to Envelope" << endl
  << "0. EXIT" << endl;
}


int Menu::prompt_for_seletion(){
  cout << "Enter your Selection: ";
  cin >> user_response ; 	
  return user_response;
}

//last selection, return last user response
int Menu::last_selection(){
	return (user_response); 
}

//deconstructor leave blank 
Menu::~Menu(){

}
