Description
对一个整数来说，它的余数有一些有趣的求解方法，例如：

（1） 正整数n除3的余数，等价于，正整数n的各位数字之和除3的余数；

（2） 正整数n除9的余数，可以通过这样的方法来计算：计算n 的各位数之和，设为m，如果m已经是一位数，那么余数就是m；否则设n=m，重新进行计算n的各位数之和m，直到m是一个一位数。但是，正整数除1，2，4，5，6，7，8，也存在类似的性质吗？

现在请你计算一下正整数n除一位数m的余数。文件中有一些数对，第一个为大整数n（可能大到100位），另一个为一位数m（0<m<=9）。求其n除以m的余数。

Input
Output
Sample Input
23 7
123 9
Sample Output
2
6
HINT
测试样例中会有一些非常大的整数，（可能会超出Integer的表示范围）。


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
算法
123 % 9 = 6
1 % 9 =1 
(1*10 + 2) % 9 = 3
(3*10 + 3) % 9 = 6
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
	char num[200];
	int d;
	while(cin>>num>>d){
		int len=strlen(num);
		//int t;
		int y;
		int x=num[0]-'0';
		for (int i = 0; i < len; ++i)
		{
			//cout<<"i="<<i<<endl;
			y=x%d;
			x=y*10+num[i+1]-'0';/这里运气好，只是num[i+1]在最后变成0了

		}
		cout<<y<<endl;

	}
	return 0;
}
可喜可贺，前几个提交，但感觉题目是废话多了吗，我只是用手算除法 多知识啊。
而且上网搜的算法，看有人10行出来就超自信的写了
其实思路还不是很清晰
～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～
#include<string>
#include<strstream>
using namespace std;
int main(){
   string n;
   int m;
   while(cin>>n>>m)
    {
        int pre=0;
        for(int i=0;i<n.length();i++)
        {
            int t=(int)(n[i]-'0');
            if(i==0) pre=t%m;
            else
                pre=(pre*10+t)%m;    
        }
        cout<<pre<<endl;
    }
    return 0;
}
～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～
http://bbs.csdn.net/wap/topics/190063564
又查了下发现，想利用题中结论，就要对123456789分情况讨论
125简单39题有
4看后两位，8看后3位

对6，找规律是这样（先％3=0的3 6 9 12看对％2，再4 7 10 31 16 看对％2，再5 8 11 14 17）
但高级点应该是中国剩余定理
分别计算该数对2和对3的余数，记为r2、r3，则 r6 = ( 3*r2 + 4*r3 ) % 6
或直接查下表：
 r2 \ r3 |    0    1    2
---------+------------------
    0    |    0    4    2
    1    |    3    1    5

对7
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#define dprint(expr) printf(#expr "= %d\n",expr)
#define sprint(expr) printf(#expr "= %s\n",expr)
using namespace std;
int for_9 (string num,int len){
	int sum=0;
	for (int i = 0; i < len; ++i)
	{
		sum+=num[i]-'0';
	}
	if(sum<10)
		return sum;
	else{
		char str[30];
		sprintf(str,"%d",sum);
		string str1=str;
		int len2=str1.size();
		return for_9(str1,len2);
	}
}
int for_7(string num,int len){
	/*if(len<7)
		return atoi(num)%7;
	else{
		//sprint(num);
		char num2[len];
		strncpy(num2,num,len-6);
		//sprint(num2);
		return for_7(num2,len-6);
	}*/
	if(len<7)
		return atoi(num.c_str())%7;
	else{
		int sum=0;
		string str1;
		string str2;
		while(len>7){
		str1=num.substr(len-6);
		//cout<<"str1="<<str1<<endl;
		str2=num.substr(0,len-6);
		//cout<<"str2="<<str2<<endl;
		sum+=atoi(str1.c_str());
		//cout<<"sum="<<sum<<endl;
		num=str2;
		len-=6;
	      }
		sum+=atoi(str2.c_str());
	return sum;
	}
}

int main(int argc, char const *argv[])
{
	string num;
	int d;
	int y;

	while(cin>>num>>d){
	int len=num.size();
		if(len==1&&num[0]=='0')
		{	cout<<"0"<<endl;
			continue;
		}

		switch (d)
		{case 1:{
			cout<<"0"<<endl;
			//cout<<0<<endl also right!
			//OIC,cout<<1231312311231313121212<<endl; will be wrong,thought as number 
			break;
		}
		case 2:{
			cout<<(num[len-1]%2==1)<<endl;
			break;
		}
		case 3:{
			int sum=0;
			for (int i = 0; i < len; ++i)
			{
				sum+=num[i]-'0';
			}
			cout<<sum%3<<endl;
			break;
		}
		case 4:{
			if (len<=2)
				cout<<atoi(num.c_str())%4;
			else{
				int b=(num[len-2]-'0')*10+num[len-1]-'0';
				cout<<b%4<<endl;
			}
			break;
		}
		case 5:{
			cout<<(num[len-1]-'0')%5<<endl;
			break;
		}
		case 6:{//孙子定理Orsay中国剩余定理
			int sum=0;
			for (int i = 0; i < len; ++i)
			{
				sum+=num[i]-'0';
			}
			int r1=sum%3;
			int r2=num[len-1]%2;
			int r6=( 3*r2 + 4*r1 ) % 6;
			cout<<r6<<endl;

			break;
		}
		case 7:{
			//cout<<num<<endl;
			//cout<<len<<endl;
			int b=for_7(num,len);
			cout<<b%7<<endl;
			break;
		}
		case 8:{
			if (len<=3)
				cout<<atoi(num.c_str())%8<<endl;
			else{
				int b=(num[len-3]-'0')*100+(num[len-2]-'0')*10+num[len-1]-'0';
				cout<<b%8<<endl;
			}
			break;
		}
		case 9:{
			int b=for_9(num,len);
			cout<<b%9<<endl;
			break;
		}

		}

	}
	return 0;

}

hahaha，成功用string做出来～
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~