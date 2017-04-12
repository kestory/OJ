Description

If you play games, you will know the importance of your equipment.
However, your equipment is not the only thing to determine your success.
Therefore, there are a lot of people winning without precious equipment because of their high fighting strength.
Now, you are given a list of people's fighting strength(a1, a2, a3, ……, an). //'
And the list is sorted according to their equipment value from low to high.
Your target is to find how many such pairs(i, j) exists  where ai > aj which means people i with lower equipment but higher fighting strength than people j.

Input

The first line is just an integer n (1 < n < 1000000).

The second line are n integers a1, a2, a3……an(|ai| < 2^31)

Output

You just need to output the number of pairs described above .

Sample Input

5
3 2 1 4 5
Sample Output
3
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
两重循环轻易超时间，问得是归并排序算逆序对。
听闻逆序对，甚有道理，归并于课后，了解。
写完，似了却心头一事，然OJ以WA待我，问助教得数组不能动态申请，怪编译器太宽容，然改后无果
助教又发现我并没有赋值，原来我调试信息一大堆后结果正确，删除时误删了，就样例而言结果碰巧对
于是尴尬改完，一直手输样例，与题中样例不一，以为自己错，后来卓尔相助，发现已经对了。
仍需了解非递归实现以及inplace算法。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#define dprint(expr) printf(#expr "= %d\n",expr)
#define D(x) cout<<endl<<#x<<"="<<x<<endl;
using namespace std;
const int MAX=1000100;
long long s=0;//number of inversion
void merge(int a[], int temp[], int first, int mid, int last){//e.g. 1 3 5; 2 4
	int i=first;
	int x=first;
	int j=mid+1;
	//cout<<endl<<"sorted first-mid:";
	//for (int ii = first; ii <= mid; ++ii)	cout<<a[ii];
	//cout<<endl<<"sorted mid+1-last:";
	//for (int ii = mid+1; ii <= last; ++ii)	cout<<a[ii];
	while(i<=mid&&j<=last){
		if (a[i]>a[j]){
			temp[x++]=a[j++];
			s+=mid-i+1;
		}
		else
			temp[x++]=a[i++];
	}

	while(i<=mid)	temp[x++]=a[i++];
	while(j<=last)	temp[x++]=a[j++];
	//D(s);
	//cout<<endl<<"sorted temp[]:";
	//for (int ii = first; ii <= last; ++ii)	cout<<temp[ii];
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
	int n;
	cin>>n;
	int a[MAX];
	int temp[MAX];
	for (int i = 0; i < n; ++i){
		cin>>a[i];
	}

	mergeSort(a,temp,0,n-1);
	//cout<<endl<<"sorted a[]:";
	//for (int i = 0; i < n; ++i)	cout<<a[i];
	//D(s);
	cout<<s;
}
