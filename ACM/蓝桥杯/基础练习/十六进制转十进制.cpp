#include <iostream>
#include <cmath>
#include <cstring>
#define D(x) cout<<#x<<"="<<x<<endl;
using namespace std;

int main() {
	char str[16];
	cin >> str;
	int len = strlen(str);
	long long re = 0;// Need long long !!!
	for (int i = 0; i < len; ++i) {
		int s;
		if (str[i] >= 'A' && str[i] <= 'Z') //ばか don't forget different cases
			s = str[i] - 'A' + 10;
		else
			s = str[i] - '0';
		re += s * pow(16, len - i - 1);
		//D(s)D(re)
	}
	cout << re;

	return 0;
}

