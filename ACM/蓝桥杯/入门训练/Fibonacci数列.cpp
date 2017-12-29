#include <iostream>
using namespace std;
//程设样卷里的比较题。。。
int main() {
	int n;
	cin >> n;
	int fib[1000000];
	fib[0] = fib[1] = 1;
	for (int i = 2; i < n; i ++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % 10007;
	cout << fib[n - 1] % 10007;
	return 0;
}

