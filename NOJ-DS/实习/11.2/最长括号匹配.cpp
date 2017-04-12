Description
 给定字符串，仅包含左括号'('和右括号')'，它可能不是括号匹配的，设计算法，找出最长的括号字串，并返回字串的长度。(请用栈实现，可以使用库函数)

如：

    ((): 2

    ()(): 4

    ()(()):6

    (()()): 6

Input
测试数据包括多个，每个一行：
每行为一个字符串，这个字符串由左括号'('和右括号')'组成。
Output
对应每个测试案例，输出一行，包含一个整数，表示这个测试样例的最长匹配的括号数目。没有则输出0。

Sample Input
(()
)(
()(())
(()())
Sample Output
2
0
6
6
HINT
测试样例中'(' 和 ')' 均为英文输入法下的括号。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
直接在main里面写，还没理解题目要各子串中最长的
#include <iostream>
#include <stack>
#include <cstring>
#define dprint(expr) printf(#expr "= %d\n",expr)
using namespace std;
int main(int argc, char *argv[]) {
	char parenthese[50];
	stack<char>stk;
	while(cin>>parenthese){
			int len=0;
		for (int i = 0; i < strlen(parenthese); ++i)
		{
			char c=parenthese[i];
			if(c=='('){
				
				stk.push(c);
			}
			else{
				if(!stk.empty()){
				char d=stk.top();
				if(d=='('){
					stk.pop();
					len+=2;
					}
				}
				else {
					len=0;
				}

			}
			//dprint(len);
		}
		//len=len-2*stk.size();
		//if(len<0)
		//len=0;
		cout<<len<<endl;
		//dprint(stk.size());
		for(int i=0;i<stk.size();i++)
			stk.pop();
	}
	return 0;
}

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
在函数里写，对一个式子进行分析，不能真正解决（）（（）（）
#include <iostream>
#include <stack>
#include <cstring>
#define dprint(expr) printf(#expr "= %d\n",expr)
using namespace std;
char parenthese[50];
stack<char>stk;

int get_len(int x){
	int len=0;
		for (int i = x; i < strlen(parenthese); ++i)
		{
			char c=parenthese[i];
			if(c=='(')
				stk.push(c);
			else{
				if(!stk.empty()){
				//char d=stk.top();
				//if(d=='('){
					stk.pop();
					len+=2;
					//}
				}
				else
					return len;
			}
		}
		
		//len=len-2*stk.size();
		if(len<0)
		len=0;
		//if(stk.empty())
			return len;
		//else
			//return 0;
		
}
int main(int argc, char *argv[]) {
	while(cin>>parenthese){
		int w=0;
		for (int i = 0; i < strlen(parenthese); ++i)	
		{
			//int get=get_len(i);
			/*cout<<get_len(i)<<" \n";
			if(get_len(i)>w)
				w=get_len(i);*/
				//cout<<"getlen(i):  "<<get_len(i)<<endl;}
			int get=get_len(i);
			for(int i=0;i<stk.size();i++)
				stk.pop();
			//cout<<get<<endl;
			if(get>w)
			w=get;
		}
		cout<<w<<endl;
		
	}
	return 0;
}

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
xzer过来帮我看了之前，知道前面的一些bug原因，感觉上面算法还是很难解决（）（（）（）
他说了他的方法

一开始理解为一个循环设头，一个循环设尾，一个循环遍历会简单解决，其实其中还是会包含从头到尾
而且问题多多
后来想下肯定不会那么复杂，应该直接看到不行就跳过
#include <iostream>
#include <stack>
#include <cstring>
#define dprint(expr) printf(#expr "= %d\n",expr)
using namespace std;
int main(int argc, char *argv[]) {
	char parenthese[50];
	stack<char>stk;
	while(cin>>parenthese){
	int w=0;
	int len=0;
	for (int i = 0; i < strlen(parenthese); ++i)	
	{
		for (int j = i+1; j < strlen(parenthese); ++j)
		{	
			for (int k = i; k <=j ; ++k)
			{
				char c=parenthese[k];
				if(c=='(')
					stk.push(c);
				else
				{
					if(!stk.empty()){
						stk.pop();
						len+=2;
					if(len>w)
						w=len;					
					}
				}
			}
			for(int i=0;i<stk.size();i++)
				stk.pop();

			len=0;
		}	
	}
	cout<<w<<endl;
}
return 0;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <stack>
#include <cstring>
#define dprint(expr) printf(#expr "= %d\n",expr)
using namespace std;
char parenthese[50];
stack<char>stk;

int get_len(int x){
	int len;
	for (int j = x+1; j < strlen(parenthese); ++j)
	{	len=0;
		for (int k = x; k <=j ; ++k)
		{
			char c=parenthese[k];
			if(c=='(')
				stk.push(c);
			else{
				if(stk.empty())
					return len;
				else{
					stk.pop();
					len+=2;
				}
			}
		for(int i=0;i<stk.size();i++)
			stk.pop();	
		}
		return len;
	}
		
}
int main(int argc, char *argv[]) {
	while(cin>>parenthese){
		int w=0;
		for (int i = 0; i < strlen(parenthese); ++i)	
		{
			int get=get_len(i);
			//cout<<get<<endl;
			if(get>w)
			w=get;
		}
		cout<<w<<endl;
		
	}
	return 0;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
调了良久终于应该没有bug了，其实就是到底在循环里面还是外面
针对一个句子就能求解的算法太难，所以多套循环，不满足就退出，这样还是会找到最大值，何乐而不为
#include <iostream>
#include <stack>
#include <cstring>
#define dprint(expr) printf(#expr "= %d\n",expr)
using namespace std;
char parenthese[50];
stack<char>stk;

int get_len(int x){
	int len;
	int m=0;
	int lr;
	for (int j = x+1; j < strlen(parenthese); ++j)
	{	len=0;
		//m=0;
		lr=0;
		for (int k = x; k <=j ; ++k)
		{
			//dprint(k);
			//dprint(j);
			char c=parenthese[k];
			if(c=='('){
				++lr;
				//dprint(l);
				stk.push(c);
				}
			else if(c==')')
			{
				//if(!stk.empty()){
					--lr;			
					//dprint(lr);
					if(lr<0)
						continue;
					stk.pop();
					len+=2;
					//cout<<len<<endl;
				//}
			}
			//if(lr<0)
				//continue;
		}
		/*dprint(lr);
		dprint(len);
		dprint(m);
		*///cout<<(lr==0)&&(len>m)<<endl;
		if((lr==0)&&(len>m))
			m=len;
		for(int i=0;i<stk.size();i++)
			stk.pop();	
	}
	return m;
		
}
int main(int argc, char *argv[]) {
	while(cin>>parenthese){
		int w=0;
		for (int i = 0; i < strlen(parenthese); ++i)	
		{
			int get=get_len(i);
			//cout<<get<<endl;
			if(get>w)
			w=get;
		}
		cout<<w<<endl;
		
		//cout<<strlen(parenthese);
	}
	return 0;
}


