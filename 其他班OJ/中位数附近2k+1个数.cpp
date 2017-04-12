题目描述
给出一串整型数 a1,a2,...,an 以及一个较小的常数 k，找出这串数的中位数 m 和最接近 m 的小于等于 m 的 k 个数，以及最接近 m 的大于等于 m 的 k 个数。将这 2k+1 个数按升序排序后输出。


中位数定义：如果数串的大小是偶数 2j，中位数是从小到大排列的第 j 个数；如果数串的大小是奇数 2j+1，中位数是从小到大排列的第 j+1 个数。

输入
第一行是 k 的值和数串的长度 n。

第二行是以空格隔开的 n 个整型数，最后一个数后面有空格。

输出
按升序排列的 2k+1 个数，以空格分开，最后一个数后面没有空格。结果可能出现重复的数。
样例输入
2 10
7 2 5 7 2 10 7 7 13 15
样例输出
5 7 7 7 7
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
用以前的，很快，但为啥现在MAX都要3千万才行。。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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
	int k,n;
	cin>>k>>n;
	int a[MAX];
	for (int i = 0; i < n; ++i)
		cin>>a[i];
	int temp[MAX];
	//while(scanf("%d",&a[n])&&a[n]!=-1)
	//	n++;
	//BubbleSort_int(a,n);
	mergeSort(a,temp,0,n-1);
	//for (int i = 0; i < n; ++i)
	//	printf("%d ",a[i]);
	//printf("%d",a[n-1]);
	int m=(n+1)>>1;
	//D(m);
	for (int i = m-k-1; i < m+k; ++i)
	{
		cout<<a[i]<<" ";
	}

}
