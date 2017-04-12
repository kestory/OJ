Input

The input will contain a list of numbers no longer than 50.

Output

Your program should first output "N    Count". Then in each line, you should output the number and its count, seperated by 4 spaces('    ').
The numbers are sorted from largest to smallest.

Sample Input

-12 3 -12 4 1 1 -12 1 -1 1 2 3 4 2 3 -12
Sample Output

N    Count
4    2
3    3
2    2
1    4
-1    1
-12    4
HINT
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
几乎没有bug，OJ一次成功
想切换为C语言，毕竟输入输出都是C mode
发现C结构体和C++有区别
struct Node{
	int n;
	int count;
	struct Node *next;
};
typedef struct Node Node;

Node *p=(struct Node*)malloc(sizeof(struct Node));
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <stdio.h>
#include <stdlib.h>
struct Node{
	int n;
	int count;
	struct Node *next;
};
typedef struct Node Node;
void sort(Node *h){
    for (Node *p1 = h; p1->next != NULL; p1 = p1->next)
    {
        Node *p_max = p1;
        for (Node *p2 = p1->next; p2 != NULL; p2 = p2->next)
            if (p2->n>p_max->n)
                p_max = p2;

        if (p_max != p1)
        {
            int temp1 = p1->n;
            p1->n = p_max->n;
            p_max->n = temp1;
            int temp2 = p1->count;
            p1->count = p_max->count;
            p_max->count = temp2;
        }
    }
}
void pp(Node *h){
	for (Node *p = h; p != NULL; p = p->next)
		printf("%d    %d\n", p->n,p->count);
}
int main(int argc, char *argv[]) {
	int a[64];
	int num=0;
	while(~scanf("%d",&a[num]))
		num++;
	//int a[64]={-12,3,-12,4,1,1,-12,1,-1,1,2,3,4,2,3,-12};
	//num=16;
	printf("N    Count\n");
	Node *hh=NULL;
	Node *h=NULL;
	for (int i = 0; i < num; ++i){
		h=hh;
		while(h!=NULL){
			if(a[i]==h->n){
				h->count++;
				break;
			}
			h=h->next;
		}
		if (h==NULL){
			//Node *p=new Node;
			Node *p=(struct Node*)malloc(sizeof(struct Node));
			p->n=a[i];
			p->count=1;
			p->next=hh;
			hh=p;
		}
	}
	sort(hh);
	pp(hh);
	return 0;
}
