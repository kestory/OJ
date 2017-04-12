Description
使用3个队列，分别保留手机上最近10个，（0）未接来电、（1）已接来电、（2）已拨电话。

Input
全部通话记录，每行一条记录。

每条记录包含两个数字，第一个数代表记录类型，第二个数代表手机号码。

Output
分3列输出未接来电、已接来电、已拨电话。

列之间用空格分割，后接电话在最先输出，不足10条用0占位。

Sample Input
2	18270477699
1	10149800116
0	19906559817
1	16209018105
1	16804212234
2	19289130583
1	17982711123
0	10897630486
1	11860787674
0	15192777554
Sample Output
15192777554 11860787674 19289130583
10897630486 17982711123 18270477699
19906559817 16804212234 0
0 16209018105 0
0 10149800116 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <cstring>
using namespace std;
class Stack
{public:
	Stack() { top=NULL; }
	//~Stack();
	bool push(char m[],int len);
	bool pop(char m[],int len);
	bool IsEmpty();
private:
	struct Node
	{	char content[20];
		Node *next;
	} *top;
};

bool Stack::push(char m[],int len)
{
	Node *p=new Node;
	if (p==NULL)
	{	cout<<"overflow"<<endl;
		return false;
	}
	else
	{	strcpy(p->content,m);
		p->next=top;
		top=p;
		return true;
	}
}
bool Stack::pop(char m[],int len)
{
	if (top==NULL)
	{	cout<<"Empty"<<endl;
		return false;
	}
	else
	{	Node *p=top;
		top=top->next;
		cout<<p->content<<" ";//strcpy(m,p->content);
		delete p;
		return true;
	}
}

bool Stack::IsEmpty()
{
	return top==NULL;
}

int main(int argc, char const *argv[])
{
	Stack A;
	Stack B;
	Stack C;
	int x=-1;
	int count=0;
	char num[20];
	int w=5;
	while(w>0)
	{
		if (x==0)
		{
			A.push(num,20);count++;
		}
		else if (x==1)
		{
			B.push(num,20);count++;
		}
		else if (x==2)
		{
			C.push(num,20);count++;
		}
		else
			return -1;
		w--;
	}
	for (int i = 0; i < count; ++i)
	{
		if (A.IsEmpty())
			cout<<"0";
		else if (!A.IsEmpty())
			A.pop(num,20);
		else if (B.IsEmpty())
			cout<<"0";
		else if (!B.IsEmpty())
			B.pop(num,20);
		else if (C.IsEmpty())
			cout<<"0";
		else if (!C.IsEmpty())
			C.pop(num,20);
		cout<<endl;
	}

	return 0;
}

#include <iostream>
#include <stack>
using namespace std;
int main(int argc, char const *argv[])
{
	stack<long long> mystack0;
	stack<long long> mystack1;
	stack<long long> mystack2;
	int a;
	long long num;

	while (cin >> a >> num&&a != -1){
		if (a == 0)
		{
			mystack0.push(num);//count++;
		}
		else if (a == 1)
		{
			mystack1.push(num);//count++;
		}
		else if (a == 2)
		{
			mystack2.push(num);//count++;
		}
	}
	for (int i = 0; i < 10; ++i)
	{
		if (mystack0.empty())
			cout << "0";
		else if (!mystack0.empty())
			cout << mystack0.top(); mystack0.pop();
		cout << " ";
		if (mystack1.empty())
			cout << "0";
		else if (!mystack1.empty())
			cout << mystack1.top(); mystack1.pop();
		cout << " ";
		if (mystack2.empty())
			cout << "0";
		else if (!mystack2.empty())
			cout << mystack2.top(); mystack2.pop();
		cout << endl;
	}
	return 0;
}
15192777554 11860787674 19289130583
10897630486 17982711123 18270477699
19906559817 16804212234 0
0 16209018105 0
0 10149800116 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0


#include <iostream>
#include <stack>
using namespace std;
int main(int argc, char const *argv[])
{
	stack<long long> mystack0;
	stack<long long> mystack1;
	stack<long long> mystack2;
	int a;
	long long num;

	while (cin >> a >> num){
		if (a == 0)
		{
			mystack0.push(num);//count++;
		}
		else if (a == 1)
		{
			mystack1.push(num);//count++;
		}
		else if (a == 2)
		{
			mystack2.push(num);//count++;
		}
		else
			return 0;
	}
	for (int i = 0; i < 10; ++i)
	{
		if (mystack0.empty())
			cout << "0 ";
		else if (!mystack0.empty()){
			cout << mystack0.top()<<" "; 
			mystack0.pop();
		}
		//cout << " ";
		if (mystack1.empty())
			cout << "0 ";
		else if (!mystack1.empty()){
			cout << mystack1.top()<<" "; 
			mystack1.pop();
		}
		//cout << " ";
		if (mystack2.empty())
			cout << "0"<<endl;
		else if (!mystack2.empty()){
			cout << mystack2.top()<<endl; 
			mystack2.pop();
		}
		//cout << endl;
	}
	return 0;
}