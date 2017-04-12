Problem E: ACCELERATED HEAPSORT

Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 135  Solved: 79
[Submit][Status][Web Board]
Description

ACCELERATED HEAPSORT

Input

For each of the input, the first line of the input will be the size of the array(size <= 1, 000, 000), and the second line is the integers in the array, seperated by commas.

Output

For each of the input, your program should use accelerated heap sort to sort the intergers in incresing order and output them

Sample Input

3
1 3 2
10
3 4 6 1 2 6 0 -1 2 5
Sample Output

1 2 3
-1 0 1 2 2 3 4 5 6 6
HINT

Remember to use ACCELERATED HEAPSORT
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <cstdio>
#include <iostream>
#define dprint(expr) printf(#expr "= %d\n",expr)
#define D(x) cout<<#x<<"="<<x<<endl;
#define exchange(a,b)     (a=a^b,b=a^b,a=a^b)
using namespace std;
#define MAX 1000000

int main(int argc, char *argv[]) {
int n=0;//size
	int a[MAX];//array
	//int temp[MAX];//I just use mergesort to test :-)
	ios::sync_with_stdio(false);
	while(cin>>n){
	for (int i = 0; i < n; ++i)		cin>>a[i];
	//mergeSort(a,temp,0,n-1);
	//quicksort;

	cout<<a[0];//the Presentation
	for (int i = 1; i < n; ++i)		cout<<' '<<a[i];
	cout<<'\n';
	}
	return 0;
}
