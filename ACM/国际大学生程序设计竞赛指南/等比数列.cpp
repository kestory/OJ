#include <iostream>
#include <fstream>
#include <cmath>
#define D(x) cout<<#x<<"="<<x<<endl;
using namespace std;
//1+q+q^2+q^3+...+q^n
int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	ifstream cin("222.txt");
	double q;
	int n;
	double sum = 0;
	while (cin >> n >> q) {
		for (int i = 0; i <= n; ++i)//till q^n
		{	/*double a = 1;
			for (int j = 0; j < i; ++j)
				a *= q;
			//D(a)
			sum += a;*/
			if (q == 1)sum = 1 + n;//expression
			else	sum = (1 - pow(q, n + 1)) / (1 - q);
		}
		//cout.precision(3);
		//cout << fixed << sum << endl;
		printf("%.3f\n", sum);
		sum = 0;
	}
	return 0;
}

