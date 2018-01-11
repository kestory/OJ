#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
//16->10->8
int main() {
	string a[10];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i) {
		int len = a[i].length();
		long long re = 0;
		for (int j = 0; j < len; ++j) {
			int s;
			if (a[i][j] >= 'A' && a[i][j] <= 'Z')
				s = a[i][j] - 'A' + 10;
			else
				s = a[i][j] - '0';
			re += s * pow(16, len - j - 1);
		}
		char str[100000];
		sprintf(str, "%llo", re);
		for (int j = 0; j < strlen(str); ++j)
			if (str[j] >= 'a' && str[j] <= 'z')
				str[j] = str[j] + 'A' - 'a';
		cout << str << endl;
	}
	return 0;
}
