#include <iostream>
#include <string.h>
#include <cmath>     /* fabs&&abs */
#include <float.h>
#include<iomanip>	
#define D(x) cout<<#x<<"="<<x<<'\t';
using namespace std;

double find_m(double *a,int n){//get the max fabs
	double z=-1;
	for(int i=0;i<n;++i)
		if(fabs(a[i])>z)
			z=fabs(a[i]);
	return z;		
}
double find_max(double *a,int n){//get the max
	double z=DBL_MIN;
	for(int i=0;i<n;++i)
		if(a[i]>z)
			z=a[i];
	return z;		
}
double find_min(double *a,int n){//get the min
	double z=DBL_MAX;
	for(int i=0;i<n;++i)
		if(a[i]<z)
			z=a[i];
	return z;		
}
int main(){
	ios::sync_with_stdio(false);
	int t=0;
	cin>>t;

	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		double *a=new double [n];
		double *b=new double [n];
		for(int j=0;j<n;j++)
			cin>>a[j]>>b[j];
		double f=find_m(a,n);
		double mm=find_max(a,n)-find_min(a,n);
		for(int k=0;k<f;k++){
			
			for(int w=0;w<n;w++)	a[w]+=b[w];
			double mmm=fabs(find_max(a,n)-find_min(a,n));

		//D(find_max(a,n))D(find_min(a,n))
			if(mmm<mm)
				mm=mmm;
		}

		//delete []a;
		//delete []b;

		cout<<setiosflags(ios::fixed)<<setprecision(7)<<mm<<endl;

	}
	return 0;
}

