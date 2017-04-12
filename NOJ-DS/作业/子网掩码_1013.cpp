Description
子网掩码计算方法 
 
子网掩码是用来判断任意两台计算机的IP地址是否属于同一子网络的根据。

最为简单的理解就是两台计算机各自的IP地址与子网掩码进行AND运算后，如果得出的结果是相同的，则说明这两台计算机是处于同一个子网络上的，可以进行直接的通讯。就这么简单。

请看以下示例：

运算演示之一：aa 
I P 地址　 192.168.0.1 
子网掩码　 255.255.255.0 
AND运算

转化为二进制进行运算： 
I P 地址　11010000.10101000.00000000.00000001 
子网掩码　11111111.11111111.11111111.00000000 
AND运算

11010000.10101000.00000000.00000000 
转化为十进制后为：

192.168.0.0


运算演示之二： 
I P 地址　 192.168.0.254 
子网掩码　 255.255.255.0 
AND运算

转化为二进制进行运算： 
I P 地址　11010000.10101000.00000000.11111110 
子网掩码　11111111.11111111.11111111.00000000 
AND运算

11010000.10101000.00000000.00000000 
转化为十进制后为：

192.168.0.0


运算演示之三： 
I P 地址　 192.168.0.4 
子网掩码　 255.255.255.0 
AND运算

转化为二进制进行运算： 
I P 地址　11010000.10101000.00000000.00000100 
子网掩码　11111111.11111111.11111111.00000000 
AND运算

11010000.10101000.00000000.00000000 
转化为十进制后为：

192.168.0.0


通过以上对三组计算机IP地址与子网掩码的AND运算后，我们可以看到它运算结果是一样的。均为192.168.0.0

所以计算机就会把这三台计算机视为是同一子网络。

Input
第一行是本机IP地址

第二行是子网掩码

第三行整数N，表示后面有N个IP地址

第1个IP地址

......

第N个IP地址

Output
计算并输出N个IP地址是否与本机在同一子网内。

对于在同一子网的输出"INNER"

对于在不同子网的输出“OUTER”

Sample Input
192.168.0.1
255.255.255.0
3
192.168.0.2
192.168.0.254
192.168.1.2
Sample Output
INNER
INNER
OUTER
HINT

~~~~~~~~~~~~~~~~
题目长却有点误导（甚至192的二进制都错的，华为oj题的质量啊）
先strtok切割字符串，又一次加强印象，然后想如何转成8位二进制再按位与，
看到	int a=255;
	int b=192;
	int c=a&b;
	cout<<c;
输出192，我就放心了，无须转换成2进制了。发现之前学到一个很好的思想
运用1与任何数进行&（按位与）运算，可获得其2进制的最低位
然后就很容易了，思路稍微清晰就可以了，submit and AC～
~~~~~~~~~~~~~~~~
#include <iostream>
#include <cstring>
#define dprint(expr) printf(#expr "= %d\n",expr)
using namespace std;
void change(char a[],int b[]){
	char *ptr;
	ptr=strtok(a,".");
	int i=0;
	b[i]=atoi(ptr);
	while(ptr!=NULL)
	{
		ptr=strtok(NULL,".");
		if(ptr!=NULL){//the last time ptr will be NULL,without this "if",error will happen
			i++;
			b[i]=atoi(ptr);
		}
	}
}
int main(int argc, char *argv[]) {
	char IP[20];
	char subnet_mask[20];
	cin>>IP>>subnet_mask;
	int IP_i[4];
	int subnet_mask_i[4];
	change(IP,IP_i);
	change(subnet_mask,subnet_mask_i);
	int right[4];
	for (int i = 0; i < 4; ++i)
	{
		right[i]=IP_i[i]&subnet_mask_i[i];
	}
	//for (int j = 0; j < 4; ++j){\
		cout<<j<<" "<<right[j]<<endl;\
	}
	int n;
	cin>>n;
	char ip[20];
	int ip_i[4];
	for (int i = 0; i < n; ++i)
	{		
		cin>>ip;
		change(ip,ip_i);
		//for (int j = 0; j < 4; ++j){\
			cout<<j<<" "<<ip_i[j]<<endl;\
		}
		int tst[4];
		for (int j = 0; j < 4; ++j){
			tst[j]=ip_i[j]&subnet_mask_i[j];
		}
		bool flag=true;//all be true is true
		//for (int j = 0; j < 4; ++j){\
			cout<<j<<" "<<tst[j]<<endl;\
		}
		
		for (int j = 0; j < 4; ++j){
			if(tst[j]!=right[j])
				flag=false;
		}
		if(flag==false)
			cout<<"OUTER\n";
		else
			cout<<"INNER\n";
	}
	return 0;
}

