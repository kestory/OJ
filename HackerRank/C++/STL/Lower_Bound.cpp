#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n, x;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		v.push_back(x);
	}
	int q;
	cin >> q;
	int y;
	for (int i = 0; i < q; ++i)
	{
		cin >> y;
		vector<int>::iterator it = lower_bound (v.begin(), v.end(), y);
		//if (find(v.begin(), v.end(), y) != v.end()) //知道为什么end要下一位了
		if (v[it - v.begin()] == y)//find 的确有点过分了，时间超限，这个方法真的好
			cout << "Yes " << (it - v.begin() + 1) << endl;
		else
			cout << "No " << (it - v.begin() + 1) << endl;


	}

	return 0;
}
