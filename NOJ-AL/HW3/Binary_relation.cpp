Description

假设集合中元素个数最多64个，编一个程序判断该集合上任意给定的二元关系满足那些性质

Input

首先输入集合的元素，用 -1表示结尾

然后输入二元关系的个数

然后依次输入二元关系的两个元素

Output

若满足自反，对称，或传递性质，则输出这个性质

Sample Input

1 2 - 1
4
1 1
2 2
1 2
2 1
Sample Output

reflexive
symmetric
transitive
------------------------------------------------------------------------
居然一次扔进去就过了，被代码美哭。。
第一次用了map，用vector学习了动态二维数组
最后传递性是用 复合矩阵法 来做的，就是 M*M属于M(M为0，M*M必为0)
------------------------------------------------------------------------
#include <map>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iostream>
#define D(x) cout<<#x<<"="<<x<<endl;
using namespace std;

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	//int e[64];
	/*map<int , string >mmp;
	map<int, string>::iterator  iter;
	string element;
	int num = 0;
	cin >> element;
	while (element != "-1") {
		mmp[num] = element;
		cin >> element;
		num++;
	}*/
	map<string, int >mmp;
	map<string, int>::iterator  iter1, iter2;
	string element;
	int num = 0;
	cin >> element;
	while (element != "-1") {
		mmp[element] = num;
		cin >> element;
		num++;
	}
	//for (int i = 0; i < num; ++i)cout<<mmp[i];
	int n;
	cin >> n;
	/*int **matrix = new int *[num]; //the_relation_matrix
	for (int i = 0; i < num; ++i)
		matrix[i] = new int [num];*/
	vector<vector<int> > matrix(num, vector<int>(num));//the_relation_matrix
	for (int i = 0; i < num; ++i)
		for (int j = 0; j < num; ++j)
			matrix[i][j] = 0;

	//D(mmp["1"])D(mmp["2"])D(mmp["3"])D(mmp["4"])

	string a, b;
	for (int i = 0; i < n; ++i)
	{
		a = "x";
		b = "x";
		cin >> a >> b;
		iter1 = mmp.find(a);
		iter1 = mmp.find(b);
		if (iter1 == mmp.end() || iter2 == mmp.end())
			continue;
		//D(a)D(b)
		//D(mmp.find(a)->second)D(mmp.find(b)->second)
		matrix[mmp[a]][mmp[b]] = 1;//I have no idea why this don't work
		//matrix[iter1->second][iter2->second]=1;
		//matrix[mmp.find(a)->second][mmp.find(b)->second] = 1; //this beat ^ and ==^^
	}

	/*for (int i = 0; i < num; i++) {//the_print
		for (int j = 0; j < num; j++)
			cout << setw(3) << matrix[i][j];
		cout << endl;
	}*/

	bool flag1 = true;
	for (int i = 0; i < num; ++i)
		if (matrix[i][i] == 0)
			flag1 = false;

	if (flag1 == true)
		cout << "reflexive" << endl;

	bool flag2 = true;
	for (int i = 0; i < num - 1; ++i)
		for (int j = i + 1; j < num ; ++j)
			if (matrix[i][j] != matrix[j][i])
				flag2 = false;


	if (flag2 == true)
		cout << "symmetric" << endl;

	bool flag3 = true;
	vector<vector<int> > matrix2(num, vector<int>(num));//the_matrix*matrix
	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < num; ++j) {
			matrix2[i][j] = 0;
			for (int k = 0; k < num; ++k)
				matrix2[i][j] += matrix[i][k] * matrix[k][j];
		}
	}

	/*for (int i = 0; i < num; i++) {//the_print
		for (int j = 0; j < num; j++)
			cout << setw(3) << matrix2[i][j];
		cout << endl;
	}*/

	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < num; ++j) {
			if (matrix[i][j] == 0) {
				if (matrix2[i][j] != 0)
					flag3 = false;

			}
		}
	}
	if (flag3 == true)
		cout << "transitive" << endl;
	return 0;
}

