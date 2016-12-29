/*************************************
 * Kendrick Kwok
 * 912351666
 * kendrick.j.kwok@gmail.com
 * Dev-C++ 5.7.1
 *************************************/

#ifndef MONTHLYENVELOPE_H
#define MONTHYLENVELOPE_H

#include <iostream>
#include <string>
#include <vector>  
#include "envelope.h"
#include <iomanip>

using namespace std;

class MonthlyEnvelope{
	public:
		double balance;
		int month;
		int year;
		Envelope envelope;
		MonthlyEnvelope* next;
			
		MonthlyEnvelope(int, int, const Envelope&, double, MonthlyEnvelope*);
		~MonthlyEnvelope();
		
		void set_next(MonthlyEnvelope* aNext);
		MonthlyEnvelope* get_next();
};

	ostream& operator << (ostream&, const MonthlyEnvelope&); 

#endif
