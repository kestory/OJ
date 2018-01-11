#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int a;
	cin >> a;
	char str[255];
	sprintf(str, "%x", a);
	for (int i = 0; i < strlen(str); ++i)
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] + 'A' - 'a';
	cout << str;

	return 0;
}

