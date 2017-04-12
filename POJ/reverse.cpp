//若是一个浮点数呢
//完了，我没考虑数字很大时啊，难怪人家用unsign，不过这样没有负数了，最好当然是数组存放啦
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//0
//靠自己试水，通过使用sprintf(类似itoa)和atoi分正负转换
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    char string[11];
    sprintf(string, "%d", n); 
    //puts(string);
    //itoa(n,string,10);
    int len=strlen(string);
    //cout<<endl<<"len ="<<len<<endl;
    if(n<0)
    {for (int i = 1; i < len/2 ; ++i)
    {
        char t=string[i];
        string[i]=string[len-i];
        string[len-i]=t;
        //cout<<"t="<<t<<endl;
    }}
    else if(n>0)
    {for (int i = 0; i < len/2 ; ++i)
    {
        char t=string[i];
        string[i]=string[len-i-1];
        string[len-i-1]=t;
    }}  
    else if(n==0)
    cout<<"0";
    //puts(string);
    
    int nn=atoi(string);
    cout<<nn;
    return 0;
}

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//1
//把0稍微简化润色了下，性能方面没有改善
#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    char string[11];
    sprintf(string, "%d", n); 
    int len=strlen(string);
    if(n<0)
    for (int i = 1; i < len/2 ; ++i)
    {
        char t=string[i];
        string[i]=string[len-i];
        string[len-i]=t;
    }
    else
    for (int i = 0; i < len/2 ; ++i)
    {
        char t=string[i];
        string[i]=string[len-i-1];
        string[len-i-1]=t;
    }
    int reverse_n=atoi(string);
    cout<<reverse_n;
    return 0;
}

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//2 and 3 is from internet
//利用纯数字来做
//2-1
#include <iostream>
using namespace std;
int numReverse(int num) {  
      
        int modNum = 0;// 余数  
        int result = 0;  
      
        while (num / 10 != 0) {// 当num为一位数时，跳出循环  
      
            modNum = num % 10;  
            num = num / 10;  
            result = result * 10 + modNum;  
        }  
      
        return result * 10 + num;// 当num为一位数时，返回结果  
    }  
int main(int argc, char const *argv[])
{   
    int num;
    cin>>num;
    int mm=numReverse(num); 
    cout<<mm;
}

//2-2只能unsigned且有精读损失，但符合简单的思路
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int main()
{   int n;
    cin>>n;

int digits = (int)log10((double)n) ;

    int r = 0 ;
    while(n)
    {
        int t = n % 10 ;
        r += t * pow((double)10, digits--) ;
        n /= 10 ;
    }
    cout<<r;
}

//2-3最~简洁
#include <iostream>
#include <cstring>
using namespace std;
int main()
{   int a;
    cin>>a;

    int b = 0;
    for( ; a; a/=10 )
     {
             b = b*10 + a%10;
     }
    cout<<b;
}

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//3
//用string,目前还不会
#include <string.h>
#include <iostream>
using namespace std;
int main()
{
    char s[100];
    cin>>s;
    cout<<strrev(s)<<endl;    
}
但这个完全反转了，对负数不友好

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//5 你还没怎么看的网址
http://blog.csdn.net/a45872055555/article/details/37315779
