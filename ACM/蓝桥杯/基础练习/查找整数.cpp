#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[1000];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int m;
	cin >> m;
	int i = 0;
	for (; i < n; ++i) {
		if (a[i] == m) {
			cout << i + 1;
			break;
		}
	}
	if (i == n)
		cout << -1;
	return 0;
}

