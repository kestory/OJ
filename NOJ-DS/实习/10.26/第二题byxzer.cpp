#include <iostream>
using namespace std;

struct tN{
	int data;
	tN *left;
	tN *right;
	int NO;
};

int caculate(tN* root){
	if (root == NULL)
		return 1;
	else if (root->left == NULL&&root->right == NULL)
		return root->data;
	else
		return caculate(root->left)*caculate(root->right) + root->data;
}

tN *creatN(int *num, int start,int end){
	int number = end - start + 1;
	if (number == 1){
		tN *root = new tN;
		root->left = NULL;
		root->right = NULL;
		root->data = num[start];
		root->NO = start+1;
		return root;
	}
	else if (number <= 0){
		return NULL;
	}
	else{
		tN *root = NULL;
		for (int i = start; i <= end; i++){
			tN *temp = new tN;
			temp->left = creatN(num, start, i-1);
			temp->right = creatN(num, i+1, end);
			temp->data = num[i];
			temp->NO = i+1;
			if (caculate(temp) > caculate(root)){
				delete root;
				root = temp;
			}
			else
				delete temp;
		}
		return root;
	}
}
void show(tN *tree){
	if (tree == NULL)
		return;
	cout << tree->NO << " ";
	show(tree->left);
	show(tree->right);
}
void init(int n){
	while (cin >> n){
		int *num = new int[n];
		for (int i = 0; i < n; i++)
			cin >> num[i];
		tN *tree = creatN(num, 0, n - 1);
		cout << caculate(tree) << endl;
		show(tree);
		cout << endl;
	}
}
int main(){
	int n = 0;
	init(n);
	return 0;
}