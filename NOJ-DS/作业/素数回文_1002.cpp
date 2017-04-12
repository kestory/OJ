Description
小王对既是素数又是回文的数特别感兴趣。比如说151既是素数又是个回文。现在小王想要你帮助他找出某个范围内的素数回文数，请你写个程序找出 a 跟b 之间满足条件的数。(5 <= a < b <= 100,000,000);

Input
输入a和b(5 <= a < b <= 100,000,000)

Output
按从小到大输出a，b之间所有满足条件的素数回文数
Sample Input
5 500
Sample Output
5
7
11
101
131
151
181
191
313
353
373
383
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <cmath>
using namespace std;

void change(int &a,int &b){
	if (a>b)
	{
		int t=a;
		a=b;
		b=t;
	}
	else
		return;

}
bool palindrome(int n);//huiwen
bool prime_number(int n);//sushu
int main(int argc, char const *argv[])
{
	int a,b;
	cin>>a>>b;
	change(a,b);
	//cout<<a<<" "<<b;
	for (int i = a; i <= b; ++i)
	{
		if (palindrome(i)&&prime_number(i))
		{
			cout<<i<<endl;
		}
	}
	
	return 0;
}

bool palindrome(int n){
	char str[255];
	sprintf(str, "%d", n); 
	int len=0;
	for(;str[len]!='\0';len++);
	//int len=strlen(str);
	bool flag=true;
	for (int i = 0; i <= len/2; ++i)
	{
		if(str[i]==str[len-i-1])
			continue;
		else
			flag=false;
	}
	if (flag==false)
		return false;
	else
		return true;
}
bool prime_number(int n){
	int m=sqrt(n);
	bool flag=false;
	for (int i = 2; i <= m; ++i)
	{	if(n%i==0)
			flag=true;
	}
	if (flag==false)
		return true;
	else
		return false;
}