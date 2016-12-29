/*************************************
 * Kendrick Kwok
 * 912351666
 * kendrick.j.kwok@gmail.com
 * Dev-C++ 5.7.1
 *************************************/

#include "monthly_envelope.h"

MonthlyEnvelope::MonthlyEnvelope(int mth, int yr, const Envelope &env, double s_bal, MonthlyEnvelope* nx)
{
		//passing in variables
		month = mth;
		year = yr;
		envelope = env;
		balance = s_bal; 
	    next = nx;	
}

MonthlyEnvelope::~MonthlyEnvelope()
{
}

void MonthlyEnvelope::set_next(MonthlyEnvelope* aNext)
{
	//set pointer next
	next = aNext;
}


MonthlyEnvelope* MonthlyEnvelope::get_next()
{
	//returns the value next
	return(next);
}

ostream& operator << (ostream& ost, const MonthlyEnvelope& me)
{

	ost << fixed << setprecision(2) << me.envelope.id << " " << me.month << " " << me.year << " " << me.balance << endl;
  	return ost;
}

