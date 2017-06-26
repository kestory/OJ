Description

在一个夜黑风高,下着暴风雨的夜晚,Farmer John的牛棚的屋顶、门被吹飞了。 好在许多牛正在度假，所以牛棚没有住满。
牛棚一个紧挨着另一个被排成一行，牛就住在里面过夜。 有些牛棚里有牛，有些没有。
所有的牛棚有相同的宽度。 自门遗失以后,farmer John必须尽快在牛棚之前竖立起新的木板。
他的新木材供应商将会供应他任何他想要的长度,但是吝啬的供应商只能提供有限数目的木板。
Farmer John想将他购买的木板总长度减到最少。

Input

给出:可能买到的木板最大的数目M(1<= M<=50);牛棚的总数S(1<= S<=200); 牛棚里牛的总数C(1 <= C <=S);
和牛所在的牛棚的编号stall_number(1 <= stall_number <= S)（共C行）

Output

计算拦住所有有牛的牛棚所需木板的最小总长度 输出所需木板的最小总长度作为答案

Sample Input
1 200 2
1
200
Sample Output
200
-----------------
SAMPLE INPUT
4 50 18 3 4 6 8 14 15 16 17 21 25 26 27 30 31 40 41 42 43
SAMPLE OUTPUT
25
[ 一种最优的安排是用板拦牛棚 3-8,14-21,25-31,40-43.]
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
可以贪心，如下
	->N=1  从第一个牛棚到最后一个牛棚打上一条木板
	->N=2  在这个木板上找一个最长空缺 去掉木板
	->N=3  找前二长的空缺去掉
OJ和coderunner不支持匿名函数，Clion可以
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <algorithm>//sort
#define D(x) cout<<#x<<"="<<x<<endl;
using namespace std;
int cmp1(const int & a, const int &b)
{
	return a < b;
}
int cmp2(const int  & a, const int  &b)
{
	return a > b;
}
int main()
{
	ios::sync_with_stdio(false);
	int m, s, c, a[128], len[300], ans;
	cin >> m >> s >> c;
	for (int i = 0; i < c; ++i)
		cin >> a[i];
	sort(a, a + c, cmp1); //升序
	//sort(a, a + c, [&](int a, int b) {return a < b;});//sort可以对数组操作

	for (int i = 0; i < c - 1; i++)
		len[i] = a[i + 1] - a[i] - 1;//减一是因为比如34567中34&67有牛，拿走5这个空位只有6-4-1=1个长度
	//for (int i = 0; i < c - 1; i++) cout<<len[i]<<'\t';
	sort(len, len + c - 1, cmp2);
	//sort(len, len + c - 1, [&](int a, int b) {return a > b;});

	ans = a[c - 1] - a[0] + 1;//已然一块木板
	for (int i = 0; i < m - 1; i++)//这个循环会进行 m-1 次
		ans -= len[i];
	cout << ans;
	return 0;
}
