/*
* Author: Kendrick Kwok
*
Select the largest n your software can support and then K so that this
loop with an iterative version of bs runs 3 seconds or more. Then measure and
compare this run time
and the run time of the loop that uses a recursive version of bs. Compare these
run times
using maximum compiler optimization (release version) and the slowest version
(minimum optimization or the debug version). If you use a laptop, make
measurements
using AC power, and then same measurements using only the battery. What
conclusions
can you derive from these experiments? Who is faster? Why?
/*
* This program tests the times of recursion and iteration in binary search.
* What conclusions have I derived from this program? Not only have I wrote
* this program to be the fastest and most efficient programming, performing
* stops and ends in each search, but I have also recorded have the times with
* different compiler optimizations. The output is as follows. With the laptop,
* using AC power, it has taken me 10 seconds for iteration and 13 seconds for
* recursion. With battery power, it takes me 15 seconds for iteration and 13
* seconds for recursion.
*
* What does this program show? This test shows that with different compiler
* optimizations, with different states of the computer, it can make one faster
* then the other, and creating different results. The program might not be the
* only factor in the way of how fast a program different can run.
*/
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#define N 110;
using namespace std;
int bsr (int array[], int count, int x);
int bsi(int array [], int n, int key);
int bsr (int array[], int first, int last, int key){
//compute midpoint
//if first is less than last
if (first <= last )
{
//compute the midpoint
int mid = (first + last)/2;
if (key == array[mid]) return mid;
else if (key < array[mid]) return bsr (array, first, mid-1, key);
else return bsr(array, mid+1, last, key);
}
return -1;
}//iteration
int bsi (int array[], int first, int last, int key)
{
//compute midpoint
while (first <= last)
{
//compute the midpoint
int mid = (first + last)/2;
if (key == array[mid]) return mid;
else if (key < array[mid]) last = mid - 1;
else first = mid + 1;
}
return -1;
}
int main()
{
//declarations
int array[110], n = 100, k = 1000000;
clock_t start, end, clockTicksTaken, start1, end1, clockTicksTaken1;
double run_timeI, run_timeR;
//initialize everything to 0
for(int i = 0; i < n ; i++){
array[i] = i;
}
//start the stopwatch of when iteration starts and end
start = clock();
for(int j=0; j<k; j++)
for(int i=0; i<n; i++)
if(bsi(array,0, n, i) != i)
cout << "ERROR";
end = clock();
//Finding the length of seconds, subtract end with the start
clockTicksTaken = (double)end - (double)start;
run_timeI = clockTicksTaken / (double)CLOCKS_PER_SEC;
cout << "Iterator runs at " << run_timeI <<
" seconds for iterating Binary Search." << endl;
//start the stopwatch of when recursion starts and end
start1 = clock();
for(int j=0; j<k; j++)
for(int i=0; i<n; i++)
if(bsr(array,0, n, i) != i)
cout << "ERROR";
end1 = clock();
//Finding the length in seconds, subtract end with start
clockTicksTaken1 = (double)end1 - (double)start1;
run_timeR = clockTicksTaken1 / (double)CLOCKS_PER_SEC;
cout << "Recursion runs at " << run_timeR <<
" seconds for recursion Binary Search." << endl;
}/*Output
*
* AC POWER
* *************
* Iterator runs at 10.5624 seconds for iterating Binary Search.
Recursion runs at 13.2747 seconds for recursion Binary Search.
*
*BATTER POWER
***************
* Iterator runs at 15.8393 seconds for iterating Binary Search.
* Recursion runs at 13.2438 seconds for recursion Binary Search.
*/
