//============================================================================
// Name        : polynomial.cpp
// Author      : Kendrick Kwok (912351666)
// Version     : Eclipse C++ 3.8.1 – 5.1
// Date        : 4/1/16
// Description : This program asks the user to fill out a polynomial equation and
//               be able to do specific functions to this polynomial.
//               Created an ADT that is able to hold specific functionalities.
//============================================================================

#include "polynomial.h";
using namespace std;

//Check if the user input sentence is actually a sentence, if not, let user redo
int checkIfCorrect(int checkCorrect){

    while(cin.fail())
       {
         cin.clear();
         cin.ignore(256,'\n');
         cout << "Not an integer! Type in an integer: ";
         cin >> checkCorrect;
       }
           return checkCorrect;
}

//if the user input is zero for expression equation, make user re-do input. Expression cannot have 0 numbers.
int checkIfCorrectZero(int checkCorrect){

    while( checkCorrect == 0)
       {
         cin.clear();
         cin.ignore(256,'\n');
         cout << "Your input created 0 numbers in expression. This does not make sense. Re-try:  ";
         cin >> checkCorrect;
       }
           return checkCorrect;
}

//Constructor-- Everytime a new polynomial object is created, cout "created polynomial"
Polynomial::Polynomial() {
//empty constructor with no terms
}


//Reads from user and input the numbers for the expression
 void Polynomial::readFromUser(){

    cout << "-------------******************-------------" << endl;
    cout << "Enter how many numbers there are in the expression: ";

    cin >> numbersInExpression2;

    //Check if it is an integer or actually has numbers. Will make user re-do if both requirements do not meet.
    int correctNumbersInExpression2 = checkIfCorrect(numbersInExpression2);
    correctNumbersInExpression = checkIfCorrectZero(correctNumbersInExpression2);

    for (int counter = 0 ; counter < correctNumbersInExpression; counter++){
        cout << endl << "This is the " << counter + 1 << " st number in the expression!" << endl;

        cout << "-------------******************-------------" << endl;

        cout << "What is the number of your coefficient?: ";
        cin >> numberOfCoefficient;
        correctNumberOfCoefficient = checkIfCorrect(numberOfCoefficient);

        cout << " What is number of degrees? (Type in 0 if there is no variable x): ";
        cin >> numberOfDegree;
        correctNumberOfDegree = checkIfCorrect(numberOfDegree);

        //Push_back numbers, polynomial Vector should look like this --> [coeff][degree][coeff][degree].....
        polynomialVector.push_back(correctNumberOfCoefficient);
        polynomialVector.push_back(correctNumberOfDegree);

        cout << "Your " << counter << " th number is " << correctNumberOfCoefficient << "^" << correctNumberOfDegree << endl;
    }

    //Displays the expression that you put into the polynomial

    cout << "-------------******************-------------" << endl;
    cout << "Your polynomial expression is: ";

    unsigned int i;
    for (i = 0 ; i < polynomialVector.size() -2; i++){
         cout << polynomialVector[i] << "x^" << polynomialVector[i+1] << " + ";
         i = i + 1;
    }

    cout << polynomialVector[i] << "x^" << polynomialVector[i+1] << endl;
}

//find the degree of the polynomial
 int Polynomial::degree(){
   //stores all the degrees from polynomialVector into new vector findBiggestDegree
    for (unsigned int i = 0 ; i < polynomialVector.size() ; i++){
        findBiggestDegree.push_back(polynomialVector[i+1]);
        i = i + 1;
    }
        // From find biggest degree, with original as the biggest number, loop through the vector...
        // until vector has been scoped and biggest degree is found
        original = findBiggestDegree[0];
        for (unsigned int originalIndex=1; originalIndex < findBiggestDegree.size(); originalIndex++) {

            if (findBiggestDegree[originalIndex] > original) {
                original = findBiggestDegree[originalIndex];
            }
        }
        //return the biggest degree
        return original;
}

//Finds the coefficient with the given degree
 int Polynomial::coefficient(int power){

    //If the power matches, find the coefficient linked with user inputed degree...
    //Because the vector is [coeff][degree][coeff][degree].... i+1 = degree and coeff = i.
    for (unsigned int i =0; i < polynomialVector.size(); i++){
        //if userInput degree == degree in vector
        if (power == polynomialVector[i+1]){
            //return coefficient
            return polynomialVector[i];
        }
    }
}

//find the user-inputed power and change the coefficient from user input
void Polynomial::changeCoefficient(int newCoefficient, int power){
    for (unsigned int i =0; i < polynomialVector.size(); i++){
        //if user input degree = vector degree
        if (power == polynomialVector[i+1]){
            //vector coefficient = user input coefficient
                polynomialVector[i] = newCoefficient;
        }
       i+=1;
    }
        cout << "You attempted to change some of the coefficients. ";
        cout << "Your new polynomial is now: ";

    //print out vector contents
        unsigned int i;
        for (i = 0 ; i < polynomialVector.size() -2; i++){
            cout << polynomialVector[i] << "x^" << polynomialVector[i+1] << " + ";
            i = i + 1;
        }

         cout << polynomialVector[i] << "x^" << polynomialVector[i+1] << endl;
}

//Multiply the contents in the vector by user input integer
 void Polynomial::multiplyPolynomial(int multiplyNumber){

     //Only want to multiply coefficients inside the vector, placements are even numbers...
    //coefficients wanted are i, i+2, i+4... therefore increment i count by two every single loop
    for (unsigned int i=0; i < polynomialVector.size();i++){
     polynomialVector[i] = polynomialVector[i] * multiplyNumber;
     i += 1;
    }

    cout << "You multiplied the expression by " << multiplyNumber <<"! ";
    cout <<  "Your new polynomial is now: ";

    //printing vector
    unsigned int i;

    for (i = 0 ; i < polynomialVector.size() -2; i++){
        cout << polynomialVector[i] << "x^" << polynomialVector[i+1] << " + ";
        i = i + 1;
    }

    cout << polynomialVector[i] << "x^" << polynomialVector[i+1] << endl;
}

//Two Polynomials :: Created two copies of the polynomials that you want to add
//**Check the degrees of both param Polynomial and current Polynomial, and if match, add coefficient by degree...
//on newly created addedPolynomial. Mark it 0. Those that have not been pushed (those that are not marked 0) ...
//push back into the addedPolynomial. Return addedPolynomial.

 void Polynomial::addPolynomial(Polynomial poly){

   //declare new objects for replicating
   Polynomial addedPolynomial;
   Polynomial replicaToAdd;

    //copy param-passed polynomial to Polynomial vector addedPolynomial.polynomialVector
    for (int i = 0 ; i < poly.polynomialVector.size(); i++){
     addedPolynomial.polynomialVector.push_back(poly.polynomialVector[i]);
    }

    //copy function called polynomialvector to replicaToAdd polynomial.vector
    for(int i =0; i < polynomialVector.size(); i++){
     replicaToAdd.polynomialVector.push_back(polynomialVector[i]);
    }

    //Loop both polynomial vectors. Want to change the coefficients, and because data structure is ...
    //[coeff][degree][coeff][degree].....Coeff is equal to even numbered index. i, i+2, i+4......
    for( unsigned int i =0; i <= addedPolynomial.polynomialVector.size(); i++){
        for (unsigned int j=0; j <= replicaToAdd.polynomialVector.size() ; j++){
            //if the degrees match, add the values and push into addedPolynomial
            if (replicaToAdd.polynomialVector[j+1] == addedPolynomial.polynomialVector[i+1]){
                addedPolynomial.polynomialVector[i] = replicaToAdd.polynomialVector[j] + addedPolynomial.polynomialVector[i];
                //mark 0 if numbers have been pushed back
                replicaToAdd.polynomialVector[j]=0;
                replicaToAdd.polynomialVector[j+1]=0;
                j+=1;
            }
             else{
                j+=1;
             }
         }
        i+=1;
    }

    //If there are still numbers that have not been used (numbers that are not marked 0), push back the rest ...
    //into addedPolynomial
    for (int i =0; i < replicaToAdd.polynomialVector.size(); i++){
        if (replicaToAdd.polynomialVector[i] != 0){
            addedPolynomial.polynomialVector.push_back(replicaToAdd.polynomialVector[i]);
        }
    }
    //Print the polynomials
    cout << "You just added the Polynomials! You have the following result!: ";

    unsigned int i =0;

    for (int i = 0 ; i < addedPolynomial.polynomialVector.size()-2; i++){
        cout << addedPolynomial.polynomialVector[i] << "x^" << addedPolynomial.polynomialVector[i+1] << " + ";
            i = i + 1;
    }

    cout << addedPolynomial.polynomialVector[addedPolynomial.polynomialVector.size()-2] << "x^"
            << addedPolynomial.polynomialVector[addedPolynomial.polynomialVector.size()-1] << endl;
}

//function that prints the final polynomial
 void Polynomial::printFinalPolynomial(){

     cout << "You printed the following Polynomial: ";

    for (int i = 0 ; i < polynomialVector.size()-2; i++){
        cout << polynomialVector[i] << "x^" << polynomialVector[i+1] << " + ";
                    i = i + 1;
    }

        cout << polynomialVector[polynomialVector.size()-2] << "x^" << polynomialVector[polynomialVector.size()-1] << endl;
}

//overloads the polynomial operator
 Polynomial Polynomial::operator-(){

     for (int i = 0 ; i < polynomialVector.size(); i++){
          polynomialVector[i] = polynomialVector[i] * -1;
          i+=1;
     }

         //Return empty parameter class Polynomial
         return(Polynomial());
}


