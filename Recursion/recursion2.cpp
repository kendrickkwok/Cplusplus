//============================================================================
// Name        : recursion2.cpp
// Author      : Kendirck Kwok
// Version     : Eclipse 3.8.1
// Date        : 4/15/16
// Description : Takes the number and using recursion can sum up the digits
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int digitSum(int input) {

    if (input!=0)
    {
    //base case
    if (input < 10){
        return input;
    }
        else {
                return digitSum(input/10) + input%10;
        }
    }
}

//Error Checking
int checkIfCorrect(int checkCorrect){

    while(cin.fail() || checkCorrect < 0)
       {
         cin.clear();
         cin.ignore(256,'\n');
         cout << "Not an integer or a Positive! Type in an integer: ";
         cin >> checkCorrect;
       }
           return checkCorrect;
}

int main() {
    //variable declarations
    int input;
    int tryInput;

    cout <<"This program sums the digits and returns the given value." << endl;
    cout << "Enter an integer number: ";

    //Check to see if the input is a integer...if not let user redo
    cin >> tryInput;
    input = checkIfCorrect(tryInput);
    cout << "The sum of the digits of " << input << " is: ";

    //print the result of the sum
    cout << digitSum(input);
}

