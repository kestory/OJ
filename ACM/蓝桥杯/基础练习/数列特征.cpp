#include <iostream>
#include <climits>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[10000];
	/*for (int i = 0; i < n; ++i)
		cin>>a[i];
		*/
	int max = INT_MIN, min = INT_MAX, sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i]; //save for one loop
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
		sum += a[i];
	}
	cout << max << endl << min << endl << sum << endl;
	return 0;
}

