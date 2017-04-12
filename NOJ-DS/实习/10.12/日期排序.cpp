Description
有一些日期，日期格式为“MM/DD/YYYY”。编程将其按日期大小排列。

Input
Output
Sample Input
15/12/1999
10/21/2003
10/22/2003
02/12/2004
11/30/2005
12/31/2005
Sample Output
15/12/1999
10/21/2003
10/22/2003
02/12/2004
11/30/2005
12/31/2005
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
#include <cmath>
using namespace std;
struct Node{
	int m;
	int d;
	int y;
	Node *next;
};
void sort(Node *h)
{
    for (Node *p1 = h; p1->next != NULL; p1 = p1->next)
    {
        Node *p_max = p1;
        for (Node *p2 = p1->next; p2 != NULL; p2 = p2->next){
            if (p2->y<p_max->y)
                {p_max = p2;}
        }

        if (p_max != p1)
        {
            int temp = p1->y;
            p1->y = p_max->y;
            p_max->y = temp;
			int tempp = p1->m;
			p1->m = p_max->m;
			p_max->m = tempp;
			int temppp = p1->d;
			p1->d = p_max->d;
			p_max->d = temppp;
        }
    }
    //上面按年排好，下面针对相邻的翻转||!!!!!!这样不行，比如321你只能变成213，一次for只能改变一层所以要两层for啊
	Node *p1=NULL;
	Node *p2=NULL;
    for (p1 = h,p2=h->next; p1->next->next != NULL; p1 = p1->next,p2=p2->next)
    {
        	if (p1->y==p2->y)
        	{
        		if (p1->m>p2->m)
        		{
        	            int temp1 = p1->m;
        	            p1->m=p2->m;
        	            p2->m=temp1;
        	            int temp2 = p1->d;
        	            p1->d=p2->d;
        	            p2->d=temp2;

        		}
        	}
    }
    for (p1 = h, p2=h->next; p1->next->next != NULL; p1 = p1->next,p2=p2->next)
    {
        	if (p1->y==p2->y&&p1->m==p2->m)
        	{
        		if (p1->d>p2->d)
        		{
        	            int temp3 = p1->d;
        	            p1->d=p2->d;
        	            p2->d=temp3;
        		}
        	}
    }
}
/*
void BubbleSort(Node *h)  
{  
	int temp;  
	for (Node *p1 = h; p1->next != NULL; p1 = p1->next)
	{  
		for (int j = count - 1; j >= i; j--)  
		{  
			if (pData[j] < pData[j - 1])  
			{  
				temp = pData[j - 1];  
				pData[j - 1] = pData[j];  
				pData[j] = temp;  
			}  
		}  
	}  
}  */
void p(Node *h){
	for (Node *p = h; p != NULL; p = p->next)
		printf("%02d/%02d/%04d\n",p->m,p->d,p->y);
//printf("a=%06d\n", a);//输出6位十进制整数 左边补0，显示 a=001234
}

int main(int argc, char const *argv[])
{
	Node *h=NULL;
	int mm,dd,yyyy;
	char x;
	//for(int i=0;i<6;i++)
	//{cin>>mm>>x>>dd>>x>>yyyy;
	while(cin>>mm>>x>>dd>>x>>yyyy){
	/*cout<<"\nx="<<x;
		cout<<"\nmm="<<mm;
			cout<<"\ndd="<<dd;
				cout<<"\nyyyy="<<yyyy;}*/
	//while(cin>>mm<<x<<dd<<x<<yyyy){
		Node *p=new Node;
		p->m=mm;
		p->d=dd;
		p->y=yyyy;
		p->next=h;
		h=p;
	}
	sort(h);
	p(h);
	return 0;
}