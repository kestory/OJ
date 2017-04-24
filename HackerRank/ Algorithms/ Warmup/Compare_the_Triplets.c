#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#define dprint(expr) printf(#expr "= %d\n",expr);
int* solve(int a0, int a1, int a2, int b0, int b1, int b2, int *result_size){
	// Complete this function
	//int *r=new int[2];
	int *r=(int *)malloc(sizeof(int)*2);
	r[0]=0;
	r[1]=0;
	if(a0>b0)
		r[0]++;
	else if(a0<b0)
		r[1]++;
	if(a1>b1)
		r[0]++;
	else if(a1<b1)
		r[1]++;
	if(a2>b2)
		r[0]++;
	else if(a2<b2)
		r[1]++;
	*result_size=2;
	/*dprint(r[0])dprint(*result_size)
	if(r[0]>0)	(*result_size)++;
	if(r[1]>0)	(*result_size)++;
	dprint(r[1])dprint(*result_size)*/
	return r;
}

int main() {
	int a0;
	int a1;
	int a2;
	scanf("%d %d %d", &a0, &a1, &a2);
	int b0;
	int b1;
	int b2;
	scanf("%d %d %d", &b0, &b1, &b2);
	int result_size;
	int* result = solve(a0, a1, a2, b0, b1, b2, &result_size);
	//dprint(result_size)
	for(int result_i=0; result_i < result_size; result_i++) {
		if(result_i) {
			printf(" ");
		}
		printf("%d", result[result_i]);
	}


	return 0;
}

