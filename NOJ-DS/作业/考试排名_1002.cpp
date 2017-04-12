Description
C++编程考试使用的实时提交系统，具有即时获得成绩排名的特点。它的功能是怎么实现的呢？ 
我们做好了题目的解答，提交之后，要么“AC”，要么错误，不管怎样错法，总是给你记上一笔，表明你曾经有过一次错误提交，因而当你一旦提交该题 “AC”后，就要与你算一算帐了，总共该题错误提交了几回。虽然你在题数上，大步地跃上了一个台阶，但是在耗时上要摊上你共花去的时间。特别是，曾经有过 的错误提交，每次都要摊上一定的单位时间分。这样一来，你在做出的题数上，可能领先别人很多，但是，在做出同样题数的人群中，你可能会在耗时上处于排名的 劣势。 
例如：某次考试一共8题（A，B，C，D，E，F，G，H），每个人做的题都在对应的题号下有个数量标记，负数表示该学生在该题上有过的错误提交 次数，但到现在还没有AC，正数表示AC所耗的时间，如果正数a跟上一对括号，里面有个整数b，那就表示该学生提交该题AC了，耗去了时间a，同时，曾经 错误提交了b次，因此对于下述输入数据： 
name A B C D E F G H 
Smith -1 -16 8 0 0 120 39 0 
John 116 -2 11 0 0 82 55(1) 0 
Jose 72(3) 126 10 -3 0 47 21(2) -2 
Bush 0 -1 -8 0 0 0 0 0 
Alice -2 67(2) 13 -1 0 133 79(1) -1 
Bob 0 0 57(5) 0 0 168 -7 0 
若每次错误提交的罚分为20分，则其排名从高到低应该是这样的： 
Jose 5 376 
John 4 284 
Alice 4 352 
Smith 3 167 
Bob 2 325 
Bush 0 0

Input
输入数据的第一行是考试题数n（1≤n≤12）以及单位罚分数 m（10≤m≤20），每行数据描述一个学生的用户名（不多于10个字符的字串）以及对所有n道题的答题现状，其描述采用问题描述中的数量标记的格式，见 上面的表格，提交次数总是小于100，AC所耗时间总是小于1000。

Output
将这些学生的考试现状，输出一个实时排名。实时排名显然先按AC题数的多 少排，多的在前，再按时间分的多少排，少的在前，如果凑巧前两者都相等，则按名字的字典序排，小的在前。每个学生占一行，输出名字（10个字符宽），做出 的题数（2个字符宽，右对齐）和时间分（4个字符宽，右对齐）。名字、题数和时间分相互之间有一个空格。

Sample Input
8 20
Smith     -1      -16     8       0      0      120     39      0
John      116     -2      11      0      0      82      55(1)   0
Josephus  72(3)   126     10      -3     0      47      21(2)   -2
Bush      0       -1      -8      0      0      0       0       0
Alice     -2      67(2)   13      -1     0      133     79(1)   -1
Bob       0       0       57(5)   0      0      168     -7      0
Sample Output
Josephus    5  376
John        4  284
Alice       4  352
Smith       3  167
Bob         2  325
Bush        0    0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
#include <cstring>
#include <iomanip>
//#define dprint(expr) printf(#expr "= %d\n",expr)
using namespace std;
struct Node{
	char name[15];
	int num;
	int ti;
	Node *next;
};
bool bijiao(Node *a,Node *b){
	if(a->num>b->num)
		return true;
	else if (a->num==b->num)
	{
		if (a->ti<b->ti)
			return true;
		else if (a->ti==b->ti)
		{
			if (strcmp(a->name,b->name)<0)
				return true;
			else
				return false;
		}
		else
			return false;

	}
	else
		return false;
}

void sort(Node *h)
{	char t_name[15];
	int t_num;
	int t_ti;
	for (Node *p1 = h; p1->next != NULL; p1 = p1->next)
	{
		Node *p_max = p1;
		for (Node *p2 = p1->next; p2 != NULL; p2 = p2->next)
			if(bijiao(p2,p_max)==true)//if (p2->b>p_max->b)
				p_max = p2;

		if (p_max != p1){
		strcpy(t_name,p_max->name);
		strcpy(p_max->name,p1->name);
		strcpy(p1->name,t_name);

		t_num=p_max->num;
		p_max->num=p1->num;
		p1->num=t_num;
		
		t_ti=p_max->ti;
		p_max->ti=p1->ti;
		p1->ti=t_ti;
		}
	}
}
void ppp(Node *h){
	for (Node *p = h; p != NULL; p = p->next){
		cout<<std::left<<setw(10)<<p->name<<" "<<std::right<<setw(2)<<p->num<<" "<<setw(4)<<p->ti<<endl;
		// printf("%-10s%3d%5d\n",s[i].name,s[i].cnt,s[i].sum);  
	}
//cout<<'s'<<setw(8)<<'a'<<endl;
}

int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	Node *h=NULL;

	char names[15];

	char ac[10];
/*	for(int x=0;x<6;x++) */
while(~scanf("%s",names)){
		Node *p=new Node;
		p->num=0;
		p->ti=0;
		//cin>>names;
		strcpy(p->name,names);

		for (int i = 0; i < n; ++i)
		{
			cin>>ac;
			bool ac_n=false;
			char *str=ac;
			char *ptr;
			//int first_place;
			for (int j = 0; j < strlen(ac); ++j)
			{
				if(ac[j]=='(')
				ac_n=true;
				//first_place=j;
			}
			if (ac_n==true)
			{
				 ptr = strtok(str, "(");
				 ptr = strtok(NULL, ")");
				 p->ti=p->ti+m*atoi(ptr)+atoi(str);
				 p->num++;
			}
			else{
				int nn=atoi(str);
				if (nn>0)
				{
					p->num++;
					p->ti+=nn;
				}
				//else
			}
		}
		p->next=h;
		h=p;
		//BubbleSort(h);
			//ppp(h);
	}
	//BubbleSort(h);
	sort(h);
	ppp(h);

	return 0;
}
/写了一晚上，4个小时可能，主要就是识别和排序，我总是懒得写排序直接复制所以老出错，还有最大最小要分清
～～～～～～～～～～～～～～～值得学习的～～～～～～～～～～～～～～～～～～～～～～～～～～～
/用了#include <algorithm>  的sort，strstr，原来搞acm写oj就是要善于用现成的东西而非造轮子啊，STL大法好
#include <stdio.h>  
#include <algorithm>  
#include <string.h>  
using namespace std;  
  
struct STU  
{  
    char name[20];  
    int sum;  
    int cnt;  
} s[1000];  
  
int cmp(STU x,STU y)//先按题数排，再按总时间小的在头排序  
{  
    if(x.cnt!=y.cnt)  
        return x.cnt>y.cnt;  
    return x.sum<y.sum;  
}  
  
int main()  
{  
    int n,t;  
    while(~scanf("%d%d",&n,&t))  
    {  
        int i,j,k = 0;  
        char sc[100];  
        while(~scanf("%s",s[k].name))  
        {  
            s[k].sum = s[k].cnt = 0;  
            for(i = 0; i<n; i++)  
            {  
                scanf("%s",sc);  
                if(!strcmp(sc,"0"))//没提交，自然不算  
                    continue;  
                if(sc[0] == '-')//提交的都是错的，而且没A，也不算  
                    continue;  
                s[k].cnt++;  
                int len = strlen(sc),f = 0,l = 0;  
                if(!strstr(sc,"("))//没有括号代表1A，，直接算  
                {  
                    while(sc[l])  
                    {  
                        f = f*10+sc[l]-'0';  
                        l++;  
                    }  
                    s[k].sum+=f;  
                    continue;  
                }  
                while(sc[l]!='(')//有括号就要算出提交的时间  
                {  
                    f = f*10+sc[l]-'0';  
                    l++;  
                }  
                s[k].sum+=f;  
                f = 0;  
                l++;  
                while(sc[l]!=')')//罚时  
                {  
                    f = f*10+sc[l]-'0';  
                    l++;  
                }  
                f = f*t;  
                s[k].sum+=f;  
            }  
            k++;  
        }  
        sort(s,s+k,cmp);  
        for(i = 0; i<k; i++)  
        {  
            printf("%-10s%3d%5d\n",s[i].name,s[i].cnt,s[i].sum);  
        }  
    }  
  
    return 0;  
}  