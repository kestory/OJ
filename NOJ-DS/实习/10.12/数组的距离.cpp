Description
已知元素从小到大排列的两个数组x[]和y[]，请写出一个程序算出两个数组彼此之间差的绝对值中最小的一个，这叫做数组的距离

Input
第一行为两个整数m, n(1≤m, n≤1000)，分别代表数组f[], g[]的长度。 
第二行有m个元素，为数组f[]。 
第三行有n个元素，为数组g[]。

Output
数组的最短距离

Sample Input
5 5
1 2 3 4 5
6 7 8 9 10
Sample Output
1
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
#include <cmath>
using namespace std;
void BubbleSort(int* pData, int count)  
{  
	int temp;  
	for (int i = 1; i < count; i++)  
	{  
		for (int j = count - 1; j >= i; j--)  
		{  
			if (pData[j] < pData[j - 1])  
			{  
				temp = pData[j - 1];  
				pData[j - 1] = pData[j];  
				pData[j] = temp;  
			}  
		}  
	}  
}  

int main(int argc, char const *argv[])
{
	int m,n;
	int f[50];
	int g[50];
	int c[1024];
	for (int i = 0; i < 1024; ++i)
	{
		c[i]=65535;
	}
	cin>>m>>n;
	for (int i = 0; i < m; ++i)
		cin>>f[i];
	for (int i = 0; i < n; ++i)
		cin>>g[i];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			c[i*m+j]=abs(g[i]-f[j]);
			cout<<"\ni*m+j="<<i*m+j<<endl;
			cout<<"c[]="<<c[i*m+j]<<endl;
		}
	}
	for (int i = 0; i<24; ++i)
	{
		cout<<c[i]<<" ";
	}
	cout<<"\nfirst "<<c[0];
	BubbleSort(c, 1024);
	cout<<"\nsecond "<<c[0];
	return 0;
}




#include <iostream>
using namespace std;
int a(int x){
	if(x>0)
		return x;
	else 
		return -x;
}
int main()
{
	int m,n;
	int cha1=100;
	int cha2;
	int f[1024];
	int g[1024];
	cin>>m>>n;
	for (int i = 0; i < m; ++i)
		cin>>f[i];
	for (int i = 0; i < n; ++i)
		cin>>g[i];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cha2=a(g[i]-f[j]);
			if(cha2<cha1)
			cha1=cha2;
		}
	}
	cout<<cha1;
	return 0;
}