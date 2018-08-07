
wwy问的这题，在大巴上思考全排列，回来发现有stl函数next_permutation，但依然TLE
ios::sync_with_stdio(false);也不行，只能改为scanf

大巴上思考：按序生成全部序列然后存储下来再search，但其实只管next后几个即可
全排列的生成算法：递归遍例，循环移位法，C++/STL中定义的next_permutation和prev_permutation

#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	string s = "121";
	sort(s.begin(), s.end());
	do {
		cout << s << '\n';
	} while(next_permutation(s.begin(), s.end()));
	//若新排列按字典序大于旧者则为 true 。若抵达最后重排并重置范围为首个排列则为 false
	cout << "After loop: " << s << '\n';
}

参数
first, last	-－	要重排的元素范围
is_permutation  (C++11) 
判断一个序列是否为另一个序列的排列组合 


#include <algorithm>
#include <iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int m,n,k;
	int a[1024];
	cin>>m;
	while(m--){
		cin>>n>>k;
		for (int i = 0; i < n; ++i)		
			cin>>a[i];
		for (int i = 0; i < k; ++i)
			next_permutation(a,a+n);
		for (int i = 0; i < n; ++i)		
			cout<<a[i]<<' ';
		cout<<endl;
	}
}


#include <algorithm>
#include <iostream>
using namespace std;
int main(){
	int m,n,k;
	int a[1024];
	scanf("%d", &m);
	while(m--){
		scanf("%d%d", &n,&k);
		for (int i = 0; i < n; ++i)		
			scanf("%d", &a[i]);
		for (int i = 0; i < k; ++i)
			next_permutation(a,a+n);
		printf("%d",a[0]);
        for(int i = 1; i < n; i++)     
            printf(" %d",a[i]);
        printf("\n");
	}
}