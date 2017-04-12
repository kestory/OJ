Problem B: n皇后

Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 144  Solved: 82
[Submit][Status][Web Board]
Description

n皇后是一个古老而著名的问题：如何在一个n*n的棋盘上放置n个皇后，使得皇后彼此不能相互攻击（即每行、每列、每斜线最多放一个皇后）。试计算有多少可能的解。

Input

一个整数n

Output

解的数量。

Sample Input

4
Sample Output

2
HINT

4皇后有两个解，分别是 {(1, 2), (2, 4), (3, 1), (4, 3)}和 {(1, 3), (2, 1), (3, 4), (4, 2)}。 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <cmath>
#include <iostream>
#define dprint(expr) printf(#expr "= %d\n",expr)
#define D(x) cout<<#x<<"="<<x<<endl;
#define exchange(a,b)     (a=a^b,b=a^b,a=a^b)
using namespace std;
bool safe(int queen[], int row, int col) {
	for (int i = 0; i < row; ++i) { //i is temprow	(row,col) vs (i, queen[i])
		if (col == queen[i] || (col - row) == (queen[i] - i) || (row + col) == (i + queen[i]))
			return false;
	}
	return true;
}
void place(int queen[], int row, int n, int &r) {
	if (row == n)
		r++;
	else {
		for (int i = 0; i < n; ++i)//i is tempcol for row
		{
			if (safe(queen, row, i)) {
				queen[row] = i;
				place(queen, row + 1, n, r);
			}
		}
	}
}

int main(int argc, char *argv[]) {
	int r = 0, n = 0;
	cin >> n; //square
	int *queen = new int[n];//the col of queen[i]
	place(queen, 0, n, r);
	cout << r;

	return 0;
}
