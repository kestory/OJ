Description
棋盘上A点有一个过河卒，需要走到目标B点。卒行走的规则：可以向下、或者向右。同时在棋盘上C点有一个对方的马，该马所在的点和所有跳跃一步可达的点称为对方马的控制点。因此称之为“马拦过河卒”。 
棋盘用坐标表示，A点(0, 0)、B点(n, m)(n, m为不超过15的整数)，同样马的位置坐标是需要给出的。现在要求你计算出卒从A点能够到达B点的路径的条数，假设马的位置是固定不动的，并不是卒走一步马走一步。

Input
一行四个数据，分别表示B点坐标和马的坐标。（保证所有的数据有解）

Output
一个数据，表示所有的路径条数。

Sample Input
6 6 3 3
Sample Output
6
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#define dprint(expr) printf(#expr "= %d\n",expr)
using namespace std;
int a[15][15];
int dfs(int x,int y){
	/*if(x-1==0&&y-1==0)
		return 2;
	else if(x-1==0||y-1==0)
		return 1;
	
	else if (a[x-1][y]==-1&&a[x][y-1]==0)
		return dfs(x,y-1);
	else if(a[x-1][y]==0&&a[x][y-1]==-1)
		return dfs(x-1,y);	
	else if(a[x-1][y]==-1&&a[x][y-1]==-1)
		return 0;
	else// if (a[x-1][y]==0&&a[x][y-1]==0)
		return dfs(x-1,y)+dfs(x,y-1);*/
	if(x==0&&y==0)
		return 1;
	else if(x<0||y<0)
		return 0;
	else if(a[x][y]==-1)
		return 0;
	else
		return dfs(x-1,y)+dfs(x,y-1);
		
}//对递归的使用实现比较缺少经验，这本是个简单明了的事啊。看上面就知道只要考虑x,y就行，考虑到x-1,y-1就又复杂又错误了
int main(int argc, char const *argv[])
{
	int bx,by,cx,cy;
	cin>>bx>>by>>cx>>cy;
	
	a[cx][cy]=-1;
	for (int x = 0; x < 15; ++x)
	{
		for (int y = 0; y < 15; ++y)//对棋盘元素逐个判断，没有不在棋盘上的风险
			if ((abs(x-cx)==1&&abs(y-cy)==2)||(abs(x-cx)==2&&abs(y-cy)==1))
				a[x][y]=-1;//{a[x][y]=0;dprint(x);dprint(y);}
	}
	cout<<dfs(bx,by);

	return 0;
}