Description

There are n single - list nodes labeled 1...n. Each node has a successor pointer, which could be NULL.
Your task is to calculate the length of the longest chain from those formed by those nodes. The input list is guaranteed to contain no loop or cycle.

Input

The input consists of two lines. The first line contains an integer n (1 <= n <= 10 ^ 5).
The second line contains nintegers s1, s2, …, sn, in which si (0 <= si <= n) indicates that the successor of the i - th node is si;
in particular, si = 0 means that the successor pointer of the i - th node is NULL;

Output

Print the length of the longest chain.

Sample Input

6
2 3 0 1 0 3
Sample Output

4
HINT

The longest chain in the sample: 4->1->2->3
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
似乎有点暴力哈，尤其最后过与不过就是看MAX够不够大。。
把思路理清那就下表全转换为从0开始，找出所有chain中最长的即可，总感觉可以用并查集哎
可怜我之前都一直不知道动态数组。。终于不要傻傻的用一个超大的MAX了。。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
using namespace std;
//#define MAX 100000
struct Node {
	int num;
	struct Node *next;
};

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	int n = 0;
	cin >> n;
	Node *chain = new Node[n]; //Node chain[MAX];
	int k = 0;
	for (int i = 0; i < n; ++i) {
		cin >> k;
		k--;//make the index start from 0
		if (k == -1)
			chain[i].next = NULL;
		else
			chain[i].next = &chain[k];
	}
	int *len = new int[n]; //int len[MAX];
	for (int i = 0; i < n; ++i) {
		Node *p = &chain[i];
		int get_len = 0;
		while (p != NULL) {
			p = p->next;
			get_len++;
		}
		len[i] = get_len;
	}
	//for (int i = 0; i < n; ++i)
	//	cout << len[i];
	//sort(len, len + n);
	//for (int i = 0; i < n; ++i)
	//		cout<<len[i];
	//cout << len[n - 1];
	int t_m = -1;
	for (int i = 0; i < n; ++i)
		if (len[i] > t_m)
			t_m = len[i];
	cout << t_m;
	return 0;
}

