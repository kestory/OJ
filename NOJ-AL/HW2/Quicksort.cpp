Problem D: Quicksort

Time Limit: 3 Sec  Memory Limit: 128 MB
Submit: 183  Solved: 84
[Submit][Status][Web Board]
Description

快速排序

Input

For each of the input, the first line of the input will be the size of the array (size < 1, 000, 000), and the second line is the integers in the array, separated by commas.

Output

For each of the input, your program should use quicksort to sort the integers in increasing order and output them.

Sample Input

3
1 3 2
10
3 4 6 1 2 6 0 - 1 2 5
Sample Output

1 2 3
- 1 0 1 2 2 3 4 5 6 6
HINT
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
直接学习代码再改进，效率会高
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <algorithm>
#include <iostream>
#define dprint(expr) printf(#expr "= %d\n",expr)
#define D(x) cout<<#x<<"="<<x<<endl;
#define exchange(a,b)     (a=a^b,b=a^b,a=a^b)
#define MAX 1000000
using namespace std;

int partition (int arr[], int low, int high) {
	int pivot = arr[low];
	int i = low;
	for (int j = low + 1; j <= high; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);//#include <algorithm>
		}
	}
	swap(arr[i], arr[low]);
	return i;
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


int main(int argc, char *argv[]) {
	int n = 0; //size
	int a[MAX];//array
	//int temp[MAX];//I just use mergesort to test :-)
	ios::sync_with_stdio(false);
	while (cin >> n) {
		for (int i = 0; i < n; ++i)		cin >> a[i];
		//mergeSort(a,temp,0,n-1);
		//quicksort;
		quickSort(a, 0, n - 1);
		cout << a[0]; //the Presentation
		for (int i = 1; i < n; ++i)		cout << ' ' << a[i];
		cout << '\n';
	}
	return 0;
}
