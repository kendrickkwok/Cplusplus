//=======//============================================================================
// Name        : Assignment 1
// Author      : Kendrick Kwok (912351666)
// IDE Platform: Eclipse
// Date        : 2/17/16
// Description : This program is to take userInput and detect the least
//               frequency of words, store word and count into a vector,
//               display the vector, and output the highest frequency
//               of word from the vector
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <ctype.h>
#include <cstdlib>
#include <strings.h>

using namespace std;


class Container{
    public:
       string word;
       int count;
};


//Used for case UNsensitive for the frequency of letters intake
int changeChar(char letter1, char letter2)
{
   if  ( tolower(letter1) < tolower(letter2) )
            return -1;
    if ( tolower(letter1) == tolower(letter2) )
            return 0;
               return 1;
}
//Part two of using case UNsensitive for the frequency of letters intake
int stringCompare(string sentence1, string sentence2)
{
     int diff = 0;
     int size = min(sentence1.size(), sentence2.size());

         for (size_t idx = 0; idx < size && diff == 0; ++idx)
             {
                diff = diff+ changeChar(sentence1[idx], sentence2[idx]);
             }
             if (diff != 0)
                 return diff;
             if (sentence2.length() == sentence1.length())
                 return 0;
             if (sentence2.length() > sentence1.length())
                 return 1;
    return -1;
}

//gets the least frequent letter of the user input
void leastFreqLetter(string userInput){

    int printSmallest = -1;
    //Array to count the number of of times a letter is hit
    int valueCounter[25];
    //Array of alphabets
    char alphabet[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m',
                    'n','o','p','q','r','s','t','u','v','w','x','y','z'};

    // initialize valueCounter to zero
    for (int i=0; i<25; i++) {
        valueCounter[i] = 0;
    }

    // for every letter of the userInput, whenever the user hits a letter, the counter will +1 into
    // the count array with the corresponding letter

    for(unsigned int i=0; i < userInput.length(); i++){

        switch(userInput[i]){

            case 'a':
            case 'A':
                valueCounter[0]+=1;
                break;
            case 'b':
            case 'B':
                valueCounter[1]+=1;
                break;
            case 'c':
            case 'C':
                valueCounter[2]+=1;
                break;
            case 'd':
            case 'D':
                valueCounter[3]+=1;
                break;
            case 'e':
            case 'E':
                valueCounter[4]+=1;
                break;
            case 'f':
            case 'F':
                valueCounter[5]+=1;
                break;
            case 'g':
            case 'G':
                valueCounter[6]+=1;
                break;
            case 'h':
            case 'H':
                valueCounter[7]+=1;
                break;
            case 'i':
            case 'I':
                valueCounter[8]+=1;
                break;
            case 'j':
            case 'J':
                valueCounter[9]+=1;
                break;
            case 'k':
            case 'K':
                valueCounter[10]+=1;
                break;
            case 'l':
            case 'L':
                valueCounter[11]+=1;
                break;
            case 'm':
            case 'M':
                valueCounter[12]+=1;
                break;
            case 'n':
            case 'N':
                valueCounter[13]+=1;
                break;
            case 'o':
            case 'O':
                valueCounter[14]+=1;
                break;
            case 'p':
            case 'P':
                valueCounter[15]+=1;
                break;
            case 'q':
            case 'Q':
                valueCounter[16]+=1;
                break;
            case 'r':
            case 'R':
                valueCounter[17]+=1;
                break;
            case 's':
            case 'S':
                valueCounter[18]+=1;
                break;
            case 't':
            case 'T':
                valueCounter[19]+=1;
                break;
            case 'u':
            case 'U':
                valueCounter[20]+=1;
                break;
            case 'v':
            case 'V':
                valueCounter[21]+=1;
                break;
            case 'w':
            case 'W':
                valueCounter[22]+=1;
                break;
            case 'x':
            case 'X':
                valueCounter[23]+=1;
                break;
            case 'y':
            case 'Y':
                valueCounter[24]+=1;
                break;
            case 'z':
            case 'Z':
                valueCounter[25] += 1;
                break;
                    default:
                break;
        }

    }
//set temporary to valueCounter[0]...valueCounter[1]....
//use printSmallest from [0], if temporary find less in counterArray. swap values

        for (int counter = 0; counter <=25; counter++){
            if (valueCounter[counter] != 0) {
                if (printSmallest == -1) {
                    printSmallest = valueCounter[counter];
                }
                else {
                    if (valueCounter[counter] < printSmallest) {
                        printSmallest = valueCounter[counter];
                    }
                }
            }
        }
//print out Smallest Value, convert which place in Array has number, then switch with Alphabet array
        cout << "The amount of least occurence letters in the string is: " << printSmallest << endl;
        cout << "The letters with the least frequent occurence is:";

        for (int counter = 0; counter <=25; counter++)
        {
            if (printSmallest==valueCounter[counter])
            {
                cout << alphabet[counter];
            }
        }
        cout << endl << endl;
}

//gets the word frequency, and push it into a vector
void getWordFreq (vector<Container>& list, string str){

    Container container;
    string original;

    // If there is punctuation found in the code, you go from the index called counter, and erase 1 index
     for (unsigned int counter =0; counter < str.length(); counter++)
           {
            if (ispunct(str[counter]) || isdigit(str[counter]))
                {
                  str.erase(counter, 1);
                  counter--;
                }
           }

    // If there is a space on the first index, erase until you find a letter
        //After you find a letter, keep going through string until you hit a space...
            //Substring that word, and store it into the vector. Erase word from orignal Line
                //Repeat until you find end of string and store that into the vector
     for (unsigned int counter = 0; counter <= str.length(); counter++)
           {

          while (str[0]==' ')
              {
                str.erase(0, 1);
              }


               if (str.length() > 0) {
                   if ((isspace(str[counter])) || (str[counter] == '\0'))
                  {
                     container.word = str.substr(0, counter);
                     container.count = 1;
                     list.push_back(container);
                     str.erase(0, counter);
                     counter = 0;
                   }
               }
            }


        //Two arrays to delete words if similar, and up the frequency count if similar words
        //var Original = loop through whole vector]
    for (unsigned int originalIndex=0; originalIndex < list.size(); originalIndex++)
        {
             original = list[originalIndex].word;

        //second array to match Original, if second array equal to first, delete second Array index..
             //up the counter for the original, and set the check index by one to continue on the search
        for (unsigned int check=originalIndex+1; check < list.size();check++)
             {
            if (stringCompare(list[check].word, original) == 0)
                    {
                        list[originalIndex].count += 1;
                        list.erase(list.begin()+check);
                        check --;
                    }
             }
        }
}

//print out the vector contents
void printVectorContents(vector<Container>& list){

    for (unsigned int counter=0; counter<list.size();counter++)
    {
        cout << "vector [" << counter << "] contains: " << endl;
        cout << "word: " << list[counter].word << endl;
        cout << "count: " << list[counter].count<< endl;
        cout << endl;
    }
}

//displey the words with the highest frequency
void getMostFreqWord(vector<Container>& list){

    if (!list.empty()) {
    int original;

    // Find the largest freq (number) in the list
        //Original = first index
            //If the looped array index is bigger then the original, then the original (list[0]) ....
                //equal to the looped array index. Therefore, list[0] has highest number.
                    //cout the numbers in the vector with the same number
    original = list[0].count;
    for (unsigned int originalIndex=1; originalIndex < list.size(); originalIndex++)
    {
        if (list[originalIndex].count > original)
        {
            original = list[originalIndex].count;
        }
    }
    cout << "You found words with " << original << " as the highest frequency in the sentence!" << endl;
        for (unsigned int i=0; i < list.size(); i++)
            {
                if (original == list[i].count)
                    {
                        cout << i+1<<". ";
                        cout << list[i].word << endl;
                    }
            }
    }
        else
                {
                    cout << "Vector is empty -- Nothing to count" << endl;
                }
}


int main(){
   //Declaring the vector of objects in main
      vector <Container> list;
      string checkedString;

   //Asking for user input in main
      string userInput;
      cout << "This program evaluates the least frequency of letters and highest frequency of words." << endl;
      cout << "Enter a string: ";
      getline (cin, userInput);

   //Function declarations
      leastFreqLetter(userInput);
      getWordFreq(list,userInput);
      printVectorContents(list);
      getMostFreqWord(list);
}
