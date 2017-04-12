Description
计算给定的逆波兰表达式（即后缀表达式）的值。

Input
测试数据包括多个，每个一行：
每行为一个字符串，这个字符串由由数字, +, -, *, / 构成。
Output
对应每个测试样例，输出一行，包含一个整数，表示这个逆波兰式的计算结果。
Sample Input
2354-*+21/-
2345-*+21/-
Sample Output
3
-3
HINT
为简化预处理，每个输入的操作数都是个位数。

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
写过多次，再次写还是生疏，因为不理解
然后参考下面的和下下面的终于理解。
栈里存放数字就行。push(k-'0')那就是正真数字了，以后直接操作即可。
#include <iostream>
#include <cstring>
#include <stack>
#define dprint(expr) printf(#expr "= %d\n",expr)
using namespace std;
int main(int argc, char *argv[]) {
	char expr[50];
	while(cin>>expr){
	stack<int>stk;
	for (int i = 0; i < strlen(expr); ++i)
	{
		int k=expr[i];
		int a,b,c;
		if(k=='+')
		{
			a=stk.top();
			stk.pop();
			b=stk.top();
			stk.pop();
			//cout<<"a= "<<a<<endl<<"b= "<<b;
			c=a+b;
			stk.push(c);
		}
		else if(k=='-')
		{
			a=stk.top();
			stk.pop();
			b=stk.top();
			stk.pop();
			c=b-a;
			stk.push(c);
		}
		else if(k=='*')
		{
			a=stk.top();
			stk.pop();
			b=stk.top();
			stk.pop();
			c=a*b;
			stk.push(c);
		}
		else if(k=='/')
		{
			a=stk.top();
			stk.pop();
			b=stk.top();
			stk.pop();
			c=b/a;
			stk.push(c);
		}
		else {
			stk.push(k-'0');
		}
				
	}
	cout<<stk.top()<<endl;
}


	return 0;
}


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
修改了以前的代码交了
#include <stack>
#include <iostream>
using namespace std;

bool IsOperator(char ch)
{
	char ops[] = "+-*/";
	for (int i = 0; i < sizeof(ops) / sizeof(char); i++)
	{
		if (ch == ops[i])
			return true;
	}
	return false;
}



//////////////////////////////////////////////////////////////////////////
// 后缀表达式求值程序
double postFixEval(char* postFix)
{
	stack<char> st;
	int len = strlen(postFix);
	char c;

	for (int i = 0; i < len; i++)
	{
		c = postFix[i];
		if (IsOperator(c) == false)
		{
			st.push(c - '0');
		}
		else
		{
			char op1, op2;
			int val;

			op1 = st.top();
			st.pop();
			op2 = st.top();
			st.pop();
			//cout<<"\nop1:"<<op1;
			//cout<<"\nop2:"<<op2;
			//printf("\nop1:%c\nop2:%c",op1,op2);
			switch (c)
			{
			case '+':
				val = op1 + op2;
				break;
			case '-':
				val = op2 - op1;
				break;
			case '*':
				val = op1 * op2;
				break;
			case '/':
				val = op2 / op1;
				break;
			}
			//printf("\nval:%d\n",val);
			st.push(val);
		}
	}

	return st.top();
}

int main(){
	char inFix[100];
	int val;

	while (cin>>inFix)
	{
		val = postFixEval(inFix);
		printf("%d\n", val);
	}

	return 0;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	char a,b;
	cin>>a>>b;
	char aa=a-'0';
	char bb=b-'0';
	cout<<"aa="<<aa;
	int c=aa+bb;
	cout<<"\ncc="<<c;


以前一直看不懂后缀求值的代码，今天才发现这样一个东东
1
2
aa=
cc=3

理解代码是理解了，但其中原因还得深思
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
了解后自己实现就简单了
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <stack>
#include <cstring>
#include <iostream>
using namespace std;

bool IsOperator(char ch)
{
	char ops[] = "+-*/";
	for (int i = 0; i < sizeof(ops) / sizeof(char); i++)
	{
		if (ch == ops[i])
			return true;
	}
	return false;
}



//////////////////////////////////////////////////////////////////////////
// 后缀表达式求值程序
double postFixEval(char* postFix)
{
	stack<int> st;
	int len = strlen(postFix);
	char c;

	for (int i = 0; i < len; i++)
	{
		c = postFix[i];
		if (IsOperator(c) == false)
		{
			st.push(c - '0');
		}
		else
		{
			int op1, op2;
			int val;

			op1 = st.top();
			st.pop();
			op2 = st.top();
			st.pop();
			//cout<<"\nop1:"<<op1;
			//cout<<"\nop2:"<<op2;
			//printf("\nop1:%c\nop2:%c",op1,op2);
			switch (c)
			{
			case '+':
				val = op1 + op2;
				break;
			case '-':
				val = op2 - op1;
				break;
			case '*':
				val = op1 * op2;
				break;
			case '/':
				val = op2 / op1;
				break;
			}
			//printf("\nval:%d\n",val);
			st.push(val);
		}
	}

	return st.top();
}

int main(){
	char inFix[100];
	int val;

	while (cin>>inFix)
	{
		val = postFixEval(inFix);
		printf("%d\n", val);
	}

	return 0;
}

