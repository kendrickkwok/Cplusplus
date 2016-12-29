//============================================================================
// Name        : mergeFiles.cpp
// Author      : Kendrick Kwok
// Version     : Eclipse 3.8.1
// Copyright   : Kendrick.k
// Description : User inputs two folders, and program sorts both folders in ascending
//               order until both folders do not contain any more values
//============================================================================

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <ostream>

using namespace std;

void mergeFiles(ifstream& inText, ifstream& inText2, ofstream& outText){

    string userInput;
    string userInput2;
    bool flag1 = true;
    bool flag2 = true;

    //declare instant from ofstream
    //open outstream file
    outText.open("mergedFile.txt");
    //if file failed to open, output message
    if (outText.fail()) {
    cout << "file failed to open.";
    }
        //1.This whole while loop compares two numbers, and depending on the condition, sorts it
        //in a pertaining order...
        //2. While one or the other file that has not reached the end, keep looping.
        while (!inText.eof() && !inText2.eof()) {
            //execute if bool flag 1 is true, folder 1 next number put into userInput
            if (flag1) {
             inText >> userInput;
            }
                //execute if bool flag 2 is true, folder 2 next number put into userInput2
                if (flag2){
                 inText2 >> userInput2;
                }
            //convert string into integer values
            int value = atoi(userInput.c_str());
            int value2 = atoi(userInput2.c_str());

            //if first folder value is less then second folder value, first value outputed
            if (value < value2) {
             outText << value << endl;
             cout << "You just put from File #1 " << value << " in mergedFile.txt!" << endl;
             flag2 = false;
             flag1 = true;

            }else{
                  //if second folder value is less then first folder value, folder two value outputed
                  if (value2 < value) {
                   outText << value2 << endl;
                   cout << "You just put from File #2 " << value2 << " in mergedFile.txt!" << endl;
                   flag1 = false;
                   flag2 = true;

                  }else{
                          //if the value from folder 1 is the same as folder 2, put both numbers into outFile
                          if (value2 == value) {
                            outText << value << endl;
                            outText << value2 << endl;
                            cout << "You just put from File #1 and File #2 " << value << " in mergedFile.txt!" << endl;
                            flag1 = true;
                            flag2 = true;
                           }

                       }
                }
         }

   //If first file done, then output all values from second folder
   if (inText.eof()) {
        outText << userInput2 << endl;

            while (!inText2.eof()) {
             int value = atoi(userInput.c_str());
             int value2 = atoi(userInput2.c_str());
             inText2 >> value2;
             outText << value2 << endl;
             cout << "You just put from File 2 " << value2 << " in mergedFile.txt!" << endl;
            }

           }else{

            if (inText2.eof()) {
                 outText << userInput << endl;
                 while (!inText.eof()) {
                 int value = atoi(userInput.c_str());
                 int value2 = atoi(userInput2.c_str());
                 inText >> value;
                 outText << value << endl;
                 cout << "You just put from File 2 " << value << " in mergedFile.txt!" << endl;
                 cout << endl;
                }
            }
        }
            cout << "Merge complete!" << endl;
            cout << "Your newly merged file is under mergedFile.txt!";
   }

int main() {
   //declared variables
   ofstream outText;
   ifstream inText;
   ifstream inText2;

   //Keep looping until you can actually open Folder 1
   cout << "This program merges two files into one new file." << endl;
   cout << "What is folder #1 you want to open? (include .txt): " << flush;
     while (true) {
       string inputFileName1;
       getline( cin, inputFileName1 );
       inText.open( inputFileName1.c_str() );
           if (inText) break;
               cout << "File cannot open. Please enter another file: " << flush;
     }

   //Keep looping until you can actually open Folder 2
   cout << "What is folder #2 you want to open? (include .txt): " << flush;
     while (true) {
       string inputFileName2;
       getline( cin, inputFileName2 );
       inText2.open( inputFileName2.c_str() );
           if (inText2) break;
               cout << "File cannot open. Please enter another file: " << flush;
     }
     mergeFiles(inText,inText2, outText);
}
