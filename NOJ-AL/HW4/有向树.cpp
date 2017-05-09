Description

判断一个有向图是否为树，一般需要满足以下两个个条件：

1. 有且仅有一个节点，为根节点，没有任何有向边指向该节点

2. 除了根节点的任意节点，有且仅有一条有向边指向这个节点

Input

输入首先为边的数目，然后包含一串数字，数字成对出现，前一个数字表示有向边的开始节点，后一个数字表示有向边的终点。

Output

你的程序需要首先判断是否为树，如果是树，则输出tree，并输出树的高度，用空格隔开

如果不是树，则输出not tree，并输出不满足的条件1或者2，用空格隔开。如果两个条件都不满足，输出not tree 1即可

Sample Input

5
6 8 5 3 5 2 6 4 5 6
Sample Output

tree 3
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
一小时不到就AC啦～
存储有些暴力，但是容易实现，且似乎要优化过于麻烦
算树高度用的上一次Longest_Chain的方法
其余真是只要逻辑与数学就能做出来，不用构造复杂数据结构，所以还没有做一个图出来
条件2就是入度最大为1，条件1就是存在点中要么入度为1，还有一点必须为0，这样我的b[]就顺便表示点在不在了
这个在计算高度时为叶子设置NULL也有帮助
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <cstring>//memset
#include <vector>
#include <algorithm>
#define D(x) cout<<#x<<"="<<x<<endl;
using namespace std;
struct Node {
	int num;
	struct Node *next;
};
int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	int edges;
	cin >> edges;
	//int num=edges<<1;
	vector<int> v;
	int x, y;
	int a[1024];//the_in-degree_of_each_vertex
	int b[1024];//which_vertex_was_in
	//int h[1024];//height
	memset(a, -1, sizeof(a));
	memset(b, -1, sizeof(b));
	//memset(h, 0, sizeof(h));
	Node chain[1024];
	int len[1024];
	for (int i = 0; i < edges; ++i) {
		cin >> x >> y;
		v.push_back(x);
		v.push_back(y);
		//if (h[y] == 0)
		//	h[x] = 1;
		//h[x] += h[y];

		//if (find(v.begin(), v.end(), y) != v.end())
		if (b[y] == -1)//before find y
			chain[y].next = NULL;
		chain[x].next = &chain[y];

		if (a[y] == -1)
			a[y] = 1;
		else if (a[y] > -1)
			a[y]++;
		b[x] = 0;
		b[y] = 0;
	}
	int m = *max_element(v.begin(), v.end()) + 1;
	/*
	for (int i = 0; i < m; ++i)
		cout << h[i] << " ";
	cout << endl;
	for (int i = 0; i < m; ++i)
		cout << b[i] << " ";
	*/
	int num_of_zero = 0;
	for (int i = 0; i < m; ++i)
		if (b[i] == 0 && a[i] == -1) {
			a[i] = 0;
			num_of_zero++;//the_root
		}
	bool condition1 = false, condition2 = false;
	if (num_of_zero == 1)
		condition1 = true;
	/*int max = -1;
	for (int i = 0; i < m; ++i)
		if (a[i] > max)
			max = a[i];
	if (max == 1)
		condition2 = true;
	*/
	condition2 = true;//all_in-degree<=1
	for (int i = 0; i < m; ++i)
		if (a[i] > 1)
			condition2 = false;
	int max = -1;
	if (condition1 && condition2) {
		for (int i = 0; i < m; ++i) {
			Node *p = &chain[i];
			int get_len = 0;
			while (p != NULL) {
				p = p->next;
				get_len++;
			}
			len[i] = get_len;
		}
		for (int i = 0; i < m; ++i)
			if (len[i] > max)
				max = len[i];

	}



	if (condition1 && condition2)
		cout << "tree " << max;
	else if (condition1)
		cout << "not tree 2";
	else
		cout << "not tree 1";


	return 0;
}

