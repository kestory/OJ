#include <iostream>
#include <string.h>
using namespace std;
#define D(x) cout<<#x<<"="<<x<<endl;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int t = 0;
	int n = 0;
	int a[1000000];
	int b[1000000];
	memset(b, 0, sizeof(b));
//for(int z=0;z<10;z++)cout<<b[z]<<'\t';
//cout<<endl;
	cin >> t; //scanf("%d",&t);
	//int
	for (int i = 0; i < t; i++) {
		cin >> n; //scanf("%d",&n);
		int p = -1;
		int x = -1;
		for (int j = 0; j < n; j++) {
			cin >> a[j]; //scanf("%d",&a[j]);//
			b[a[j]]++;
		}
//for(int z=0;z<10;z++)cout<<b[z]<<'\t';
//cout<<endl;
		for (int j = 0; j < 1000000; j++) {
			if (b[j] > p)
				p = b[j];
		}
		//cout<<p<<endl;
		for (int j = 0; j < 1000000; j++) {
			if (b[j] == p)
				cout << j << endl;
		}

	}
	return 0;
}

