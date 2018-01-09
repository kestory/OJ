#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int a[35][35];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		memset(a[i], 0, sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		a[i][0] = 1;

	for (int i = 1; i < n; ++i)
		for (int j = 1; j <= i; ++j)
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j)
			cout << a[i][j] << ' ';
		cout << endl;
	}

	return 0;
}

