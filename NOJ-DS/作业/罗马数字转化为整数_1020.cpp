Description
给定一个罗马数字，将其转化为一个整数。


Input
输入的罗马数字大小范围保证在1~3999之间。
Output
输出为一个整数。
Sample Input
DCXXI
DCCLXVIII
Sample Output
621
768
HINT
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
简单的，先是投机取巧只写加法，果然不通过，然后没什么技巧的暴力写了下前5名通过～
看网上leetcode代码，发现用了map然后去学，然后想找一个代码笔记，不知不觉时间飞逝

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <string>
using namespace std;
bool judge(char a,char b){
	int v1=0;
	if(a=='I')
		v1=1;
	else if(a=='V')
		v1=2;
	else if(a=='X')
		v1=3;
	else if(a=='L')
		v1=4;
	else if(a=='C')
		v1=5;
	else if(a=='D')
		v1=6;
	else if(a=='M')
		v1=7;
	int v2=0;
	if(b=='I')
		v2=1;
	else if(b=='V')
		v2=2;
	else if(b=='X')
		v2=3;
	else if(b=='L')
		v2=4;
	else if(b=='C')
		v2=5;
	else if(b=='D')
		v2=6;
	else if(b=='M')
		v2=7;
	int c=v1-v2;
	return (c>0)?true:false;

}
int main(int argc, char *argv[]) {
	string str;
	while(cin>>str){
	int value=0;
	for (int i = 0; i < str.length(); ++i)
	{
		if(i+1<str.length()&&judge(str[i],str[i+1])){
		if(str[i]=='I')
			value+=1;
		else if(str[i]=='V')
			value+=5;
		else if(str[i]=='X')
			value+=10;
		else if(str[i]=='L')
			value+=50;
		else if(str[i]=='C')
			value+=100;
		else if(str[i]=='D')
			value+=500;
		else if(str[i]=='M')
			value+=1000;
	}
		else if(i+1<str.length()&&!judge(str[i],str[i+1])){
		if(str[i]=='I')
			value-=1;
		else if(str[i]=='V')
			value-=5;
		else if(str[i]=='X')
			value-=10;
		else if(str[i]=='L')
			value-=50;
		else if(str[i]=='C')
			value-=100;
		else if(str[i]=='D')
			value-=500;
		else if(str[i]=='M')
			value-=1000;

		}
		else{
		if(str[i]=='I')
			value+=1;
		else if(str[i]=='V')
			value+=5;
		else if(str[i]=='X')
			value+=10;
		else if(str[i]=='L')
			value+=50;
		else if(str[i]=='C')
			value+=100;
		else if(str[i]=='D')
			value+=500;
		else if(str[i]=='M')
			value+=1000;
		}
	}
	cout<<value<<endl;
}
	
	return 0;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
简洁许多啊
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
	string s;
	int deci;
	while(cin>>s){
	int result = 0;
	int deci_pre = 4000;//max
	for( int i = 0; i < s.size(); ++i ){
		switch(s[i]){
			case 'I': deci = 1;
			break; 
			case 'V': deci = 5;
			break;
			case 'X': deci = 10;
			break;
			case 'L': deci = 50;
			break;
			case 'C': deci = 100;
			break;
			case 'D': deci = 500;
			break;
			case 'M': deci = 1000;
		}
		if( deci > deci_pre )	result -= deci_pre;
		else	result += deci;	
		//result += deci;
		//if( deci > deci_pre )\
			result -= deci_pre*2;
		deci_pre = deci;
	}
	cout<<result<<endl;
	}
}


