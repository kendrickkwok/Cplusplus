/*************************************
 * Kendrick Kwok
 * 912351666
 * kendrick.j.kwok@gmail.com
 * Dev-C++ 5.7.1
 *************************************/

#ifndef ENVELOPE_H
#define ENVELOPE_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
//creating class envelope
class Envelope 
{
	public:
		int id;
		string title;
	
};

ifstream& operator >> (ifstream&, Envelope&);
ofstream& operator << (ofstream&, const Envelope&);	
ostream& operator << (ostream&, const Envelope&);

#endif 
	
