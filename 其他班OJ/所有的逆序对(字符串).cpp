题目描述
给出一个字符串数组，如果（按照字典序）一个大的字符串在比它小的字符串前面我们称这两个字符串组成一个“逆序对”。你需要找到所有的逆序对的个数。

输入
第一行是数组大小，第二行是以空格分隔的字符串数组.

注：预先知道每个字符串的长度都是 10.

输出
所有的逆序对个数.
注意：结果比较大，请用 long 类型保存.

样例输入
3
aaaaaaaaaa cccccccccc bbbbbbbbbb
样例输出
wo yi yue du guan yu chao xi de shuo ming
1
提示
不要使用蛮力算法
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
把之前的对 int 的改来改，复习了对字符串的操作，自己运行没问题了
OJ 一直越界，果真改下 MAX 就行。。。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <cstring>
#define dprint(expr) printf(#expr "= %d\n",expr)
#define D(x) cout<<endl<<#x<<"="<<x<<endl;
using namespace std;
const int MAX=100010;
long long s=0;//number of inversion
void merge(char a[][11], char temp[][11], int first, int mid, int last){//e.g. 1 3 5; 2 4
	int i=first;
	int x=first;
	int j=mid+1;
	while(i<=mid&&j<=last){
		if(strcmp(a[i],a[j])>0){//if (a[i]>a[j]){
			strcpy(temp[x],a[j]);//temp[x++]=a[j++];
			x++;
			j++;
			s+=mid-i+1;
		}
		else{
			strcpy(temp[x],a[i]);//temp[x++]=a[i++];
			x++;
			i++;
		}
	}

	while(i<=mid)	{
		strcpy(temp[x],a[i]);//temp[x++]=a[i++];
			x++;
			i++;

	}
	while(j<=last)	{
		strcpy(temp[x],a[j]);//temp[x++]=a[j++];
			x++;
			j++;

	}
	for (int ii = first; ii <= last; ++ii)		strcpy(a[ii],temp[ii]);//a[ii]=temp[ii];
}
void mergeSort(char E[][11], char temp[][11], int first, int last){
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
	char a[MAX][11];
	char temp[MAX][11];
	for (int i = 0; i < n; ++i){
		cin>>a[i];
	}
	//cout<<a[0]<<endl;
	//cout<<a[1]<<endl;
	//cout<<a[2]<<endl;

	mergeSort(a,temp,0,n-1);
	cout<<"wo yi yue du guan yu chao xi de shuo ming"<<endl;
	cout<<s;
}
