Description
给定一系列的非负整数，将它们排列组合使之构成一个最大的数。

例如：给定[3,30,34,5,9],它们能够生成的最大的数为9534330.

Input
输入为一行数字，以逗号分隔。
Output
输出为一个数字，表示你的结果。
Sample Input
3,30,34,5,9
0,1,4,56,3,9
Sample Output
9534330
9564310
HINT
结果可能非常大，所以你可以使用String来存储数字。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
这题不算很简单吧，，其实也没什么吧
主要是你不要想着投机取巧，直接写get_i,而非get_top,get_second写了还过不了
期间由于冒泡排序不熟悉还出了怪怪得错，想清楚每一步，多调试就还好。
偶尔学到的擦边知识还是很有用的。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <cstring>
#define dprint(expr) printf(#expr "= %d\n",expr)
#define D(x) cout<<#x<<"="<<x<<endl;
#define DS(x) cout<<#x<<" = "<<x<<"	";
using namespace std;
int get_top(int x){
	int k=x/10;
	int w;
	while(k>0){
		w=k;
		k/=10;
	}
	return w;
}
int get_len(int x){
	int len=1;
	int k=x/10;
	while(k>0){
		len++;
		k/=10;
	}
	return len;
}
int get_second(int x){
	//D(x);
	if(get_len(x)==1)
		return x;
	else{
		while(get_len(x)>2){
			x/=10;
		}
		return x%10;
	}
}


int main(int argc, char *argv[]) {
	char a[1024];
	int n[16];
	while(cin>>a){		
		char *ptr;		
		ptr=strtok(a,",");
		int j=0;
		while(ptr!=NULL){
			n[j]=atoi(ptr);
			ptr=strtok(NULL,",");
			j++;
		}
	//for (int i = 0; i < j; ++i)\
		cout<<n[i]<<' ';\
	cout<<endl<<endl<<endl;//奇怪，没这个3,30输出303，有输出330
	for (int i = 0; i < j; ++i)
	{
		int bigger=-1;
		for (int k = j-1; k >= i; --k)
		{
			if(get_top(n[k])<get_top(n[k+1])||((get_top(n[k])==get_top(n[k+1]))&&(get_second(n[k])<get_second(n[k+1])))){
				bigger=n[k+1];
				n[k+1]=n[k];
				n[k]=bigger;}
		
		//for (int i = 0; i < j; ++i)\
			cout<<n[i];\
		cout<<endl;
		}
	}
	for (int i = 0; i < j; ++i)
		cout<<n[i];
	cout<<endl;
	memset(n,0,sizeof(n));//轻巧的刷新一下n数组
}
	return 0;
}

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <cstring>
#define dprint(expr) printf(#expr "= %d\n",expr)
#define D(x) cout<<#x<<"="<<x<<endl;
#define DS(x) cout<<#x<<" = "<<x<<"	";
using namespace std;
int get_len(int x){
	int len=1;
	int k=x/10;
	while(k>0){
		len++;
		k/=10;
	}
	return len;
}
int get_i(int x,int i){
	if(get_len(x)<i)
		return x;
	else{
		while(get_len(x)>i){
			x/=10;
		}
		return x%10;
	}

}
int main(int argc, char *argv[]) {
	char a[1024];
	int n[16];
while(cin>>a){	
		char *ptr;		
		ptr=strtok(a,",");
		int j=0;
		while(ptr!=NULL){
			n[j]=atoi(ptr);
			ptr=strtok(NULL,",");
			j++;
		}
		//D(j);
	for (int i = 0; i < j; ++i)
	{
		int bigger=-1;
		for (int k = j-2; k >= i; --k)
		{
			int l=max(get_len(n[k]),get_len(n[k+1]));
			//D(get_len(n[k]));
			//D(get_len(n[k+1]));
			//D(l);
			bool flag=false;
			for(int w=0;w<l;w++)
			{
				if(get_i(n[k],w+1)<=get_i(n[k+1],w+1))
					flag=true;
				else
					flag=false;
			}
			//D(flag);
			if(flag){
			bigger=n[k+1];
			n[k+1]=n[k];
			n[k]=bigger;
			}
			
		}
	}
	for (int i = 0; i < j; ++i)
		cout<<n[i];
	cout<<endl;
	memset(n,0,sizeof(n));//轻巧的刷新一下n数组
}
	return 0;
}

