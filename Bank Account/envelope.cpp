/*************************************
 * Kendrick Kwok
 * 912351666
 * kendrick.j.kwok@gmail.com
 * Dev-C++ 5.7.1
 *************************************/

#include "envelope.h"
#include <fstream>
#include <ostream>
#include <iomanip>
#include <fstream>  
#include <sstream>  
#include <cstring>

//pushing in inputfile, overloading >> operator
ifstream& operator >> (ifstream& ifs, Envelope& env)
{

  ifs >> env.id;
  ifs.get();
  getline(ifs, env.title);
  return ifs;
}	

//pushing output file stream, overloading << operator
ofstream& operator << (ofstream& ofs, const Envelope& env)
{
  ofs << fixed << setprecision(2) << env.id << " " << env.title << endl;
  return ofs;
}

//pushing everything into ostream operator, overloading <<	
ostream& operator << (ostream& ost, const Envelope& env)
{
  ost << fixed << setprecision(2) << env.id << "  "
  << env.title << endl;
  return ost;	
}
