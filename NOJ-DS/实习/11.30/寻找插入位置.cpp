Description

给定一个排好序的数组S和一个数字a，如果这个数字a在S中，则返回它的数组索引；如果不在数组中，则返回它应该插入的位置。

数组S保证无重复。



Input
输入为两行：第一行为数组，第二行为一个数字。
Output
输出为一行，为一个数字。
Sample Input
1,3,5,6
5
1,3,5,6
2
1,3,5,6
7
1,3,5,6
0
Sample Output
2
1
4
0
HINT
~~~~~~~~~~~~~~~~~~~~~~~~
一条大部分人20分钟的题，我 1.5 小时加很多WA，可能是学习收获最多的了。。
自己和很多人不知怎么的就默认输入 0～9 了
还是应该把字符串切割好在一起处理，就很明了了
恢复了很多知识点，顺便学到了一些
~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <string>
#define dprint(expr) printf(#expr "= %d\n",expr)
#define D(x) cout<<#x<<"="<<x<<endl;
#define DS(x) cout<<#x<<" = "<<x<<"	";
using namespace std;
int main(int argc, char *argv[]) {
	string a;
	int num;
	while(cin>>a){
		cin>>num;
		//cout<<"123";
		int i;
		for(i=0;i<a.size();i++){
			int c=a[i]-'0';
			if(a[i]==',')
				continue;
			else if(c>=num){
				cout<<i/2<<endl;
				break;
			}
			else
				continue;
		}
		if(i==a.size())
			cout<<(i+1)/2<<endl;
	}
	return 0;
}
~~~~~~~~~~~~~~~~~~~~~~~~
想回车控制输入int数组
只能0～9连续的
>12345
>1 2 3 4 5
~~~~~~~~~~~~~~~~~~~~~~~~
#include <stdio.h>  
int main()  
{  
	int arr[100] = {0};  
	int i = 0;  
	char ch = '0';  
  
	ch = getchar();  
  
	while('\n' != ch)//回车结束  
	{  
		arr[i] = ch - '0';//char型转化为int型  
		ch = getchar();  
		++i;  
	}  
	arr[i] = '\0';//数组尾部  
	for (i = 0; arr[i] != '\0'; ++i)  
	{  
		printf("%d ",arr[i]);  
	}  
	return 0;  
} 

~~~~~~~~~~~~~~~~~~~~~~~~
有点牵强，但还是一种新思路
~~~~~~~~~~~~~~~~~~~~~~~~
一道看上去很吓人的算法面试题：如何对n个数进行排序，要求时间复杂度O(n)，空间复杂度O(1)

看上去似乎任何已知的算法都无法做到，如果谁做到了，那么所有的排序方 法：QuickSort，ShellSort，HeapSort，BubbleSort等等等等，都可以扔掉了，还要这些算法干吗阿，呵呵。不过实际上， 在数字范围有限制的情况下，是有一个这样的算法的，只需要用一个数组记录每个数字出现次数就可以了。

假定你的数字范围在0到65535范围之内，定义一个数组count[65536]（这个空间是常量，和n无关，所以是O(1) )，初值全部为0。

那么假设有下面这些数字：

100

200

300

119

0

6

...

那么对于每个这个数字，都做在count中记录一下：

100 => count[100]++

200 => count[200]++

300 => count[300]++

119 => count[119]++

0 => count[0]++

6 => count[6]++

...

最后，遍历一边所有这些数字就可得到0~65535每个数字的个数（在count数组中），然后再顺序遍历count数组，count[n] = m，则输出m个n，（比如说有count[3] = 2, 那么说明有2个数字3），依次输出，最后可得结果。第一次遍历是O(n)，第二次遍历是O(1)，为常量，所以最后的时间复杂度为O(n)，而空间复杂度 为O(1)

这个算法很简单，相信大家都会，只是这个题太过于变态了，一般会把面试者吓住（我原来面试也出过这个题，只不过题目的表述形式要“友善”的多，呵呵）

~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <cstring>
#define dprint(expr) printf(#expr "= %d\n",expr)
#define D(x) cout<<#x<<"="<<x<<endl;
#define DS(x) cout<<#x<<" = "<<x<<"	";
using namespace std;
int main(int argc, char *argv[]) {
	char a[1024];
	int n[16];
	int num;
	while(cin>>a){
		cin>>num;
		char *ptr;		
		ptr=strtok(a,",");
		//D(ptr);
		int j=0;
		while(ptr!=NULL){
			n[j]=atoi(ptr);
			ptr=strtok(NULL,",");
			j++;
		}
		/*while(j>=0){
			D(n[j]);
			D(j);
			j--;
		}*/
		//D(j);
		int i;
		for (i = 0; i < j; ++i)
		{
			if(num<=n[i]){
				cout<<i<<endl;
				break;
			}
		}
		if(i==j)
			cout<<j<<endl;
	}
	return 0;
}