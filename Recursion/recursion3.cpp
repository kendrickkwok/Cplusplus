//============================================================================
// Name        : recursion3.cpp
// Author      : Kendirck Kwok
// Version     : Eclipse 3.8.1
// Date        : 4/15/16
// Description : Takes a number and determines how many steps there are to take
//               using recursion
//============================================================================

#include <iostream>
#include <string>

using namespace std;

//Recursion problem used..Fibonnaci Sequence:: F(n) = F(n-1) + F(n-2)
int waysToClimb(int numStairs) {
//If stairs is incremented to 1 after recursion, return 1
    if (numStairs <= 1){
        return 1;
    }
    //If stairs is incremented to 2 after recursion, return 2
        if (numStairs == 2) {
            return 2;
        }
            //if number is not 1 or 2, then recurse using Fibonacci Sequence
            //... < F(n) = F(n-1) + F(n-2) >
            return(waysToClimb(numStairs-1) + waysToClimb(numStairs-2));
}

//Error checking to see if the number inputed is a number
int checkIfCorrect(int checkCorrect){

    while(cin.fail() || checkCorrect < 0)
       {
         cin.clear();
         cin.ignore(256,'\n');
         cout << "Input was either a string or a negative number. Type in a positive integer: ";
         cin >> checkCorrect;
       }
           return checkCorrect;
}

int main()
{
    //variable declarations
    int correctionCheck;
    int numStairs;
    int finalResult;
    cout << "How many stairs do you want to climb?: ";
    cin >> correctionCheck;

    //Error checking to see if it is an integer
    numStairs = checkIfCorrect(correctionCheck);
    finalResult = waysToClimb(numStairs);
    cout << "The number of ways to go up " << numStairs << " stairs is " << finalResult << " steps" << endl;
}
