//============================================================================
// Name        : sortBigList.cpp
// Author      : Kendrick Kwok
// Version     : Eclipse 3.8.1
// Copyright   : Kendrick.k
// Description : Inserts 7777 - 7781 in 6000th line of a program using seekg
//============================================================================

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ostream>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
    vector <string> memoryVectorFirst;
    vector <string> memoryVectorLast;
    int byteCountRead1 = 0;
    int byteCountRead2 = 29995;
    int byteCountWrite = 29995;
    int numberToBeInserted = 7777;
    ifstream readFile;
    ofstream writeFile;
    string fileName;
    string line;


    readFile.open("file1.txt");
    //Store all numbers starting from [0] to line where you want to put
    for (int counter=0; counter < 6000; counter++) {
        // byteCountRead1 = 0;
        readFile.seekg(byteCountRead1);
        getline (readFile, line);
        //Have to convert value into a string
        memoryVectorFirst.push_back(line);
        cout << "You put " << line <<" into the vector 1 for keeping" << endl;
        cout << "The position is: " << readFile.tellg() << "bytes" << endl;
        byteCountRead1 = byteCountRead1 + 5 ;
    }
    //Store all numbers starting from the desired line to the end of the file
    for (int counter = 0; counter = !readFile.eof(); counter++) {
        //Position the cursor to the file byte number where you want to read
        readFile.seekg(byteCountRead2);
        getline (readFile, line);
        memoryVectorLast.push_back(line);
        cout << "You put " << line <<" into the vector 2 for keeping" << endl;
        cout << "The position is: " << readFile.tellg() << "bytes" << endl;
        byteCountRead2 = byteCountRead2 + 5 ;
    }

        readFile.clear();
        readFile.close();

    writeFile.open("file1.txt");

    for (int i = 0; i < memoryVectorFirst.size(); i++){
     writeFile << memoryVectorFirst[i] << endl;
    }

    for (int counter = 0; counter < 5; counter++) {
     writeFile.seekp(byteCountWrite);
     writeFile << numberToBeInserted + counter << endl;
     byteCountWrite = byteCountWrite + 5;
    }

    for (int i = 0; i < memoryVectorLast.size(); i++) {
      writeFile << memoryVectorLast[i] << endl;
    }
    cout << endl << "No more bytes parsed.";
    cout << endl << "Numbers have been successfully inserted into the file!" << endl;
}

