Description

Write a program that reads in ten numbers and then outputs the sum of all positive numbers, the sum of all nonpositive numbers, and the sum of all the ten numbers. The user enters the ten numbers just once each and the user can enter them in any order. Your program should not ask the user to enter the positive numbers and the negative numbers separately.

Input

Ten numbers

Output

The sum of the numbers greater than zero, the sum of the numbers less than zero, and the sum of all numbers, seperated by commas. Each value output should be rounded to 2 digits after the decimal point.

Sample Input

2 3 -3 4 5 6 12 7 0 -5
Sample Output

39.00,-8.00,31.00
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
数据们都要浮点类型
头文件要写全
三个for循环可以简化成一个
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define dprint(expr) printf(#expr "= %d\n",expr)
#define D(x) cout<<#x<<"="<<x<<endl;
using namespace std;
int main(int argc, char *argv[]) {
	double a[10];
	memset(a,0,sizeof(a));//initialise
	//for(int i=0;i<10;i++)\
		a[i]=0;
	double s1=0,s2=0,s3=0;
	for(int i=0;i<10;i++)
		cin>>a[i];
	for(int i=0;i<10;i++){
		s3+=a[i];
		if(a[i]>0)
			s1+=a[i];
		else
			s2+=a[i];
	}
	/*for(int i=0;i<10;i++){
		if(a[i]<0)
			s2+=a[i];
	}
	for(int i=0;i<10;i++){	
		s3+=a[i];
	}*/	
	printf("%0.2f,%0.2f,%0.2f",s1,s2,s3);	
}