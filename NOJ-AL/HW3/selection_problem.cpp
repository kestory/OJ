Description

实现BG书上5.4.2所述线性选择算法：给定n个整数（无序且不重复），每个整数的大小以及n的大小都不超过int的表示范围，求出这n个数中第k小的数，k <= n 且 k >= 1.

Input

第1行给出整数个数n
第2行给出的数k表示要求的第k小的数
第3行给出n个整数，每个整数用空格隔开

Output

第k小的整数
Sample Input
5
2
3 6 50 2 1
Sample Output
2
HINT
该线性算法最主要在于选择了合适的partition pivot，使得数据规模急剧减少。主要实现这一点就行，其他的条件可以稍微放松，例如：

1 当n不是5的倍数时，可以下取整而不是上取整，剩下的不够5个的数放到步骤3处理。
2 Figure 5.3 的C和B部分本来不需要比较，但在实现过程中考虑到移动数据往往还是要遍历。

当然，对于有能力有精力的同学，我们还是鼓励你能准确地实现书上的算法。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
先是sort一下输出都能过。。。
然后用了一般的findk方法，顺便把quicksort弄明白了
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <algorithm>
#include <iostream>
#define dprint(expr) printf(#expr "= %d\n",expr)
#define D(x) cout<<#x<<"="<<x<<endl;
#define exchange(a,b)     (a=a^b,b=a^b,a=a^b)
using namespace std;
#define MAX 1000000

int partition (int arr[], int low, int high) {
	int pivot = arr[low];
	int i = low;
	for (int j = low + 1; j <= high; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);//#include <algorithm>
		}
	}
	swap(arr[i], arr[low]);
	return i;
}

int findKth(int E[], int first, int last, int k) {
	int ans;
	if (first == last)
		ans = E[first];
	else {
		int pivotElement = E[first];
		int splitPoint = partition(E[], first, last);
		E[splitPoint] = pivotElement;
		if (k < splitPoint)
			ans = findKth(E, first, splitPoint - 1, k);
		else if (k > splitPoint)
			ans = findKth(E, splitPoint + 1, last, k);
		else
			ans = pivotElement;
	}
	return ans;
}

int main(int argc, char *argv[]) {
	int n = 0, k = 0;
	cin >> n >> k;
	int a[MAX];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	cout << findKth(a, 0, n - 1, k - 1);
	return 0;
}

