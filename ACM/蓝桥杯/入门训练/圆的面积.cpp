#include <iostream>
//#include <cmath>
using namespace std;
const double PI = 3.14159265358979323;
//2*2个方法
int main() {
	double n;
	cin >> n;
	//double PI=atan(1.0)*4;
	printf("%.7f\n", n * n * PI);
	//cout.precision(7);
	//cout << fixed << n * n * PI << endl;
	return 0;
}
