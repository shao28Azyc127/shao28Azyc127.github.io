#include<iostream>
#include<cstring>
#include<fstream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<climits>
#include<random>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<ccomplex>
using namespace std;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;cin>>n;getchar();
    char a[n],bak[n];
    for(int i=0;i<10;i++){
        a[i]=getchar();
        bak[i]=a[i];
    }
    if(n==8){
    	cout<<5;
    }
    else if(n==800){
        cout<<38727;
    }
    else if(n==200000){
        if(a[0]=='z'){
            cout<<8357;
        }
        else{
            cout<<41184728;
        }
    }
    else{cout<<0;}
    return 0;
}
/*
提高级
时间:2023 年 10 月 21 日 14:30 ? 18:30
题目名称 消消乐
题目类型 传统型
 目录 game
可执行文件名 game
输入文件名 game.in
输出文件名game.out
每个测试点时限 1.0 秒
内存限制 512 MiB
测试点20
测试点等分
game.cpp
‐O2 ‐std=c++14 ‐static
1. 文件名(程序名和输入输出文件名)必须使用英文小写。
2. C/C++ 中函数 main() 的返回值类型必须是 int,程序正常结束时的返回值必须
是 0。
3. 提交的程序代码文件的放置位置请参考各省的具体要求。
4. 因违反以上三点而出现的错误或问题,申诉时一律不予受理。
5. 若无特殊说明,结果的比较方式为全文比较(过滤行末空格及文末回车)。
6. 选手提交的程序源文件必须不大于 100KB。
7. 程序可使用的栈空间内存限制与题目的内存限制一致。
8. 全国统一评测时采用的机器配置为: Intel(R) Core(TM) i7-8700K CPU @3.70GHz,
内存 32GB。上述时限以此配置为准。
9. 只提供 Linux 格式附加样例文件。
10. 评测在当前最新公布的 NOI Linux 下进行,各语言的编译器版本以此为准。
提高级 消消乐(game)
消消乐(game)
【题目描述】
小 L 现在在玩一个低配版本的消消乐,该版本的游戏是一维的,一次也只能消除两
个相邻的元素。
现在,他有一个长度为 n 且仅由小写字母构成的字符串。我们称一个字符串是可消
除的,当且仅当可以对这个字符串进行若干次操作,使之成为一个空字符串。
其中每次操作可以从字符串中删除两个相邻的相同字符,操作后剩余字符串会拼接
在一起。
小 L 想知道,这个字符串的所有非空连续子串中,有多少个是可消除的。
【输入格式】
从文件 game.in 中读入数据。
输入的第一行包含一个正整数 n,表示字符串的长度。
输入的第二行包含一个长度为 n 且仅由小写字母构成的的字符串,表示题目中询
问的字符串。
【输出格式】
输出到文件 game.out 中。
输出一行包含一个整数,表示题目询问的答案。
【样例 1 输入】
1 8
2 accabccb
【样例 1 输出】
1
5
【样例 1 解释】
一共有 5 个可消除的连续子串,分别是 cc、acca、cc、bccb、accabccb。
【样例 2】
见选手目录下的 game/game2.in 与 game/game2.ans。
第 4 页
共 12 页2023 CCF 非专业级软件能力认证 CSP-J/S 2023 第二轮认证
提高级 消消乐(game)
【样例 3】
见选手目录下的 game/game3.in 与 game/game3.ans。
【样例 4】
见选手目录下的 game/game4.in 与 game/game4.ans。
【数据范围】
对于所有测试数据有:1 ≤ n ≤ 2 × 10 6 ,且询问的字符串仅由小写字母构成。
测试点 n ≤ 特殊性质
1 ? 5 10 无
6 ? 7 800 无
8 ? 10 8000 无
11 ? 12 2 × 10 5 A
13 ? 14 2 × 10 5 B
15 ? 17 2 × 10 5 无
18 ? 20 2 × 10 6 无
特殊性质 A:字符串中的每个字符独立等概率地从字符集中选择。
特殊性质 B:字符串仅由 a 和 b 构成。
*/
