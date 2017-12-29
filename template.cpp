#include <iostream>
#include <fstream>
using namespace std;

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout<<#x<<"="<<x<<endl;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	ifstream cin("222.txt");
	return 0;
}
