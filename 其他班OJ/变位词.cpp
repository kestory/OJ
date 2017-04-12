题目描述
请大家在做oj题之前，仔细阅读关于抄袭的说明http://www.bigoh.net/JudgeOnline/.


变位词是指由相同的字母组成的单词，如eat、tea是变位词。本次问题给出一串单词，你需要找到所有的变位词。

输入
输入由两行组成：第一行是所有单词的总数，第二行是由空格分隔的单词列表。两行末尾都有空格。

注：为防歧义，输入的单词都是小写

输出
这次需要大家先输出一个字符串，它是“我已阅读关于抄袭的说明”的汉语拼音.输出此行的提交我们将认为已经完全阅读并了解了“关于抄袭的说明”公告.

第二行是变位词组的个数，后面是所有的变位词。每个输出的变位词占一行。一组变位词只需要输出一个字典序最小的代表即可，如eat、tea中eat字典序小于tea，所以输出eat。变位词与变位词也按照字典序从小到大排列，如eat和el中eat字典序小于el所以eat在el前面。

输出的每一行最后都没有空格。

样例输入
9
a ew vc tea oe eat zoo el le
样例输出
wo yi yue du guan yu chao xi de shuo ming
2
eat
el
提示
使用代价为O(nlgn)的方法。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：
	一个判断变位词的函数：把两个字符排序好比较
	链表表示，复制一个链表判断完就删节点来计算变位词数
	与此同时找到里面最小的放入另一个链表
	最后把这个链表排序输出就行
	我真厉害
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <cstdio>
#include <iostream>
#define dprint(expr) printf(#expr "= %d\n",expr)
#define D(x) cout<<#x<<"="<<x<<endl;
#define exchange(a,b)     (a=a^b,b=a^b,a=a^b)
using namespace std;
int main(int argc, char *argv[]) {

	return 0;
}
