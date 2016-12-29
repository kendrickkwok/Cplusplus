//============================================================================
// Name        : Assignment 1
// Author      : Kendrick Kwok (912351666)
// IDE Platform: Eclipse
// Date        : 2/17/16
// Description : This program is to take userInput of ints and store it into
//               a vector. Print out the contents, then using selection sort
//               to sort the vector from the least amount to largest, and print
//               out the vector again
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

//Check if the userinputed sentence is actually a sentence, if not, let user redo
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

//lets the user input the numbers into the vector
int readData(int indexNumbers){

    cout << "Enter a vector of numbers: ";
    cin >> indexNumbers;
    indexNumbers = checkIfCorrect(indexNumbers);

        return indexNumbers;
}

//chooses which number has the least number, input it to list[0]....then list [1]...and repeat
void selectionSort(vector <int>& list){

  //loops the vector, i = represents all the amounts in the vector
    for (int i=0; i < list.size()-1; i++)
        {
            int Minimum = i;
//second loop, loop to find the minimum, and if it's less then the first for loop...
          // minimum is equal to that value
        for (int j=i+1; j < list.size(); j++)
            {
                if (list[j] < list[Minimum])
                    {
                        Minimum=j;
                    }

            }
    //if minimum does not equal to i, swap.. selection sort sorts vector
                if (Minimum != i )
                {
                    swap (list[i], list[Minimum]);
                }
        }
    cout << endl;
}

//print the contents list in the vector
void printListContents(const vector <int>& list){
    //print out the vector contents

    for (unsigned int vectorCounter=0; vectorCounter<list.size(); vectorCounter++)
        {
            cout << list[vectorCounter] << + " ";
        }
}

int main() {
  //Variable declarations
    int counter;
    int correctCounter;
    int getX;

  //Declare a vector of ints
    vector <int> list(0);

  //Ask for userInput, push that amount into the vector
    cout << "How many numbers do you want to input into the vector?: ";
    cin >> counter;
    correctCounter = checkIfCorrect(counter);

    for (int i=0; i < correctCounter; i++)
        {
            getX=readData(correctCounter);
            cout << "You pushed " << getX << " into vector [" << i << "]!" << endl;
            list.push_back(getX);
        }

    cout << "Your current vector contents are: ";
    printListContents(list);

    selectionSort(list);

    cout << "Your vector contents after selection sort are: ";
    printListContents(list);
}
