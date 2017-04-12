Description
一个数与另一个数如果含有相同数字和个数的字符，则称两数相关。现有一堆乱七八糟的整数，里面可能充满了彼此相关的数，请你写一个程序，自动地将其剔除。

Input
第一行是一个整数N(<1000)，表示下面会有N个数；

接下来一行是跟随的N个整数，以空格分割。若N=0，则程序结束。

Output
按从小到大的顺序输出非相关数，若没有非相关数，则输出None

Sample Input
8
213 667 3 213 43 34 677 2
3
322 232 232
0


Sample Output
2 3 667 677
None
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <cmath>
using namespace std;
void BubbleSort(char pData[], int count)  
{  
	//int temp;  
	for (int i = 1; i < count; i++)  
	{  
		for (int j = count - 1; j >= i; j--)  
		{  
			if (pData[j]-'0' < pData[j - 1]-'0')  
			{  
				char temp = pData[j - 1];  
				pData[j - 1] = pData[j];  
				pData[j] = temp;  
			}  
		}  
	}  
} 
void BubbleSort_int(int pData[], int count)  
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
} 
int main(int argc, char const *argv[])
{	int a;
	char str[255];
	while(cin>>a&&a!=0){
		int w[a];
		int k[a];
	for (int i = 0; i < a; ++i)
		{
			cin>>w[i];
			int len=sprintf(str,"%d",w[i]);
			BubbleSort(str,len);
			w[i]=atoi(str);
			//cout<<w[i];
		}
	for (int i = 0; i < a; ++i)
			k[i]=0;
	for (int i = 0; i < a; ++i){
		for (int j = i+1; j < a; ++j)	{
			if (w[i]==w[j])
			{
				k[i]=1;
				k[j]=1;
			}
		}
	}
	/*for (int i = 0; i < a; ++i)//////////
	{
		cout<<k[i];
	}*/
	int count=0;
	int pr[a];
	for (int i = 0; i < a; ++i)
	{
	if (k[i]==0){
		pr[count]=w[i];
		count++;
	}
	}
	if (count==0)
	{
		cout<<"None"<<endl;
	}
	else{
		/*for (int i = 0; i < count; ++i)
		{
			cout<<pr[i]<<" ";
		}*/
		//cout<<"\nbeforeshangmain\n";
		BubbleSort_int(pr,count);
		//p(pr,a);
		for (int i = 0; i < count; ++i)
		{
			cout<<pr[i]<<" ";
		}
	
	}

	}
	return 0;
}

