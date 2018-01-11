#include <iostream>
#include <cmath>
#define D(x) cout<<#x<<"="<<x<<endl;
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 10000; i < 100000; ++i) {
		int a = i % 10;
		int b = i / 10 % 10;
		int c = i / 100 % 10;
		int d = i / 1000 % 10;
		int e = i / 10000 % 10;
		if (a == e && b == d && (a + b + c + d + e) == n)
			cout << i << endl;
	}
	for (int i = 100000; i < 1000000; ++i) {
		int a = i % 10;
		int b = i / 10 % 10;
		int c = i / 100 % 10;
		int d = i / 1000 % 10;
		int e = i / 10000 % 10;
		int f = i / 100000 % 10;
		if (a == f && b == e && c == d && (a + b + c + d + e + f) == n)
			cout << i << endl;
	}
	return 0;
}


#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int a = 1; a < 10; a++)
		for (int b = 0; b < 10; b++)
			for (int c = 0; c < 10; c++) {
				if ((a + b + c + b + a) == n)
					cout << a << b << c << b << a << endl;
			}
	for (int a = 1; a < 10; a++)
		for (int b = 0; b < 10; b++)
			for (int c = 0; c < 10; c++) {
				if ((a + b + c + c + b + a) == n)
					cout << a << b << c << c << b << a << endl;
			}
	return 0;
}
