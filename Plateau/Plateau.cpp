/*
* Author: Kendrick Kwok
*
* Problem 1:
*
Plateau program (max sequence length) (a combinatorial algorithm)
* The array a(1..n) contains sorted integers. Write a function maxlen(a,n) that
*returns the length of the longest sequence of identical numbers (for example, if
*a=(1,1,1,2,3,3,5,6,6,6,6,7,9) then maxlen returns 4 because the longest sequence
*6,6,6,6 4 numbers. Write a demo main program for testing the work of maxlen.
Explain your solution, and insert comments in your program.
*
*/
/*This is a good procedural program because this is the fastest way to find
*the max frequency number in the array. This is in O(n) time complexity, and it
*the output shows it is working. The idea behind this is that we take the array,
*find the highest amount of counts, and compare these counts with other numbers.
*If the number compared is lower then the one being compared, a new number
becomes max count. This repeats until the array is finished and the number with
max count max is printed.
*/
#include <iostream>
using namespace std;
int max_len(int array[], int size);
int counter, maxCount;
int max_len(int array[], int size)
{
int previous = array[0];
for (int i=0; i < size; i++){
//if the array is equal to first of array, increment counter
if (array[i] == previous) counter++;
else
{
//else the previous is equaling to array
previous = array[i];
//if the max count happens to be less the what is counted
//...counter is returned to one and go back to array
if (maxCount < counter) maxCount = counter;
counter = 1;
}
}
return maxCount;
}
int main()
{
//declare a size of array 13
int array[13] = {1,2,2,2,2,2,2,3,5,5,5,7,8};
int size = 13;
cout << max_len(array, size);
}
/* Output
* 6
*////
