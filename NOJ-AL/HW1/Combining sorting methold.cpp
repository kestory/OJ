Description

Everybody with computer science background more or less has learnt something about sorting methods such as selection sort, insertion sort, merge sort and quick sort.
It is with sheer significance that we could use these sort methods flexibility and combine their respective characteristics to solve some new problems.
Now, there is a sequence of numbers having been sorted partially. Here, partially sorted means the sequence is combined by several subsequences which have been sorted from smallest to largest.
For example, the given sequence is 7 8 9 1 2 11 39 9 9 which is composed by sorted subsequences 7 8 9, 1 2 11 39, 9 9.  Your task is to sort the given sequence from smallest to largest using characterizes of the sorted subsequences.

Input

A given sequence described above whose length is no longer than 3,000,000.
The absolute values of the numbers of the sequence are no larger than 2^31.
(Obviously we do not want you to directly use the sort methods you have learnt before and such directly use will probably causeruntime error).

Output

Sorted sequence of the given sequence.

Sample Input
7 8 9 1 11 2

Sample Output
1 2 7 8 9 11

HINT
We stongly suggest you to using scanf and printf to input and output in order to saving time.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
I did not write so many code, just C+C&C+V from the code before.
Just make MAX=3001000
konw while(~scanf("%d",&a[n]))
and notice Presentation
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <cstdio>
#include <iostream>
#define dprint(expr) printf(#expr "= %d\n",expr)
#define D(x) cout<<#x<<"="<<x<<endl;
using namespace std;
const int MAX=3001000;
/*void BubbleSort_int(int pData[], int count)
{
	//int temp;
	for (int i = 1; i < count; i++)
	{
		for (int j = count - 1; j >= i; j--)
		{
			if (pData[j] < pData[j - 1])
			{
				int temp = pData[j - 1];
				pData[j - 1] = pData[j];
				pData[j] = temp;
			}
		}
	}
}*/
void merge(int a[], int temp[], int first, int mid, int last){
	int i=first;
	int x=first;
	int j=mid+1;
	while(i<=mid&&j<=last){
		if (a[i]>a[j]){
			temp[x++]=a[j++];
			//s+=mid-i+1;
		}
		else
			temp[x++]=a[i++];
	}

	while(i<=mid)	temp[x++]=a[i++];
	while(j<=last)	temp[x++]=a[j++];
	for (int ii = first; ii <= last; ++ii)		a[ii]=temp[ii];
}
void mergeSort(int E[], int temp[], int first, int last){
	if (first<last){
		int mid=(first+last)>>1;// just/2
		mergeSort(E, temp, first, mid);
		mergeSort(E, temp, mid+1, last);
		merge(E, temp, first, mid, last);
	    }
	return;
}
int main(int argc, char *argv[]) {
	int a[MAX];
	int temp[MAX];
	int n=0;
	while(~scanf("%d",&a[n]))
		n++;
	//while(scanf("%d",&a[n])&&a[n]!=-1)
	//	n++;
	//BubbleSort_int(a,n);
	mergeSort(a,temp,0,n-1);
	for (int i = 0; i < n-1; ++i)
		printf("%d ",a[i]);
	printf("%d",a[n-1]);

}
