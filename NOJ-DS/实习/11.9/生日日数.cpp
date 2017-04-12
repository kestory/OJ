Description
CCC老师的生日是YY年MM月DD日，他想知道自己出生后第一万天纪念日的日期（出生日算第0天）。

Input
输入有多行，格式为YY MM DD 其中1949<=YY<=2006，日期绝对合法。

Output
输出有多行。即CCC老师生日第一万天以后的日期，格式为 “Y-M-D”。

Sample Input
1979 4 16
Sample Output
2006-9-1
HINT
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
20分钟AC～
看清题目要输入多行啊
总体逻辑就是程序设计的哲学，把所有情况列出，遇到问题当时解决就行了
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#define dprint(expr) printf(#expr "= %d\n",expr)
using namespace std;
int main(int argc, char *argv[]) {
	int y,m,d;
	while(cin>>y>>m>>d){
	//int y,m,d;
	for (int i = 1; i <= 10000; ++i)
	{
		//d++;
		if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
			d=d%31+1;
		else if(m==2){
			if ((y%4==0&&y%100!=0)||(y%400==0))
			{
				d=d%29+1;
			}
			else
				d=d%28+1;
		}
		else
			d=d%30+1;
			
			//dprint(d);
		if(d==1)
		{
			m=m%12+1;
		}
		//dprint(m);
		if(m==1&&d==1)
			y++;

	}
	cout<<y<<"-"<<m<<"-"<<d<<endl;}
	//dprint(y);dprint(m);dprint(d);
	return 0;
}

