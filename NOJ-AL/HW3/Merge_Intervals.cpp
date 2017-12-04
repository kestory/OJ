Description
Given a set of n intervals, merge them and output the result.

Input
The first line contains an integer n (1≤n≤40,000). In the next n lines,
each line contains two integers: l and r(0≤l, r≤10^100),
indicating that there is an interval [l, r].

Output
Output the merge result as a sequence of non-overlapping intervals in order.

Sample Input
4
1 5
0 1
6 10
8 9
Sample Output
0 5
6 10
HINT

注意题目数据的范围，32位或64位的都不够，需要用string表示；
题目没说l < r，因此还要考虑下l >= r 的情况；
最后输出表示的时候都是前面的数不大于于后面的数，但是类似 [1 1] 两个数相同的有可能出现
------------------------------------------------------------------------------------------------
还差一点点
------------------------------------------------------------------------------------------------
#include <algorithm>
#include <string>
#include <iostream>
#define dprint(expr) printf(#expr "= %d\n",expr)
#define D(x) cout<<#x<<"="<<x<<endl;
#define exchange(a,b)     (a=a^b,b=a^b,a=a^b)
using namespace std;
#define MAX 1000

bool cmp(string b, string a) {//true when second > first
	int la = a.length();
	int lb = b.length();
	if (la > lb)	return true;
	else if (la < lb)	return false;
	else {
		for (int i = 0; i < la; ++i) {
			if (a[i] > b[i])
				return true;
		}
		return false;
	}
}
/*
bool cmp(const string x, const string y) {
	return x < y;
}
*/
int main(int argc, char *argv[]) {
	int n = 0;
	cin >> n;
	string l[MAX];
	string r[MAX];
	for (int i = 0; i < n; ++i) {
		cin >> l[i] >> r[i];
		if (cmp(r[i], l[i])) {
			string t = l[i];
			l[i] = r[i];
			r[i] = t;
		}
	}
	//for (int i = 0; i < n; ++i)	cout<<l[i]<<"\t";cout<<endl;
	//for (int i = 0; i < n; ++i)	cout<<r[i]<<"\t";cout<<endl;
	sort(l, l + n, cmp);//我先排了序，就是把包含关系变成交错关系
	sort(r, r + n, cmp);//排序后再观之，不影响结果
	//for (int i = 0; i < n; ++i)	cout << l[i] << "\t"; cout << endl;
	//for (int i = 0; i < n; ++i)	cout << r[i] << "\t"; cout << endl;
	int in;
	for (int i = 0, in = 0; i < n - 1; ++i)
	{
		if (cmp(r[i], l[i + 1])) { //r[i]<l[i+1]
			cout << l[in] << " " << r[i] << endl;
			in = i + 1;
		}
	}

	cout << l[in] << " " << r[n - 1] << endl;


	return 0;
}

