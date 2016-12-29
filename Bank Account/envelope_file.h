/*************************************
 * Kendrick Kwok
 * 912351666
 * kendrick.j.kwok@gmail.com
 * Dev-C++ 5.7.1
 *************************************/

#ifndef ENVELOPEFILE_H
#define ENVELOPEFILE_H

#include "monthly_envelope.h"

using namespace std; 
      
class EnvelopeFile {

	public:
		MonthlyEnvelope* first;
				
		EnvelopeFile();
		void add_month(int month, int year, vector<Envelope> envelopes);
		void close_month(int month, int year, vector<Envelope>);
		void add_to_envelope(int month, int year, int envelope_id, double amount);
		void display(int month, int year);
		void append_node(int mth, int yr, const Envelope& env, double s_bal);
};

bool is_next_month_existed(MonthlyEnvelope* first, int mth, int yr);
double convert_to_month(int mth, int yr);
void move_balance(MonthlyEnvelope* first, int cur_mth, int cur_yr);

#endif
