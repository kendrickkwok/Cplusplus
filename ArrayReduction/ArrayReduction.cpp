/*
* Author: Kendrick Kwok
*
* Problem 3:
* The array a(1..n) contains arbitrary integers.
* Write a function reduce(a,n) that reduces
* the array a(1..n) by eliminating from it all values that are
* equal to three largest different integers. For example, if
* a=(9,1,1,6,7,1,2,3,3,5,6,6,6,6,7,9) then
* three largest different integers are 6,7,9 and after reduction
* the reduced array will be a=(1,1,1,2,3,3,5), n=7. The
* solution should have time complexity O(n)
*/
/*
* This program is the fastest and most efficient way to find the three
* largest numbers and eliminating them. This runs on a time complexity
* of O(n). A number is assigned to the first top1, and as array progresses,
* the numbers will be assigned to top2 and top3. When it goes through each array,
* numbers will be compared and will be assigned larger numbers if the
* number compared is bigger. After numbers are found, we go through the loop
* and assign different numbers into another array. We then print out the array,
* and a reduced array is formed.
*/
#include <iostream>
#include <cmath>
using namespace std;
void reduce (int[], int);
void printArray(int[], int size);
void reduce (int array[], int size)
{
//top 1 is assigned with first index
int top1 = array[0], top2 = array[1], top3 = array[2], temp[8], count = 0, j=0;
//if element is greater then top 1, assign value to top 1
//give the other top2 to replace value of previous tops
for (int i = 0; i < size; i++){
if (array[i] > top1)
{
top1 = array[i];
top2 = top1;
top3 = top2;
}
//if element is greater then top 2 and less than top 1,
//-- assign to top 2, shift top3 to be top 2
else if (array[i] > top2 && array[i] < top1)
{
top2 = array[i];
top3 = top2;
}
//if element is third greatest, give the top to arrayelse if ((array[i] < top2) && (array[i] < top1)) top3 = array[i];
}
//if top1, top2, and top3 are found in the array. Do not put into temp array.
//--Elements that are are not top1, top2, top3, put into array called temp.
for (int i = 0; i < size; i++)
{
if (top1 != array[i] && top2 != array[i] && top3 != array[i])
{
temp[j] = array[i];
count++;
j++;
}
}
//prints out array and shows the result
cout << "The original size of the array is: ";
printArray(array, size);
cout << endl << "The largest integers in the array are: " << top1 << " "
<< top2 << " " << top3 << endl;
cout << "After reduction, the array lost " << count << " numbers." << endl;
cout << "The array is now: ";
printArray(temp, count);
}
//prints out array
void printArray(int array[], int size)
{
for (int i = 0; i < size; i++ ) cout << array[i] << "|";
}
int main()
{
int size = 16;
int array[16] = {9,1,1,6,7,1,2,3,3,5,6,6,6,6,7,9};
reduce (array, size);
}
//Output **
/*
The original size of the array is: 9|1|1|6|7|1|2|3|3|5|6|6|6|6|7|9|
The largest integers in the array are: 9 7 6
After reduction, the array lost 7 numbers.
The array is now: 1|1|1|2|3|3|5|
*////////////////
/*
