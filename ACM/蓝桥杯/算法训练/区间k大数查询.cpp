#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//int find_k(int l, int r, int k)
int main( ) {
	int n;
	cin >> n;
	vector<int> v1(n);
	vector<int> v2(n);
	for (int i = 0; i < n; ++i)
		cin >> v1[i];
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int l, r, k;
		cin >> l >> r >> k;
		for (int j = 0; j < n; ++j)
			v2[j] = v1[j];
		sort(v2.begin() + l - 1, v2.begin() + r);//是l-1和r
		//for (int j = 0; j < n; ++j)
		//    cout<<v2[j]<<' ';
		cout << *(v2.begin() + r - k) << endl;//有括号
	}
	return 0;
}
