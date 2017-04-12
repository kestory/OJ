~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Description
        设有N堆沙子排成一排，其编号为 1，2，3，…，N（N< =300）。
        每堆沙子有一定的数量，可以用一个整数来描述，现在要将这N堆沙子合并成为一堆，
        每次只能合并相邻的两堆，合并的代价为这两堆沙子的数量之和，
        合并后与这两堆沙子相邻的沙子将和新堆相邻，合并时由于选择的顺序不同，合并的总代价也不相同，
        如有4堆沙子分别为  1    3    5    2  我们可以先合并 1、2 堆，代价为 4，得到 4  5  2  又合并  1，2 堆，代价为 9，得到 9  2 
        再合并得到 11，总代价为4+9+11=24，
        如果第二步是先合并 2，3 堆，则代价为 7，得到 4  7，
        最后一次合并代价为 11，总代价为 4+7+11=22；
        问题是：找出一种合理的方法，使总的代价最小。输出最小代价。
Input
第一行一个数N表示沙子的堆数N。 第二行N个数，表示每堆沙子的质量。  < =1000
Output
合并的最小代价
Sample Input
4
1 3 5 2
Sample Output
22
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
想到链表比较符合“两堆并成一堆”，又想到每次找最小两个，像Huffman树那样就行
然而先是发现不能申明长度不定的数组，然后我用的是一个链表一个数组，两个要对应就要用尾指针建立
但链表果真问题多，还有我想的算法不完善，比如 3 4 6 5 4 2 变 7 6 5 6 这时应选后面的 5 6 合并结果会小
所以要把所有结果找出来然后选最小的，要用到动归
把我链表实现的起码两个和最小的这种算法bug找出来吧
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#define dprint(expr) printf(#expr "= %d\n",expr)
using namespace std;

struct Node{
    int value;
    int num;
    Node *next;
};
int main(int argc, char *argv[]) {
	int N;
	int cost[100];
	Node *h=NULL;
	Node *tail=NULL;
	cin>>N;
	for (int i = 0; i < N; ++i){
		Node *p=new Node;
		cin>>p->value;
		p->num=i;
		if(h==NULL)
			h=p;
		else
			tail->next=p;
		tail=p;
		
	}
	while(h->next!=NULL){//stop while there is only one number
	
	int n=0;//build cost[n-1]
	for(Node *p1=h;p1->next!=NULL;p1=p1->next){
		cost[n]=p1->
		value+p1->next->value;
		n++;
	}

	for (int i = n; i <= N-1; ++i)
		cost[i]=10000;	

	int min=10000;//find the min_i
	int the_i=0;
	for (int i = 0; i < n; ++i)
		if(cost[i]<min){
			min=cost[i];
			the_i=i;
		}

	Node *p2=h;//get the to_be_changed_sand	
	while(p2->value!=the_i)
		p2=p2->next;

	if (p2->next != NULL)
		p2->value=p2->value+p2->next->value;
		
	Node *p3=p2->next;//merger the two sands
	p2->next=p3->next;
	delete p3;

	for(p2=p2->next;p2->next!=NULL;p2=p2->next)
		p2->value--;

	}
	cout<<h->value;
	return 0;
}

~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#define dprint(expr) printf(#expr "= %d\n",expr)
using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin>>n;
	int sand[305];
	for (int i = 0; i < n; ++i)
	{
		cin>>sand[i];
	}
	return 0;
}



http://blog.csdn.net/wxf1995/article/details/5920019
http://wenku.baidu.com/link?url=z7wCmLcZVqFa0FTxCcqboR0VSiQJSe0TNa5m7YmMOI0PShFQMty37515-i9tXYPSj8Inug1pylyJ_R00_PJfPlCDNwCalFy24L834GpmpK7
http://hzwer.com/575.html
http://blog.csdn.net/asdfghjkl1993/article/details/19010369
http://blog.csdn.net/Asmodians_ll/article/details/52033305






