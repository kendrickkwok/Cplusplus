//============================================================================
// Name        : polynomial.h
// Author      : Kendrick Kwok (912351666)
// Version     : Eclipse C++ 3.8.1 – 5.1
// Date        : 4/1/16
// Description : This program asks the user to fill out a polynomial equation and
//               be able to do specific functions to this polynomial.
//               Created an ADT that is able to hold specific functionalities.
//============================================================================

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>
#include <vector>
using namespace std;

class Polynomial{

    public:
        //One default constructor, which creates a polynomial with no terms
        Polynomial();
        //One method allowing to get entire polynomial by interacting with user
        void readFromUser();
        //Return the degree of a polynomial, highest power of a term with non-zero
        int degree();
        //Method that returns the coefficient of xth power term
        int coefficient(int);
        //Replaces coefficients of the term with newCoefficient
        void changeCoefficient (int, int);
        //Method that multiplies polynomial by integer
        void multiplyPolynomial(int);
        //Method that adds two polynomials
        void addPolynomial(Polynomial);
        //Method that prints out a polynomial
        void printFinalPolynomial();
        //Overload negcoefficientative polynomial
        //Polynomial operator -(Polynomial);
        Polynomial operator -();

    private:
        //polynomialVector is stored as follows :: [coefficient][degree][coefficient][degree][coefficient]...
        vector<int> polynomialVector;
        //findBiggestDegree is stored as follows :: [degree][degree][degree][degree]...
        vector<int> findBiggestDegree;

        //used in readFromUser() method;
        int numbersInExpression2;
        int correctNumbersInExpression;
        int numberOfCoefficient;
        int correctNumberOfCoefficient;
        int numberOfDegree;
        int correctNumberOfDegree;

        //used in degree() method;
        int original;

        //used in addPolynomial
        int result;
};

#endif POLYNOMIAL_H_
