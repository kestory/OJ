Description
最初地面上有一堆n个硬币(5< =N< =2000)，从上面数第i个硬币的价值为C_i(1< =C_i< =100000); 游戏开始后，A先取一枚或两枚硬币。如果A取了一枚，那么B可以继续取一枚或两枚；如果A取了两枚，那么B可以取一到四枚硬币。每次都只能从最上面取。每一次，当前取硬币的人都至少取一枚硬币，最多可以取他的对手上一次取硬币数目的两倍。当没有硬币可取的时候，游戏就结束了。 然后，他们就可以用得到的硬币向John买东西，当然，他们游戏的目的就是要尽可能使自己得到的硬币价值更大。现在你的任务是，求出在两个人都想得到更大价值的情况下，游戏结束后，第一个人最多能得到的硬币价值。
Input
第1行：  一个整数，N（5< =N< =2000）。  第2到n+1行：  第  i+1  行代表从上数第i枚硬币的价值。
Output
一行：一个数字，第一个人能得到的最大价值
Sample Input
5
1
3
1
7
2
Sample Output
9
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
说是动规，看了挺久，连不动规都不会，只能修补网上代码发一份了
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#define dprint(expr) printf(#expr "= %d\n",expr)
#define D(x) cout<<#x<<"="<<x<<endl;
#define DS(x) cout<<#x<<" = "<<x<<"	";
using namespace std;
int n;
int sum[2048];
int f[2048][2048];
void dp(void){
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		f[i][j]=f[i][j-1];//自己特有的两条路保留，直接连到f(i,j-1)的最优解上
		if(i-j*2>=0) 
			f[i][j]=max(f[i][j],sum[i]-f[i-j*2][j*2]);
		if(i-(j*2-1)>=0)
			f[i][j]=max(f[i][j],sum[i]-f[i-(j*2-1)][j*2-1]);
	}
	cout<<f[n][1];
}
int main(int argc, char *argv[]) {
	//int n=0;
	int C_i[2048]={0};
	
	cin>>n;
	for (int i = n; i >= 1; --i)
		cin>>C_i[i];
	for (int i = 1;i <= n;++i)
		sum[i] = C_i[i] + sum[i - 1];
	dp();
	return 0;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
下面两个都是网上解答
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <cstdio>
#include <algorithm>
#include <iostream>
#define D(x) cout<<#x<<"="<<x<<endl;
#define DS(x) cout<<#x<<"="<<x<<" ";
#define MAX_N 2050
#define INF 0x3F3F3F3F
using namespace std;

int N, C[MAX_N];

//0:A, 1:B
int dp[2][MAX_N][MAX_N], sum[MAX_N];
void solve() {
	for (int i = 1;i <= N;++i)
		sum[i] = C[i] + sum[i - 1];
	for (int i = 1;i <= N;++i) {
		for (int j = 1;j <= N;++j) {
			if (j > i) break;
			dp[0][i][j] = dp[1][i - j][1] + sum[i] - sum[i - j];
			dp[1][i][j] = dp[0][i - j][1];
			for (int k = 1;k <= j * 2 && k + j <= i;++k) {
				dp[0][i][j] = min(dp[0][i][j], dp[1][i - j][k] + sum[i] - sum[i - j]);
				dp[1][i][j] = max(dp[1][i][j], dp[0][i - j][k]);
			}
			if (j == i) dp[0][i][j] = sum[i], dp[1][i][j] = 0;
			//printf("dp[0][%d][%d]:%d\n", i, j, dp[0][i][j]);
			//printf("dp[1][%d][%d]:%d\n", i, j, dp[1][i][j]);
		}
	}
	printf("%d\n", max(dp[0][N][1], dp[0][N][2]));
}

int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for (int i = N;i >= 1;--i)
		scanf("%d", &C[i]);
	solve();
	return 0;
}


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,a[2005],f[2005][2005],sum[2005];
int main(){
//    freopen("01.txt","r",stdin);
	scanf("%d",&N);
	for(int i=N;i>0;i--)
		scanf("%d",&a[i]);
	for(int i=1;i<=N;i++)
		sum[i]=sum[i-1]+a[i];
	
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++){
			f[i][j]=f[i][j-1];//自己特有的两条路保留，直接连到f(i,j-1)的最优解上
			if(i-j*2>=0) 
				f[i][j]=max(f[i][j],sum[i]-f[i-j*2][j*2]);
			if(i-(j*2-1)>=0)
				f[i][j]=max(f[i][j],sum[i]-f[i-(j*2-1)][j*2-1]);
		}
	printf("%d\n",f[N][1]);
	return 0;
}