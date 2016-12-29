/*
* Author: Kendrick Kwok
*
* Write a program BigInt(n) that displays an arbitrary positive integer
* n using big characters of size 7x7, as in the following example for
BigInt(170):
*/
/*
* This program finds each digit user inputs. Using recursion, BigInt(n)
* recurses and for each digit, it finds the correct number and assigns
* the number to draw a matrix. The matrix is copied into another matrix
* called bigMatrix. Print array is then called and prints the bigMatrix
* onto the output.
*
* This is a good program because not only does it do what it is intended
* for it to do, but this has fast precise code that allows the program to
* avoid failure. This code is also written for the code to run fast and
* efficiently. Below is the output of the assignment.
*/
#include <cstdlib>
#include <stdio.h>
#include <iostream>
using namespace std;
#define DIMENSION 7
#define COLSPACE 1
int counter = 0, countPlacement = 0;
char** bigMatrix;
void BigInt(int digits);
void createBigMatrix(int number);
void getDigitMatrix(int value);
void print_Matrix();
void copyMatrix(char matrix[][DIMENSION]);
int main()
{
int number, counting;
cout << "Please enter any number: ", cin >> number;
//error checking, avoid crashing program
while(cin.fail())
{
cout << "Error! Please Try again! ";
cin.clear(),cin.ignore(256,'\n'), cin >> number;
}
//assign counting to number
counting = number;
//Find the size of the matrix needed to be printed
createBigMatrix(counting);
BigInt(number);
print_Matrix();
return 0;
}void BigInt(int value)
{
//Keep recursing until the number is finished
//--each digit is sent to getDigitMatrix, which retrieves a matrix and copies
it
//----to big matrix
if (value >= 10) BigInt(value/10);
int digit = value % 10;
getDigitMatrix(digit);
}
void createBigMatrix(int counting)
{
//finding how many digits are in user input
while (counting >= 10){
counting = counting/10;
counter++;
}
//find the dimensions of the big matrix array
counter = counter * DIMENSION;
bigMatrix = new char*[DIMENSION];
for(int i = 0; i < DIMENSION; ++i)bigMatrix[i] = new char[counter+COLSPACE];
for (int i=0; i<DIMENSION; ++i) {
for (int j=0; j<DIMENSION*(counter+COLSPACE); ++j) {
bigMatrix[i][j] = ' ';
}
}
}
void print_Matrix()
{
//prints out bigMatrix which ahs the results
int i = 0, j = 0;
for(i = 0; i < DIMENSION; i++)
{
for(j = 0; j < countPlacement; j++)
{
cout << bigMatrix[i][j];
}
cout << "\n";
}
}
void getDigitMatrix(int value)
{
//big switch statement to see which number should be assigned to which matrix
switch(value)
{
case 0:
{
char matrix[DIMENSION][DIMENSION] = {' ','@','@','@','@','@',' ',
'@','@','@','@','@','@','@',
'@','@',' ',' ',' ','@','@',
'@','@',' ',' ',' ','@','@',
'@','@',' ',' ',' ','@','@',
'@','@','@','@','@','@','@',
' ','@','@','@','@','@',' ',};copyMatrix(matrix);
break;
}
case 1:
{
char matrix1[DIMENSION][DIMENSION] = {' ',' ',' ','@','@',' ',' ',
' ',' ','@','@','@',' ',' ',
' ',' ',' ','@','@',' ',' ',
' ',' ',' ','@','@',' ',' ',
' ',' ',' ','@','@',' ',' ',
' ',' ',' ','@','@',' ',' ',
' ','@','@','@','@','@','@',};
copyMatrix(matrix1);
break;
}
case 2:
{
char matrix2[DIMENSION][DIMENSION] = {' ','@','@','@','@','@',' ',
'@','@',' ',' ',' ','@','@',
' ',' ',' ',' ','@','@','@',
' ',' ',' ','@','@','@',' ',
' ',' ','@','@',' ',' ',' ',
'@','@','@','@','@','@','@',
'@','@','@','@','@','@','@',};
copyMatrix(matrix2);
break;
}
case 3:
{
char matrix3[DIMENSION][DIMENSION] = {' ','@','@','@','@','@',' ',
'@','@',' ',' ',' ','@','@',
' ',' ',' ',' ',' ','@','@',
' ',' ',' ','@','@','@',' ',
' ',' ',' ','@','@','@','@',
'@','@',' ',' ',' ','@','@',
' ','@','@','@','@','@',' ',};
copyMatrix(matrix3);
break;
}
case 4:
{
char matrix4[DIMENSION][DIMENSION] = {' ',' ',' ',' ','@','@',' ',
' ',' ',' ','@','@','@',' ',
' ',' ','@',' ','@','@',' ',
' ','@',' ',' ','@','@',' ',
'@','@','@','@','@','@','@',
' ',' ',' ',' ','@','@',' ',
' ',' ',' ','@','@','@','@',};
copyMatrix(matrix4);
break;
}
case 5:
{
char matrix5[DIMENSION][DIMENSION] = {'@','@','@','@','@','@','@',
'@','@',' ',' ',' ',' ',' ',
'@','@','@','@','@','@',' ',
' ',' ',' ',' ',' ','@','@',
' ',' ',' ',' ',' ','@','@','@','@',' ',' ',' ','@','@',
' ','@','@','@','@','@',' ',};
}
copyMatrix(matrix5);
break;
}
case 6:
{
char matrix6[DIMENSION][DIMENSION] = {'@','@','@','@','@','@','@',
'@','@',' ',' ',' ',' ','@',
'@','@',' ',' ',' ',' ',' ',
'@','@','@','@','@','@',' ',
'@','@',' ',' ',' ','@','@',
'@','@',' ',' ',' ','@','@',
' ','@','@','@','@','@',' ',};
copyMatrix(matrix6);
break;
}
case 7:
{
char matrix7[DIMENSION][DIMENSION] = {' ','@','@','@','@','@','@',
'@','@',' ',' ',' ','@','@',
' ',' ',' ',' ','@','@',' ',
' ',' ',' ','@','@',' ',' ',
' ',' ','@','@',' ',' ',' ',
'@','@','@',' ',' ',' ',' ',
'@','@',' ',' ',' ',' ',' ',};
copyMatrix(matrix7);
break;
}
case 8:
{
char matrix8[DIMENSION][DIMENSION] = {' ','@','@','@','@','@',' ',
'@','@',' ',' ',' ','@','@',
'@','@',' ',' ',' ','@','@',
' ','@','@','@','@','@',' ',
'@','@',' ',' ',' ','@','@',
'@','@',' ',' ',' ','@','@',
' ','@','@','@','@','@',' ',};
copyMatrix(matrix8);
break;
}
case 9:
{
char matrix9[DIMENSION][DIMENSION] = {' ','@','@','@','@','@',' ',
'@','@',' ',' ',' ','@','@',
'@','@',' ',' ',' ','@','@',
' ','@','@','@','@','@',' ',
' ',' ',' ',' ',' ','@','@',
'@','@',' ',' ',' ','@','@',
' ','@','@','@','@','@',' ',};
copyMatrix(matrix9);
break;
}
default:
break;
}void copyMatrix(char matrix[DIMENSION][DIMENSION]){
int i = 0, j = 0;
//for each 7x7 matrix, copy and paste into big matrix
for(j = 0; j < DIMENSION; j++)
{
for(i = 0; i < DIMENSION; i++)
{
//count placements records the matrixes in different indexes of bigMatrix
bigMatrix[i][countPlacement]= matrix[i][j];
}
//count placement holds the value in where bigMatrix should copy the columns
//-- this lets bigMatrix avoid from overwriting
countPlacement++;
}
countPlacement++;
}
//*Output
/*
* Please enter any number: 123
@@
@@@@@
@@@@@
@@@
@@
@@ @@
@@
@@
@@@
@@
@@
@@@
@@@
@@
@@
@@@@
@@
@@@@@@@ @@
@@
@@@@@@ @@@@@@@ @@@@@
*/
