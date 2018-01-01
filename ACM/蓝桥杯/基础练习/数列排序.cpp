#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main( ) {
	vector<int> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.begin() + n);
	cout << v[0];
	for (int i = 1; i < n; ++i) cout << ' ' << v[i];
	return 0;
}
