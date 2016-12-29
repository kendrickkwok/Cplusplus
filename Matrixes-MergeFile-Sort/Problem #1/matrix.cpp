//============================================================================
// Name        : testassiggn2.cpp
// Author      : Kendrick Kwok
// Version     :
// Copyright   : Kendrick.k
// Description : This program asks userInput for the
//               dimensions of matricies and multiplies them.
//============================================================================

#include <cstdlib>
#include <iostream>
#include <vector>
#include <exception>
#include <iomanip>

using namespace std;

class Grid{
    public:
        double valuesForMatrix;
        double valuesForMatrix2;

//Creates the first matrix in the program
 void createMatrix1(int rowCount, int columnCount) {
        for (int row = 0; row < rowCount; row++){
            //pushback vector of 0s
            dynamicGrid.push_back(vector<double>(0));
                   for (int col = 0; col < columnCount; col++) {
                    cout << "Input value for Matrix 1 at " << "[" << row << "]"<< "[" << col << "]" << ":";
                    cin >> valuesForMatrix;
                    valuesForMatrix = checkIfCorrect(valuesForMatrix);
                    //push back the vector into the designated place [row][col]
                    dynamicGrid[row].push_back(valuesForMatrix);
                   }
        }
//Prints the content of the first matrix onto the console
        cout << "Your first matrix contains: " << endl << setw(8);

        for (int row = 0; row < dynamicGrid.size(); row++) {
                 for (int col = 0; col < dynamicGrid[0].size(); col++){
                     cout << dynamicGrid[row][col]<< setw(8);
                 }
                 cout << endl;
         }
         cout << endl;
 }

//Creates the second matrix in the program
 void createMatrix2(int rowCount2, int columnCount2) {

     for (int row = 0; row < rowCount2; row++){
    //pushback vector of 0s
        dynamicGrid2.push_back(vector<double>(0));
            for (int col = 0; col < columnCount2; col++) {
             cout << "Input value for Matrix 2 at " << "[" << row << "]"<< "[" << col << "]" << ":";
             cin >> valuesForMatrix2;
             valuesForMatrix2 = checkIfCorrect(valuesForMatrix2);
             //push back the vector into the designated place [row][col]
             dynamicGrid2[row].push_back(valuesForMatrix2);
            }
     }

    cout << "Your second matrix contains: " << endl << setw(8);
          for (int row = 0; row < dynamicGrid2.size(); row++) {
              for (int col = 0; col < dynamicGrid2[0].size(); col++){
               cout << dynamicGrid2[row][col] << setw(8);
              }
           cout << endl;
          }
     cout << endl;
 }

//Function multiplies matricies of two. Rows of first matrix is slowest, then comes columns of second matrix..
//then the inner arrays of both matrixes. loops go in descending order starting from slowest to fastest to..
//produce result. Sum is pushed back into desired location in a third matrix.
 void multiplyMatrixes(int innerArray) {

     for (int row = 0; row < dynamicGrid.size(); row++) {
            //pushback a vector of 0s
            multiplyGrid.push_back(vector<double>(0));
          for (int col = 0; col < dynamicGrid2[0].size(); col++) {
              //everytime it loops, allocate sum to be back by 0
              double sum=0;
                  //sum is equal to sum + the row and col values for each loop
                  for (int counter=0; counter < innerArray; counter++ ) {
                      sum = sum + dynamicGrid[row][counter]*dynamicGrid2[counter][col];
                  }
                   multiplyGrid[row].push_back(sum);
           }
     }
         cout << "Your multiplied matrix is: " << endl << setw(8);

         for (int row = 0; row < multiplyGrid.size(); row++) {
               for (int col = 0; col < multiplyGrid[0].size(); col++) {
               cout << multiplyGrid[row][col] << setw(8);
               }
          cout << endl;
          }
  }

//function checkIfCorrect checks if userInput is an integer. if it is not, then userInput promped again.
 double checkIfCorrect(double checkCorrect) {
    while(cin.fail()) {
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Not an integer! Type in an integer: ";
        cin >> checkCorrect;
    }
        return checkCorrect;
 }

//function checks if the columns of Matrix 1 matches rows of Matrix 2, if not, go back to loop and prompt again.
 int exceptionCheck(int a, int b) {
    if(b!=a)
        throw 1;
    return a,b;
 }

    private:
       //set vector of vectors for matrix 1, matrix 2, and the results printed on matrix 3.
       vector<vector<double> > dynamicGrid;
       vector<vector<double> > dynamicGrid2;
       vector<vector<double> > multiplyGrid;
 };

int main(){
    Grid g;
    //Rows and columns for the first matrix
    int Rows;
    int Columns;
    //Rows and columns for the second matrix
    int Rows2;
    int Columns2;
    bool flag1 = false;

    cout << "This program asks userInput for the dimensions of matricies and multiplies them." << endl;

    //while loop, exit loop until they match Columns from first matrix and rows from second matrix
    while (!flag1){
        try {
             cout << "How many rows do you want in the first matrix?: ";
             cin >> Rows;
             Rows = g.checkIfCorrect(Rows);

             cout << "How many columns do you want in the first matrix: ";
             cin >> Columns;
             Columns = g.checkIfCorrect(Columns);
             cout << "Your first matrix entered is a " << Rows << "*" << Columns << " matrix" << endl << endl;

             cout << "How many rows do you want in the second matrix?: ";
             cin >> Rows2;
             Rows2 = g.checkIfCorrect(Rows2);
             g.exceptionCheck(Columns, Rows2);
             flag1 = true;
            }
        catch(int& code) {
            cout << "Number of Columns in Matrix 1 and Rows in Matrix 2 must match! Try again." << endl;
        }
    }

    cout << "How many columns do you want in the second matrix: ";
    cin >> Columns2;
    Columns = g.checkIfCorrect(Columns);
    cout << "Your second matrix entered is a " << Rows2 << "*" << Columns2 << " matrix" << endl << endl;

    //funcition declarations
    g.createMatrix1(Rows, Columns);
    g.createMatrix2(Rows2, Columns2);
    g.multiplyMatrixes(Columns);
}
