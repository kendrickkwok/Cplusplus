/*
* Author: Kendrick Kwok
*
* Problem 2:
* We know three points on a curve: ( x 1 , y 1 ), ( x 2 , y 2 ), ( x 3 , y 3 ).
* You have to create a program that for any value x 1  x  x 3 computes the
* corresponding value y assuming that the segment of curve can be approximated
* with the parabola y = ax^2 + bx + c . Write a function that can be called as
* y(x1,y1,x2,y2,x3,y3,x) and a main program that reads x1,y1,x2,y2,x3,y3 and
* then displays y(x1,y1,x2,y2,x3,y3,x) in n=40 equidsitant x points between x1
* and x3.
*/
/*
* This program takes three points of x, and three points of y.
* This is a good program because it shows two different ways of getting
* similar answers. This is also a good procedural program because it finds
* the fastest and most efficient ways to find the answers to this problem.
*
* From my program, I used Cramers. This finds a, b, and c using matricies and
* determinants. Then, I used Langrange interpolation formula to find the
* same thing. Suprisingly, both of these gave me the same results.
* My x1 had a value of 1, and my x2 had a value of 10. From 1 - 10,
* i found the 40 values of y in between these x's. The output is on the bottom.
*/
#include <cstdlib>
#include <iostream>
using namespace std;
void findY(int x1, int y1, int x2, int y2, int x3, int y3, int x);
void findYLagrange(int x1, int y1, int x2, int y2, int x3, int y3, int x);
void calculateTable(int x1, int y1, int x3, int y3, float a, float b, float c,
double x);
int main() {
//Test points
int x1 = 1, x2 = 5, x3 = 10, y1 = 5, y2 = 15, y3 = 25;
double x = 40;
findY(x1, y1, x2, y2, x3, y3, x);
findYLagrange(x1, y1, x2, y2, x3, y3, x);
return 0;
}
int determinant(int x1, int x2, int x3, int y1, int y2, int y3, int z1, int z2,
int z3){
/*
* *Given the 3x3 Matrix, the following equation should be
* |a b c| or |x1 x2 x3|
* |d e f| or |y1 y2 y3|
* |g h i| or |z1 z2 z3|
*
*a((e * i) - (f * h))- b((d * i) - (f * g)) + c((d * h) - (e * g))
*/}
double foundDeterminant = x1*((y2 * z3) - (y3 * z2))
-x2*((y1 * z3) - (y3 * z1))
+ x3*((y1 * z2) - (y2 * z1));
return foundDeterminant;
void findY(int x1, int y1, int x2, int
//Using the cramer rule
//Find a, b, and c
//
5 = 1a^2 + 1b + c;
a = |5 1
//
15= 5a^2 + 5b + c;
|15 5
//
25= 10a^2 + 10b + c;
|25 10
1);
y2, int x3, int y3, int x){
1| b = |1^2 5 1| c = |1^2 1 5 |
1|
|5^2 15 1|
|5^2 5 15|
1|
|10^2 25 1|
|10^2 10 25|
double foundDeterminant = determinant( x1*x1, x1, 1, x2*x2, x2, 1, x3*x3, x3,
double a = determinant(y1,x1,1,y2,x2,1,y3,x3,1)/foundDeterminant;
double b = determinant(x1*x1,y1,1,x2*x2,y2,1,x3*x3,y3,1)/foundDeterminant;
double c = determinant(x1*x1,x1,y1,x2*x2,x2,y2,x3*x3,x3,y3)/foundDeterminant;
}
cout << "With the three linear equations, a is: "<< a << endl;
cout << "With the three linear equations, b is: "<< b << endl;
cout << "With the three linear equations, c is: "<< c << endl;
void findYLagrange(int x1, int y1, int x2, int y2, int x3, int y3, int x){
double denominator1 = ((x1-x2)*(x1-x3));
double denominator2 = ((x2-x1)*(x2-x3));
double denominator3 = ((x3-x1)*(x3-x2));
double b = -((((y1*(x2+x3))/denominator1)+((y2*(x1+x3))/denominator2)+
((y3*(x1+x2))/denominator3)));
double a = (((y1/denominator1)+(y2/denominator2)+(y3/denominator3)));
double c = ((((y1*x2*x3)/denominator1)+((y2*x1*x3)/denominator2)+
((y3*x1*x2)/denominator3)));
cout << "In Langrange, a is: "<< a << endl;
cout << "In Langrange, b is: "<< b << endl;
cout << "In Langrange, c is: "<< c << endl;
}
calculateTable(x1,y1,x3,y3,a,b,c,x);
void calculateTable(int x1, int y1, int x3, int y3, float a, float b, float c,
double x)
{
cout << "From the curve of " << x1 << " to " << x3 <<
" the table is as follows: " << endl;
double size = x3/x;
double i = 0;
while (i < x3)
{
cout << "fx(" << i << ") = " << a*(i*i)+(b*i)+c << endl;
i+=size;
}
}//Output :
/*
With the three linear equations, a is:
With the three linear equations, b is:
With the three linear equations, c is:
In Langrange, a is: -0.0555556
In Langrange, b is: 2.83333
In Langrange, c is: 2.22222
From the curve of 1 to 10 the table is
fx(0) = 2.22222
fx(0.25) = 2.92708
fx(0.5) = 3.625
fx(0.75) = 4.31597
fx(1) = 5
fx(1.25) = 5.67708
fx(1.5) = 6.34722 fx(1.75) = 7.01042
fx(2) = 7.66667
fx(2.25) = 8.31597
fx(2.5) = 8.95833 fx(2.75) = 9.59375
fx(3) = 10.2222
fx(3.25) = 10.8437
fx(3.5) = 11.4583 fx(3.75) = 12.066
fx(4) = 12.6667
fx(4.25) = 13.2604
fx(4.5) = 13.8472 fx(4.75) = 14.4271
fx(5) = 15
fx(5.25) = 15.566
fx(5.5) = 16.125 fx(5.75) = 16.6771
fx(6) = 17.2222
fx(6.25) = 17.7604
fx(6.5) = 18.2917 fx(6.75) = 18.816
fx(7) = 19.3333
fx(7.25) = 19.8437
fx(7.5) = 20.3472 fx(7.75) = 20.8437
fx(8) = 21.3333
fx(8.25) = 21.816
fx(8.5) = 22.2917 fx(8.75) = 22.7604
fx(9) = 23.2222
fx(9.25) = 23.6771
fx(9.5) = 24.125 fx(9.75) = 24.566
*////
