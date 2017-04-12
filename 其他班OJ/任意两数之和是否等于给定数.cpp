题目描述
给定一个 int 数组 arr，元素按照升序排列且各不相同。另外有一个目标数 c，请你找出 arr 中所有的数对 a, b，使得 a + b = c。
输入
输入为三行，第一行为 arr 的元素个数，第二行为 arr，元素以空格分隔，第三行为目标数 c。
输出
所有符合条件的数对 a, b。a 和 b 以空格分开，每个数对占据一行。每行中 a < b，所有数对以它的第一个数（也就是 a 的值）升序排列。
样例输入
9
-2 0 1 2 3 5 6 8 10
8
样例输出
-2 10
0 8
2 6
3 5
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
明显的是arr[i]和arr[j]的事，我全都直接i和j了，半晌还找不出
既然是有序的，应该有复杂度低的算法吧
二分法搜索！成功降低时间
构造hash表{O(1)}！我直接用了一个超大数组来存，写完发现会有负数，所以还得用hash
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#define dprint(expr) printf(#expr "= %d\n",expr)
#define D(x) cout<<#x<<"="<<x<<endl;
using namespace std;
int main(int argc, char *argv[]) {
    int n,d;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin>>arr[i];
    cin>>d;
    for (int i = 0; i < n; ++i){
        for (int j = i+1; j <= n; ++j){//(int j = n; j >= i+1; --j) Also Right
            //D(i);D(j);
            if((arr[i]+arr[j])==d){
               // cout<<"\t\t\t";
                cout<<arr[i]<<" "<<arr[j]<<endl;
                break;
            }
        }
    }
    return 0;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#define D(x) cout<<#x<<"="<<x<<endl;
using namespace std;
int binarySearch(int E[], int first, int last, int K){
    int index=0;
    if (last<first)
        index=-1;
    else{
        int mid=(first+last)>>1;
        if (K==E[mid])
            index=mid;
        else if (K<E[mid])
            index=binarySearch(E, first, mid-1, K);
        else
            index=binarySearch(E, mid+1, last, K);
        }
        return index;
}
int main(int argc, char *argv[]) {
    int n,d;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin>>arr[i];
    cin>>d;
    //D(n);
    for (int i = 0; i < n; ++i){
            int j=binarySearch(arr,i+1,n-1,d-arr[i]);
            //D(i);D(j);
               // cout<<"\t\t\t";
            if(j!=-1)
                cout<<arr[i]<<" "<<arr[j]<<endl;
    }
    return 0;
}
