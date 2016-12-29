/*************************************
 * Kendrick Kwok
 * 912351666
 * kendrick.j.kwok@gmail.com
 * Dev-C++ 5.7.1
 *************************************/

#ifndef budget_application_H
#define budget_application_H

#include <iomanip>
#include "menu.h"
#include "budget.h"

class BudgetApplication{
	public: 
	
	BudgetApplication();
	bool is_running(); 
    void prompt_loop();
    ~BudgetApplication();
	 
	private: 
	void process_menu_selection();  
	Budget b;
	Envelope e;
	Menu menu;
};
#endif 
