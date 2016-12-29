/*************************************
 * Kendrick Kwok
 * 912351666
 * kendrick.j.kwok@gmail.com
 * Dev-C++ 5.7.1
 *************************************/

#ifndef MENU_H
#define MENU_H

#include <iostream>

using namespace std;

	enum menu_options{
		INTIAL_VALUE= -1, 
	    EXIT_PROGRAM, 
        SHOW_BUDGET, 
        ADD_ACCOUNT,
		ADD_TO_ACCOUNT, 
        SPEND_FROM_ACCOUNT,
        SHOW_ENVELOPES,
        CHANGE_DATE,
        SHOW_CURRENT_MONTH,
        CLOSE_CURRENT_MONTH,
        SPEND_FROM_ENVELOPE,
        DEPOSIT_TO_ENVELOPE
	}; 

class Menu
{
	
    public:
	     
		Menu();
		void show_menu();
		int prompt_for_seletion();
		int last_selection();
		~Menu();
		int user_response;
};
#endif
