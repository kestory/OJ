#include <iostream>
#include <string>
using namespace std;
const int n = 4;//01234
const int N = 32;//2^5
int main( ) {//算法课里二进制计数器的平摊分析
	string wu[N];
	for (int i = 0; i < N; ++i) {
		wu[i] = "00000";//need change if >5
	}
	/*
	for (int i = 1; i < 32; i += 2)
		wu[i][4] = '1';
	for (int i = 2; i < 32; i += 4) {
		wu[i][3] = '1';
		wu[i + 1][3] = '1';
	}
	for (int i = 4; i < 32; i += 8)
		for (int j = 0; j < 4; ++j)
			wu[i + j][2] = '1';
	for (int i = 8; i < 32; i += 16)
		for (int j = 0; j < 8; ++j)
			wu[i + j][1] = '1';
	for (int i = 16; i < 32; i += 32)
		for (int j = 0; j < 16; ++j)
			wu[i + j][0] = '1';
	*/
	for (int x = 1, y = 0; x < N ; x *= 2, y++)//必要的拓展，为了5位以上
	{
		for (int i = x; i < N; i += x * 2)
			for (int j = 0; j < x; ++j)
				wu[i + j][n - y] = '1';
	}

	for (int i = 0; i < N; i++) {
		cout << wu[i] << endl;
	}
	return 0;
}
//char[][]似乎有问题

//5层循环
#include <iostream>
using namespace std;
int main() {
	for (int i = 0; i <= 1; i++)
		for (int j = 0; j <= 1; j++)
			for (int k = 0; k <= 1; k++)
				for (int l = 0; l <= 1; l++)
					for (int m = 0; m <= 1; m++) {
						cout << i << j << k << l << m << endl;
					}
	return 0;
}

//模拟二进制自增
#include <iostream>
using namespace std;
int main() {
	char a[6] = "00000";
	for (int i = 0; i < 32; ++i) {
		cout << a << endl;
		a[4] += 1;
		for (int j = 4; j > 0; --j) {
			if (a[j] == '2') {
				a[j] = '0';
				a[j - 1] += 1;
			}
		}
	}
	return 0;
}
