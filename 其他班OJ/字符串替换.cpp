题目描述

P185，4.13. 字符串替换操作replace(A String& s, A String& t, A String& v)是指：若t是s的子串，则用串v替换串t在串s中的所有出现；若t不是s的字串，则s不变。试实现该算法。

输入

多组输入。每组数据‘#’号开始，‘#’号结束：第一行为字符串t，第二行为字符串v，第三行开始，直至以‘#’标注的行为结束，其内容为s（不包括‘#’）

输出

输出替换后的文本，保持原有格式（行数及空格数）

样例输入

#
bab
abdc
aabbabcbaabaaacbab
#
#
you
My
Now, put your Thrift definitions in src/main/thrift, run sbt scrooge-gen, and you should see generated Scala class files under src_gen! Note that by default, Scrooge will put your generated Scala class files in target/src_managed. If you want to publish the generated classes in a jar, check them in, or compile the classes. You will almost certainly want something like the above setting.
#
样例输出

aababdccbaabaaacabdc
Now, put Myr Thrift definitions in src/main/thrift, run sbt scrooge-gen, and My should see generated Scala class files under src_gen! Note that by default, Scrooge will put Myr generated Scala class files in target/src_managed. If My want to publish the generated classes in a jar, check them in, or compile the classes. You will almost certainly want something like the above setting.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <string>
#define dprint(expr) printf(#expr "= %d\n",expr)
using namespace std;
int main(int argc, char const *argv[])
{
		string t,v,s;
		getline(cin,t);/＊这个也算一个点，cin>>对空格 TAB 回车都会断开
		getline(cin,v);/＊所以要用getline对最后的大段文字替换
		getline(cin,s);
		string::size_type pos = 0;//int pos=0;//皆可，酷炫之度不同尔
		while((pos=s.find(t,pos))!=string::npos){
			s.replace(pos,t.size(),v);
			pos+=t.size();
		}
		cout<<s;
	return 0;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
这是我第一个Google string出的一个博客里面正好有这个函数
参考了很多
#include <iostream>
#include <string>
using namespace std;
int str_replace(string &str, const string &src, const string &dest)
{
	int counter = 0;
	string::size_type pos = 0;
	while ((pos = str.find(src, pos)) != string::npos) {
		str.replace(pos, src.size(), dest);
		++counter;
		pos += dest.size();
	}
	return counter;
}
int main(){

		string t,v,s;
		//cin>>t>>v;
		getline(cin,t);
		getline(cin,v);
		getline(cin,s);
		str_replace(s, t, v);
		//cout<<"t="<<t;		
		//cout<<"v="<<v;
		cout<<s;
		
	return 0;
}