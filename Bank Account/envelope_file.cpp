/*************************************
 * Kendrick Kwok
 * 912351666
 * kendrick.j.kwok@gmail.com
 * Dev-C++ 5.7.1
 *************************************/

#include "envelope_file.h"

EnvelopeFile::EnvelopeFile()
{
	//first constructor = NULL;
	first = NULL;
}

void EnvelopeFile::add_month(int mth, int yr, vector<Envelope> envelopes)
{
	// Create the whole list of MonthlyEnvelope here
	for (int i=0; i < envelopes.size(); i++) {
		append_node(mth, yr, envelopes.at(i), 0.0);
	}	
	cout << "exit add_month " << mth << " " << yr << endl;
}

void EnvelopeFile::append_node(int mth, int yr, const Envelope& env, double s_bal) 
{

    // Create a new node
    MonthlyEnvelope* newNode = new MonthlyEnvelope(mth, yr, env, s_bal, NULL);

    // Create a temp pointer
    MonthlyEnvelope* tmp = first;

    if ( tmp != NULL ) {
    	// Nodes already present in the list
    	// Parse to end of list
    	while ( tmp->get_next() != NULL ) {
        	tmp = tmp->get_next();
    	}	
    // Point the last node to the new node
    tmp->set_next(newNode);
    }
    else {
    	// First node in the list
    	first = newNode;
    }
}

void EnvelopeFile::display(int mth, int yr) {

	// Display each of the envelopes in the specified month and year.
	
    // Temp pointer
    MonthlyEnvelope *tmp = first;

	cout << "------ " << mth << " " << yr << " ------" << endl;
    // No nodes
    if ( tmp == NULL ) {
    	cout << "EMPTY" << endl;
    	return;
    }

    // One node in the list
    if ( tmp->get_next() == NULL ) {
    	if ((tmp->month == mth) && (tmp->year == yr)) {
	   		cout << *tmp;
    	}
    }
    else {
    	// Parse and print the list
    	do {
    		// cout << "print node = " << tmp->envelope.id << endl;
	    	if ((tmp->month == mth) && (tmp->year == yr)) {
	    		cout << *tmp;
        	}
			tmp = tmp->get_next();
    	} while ( tmp != NULL );
   }
   cout << endl;
}

void EnvelopeFile::add_to_envelope(int mth, int yr, int e_id, double amt)
{
    MonthlyEnvelope *tmp = first;

    // No nodes
    if ( tmp == NULL ) {
    	cout << "EMPTY" << endl;
    	return;
    }

    // One node in the list
    if ( tmp->get_next() == NULL ) {
    	if ((tmp->month == mth) && (tmp->year == yr) && (tmp->envelope.id == e_id)) {
	   		tmp->balance += amt;
    	}
    }
    else {
    	// Parse and print the list
    	do {
    		if ((tmp->month == mth) && (tmp->year == yr) && (tmp->envelope.id == e_id)) {
	   			tmp->balance += amt;
        		}	
			tmp = tmp->get_next();
    	} while ( tmp != NULL );
   }
}


void EnvelopeFile::close_month(int cur_mth, int cur_yr, vector<Envelope>envelopes)
{
	int new_mth, new_yr;
	
	// Make sure the next month exists
	if (is_next_month_existed(first, cur_mth, cur_yr)) {
		move_balance(first, cur_mth, cur_yr);
	}
	else {
		// next month not existed, create it
		if (cur_mth == 12) {
			new_mth = 1;
			new_yr = cur_yr + 1;
		}
		else {
			new_mth = cur_mth + 1;
			new_yr = cur_yr;
		}
		add_month(new_mth, new_yr, envelopes);
		move_balance(first, cur_mth, cur_yr);
	}
}

bool is_next_month_existed(MonthlyEnvelope* first, int mth, int yr)
{
    MonthlyEnvelope *tmp = first;
    double cur_value, tmp_value;

    // No nodes
    if ( tmp == NULL ) {
    	return(false);
    }

	cur_value = convert_to_month(mth, yr);
	
    // One node in the list
    if ( tmp->get_next() == NULL ) {
    	tmp_value = convert_to_month(tmp->month, tmp->year);
    	if (cur_value == (tmp_value-1)) {
	   		return(true);
    	}
    }
    else {
    	// Parse and print the list
    	do {
	   		tmp_value = convert_to_month(tmp->month, tmp->year);
    		if (cur_value == (tmp_value-1)) {
	   			return(true);
    		}
			tmp = tmp->get_next();
    	} while ( tmp != NULL );
   }
   return(false);
}

double convert_to_month(int mth, int yr)
{
	return(yr*12 + mth);
}

void move_balance(MonthlyEnvelope* first, int cur_mth, int cur_yr)
{
    MonthlyEnvelope *tmp = first;
    double cur_value, tmp_value, tmp2_value;
    
	cur_value = convert_to_month(cur_mth, cur_yr);
    do {
    	tmp_value = convert_to_month(tmp->month, tmp->year);
    	if (cur_value == tmp_value) {
    		// It means we need to move this balance to next month
    		// Search from the beginning of the linked list again
			MonthlyEnvelope *tmp2 = first;
			do {
				tmp2_value = convert_to_month(tmp2->month, tmp2->year);
				if ((cur_value == (tmp2_value-1)) && (tmp->envelope.id == tmp2->envelope.id)) {
					tmp2->balance =+ tmp->balance;
					tmp->balance = 0.0;
				}
				tmp2 = tmp2->get_next();
			} while (tmp2 != NULL);			
    	}
		tmp = tmp->get_next();
    } while ( tmp != NULL );
}
