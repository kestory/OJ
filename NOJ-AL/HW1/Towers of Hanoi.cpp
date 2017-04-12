#include <iostream>
#define dprint(expr) printf(#expr "= %d\n",expr)
#define D(x) cout<<#x<<"="<<x<<endl;
using namespace std;
void hanoi(char x,char y,char z,int n){//n x->y by z
	if(n==1)	cout<<x<<"-"<<y<<endl;
	else{
		hanoi(x,z,y,n-1);
		cout<<x<<"-"<<y<<endl;
		hanoi(z,y,x,n-1);
	}
}
int main(int argc, char *argv[]) {
	int a=0;
	while(cin >> a){
	hanoi('A','C','B',a);//A2CthoughB
	}
}
