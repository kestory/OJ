Description
给定一棵二叉树，判断这个树是否是对称的（即关于根节点镜像对称）。

例如，这样一棵二叉树[1,2,2,3,4,4,3]是对称的：

    1
   / \
  2   2
 / \ / \
3  4 4  3
但如下的二叉树[1,2,2,0,3,0,3] 不是对称的（0表示空节点）：

    1
   / \
  2   2
   \   \
   3    3
Input
每一行表示一棵树的层次遍历。

Output
每行为true或者false，表示这棵树是否是对称的。
（true表示这个二叉树是对称的，false表示这棵二叉树不是对称的。）
Sample Input
1,2,2,3,4,4,3
1,2,2,0,3,0,3
Sample Output
true
false
HINT
二叉树的输入加上空指针构成一棵满二叉树，按照输入的顺序建树即可，空指针的地方标识为0。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bug主要是循环后要重新设置初值！
(然后我把申明全放while(cin>>)){...}里面就更OK了，写时先不要考虑复杂度）
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <cstring>
#define dprint(expr) printf(#expr "= %d\n",expr)
using namespace std;
char a[50];

bool palindrome(int n,int m){
	bool flag=true;
	for (int i = n; i <=m ; ++i)
	{
		if(a[i]==a[m-i+n])
			{
				//dprint(i);
				//dprint(m-i+n);
				//dprint(a[i]);
				continue;}
		else{
			flag=false;
			break;
			}
	}
	return flag;
}
int main(int argc, char const *argv[])
{

	while(cin>>a){
	bool w=false;
	int x=0;
	int n=0;
	int m=0;
	while(m<strlen(a)-1){
		//dprint(n);
		m=2*n;
		w=palindrome(n,m);
		if(w==false)
			x++;

		n=n*2+2;
		}
		//dprint(x);
		if(x>0)
			cout<<"false"<<endl;
		else
			cout<<"true"<<endl;

	}

	
	return 0;
}