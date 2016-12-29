/*************************************
 * Kendrick Kwok
 * 912351666
 * kendrick.j.kwok@gmail.com
 * Dev-C++ 5.7.1
 *************************************/

#include "budget_application.h"

int main()
{
 BudgetApplication app;
 while( app.is_running() ) {
 app.prompt_loop();
 }
}
