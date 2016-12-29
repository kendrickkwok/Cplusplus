//============================================================================
// Name        : main.cpp
// Author      : Kendrick Kwok (912351666)
// Version     : Eclipse C++ 3.8.1 – 5.1
// Date        : 4/1/16
// Description : This program asks the user to fill out a polynomial equation and
//               be able to do specific functions to this polynomial.
//               Created an ADT that is able to hold specific functionalities.
//============================================================================

#include "polynomial.h"

int main(){

    //Polynomial() constructor
    Polynomial po;
    Polynomial p;

    //void readFromUser();
    po.readFromUser();
    p.readFromUser();

    //int degree(); ---- return degree
    int deg = p.degree();
        cout << "The degree of this polynomial is:  " << deg << endl;

    //int coefficient(int); ----- return coefficient
    int coef = p.coefficient(5);
        cout << "Your coefficients with the user input power is " << coef << endl;

    //void printFinalPolynomial();
    p.printFinalPolynomial();

    //void changeCoefficient (int, int);
    p.changeCoefficient(10,5);

    //void multiplyPolynomial(int);
    p.multiplyPolynomial(5);

    //void addPolynomial(Polynomial);
    p.addPolynomial(po);

    //Polynomial operator -();
    -p;
    cout << "After overloading negation, your polynomial is: ";
    p.printFinalPolynomial();
}
