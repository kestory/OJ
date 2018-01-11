#include <iostream>
#include <cmath>
#define D(x) cout<<#x<<"="<<x<<endl;
using namespace std;

int main() {
	for (int i = 100; i < 1000; ++i) {
		int a = i % 10;
		int b = i / 10 % 10;
		int c = i / 100;
		if (i == pow(a, 3) + pow(b, 3) + pow(c, 3))
			cout << i << endl;
	}
	return 0;
}

#include <iostream>
using namespace std;
int main() {
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				if ((i * i * i + j * j * j + k * k * k) == (i * 100 + j * 10 + k))
					cout << i << j << k << endl;
			}
		}
	}
	return 0;
}
