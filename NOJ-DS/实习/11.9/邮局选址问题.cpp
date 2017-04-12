Description
问题描述： 
在一个按照东西和南北方向划分成规整街区的城市里，n个居民点散乱地分布在不同的街区中。用x 坐标表示东西向，用y坐标表示南北向。各居民点的位置可以由坐标(x,y)表示。街区中任意2 点(x1,y1)和(x2,y2)之间的距离可以用数值|x1-x2|+|y1-y2|度量。 
居民们希望在城市中选择建立邮局的最佳位置，使n个居民点到邮局的距离总和最小。 
编程任务： 
给定n 个居民点的位置,编程计算n 个居民点到邮局的距离总和的最小值。

Input
第1 行是居民点数n，1<10000。< 个整数x 行是居民点的位置，每行2>

Output
n个居民点到邮局的距离总和的最小值。

Sample Input
5
1 2
2 2
1 3
3 -2
3 3
Sample Output
10
HINT
~~~~~~~~~~~~~~~~~~~~~~~~~~
保持清醒，但总是有蠢错误，两个for循环的初始化写在外面当然循环不了n*n次了
sum要赋值为0，也要加前面的值，什么时候，就要思考了。
35分钟AC
~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <stdlib.h>
#define dprint(expr) printf(#expr "= %d\n",expr)
using namespace std;
int main(int argc, char *argv[]) {
	int n;
	cin>>n;
	int x[20];
	int y[20];
	for (int i = 0; i < n; ++i)
	{
		cin>>x[i]>>y[i];
	}
	int i;
	int j;
	//int i_min,j_min;//只要最后总和最小值，不过有助于查找错误
	int sum = 10000;
	int sum_min = 10000;
	for (i=-100; i < 100; ++i){
		for (j=-100; j < 100; ++j){
			sum=0;
			for (int k = 0; k < n; ++k)
				sum=sum+abs(x[k]-i)+abs(y[k]-j);
			
			if(sum_min>sum)
				sum_min=sum;//{sum_min=sum;dprint(sum_min);	i_min=i;		j_min=j;}
		}
	}
	//dprint(i_min);
	//dprint(j_min);
	cout<<sum_min<<endl;
	return 0;
}

