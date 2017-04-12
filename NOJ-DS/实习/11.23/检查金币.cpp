Description
ACM公司生产金币的设备出了问题，使得最近生产的10批金币的重量出现了波动：本来金币的标准重量是10克，但现在有的可能是11克，有的可能9克，也有可能是10克。
现在只知道同一批金币的重量是相同的，你的任务是要把每批的单枚金币的重量找出来。
你的设备有一个电子秤，但只允许称量一次！
你从第1批中取1枚金币，第2批取3枚，...第i批取3^(i−1)枚...，第10批取3^9枚，总共29524枚。将这29524枚金币放在电子秤上，得到了总重量，就交给你的程序去！

Input
有多个测试序列，每个测试序列一行，包含一个6位的正整数W(265716≤W≤324764)，表示29524枚金币的总重量

Output
每个测试序列输出一行，包含10个用空格分开的正整数，分别表示10批金币的单枚重量，注意行尾没有空格。

Sample Input
265716
324764
295240
Sample Output
9 9 9 9 9 9 9 9 9 9
11 11 11 11 11 11 11 11 11 11
10 10 10 10 10 10 10 10 10 10
HINT
～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～
十分钟就结束了，居然没超时
～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～
#include <iostream>
#define dprint(expr) printf(#expr "= %d\n",expr)
#define D(x) cout<<#x<<"="<<x<<endl;
#define DS(x) cout<<#x<<" = "<<x<<"	";
using namespace std;
int main(int argc, char *argv[]) {
	int num[10];
	num[0]=1;
	for (int i = 1; i < 10; ++i)
		num[i]=num[i-1]*3;
	//for (int i = 0; i < 10; ++i)\
		D(a[i]);
	int sum=0;
	while(cin>>sum){
	for(int a=9;a<=11;a++)
		for(int b=9;b<=11;b++)
			for(int c=9;c<=11;c++)
				for(int d=9;d<=11;d++)
					for(int e=9;e<=11;e++)
						for(int f=9;f<=11;f++)
							for(int g=9;g<=11;g++)
								for(int h=9;h<=11;h++)
									for(int i=9;i<=11;i++)
										for(int j=9;j<=11;j++){
											int x=a+3*b+9*c+27*d+81*e+243*f+729*g+2187*h+6561*i+19683*j;
											if(x==sum)
												cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g<<" "<<h<<" "<<i<<" "<<j<<endl;
										}

	}
	return 0;
}
～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～
然后问许卓尔怎么写的，原来txp讲过，我记不得了，但一提醒，记得在离散有讲
时间复杂度从O(n^10)到O(n)
～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	int x=0;
	int n[10];
	while(cin>>x){
		x-=265716;
		for (int i = 0; i < 10; ++i)
		{
			n[i]=x%3;
			x=x/3;
		}
		for (int i = 0; i < 9; ++i)
			cout<<n[i]+9<<" ";

		cout<<n[9]+9<<endl;
	}
	return 0;
}
～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～
你写的似乎没毛病，但还要学学网上的简洁
～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～
#include <stdio.h>

void main()
{
    int k, i;
    while(scanf("%d",&k)!=EOF)
    {
        k-=265716;//此数值为每批金币重量均为9时所取得和
        for(i=0;i<10;i++)
        {
            if(i<9)
		printf("%d ",9+k%3);
            else
             	printf("%d\n",9+k%3); //just 4 \n
            k/=3;
        }
    }
}
