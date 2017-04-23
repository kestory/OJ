#include <iostream>
#include <string.h>
#include <cmath>     /* fabs&&abs */
#include <float.h>
#include <iomanip>
#define D(x) cout<<#x<<"="<<x<<'\t';
using namespace std;

bool check(int a, int b) {
	if (a * b < 0 && (a + b) > 0)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	int t = 0;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		int m = 0;
		cin >> n;
		int *a = new int [n];
		int *b = new int [n];
		int *c = new int [n];

		int *d = new int [n];
		//int *e=new int [n];
		memset(d, -1, sizeof(d));
		//memset(e,-1,sizeof(e));
		for (int j = 0; j < n; j++) {
			cin >> a[j] >> b[j];
			c[j] = a[j] - b[j];
		}
		//for(int j=0;j<n;j++)cout<<c[j]<<'\t';
		for (int j = 0; j < n - 1; j++) {
			if (check(c[j], c[j + 1])) {
				++m;
				d[m] = j + 1;
				c[j] += c[j + 1];
				for (int w = j + 1; w < n - 1; ++w)c[w] = c[w + 1];
			}


		}
		if (m == 0)cout << -1;
		else {
			cout << m;
			for (int z = 0; z < m; z++) {
				if (d[z] != -1)
					cout << d[z] << '\t' << d[z] + 1 << endl;
			}
		}
		delete []a;
		delete []b;
		delete []c;

	}
	return 0;
}

