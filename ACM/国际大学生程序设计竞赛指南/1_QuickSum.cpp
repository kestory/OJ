#include <iostream>
#include <string>
#include <fstream>
#define D(x) cout<<#x<<"="<<x<<endl;
using namespace std;

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	ifstream cin("222.txt");

	//char s[256];
	string s;
	int sum = 0;
	//while (cin.getline(s, 256)) {
	while (getline(cin, s)) {
		if (s[0] == '#')break;
		//for (int i = 0; s[i] != '\0'; ++i)
		for (int i = 0; i < s.length(); ++i)
			if (s[i] != ' ')
				sum += (s[i] - 'A' + 1) * (i + 1);
		cout << sum << endl;
		sum = 0;
	}

	return 0;
}
-------------------------------------------------
string s;
getline (std::cin, s);
-------vs-------
char cs[256];
cin.getline (cs, sizeof (cs));


The global getline() function works with C++ std::string objects.
The istream::getline() methods work with "classic" C strings (pointers to char).
