//============================================================================
// Name        : recursion.cpp
// Author      : Kendirck Kwok
// Version     : Eclipse 3.8.1
// Date        : 4/15/16
// Description : Takes a string and determines whether or not it is a Palindrome
//               using recursion
//============================================================================

#include <iostream>
#include <string>
using namespace std;


bool isPalindrome(const string& input) {

    //--basecase
    //if after deletion there is 0 or 1 letter left in the string, it is determined
    //....to be a palinedrome.
    // Return true and out yes
    if (input.length()==0 || input.length()==1){
        cout << "Yes" << endl;
        return true;
    }

    //if first letter does not match the last letter, then not a paliundrome
    //return false
        else if (input[0] != input[input.length()-1]){
            cout << "No" << endl;
            return false;
        }

    //if first letter does match with last letter, delete first and last letter and use recursion to match rest
            else{
                return isPalindrome (input.substr(1, input.length()-2) );
            }

}

int main() {
    string input;
    cout << "This Program determines whether or not the word is a Palindrome." << endl;
    cout << "Enter a word with no space and case sensitive to test: ";
    cin >> input;

    cout << "Is " << input << " a Palindrome?: ";
    isPalindrome(input);
}

