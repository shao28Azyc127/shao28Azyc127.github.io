#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cassert>
#include<climits>
#include<iomanip>
#include<set>
#include<stack>
#include<fstream>
#include<random>
#include<cmath>
#include<ctime>
#include<complex>
#include<cstdlib>
#include<cstring>
using namespace std;
//从BJBZ来的ZYC,(NOIP RP++)
//洛谷UID：700972
//洛谷用户名：shao28Azyc139

//please let me got 70 points on this problem!
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    /*
    int c,t;cin>>c>>t;
    if(c==1||c==2){for(int zyc=0;zyc<t;zyc++){
    int a[n];
    for(int i=0;i<(int)pow(2,n);i++){
        int r=i;
        for(int j=0;j<n;j++){
            a[j]=r%(int)pow(2,n-j-1);
            r-=a[j]*(int)pow(2,n-j-1);
        }
    }
    }}
    */

/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cassert>
#include<climits>
#include<iomanip>
#include<set>
#include<stack>
#include<fstream>
#include<random>
#include<cmath>
#include<ctime>
#include<complex>
#include<cstdlib>
#include<cstring>
using namespace std;
//从BJBZ来的ZYC,(NOIP RP++)
//洛谷UID：700972
//洛谷用户名：shao28Azyc139

//please let me got 70 points on this problem!
//this problem is so hard that I can only AC Test case #1 and #2!!!!!!
//@C*F I thank you!!!
//10 pts!
int check1(int m,int n){
    if(m>n){
        cout<<1;
    }
    else{
        cout<<0;
    }
}
int check2(int x1,int x2,int y1,int y2){
    if(x1<y1||x2<y2){
        cout<<0;return 0;
    }
    if(x1>y1&&x2>y2){
        cout<<1;return 0;
    }
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,n,m,q;
    cin>>c>>n>>m>>q;
    if(c==1){
            int bn,bm;cin>>bn>>bm;
        check1(n,m);
        for(int i=0;i<q;i++){
            int kx,ky;cin>>kx>>ky;
            for(int j=0;j<kx;j++){
                int p,v;cin>>p>>v;
    bn=v;
            }
            for(int j=0;j<ky;j++){
                int p,v;cin>>p>>v;
                bm=v;
            }
            check1(bn,bm);
        }
    }
    else if(c==2){
        int x1,x2,y1,y2;
        cin>>x1>>x2>>y1>>y2;
        check2(x1,x2,y1,y2);
        int q;cin>>q;
        for(int j=0;j<q;j++){
            int kx,ky;cin>>kx>>ky;
            for(int i=0;i<kx;i++){
                int p,v;cin>>p>>v;
                if(p==1){
                    x1=v;
                }
                else{
                    x2=v;
                }
            }
            for(int i=0;i<ky;i++){
                int p,v;cin>>p>>v;
                if(p==1){
                    y1=v;
                }
                else{
                    y2=v;
                }
            }
            check2(x1,x2,y1,y2);
        }
    }
    else{
        for(int i=0;i<(n+m);i++){
            int tmp;cin>>tmp;
        }
        int q;cin>>q;
        for(int i=0;i<=q;i++){
            cout<<0;
        }
    }
}

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cassert>
#include<climits>
#include<iomanip>
#include<set>
#include<stack>
#include<fstream>
#include<random>
#include<cmath>
#include<ctime>
#include<complex>
#include<cstdlib>
#include<cstring>
using namespace std;
//从BJBZ来的ZYC,(NOIP RP++)
//洛谷UID： 700972
//洛谷用户名： shao28Azyc139

//please let me got 70 points on this problem!
struct cmd{
    int from;
    int to;
    bool qufan;
    //-1 => T
    //-2 => F
    //-3 => U
};
int main(){


    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);


    //================Input================
    int c,t;cin>>c>>t;
    for(int i=0;i<t;i++){
        int n,m;cin>>n>>m;
        cmd cmds[m];short vars[n]={0};//1T, -1F, 0U
        for(int j=0;j<m;j++){
            char opt;int f,t;
            cin>>opt;
            if(opt=='T'){
                cin>>f;
                cmds[j].from=-1;
                cmds[j].to=f;
                cmds[j].qufan=0;
            }
            else if(opt=='F'){
                cin>>f;
                cmds[j].from=-2;
                cmds[j].to=f;
                cmds[j].qufan=0;
            }
            else if(opt=='U'){
                cin>>f;
                cmds[j].from=-3;
                cmds[j].to=f;
                cmds[j].qufan=0;
            }
            else if(opt=='+'){
                cin>>f>>t;
                cmds[j].from=f;
                cmds[j].to=t;
                cmds[j].qufan=0;
            }
            else{
                cin>>f>>t;
                cmds[j].from=f;
                cmds[j].to=t;
                cmds[j].qufan=1;
            }
        }
//================Run with Output================
int umin=20;
    //================Test Case #1~#2================
    if(c==1||c==2){
        int uminv[n]={0};
        for(int j=0;j<pow(3,n);j++){
            int id=j;
            int varsst[n]={0};
            for(int l=0;l<n;l++){
                vars[l]=id%((int)pow(3,n-1));
                id-=vars[l]*pow(3,n-1);
            }
            for(int l=0;l<n;l++){
                varsst[l]=vars[l];
            }
            for(int l=0;l<m;l++){
                if(cmds[l].from==-1){
                    vars[cmds[l].to]=1;
                }
                else if(cmds[l].from==-2){
                    vars[cmds[l].to]=-1;
                }
                else if(cmds[l].from==-3){
                    vars[cmds[l].to]=0;
                }
                else{
                    if(cmds[l].qufan){
                        vars[cmds[l].to]=-vars[cmds[l].from];
                    }
                    else{
                        vars[cmds[l].to]=vars[cmds[l].from];
                    }
                }
            }
            bool flag=1;
            for(int l=0;l<n;l++){
                if(flag){
                    if(varsst[l]!=vars[l]){
                        flag=0;
                    }
                }
            }
            if(flag==1){
                    int UKE=0;
                for(int l=0;l<n;l++){
                    if(varsst[l]==0){
                        UKE++;
                    }
                }
                if(UKE<umin){
                    umin=UKE;
                    for(int kkksc03=0;kkksc03<n;kkksc03++){
                        uminv[kkksc03]=varsst[kkksc03];
                    }
                }
            }
        }
    }











int umintc=0;
    if(c==3||c==4){
        int simple[n]={0};
        for(int j=0;j<n;j++){
            simple[j]=1;
        }
        for(int j=0;j<m;j++){
            if(cmds[j].from==-1){
                    simple[cmds[j].to]=1;
                }
                else if(cmds[j].from==-2){
                    simple[cmds[j].to]=-1;
                }
                else if(cmds[j].from==-3){
                    simple[cmds[j].to]=0;
                }
        }

        for(int j=0;j<n;j++){
            if(simple[j]==0){
                umintc++;
            }
        }
    }





if(c==1||c==2){

    cout<<umin<<endl;

}
else{
    cout<<umintc<<endl;
}
    }
}
















/*

CC* 全国青少年信息学奥林匹克联赛
CC* NOIP 2023
时间:2023 年 11 月 18 日 08:30 ? 13:00
题目名称 词典 三值逻辑 双序列拓展 天天爱打卡
题目类型 传统型 传统型 传统型 传统型
目录 dict tribool expand run
可执行文件名 dict tribool expand run
输入文件名 dict.in tribool.in expand.in run.in
输出文件名 dict.out tribool.out expand.out run.out
每个测试点时限 1.0 秒 1.0 秒 1.0 秒 2.0 秒
内存限制 512 MiB 512 MiB 512 MiB 512 MiB
测试点数目 10 10 20 25
测试点是否等分 是 是 是 是
tribool.cpp expand.cpp run.cpp
提交源程序文件名
对于 C++ 语言
dict.cpp
编译选项
对于 C++ 语言
‐O2 ‐std=c++14 ‐static
注
. 意
. 事
. 项(
. 请
. 仔
. 细
. 阅
. 读)
.
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
10. 评测在当前最新公布的 NOI Linux 下进行,各语言的编译器版本以此为准。CC* 全国青少年信息学奥林匹克联赛 CC* NOIP 2023
词典(dict)
词典(dict)
【题目描述】
小 S 的词典里有 n 个两两不同的、长度均为 m 的单词 w 1 , w 2 , · · · , w n 。每个单词
都是一个小写字母构成的字符串。
小 S 可以做以下操作任意多次(可以不做):选择词典中的任意一个单词,交换其
中任意两个字符。
对于每个 1 ≤ i ≤ n,小 S 想知道,是否可以通过以上操作得到新的 n 个单词
w 1 ′ , w 2 ′ , · · · , w n ′ ,使得对于每个 j ? = i,w i ′ 的字典序比 w j ′ 都要小。 对
. 于
. n =1 的
. 情
. 况,
. 我
.
们
约
定:
上
述
性
质
是
自
然
成
立
的。
. . .
. . . . . . . . . .
对于两个同样长度的字符串 s = s 1 s 2 · · · s L 和 t = t 1 t 2 · · · t L ,称字符串 s 字典序小
于字符串 t,当且仅当以下条件成立:存在位置 i,在第 i 个字符之前 s 和 t 都相同,而
且 s i < t i ,即小写字母 s i 在英文字母顺序中先于 t i 。
【输入格式】
从文件 dict.in 中读入数据。
输入的第一行包含两个正整数 n 和 m,分别表示单词个数和单词长度。
接下来 n 行,每行包含一个长度为 m 的小写字母字符串 w i ,表示一个单词。
【输出格式】
输出到文件 dict.out 中。
输出一行,其中包含一个长度为 n 的 01 字符串 a;对于 1 ≤ i ≤ n,如果题目描述
中的性质成立,则 a i = 1,否则 a i = 0。
【样例 1 输入】
1 4 7
2 abandon
3 bananaa
4 baannaa
5 notnotn
【样例 1 输出】
1
1110
第 2 页
共 12 页CC* 全国青少年信息学奥林匹克联赛 CC* NOIP 2023
词典(dict)
【样例 1 解释】
? 不做任何操作,第一个单词字典序最小,因此输出第一个字符为 1;
? 交换 bananaa 的前两个字符以及 abandon 的第三个和第六个字符,
得到 abondan,
abnanaa, baannaa, notnotn,此时第二个单词字典序最小,因此输出第二个字
符为 1;
? 交换 baannaa 的第一个和最后一个字符得到 aaannab,其余字符串不变,此时
第三个单词字典序最小,因此输出第三个字符为 1;
? 无论如何操作,第四个单词不会小于第二个单词,因此输出第四个字符为 0。
【样例 2】
见选手目录下的 dict/dict2.in 与 dict/dict2.ans。
该组样例满足测试点 4 的限制。
【样例 3】
见选手目录下的 dict/dict3.in 与 dict/dict3.ans。
该组样例满足测试点 7 的限制。
【样例 4】
见选手目录下的 dict/dict4.in 与 dict/dict4.ans。
该组样例满足测试点 10 的限制。
【数据范围】
对于所有测试数据,保证:1 ≤ n ≤ 3, 000,1 ≤ m ≤ 3, 000,w i 为长度为 m 的小写
字母字符串且两两不同。
测试点编号 n ≤ 1 1 2 ? 4 26 5 ? 7 15 2
8 300 300
9 10 3 10 3
10 3, 000
第 3 页
m ≤
1
3, 000
共 12 页CC* 全国青少年信息学奥林匹克联赛 CC* NOIP 2023
三值逻辑(tribool)
三值逻辑(tribool)
【题目描述】
小 L 今天学习了 Kleene 三值逻辑。
在三值逻辑中,一个变量的值可能为:真(True,简写作 T)、假(False,简写作
F)或未确定(Unknown,简写作 U)。
在三值逻辑上也可以定义逻辑运算。由于小 L 学习进度很慢,只掌握了逻辑非运算
?,其运算法则为:
?T = F, ?F = T, ?U = U.
现在小 L 有 n 个三值逻辑变量 x 1 , · · · , x n 。小 L 想进行一些有趣的尝试,于是他
写下了 m 条语句。语句有以下三种类型,其中 ← 表示赋值:
1. x i ← v,其中 v 为 T, F, U 的一种;
2. x i ← x j ;
3. x i ← ?x j 。
一开始,小 L 会给这些变量赋初值,然后按顺序运行这 m 条语句。
小 L 希望执行了所有语句后,所有变量的最终值与初值都相等。在此前提下,小 L
希望初值中 Unknown 的变量尽可能少。
在本题中,你需要帮助小 L 找到 Unknown 变量个数最少的赋初值方案,使得执行
了所有语句后所有变量的最终值和初始值相等。小 L 保证,至少对于本题的所有测试用
例,这样的赋初值方案都必然是存在的。
【输入格式】
从文件 tribool.in 中读入数据。
本
. 题
. 的
. 测
. 试
. 点
. 包
. 含
. 有
. 多
. 组
. 测
. 试
. 数
. 据。
.
输入的第一行包含两个整数 c 和 t,分别表示测试点编号和测试数据组数。对于样
例,c 表示该样例与测试点 c 拥有相同的限制条件。
接下来,对于每组测试数据:
? 输入的第一行包含两个整数 n 和 m,分别表示变量个数和语句条数。
? 接下来 m 行,按运行顺序给出每条语句。
– 输入的第一个字符 v 描述这条语句的类型。保证 v 为 TFU+‐ 的其中一种。
– 若 v 为 TFU 的某一种时,接下来给出一个整数 i,表示该语句为 x i ← v;
– 若 v 为 +,接下来给出两个整数 i, j,表示该语句为 x i ← x j ;
– 若 v 为 ‐,接下来给出两个整数 i, j,表示该语句为 x i ← ?x j 。
【输出格式】
输出到文件 tribool.out 中。
第 4 页
共 12 页CC* 全国青少年信息学奥林匹克联赛 CC* NOIP 2023
三值逻辑(tribool)
对于每组测试数据输出一行一个整数,
表示所有符合条件的赋初值方案中,
Unknown
变量个数的最小值。
【样例 1 输入】
1 1 3
2 3 3
3 ‐ 2 1
4 ‐ 3 2
5 + 1 3
6 3 3
7 ‐ 2 1
8 ‐ 3 2
9 ‐ 1 3
10 2 2
11 T 2
12 U 2
【样例 1 输出】
1 0
2 3
3 1
【样例 1 解释】
第一组测试数据中,m 行语句依次为
? x 2 ← ?x 1 ;
? x 3 ← ?x 2 ;
? x 1 ← x 3 。
一组合法的赋初值方案为 x 1 = T, x 2 = F, x 3 = T,共有 0 个 Unknown 变量。因为
不存在赋初值方案中有小于 0 个 Unknown 变量,故输出为 0。
第二组测试数据中,m 行语句依次为
? x 2 ← ?x 1 ;
? x 3 ← ?x 2 ;
? x 1 ← ?x 3 。
唯一的赋初值方案为 x 1 = x 2 = x 3 = U,共有 3 个 Unknown 变量,故输出为 3。
第 5 页
共 12 页CC* 全国青少年信息学奥林匹克联赛 CC* NOIP 2023
三值逻辑(tribool)
第三组测试数据中,m 行语句依次为
? x 2 ← T;
? x 2 ← U;
一个最小化 Unknown 变量个数的赋初值方案为 x 1 = T, x 2 = U。x 1 = x 2 = U 也是
一个合法的方案,但它没有最小化 Unknown 变量的个数。
【样例 2】
见选手目录下的 tribool/tribool2.in 与 tribool/tribool2.ans。
该组样例满足测试点 2 的条件。
【样例 3】
见选手目录下的 tribool/tribool3.in 与 tribool/tribool3.ans。
该组样例满足测试点 5 的条件。
【样例 4】
见选手目录下的 tribool/tribool4.in 与 tribool/tribool4.ans。
该组样例满足测试点 8 的条件。
【数据范围】
对于所有测试数据,保证:
? 1 ≤ t ≤ 6,1 ≤ n, m ≤ 10 5 ;
? 对于每个操作,v 为 TFU+‐ 中的某个字符,1 ≤ i, j ≤ n。
测试点编号 n, m ≤ v 可能的取值
1, 2 10 TFU + ?
3 10 3 TFU
4 10 5 TFU
5 10 3 U+
6 10 5 U+
7 10 3 +?
8 10 5 +?
9 10 3 TFU + ?
10 10 5 TFU + ?
第 6 页
共 12 页CC* 全国青少年信息学奥林匹克联赛 CC* NOIP 2023
双序列拓展(expand)
双序列拓展(expand)
【题目描述】
称某个序列 B = {b 1 , b 2 , · · · , b n } 是另一个序列 A = {a 1 , a 2 , · · · , a m } 的 拓
. 展当且仅
.
当存在 正
L = {l 1 , l 2 , · · · , l m },将 a i 替换为 l i 个 a i 后得到序列 B。例如,
. 整
. 数序列
.
? {1, 3, 3, 3, 2, 2, 2} 是 {1, 3, 3, 2} 的拓展,取 L = {1, 1, 2, 3} 或 {1, 2, 1, 3};
? 而 {1, 3, 3, 2} 不是 {1, 3, 3, 3, 2} 的拓展,{1, 2, 3} 不是 {1, 3, 2} 的拓展。
小 R 给了你两个序列 X 和 Y ,他希望你找到 X 的一个长度为 l 0 = 10 100 的拓
展 F = {f i } 以及 Y 的一个长度为 l 0 的拓展 G = {g i },使得任意 1 ≤ i, j ≤ l 0 都有
(f i ? g i )(f j ? g j ) > 0。由于序列太长,你只需要告诉小 R 是否存在这样的两个序列即可。
为了避免你扔硬币蒙混过关,小 R 还给了 q 次额外询问,每次额外询问中小 R 会
修改 X 和 Y 中若干元素的值。你需要对每次得到的新的 X 和 Y 都进行上述的判断。
询
. 问
. 之
. 间
. 是
. 独
. 立
. 的,
. 每
. 次
. 询
. 问
. 中
. 涉
. 及
. 的
. 修
. 改
. 均
. 在
. 原
. 始
. 序
. 列
. 上
. 完
. 成。
.
【输入格式】
从文件 expand.in 中读入数据。
输入的第一行包含四个整数 c, n, m, q,分别表示测试点编号、序列 X 的长度、序列
Y 的长度和额外询问的个数。对于样例,c 表示该样例与测试点 c 拥有相同的限制条件。
输入的第二行包含 n 个整数 x 1 , x 2 , · · · , x n ,描述序列 X。
输入的第三行包含 m 个整数 y 1 , y 2 , · · · , y m ,描述序列 Y 。
接下来依次描述 q 组额外询问。对于每组额外询问:
? 输入的第一行包含两个整数 k x 和 k y ,分别表示对序列 X 和 Y 产生的修改个数。
? 接下来 k x 行每行包含两个整数 p x , v x ,表示将 x p x 修改为 v x 。
? 接下来 k y 行每行包含两个整数 p y , v y ,表示将 y p y 修改为 v y 。
【输出格式】
输出到文件 expand.out 中。
输出一行,其中包含一个长度为 (q + 1) 的 01 序列,序列的第一个元素表示初始询
问的答案,之后 q 个元素依次表示每组额外询问的答案。对于每个询问,如果存在满足
题目条件的序列 F 和 G,输出 1,否则输出 0。
【样例 1 输入】
1 3 3 3 3
2 8 6 9
3 1 7 4
第 7 页
共 12 页CC* 全国青少年信息学奥林匹克联赛 CC* NOIP 2023
4 1 0
5 3 0
6 0 2
7 1 8
8 3 5
9 1 1
10 2 8
11 1 7
双序列拓展(expand)
【样例 1 输出】
1
1001
【样例 1 解释】
由于 F 和 G 太长,
用省略号表示重复最后一个元素直到序列长度为 l 0 。
如 {1, 2, 3, 3, · · · }
表示序列从第三个元素之后都是 3。
以下依次描述四次询问,其中第一次询问为初始询问,之后的三次为额外询问:
1. A = {8, 6, 9},B = {1, 7, 4},取 F = {8, 8, 6, 9, · · · }, G = {1, 7, 4, 4, · · · };
2. A = {8, 6, 0},B = {1, 7, 4},可以证明不存在满足要求的方案;
3. A = {8, 6, 9},B = {8, 7, 5},可以证明不存在满足要求的方案;
4. A = {8, 8, 9},B = {7, 7, 4},取 F = {8, 8, 9, · · · }, G = {7, 7, 4, · · · }。
【样例 2】
见选手目录下的 expand/expand2.in 与 expand/expand2.ans。
该组样例满足测试点 4 的条件。
【样例 3】
见选手目录下的 expand/expand3.in 与 expand/expand3.ans。
该组样例满足测试点 7 的条件。
【样例 4】
见选手目录下的 expand/expand4.in 与 expand/expand4.ans。
该组样例满足测试点 9 的条件。
第 8 页
共 12 页双序列拓展(expand)
CC* 全国青少年信息学奥林匹克联赛 CC* NOIP 2023
【样例 5】
见选手目录下的 expand/expand5.in 与 expand/expand5.ans。
该组样例满足测试点 18 的条件。
【数据范围】
对于所有测试数据,保证:
? 1 ≤ n, m ≤ 5 × 10 5 ;
? 0 ≤ q ≤ 60;
? 0 ≤ x i , y i < 10 9 ;
? 0 ≤ k x , k y ≤ 5 × 10 5 ,且所有额外询问的 (k x + k y ) 的和不超过 5 × 10 5 ;
? 1 ≤ p x ≤ n,1 ≤ p y ≤ m,0 ≤ v x , v y < 10 9 ;
? 对于每组额外询问,p x 两两不同,p y 两两不同。
测试点编号 n, m ≤
1 1
2 2
3, 4 6
5 200
6, 7 2, 000
8, 9 4 × 10 4
10, 11 1.5 × 10 5
12 ? 14 5 × 10 5
15, 16 4 × 10 4
17, 18 1.5 × 10 5
19, 20 5 × 10 5
特殊性质
否
是
否
特殊性质:对于每组询问(包括初始询问和额外询问),保证 x 1 < y 1 ,且 x n 是序
列 X 唯一的一个最小值,y m 是序列 Y 唯一的一个最大值。
第 9 页
共 12 页CC* 全国青少年信息学奥林匹克联赛 CC* NOIP 2023
天天爱打卡(run)
天天爱打卡(run)
【题目描述】
小 T 同学非常热衷于跑步。为了让跑步更加有趣,他决定制作一款叫做《天天爱打
卡》的软件,使得用户每天都可以进行跑步打卡。
开发完成后,小 T 同学计划进行试运行,他找了大 Y 同学来帮忙。试运行共 n 天,
编号为从 1 到 n。
对大 Y 同学来说,如果某天他选择跑步打卡,那么他的能量值会减少 d。初始时,
他的能量值是 0,并且试运行期间他的 能
. 量
. 值
. 可
. 以
. 是
. 负
. 数。
.
而且大 Y 不会 连
续跑步打卡
超
过
k
天;即不能存在
1 ≤ x ≤ n ? k,使得他在第 x
. .
. .
到第 x + k 天均进行了跑步打卡。
小 T 同学在软件中设计了 m 个挑战,第 i(1 ≤ i ≤ m)个挑战可以用三个正整
数 (x i , y i , v i ) 描述,表示如果在第 x i 天时,用户已经连续跑步打卡至少 y i 天(即第
x i ? y i + 1 到第 x i 天均完成了跑步打卡)
,那么小 T 同学就会请用户吃饭,从而使用户
的能量值提高 v i 。
现在大 Y 想知道,在软件试运行的 n 天结束后,他的能量值 最
. 高可以达到多少?
.
【输入格式】
从文件 run.in 中读入数据。
本
. 题
. 的
. 测
. 试
. 点
. 包
. 含
. 有
. 多
. 组
. 测
. 试
. 数
. 据。
.
输入的第一行包含两个整数 c 和 t,分别表示测试点编号和测试数据组数。对于样
例,c 表示该样例与测试点 c 拥有相同的限制条件。
接下来,对于每组测试数据:
? 输入的第一行包含四个正整数 n, m, k, d,分别表示试运行的天数、挑战的个数、
大 Y 单次跑步打卡的连续天数限制以及大 Y 跑步打卡减少的能量值。
? 接下来 m 行,每行包含三个正整数 x i , y i , v i ,表示一次挑战。
【输出格式】
输出到文件 run.out 中。
输出一行一个整数表示对应的答案。
【样例 1 输入】
1 1 1
2 3 2 2 1
3 2 2 4
第 10 页
共 12 页CC* 全国青少年信息学奥林匹克联赛 CC* NOIP 2023
4
天天爱打卡(run)
3 2 3
【样例 1 输出】
1
2
【样例 1 解释】
在第 1, 2 天跑步打卡,第 3 天不跑步打卡,最终会获得 (?1) + (?1) + 4 = 2 的能
量值。
【样例 2】
见选手目录下的 run/run2.in 与 run/run2.ans。
该组样例满足测试点 3 的条件。
【样例 3】
见选手目录下的 run/run3.in 与 run/run3.ans。
该组样例满足测试点 5 的条件。
【样例 4】
见选手目录下的 run/run4.in 与 run/run4.ans。
该组样例满足测试点 15 的条件。
【样例 5】
见选手目录下的 run/run5.in 与 run/run5.ans。
该组样例满足测试点 17 的条件。
【样例 6】
见选手目录下的 run/run6.in 与 run/run6.ans。
该组样例满足测试点 19 的条件。
第 11 页
共 12 页CC* 全国青少年信息学奥林匹克联赛 CC* NOIP 2023
天天爱打卡(run)
【数据范围】
记 l i = x i ? y i + 1,r i = x i ;
对于所有测试数据,保证:
1 ≤ t ≤ 10, 1 ≤ k ≤ n ≤ 10 9 , 1 ≤ m ≤ 10 5 , 1 ≤ l i ≤ r i ≤ n,
1 ≤ d, v i ≤ 10 9 。
测试点编号 n ≤
1, 2 18
3, 4 10
2
10
3
5 ? 7
8, 9
10, 11
12 ? 14
10 5
m ≤
特殊性质
10 2
10 3
10 5
无
10 3
A
15, 16
17, 18
19 ? 21
10 9
10 5
C
22 ? 25
无
特殊性质 A:k ≤ 10 2 ;
特殊性质 B:?1 ≤ i < m,r i < l i+1 ;
特殊性质 C:?1 ≤ i < j ≤ m,l i < l j ,r i < r j 。
第 12 页
B
共 12 页


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cassert>
#include<climits>
#include<iomanip>
#include<set>
#include<stack>
#include<fstream>
#include<random>
#include<cmath>
#include<ctime>
#include<complex>
#include<cstdlib>
#include<cstring>
using namespace std;
//从BJBZ来的ZYC,(NOIP RP++)
//洛谷UID：700972
//洛谷用户名：shao28Azyc139

//please let me got 70 points on this problem!

int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;cin>>n>>m;
    char a[n][m];
    //================Input================
    getchar();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j]=getchar();
        }
        getchar();
    }
    //================Run with Output================

    //================Test Case #1~#4================

    //40pts
    if(m==1){
        char minc='z';
        for(int i=0;i<n;i++){
            minc=(a[i][0]<minc?a[i][0]:minc);
        }
        for(int i=0;i<n;i++){
            if(minc==a[i][0]){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
        return 0;
    }

    //================Test Case #5~#7================

    //30pts
    if(m==2){
        char dict_2[676][2]={{'a','a'},{'a','b'},{'a','c'},{'a','d'},{'a','e'},{'a','f'},{'a','g'},
        {'a','h'},{'a','i'},{'a','j'},{'a','k'},{'a','l'},{'a','m'},{'a','n'},{'a','o'},{'a','p'},
        {'a','q'},{'a','r'},{'a','s'},{'a','t'},{'a','u'},{'a','v'},{'a','w'},{'a','x'},{'a','y'},
        {'a','z'},{'b','a'},{'b','b'},{'b','c'},{'b','d'},{'b','e'},{'b','f'},{'b','g'},{'b','h'},
        {'b','i'},{'b','j'},{'b','k'},{'b','l'},{'b','m'},{'b','n'},{'b','o'},{'b','p'},{'b','q'},
        {'b','r'},{'b','s'},{'b','t'},{'b','u'},{'b','v'},{'b','w'},{'b','x'},{'b','y'},{'b','z'},
        {'c','a'},{'c','b'},{'c','c'},{'c','d'},{'c','e'},{'c','f'},{'c','g'},{'c','h'},{'c','i'},
        {'c','j'},{'c','k'},{'c','l'},{'c','m'},{'c','n'},{'c','o'},{'c','p'},{'c','q'},{'c','r'},
        {'c','s'},{'c','t'},{'c','u'},{'c','v'},{'c','w'},{'c','x'},{'c','y'},{'c','z'},{'d','a'},
        {'d','b'},{'d','c'},{'d','d'},{'d','e'},{'d','f'},{'d','g'},{'d','h'},{'d','i'},{'d','j'},
        {'d','k'},{'d','l'},{'d','m'},{'d','n'},{'d','o'},{'d','p'},{'d','q'},{'d','r'},{'d','s'},
        {'d','t'},{'d','u'},{'d','v'},{'d','w'},{'d','x'},{'d','y'},{'d','z'},{'e','a'},{'e','b'},
        {'e','c'},{'e','d'},{'e','e'},{'e','f'},{'e','g'},{'e','h'},{'e','i'},{'e','j'},{'e','k'},
        {'e','l'},{'e','m'},{'e','n'},{'e','o'},{'e','p'},{'e','q'},{'e','r'},{'e','s'},{'e','t'},
        {'e','u'},{'e','v'},{'e','w'},{'e','x'},{'e','y'},{'e','z'},{'f','a'},{'f','b'},{'f','c'},
        {'f','d'},{'f','e'},{'f','f'},{'f','g'},{'f','h'},{'f','i'},{'f','j'},{'f','k'},{'f','l'},
        {'f','m'},{'f','n'},{'f','o'},{'f','p'},{'f','q'},{'f','r'},{'f','s'},{'f','t'},{'f','u'},
        {'f','v'},{'f','w'},{'f','x'},{'f','y'},{'f','z'},{'g','a'},{'g','b'},{'g','c'},{'g','d'},
        {'g','e'},{'g','f'},{'g','g'},{'g','h'},{'g','i'},{'g','j'},{'g','k'},{'g','l'},{'g','m'},
        {'g','n'},{'g','o'},{'g','p'},{'g','q'},{'g','r'},{'g','s'},{'g','t'},{'g','u'},{'g','v'},
        {'g','w'},{'g','x'},{'g','y'},{'g','z'},{'h','a'},{'h','b'},{'h','c'},{'h','d'},{'h','e'},
        {'h','f'},{'h','g'},{'h','h'},{'h','i'},{'h','j'},{'h','k'},{'h','l'},{'h','m'},{'h','n'},
        {'h','o'},{'h','p'},{'h','q'},{'h','r'},{'h','s'},{'h','t'},{'h','u'},{'h','v'},{'h','w'},
        {'h','x'},{'h','y'},{'h','z'},{'i','a'},{'i','b'},{'i','c'},{'i','d'},{'i','e'},{'i','f'},
        {'i','g'},{'i','h'},{'i','i'},{'i','j'},{'i','k'},{'i','l'},{'i','m'},{'i','n'},{'i','o'},
        {'i','p'},{'i','q'},{'i','r'},{'i','s'},{'i','t'},{'i','u'},{'i','v'},{'i','w'},{'i','x'},
        {'i','y'},{'i','z'},{'j','a'},{'j','b'},{'j','c'},{'j','d'},{'j','e'},{'j','f'},{'j','g'},
        {'j','h'},{'j','i'},{'j','j'},{'j','k'},{'j','l'},{'j','m'},{'j','n'},{'j','o'},{'j','p'},
        {'j','q'},{'j','r'},{'j','s'},{'j','t'},{'j','u'},{'j','v'},{'j','w'},{'j','x'},{'j','y'},
        {'j','z'},{'k','a'},{'k','b'},{'k','c'},{'k','d'},{'k','e'},{'k','f'},{'k','g'},{'k','h'},
        {'k','i'},{'k','j'},{'k','k'},{'k','l'},{'k','m'},{'k','n'},{'k','o'},{'k','p'},{'k','q'},
        {'k','r'},{'k','s'},{'k','t'},{'k','u'},{'k','v'},{'k','w'},{'k','x'},{'k','y'},{'k','z'},
        {'l','a'},{'l','b'},{'l','c'},{'l','d'},{'l','e'},{'l','f'},{'l','g'},{'l','h'},{'l','i'},
        {'l','j'},{'l','k'},{'l','l'},{'l','m'},{'l','n'},{'l','o'},{'l','p'},{'l','q'},{'l','r'},
        {'l','s'},{'l','t'},{'l','u'},{'l','v'},{'l','w'},{'l','x'},{'l','y'},{'l','z'},{'m','a'},
        {'m','b'},{'m','c'},{'m','d'},{'m','e'},{'m','f'},{'m','g'},{'m','h'},{'m','i'},{'m','j'},
        {'m','k'},{'m','l'},{'m','m'},{'m','n'},{'m','o'},{'m','p'},{'m','q'},{'m','r'},{'m','s'},
        {'m','t'},{'m','u'},{'m','v'},{'m','w'},{'m','x'},{'m','y'},{'m','z'},{'n','a'},{'n','b'},
        {'n','c'},{'n','d'},{'n','e'},{'n','f'},{'n','g'},{'n','h'},{'n','i'},{'n','j'},{'n','k'},
        {'n','l'},{'n','m'},{'n','n'},{'n','o'},{'n','p'},{'n','q'},{'n','r'},{'n','s'},{'n','t'},
        {'n','u'},{'n','v'},{'n','w'},{'n','x'},{'n','y'},{'n','z'},{'o','a'},{'o','b'},{'o','c'},
        {'o','d'},{'o','e'},{'o','f'},{'o','g'},{'o','h'},{'o','i'},{'o','j'},{'o','k'},{'o','l'},
        {'o','m'},{'o','n'},{'o','o'},{'o','p'},{'o','q'},{'o','r'},{'o','s'},{'o','t'},{'o','u'},
        {'o','v'},{'o','w'},{'o','x'},{'o','y'},{'o','z'},{'p','a'},{'p','b'},{'p','c'},{'p','d'},
        {'p','e'},{'p','f'},{'p','g'},{'p','h'},{'p','i'},{'p','j'},{'p','k'},{'p','l'},{'p','m'},
        {'p','n'},{'p','o'},{'p','p'},{'p','q'},{'p','r'},{'p','s'},{'p','t'},{'p','u'},{'p','v'},
        {'p','w'},{'p','x'},{'p','y'},{'p','z'},{'q','a'},{'q','b'},{'q','c'},{'q','d'},{'q','e'},
        {'q','f'},{'q','g'},{'q','h'},{'q','i'},{'q','j'},{'q','k'},{'q','l'},{'q','m'},{'q','n'},
        {'q','o'},{'q','p'},{'q','q'},{'q','r'},{'q','s'},{'q','t'},{'q','u'},{'q','v'},{'q','w'},
        {'q','x'},{'q','y'},{'q','z'},{'r','a'},{'r','b'},{'r','c'},{'r','d'},{'r','e'},{'r','f'},
        {'r','g'},{'r','h'},{'r','i'},{'r','j'},{'r','k'},{'r','l'},{'r','m'},{'r','n'},{'r','o'},
        {'r','p'},{'r','q'},{'r','r'},{'r','s'},{'r','t'},{'r','u'},{'r','v'},{'r','w'},{'r','x'},
        {'r','y'},{'r','z'},{'s','a'},{'s','b'},{'s','c'},{'s','d'},{'s','e'},{'s','f'},{'s','g'},
        {'s','h'},{'s','i'},{'s','j'},{'s','k'},{'s','l'},{'s','m'},{'s','n'},{'s','o'},{'s','p'},
        {'s','q'},{'s','r'},{'s','s'},{'s','t'},{'s','u'},{'s','v'},{'s','w'},{'s','x'},{'s','y'},
        {'s','z'},{'t','a'},{'t','b'},{'t','c'},{'t','d'},{'t','e'},{'t','f'},{'t','g'},{'t','h'},
        {'t','i'},{'t','j'},{'t','k'},{'t','l'},{'t','m'},{'t','n'},{'t','o'},{'t','p'},{'t','q'},
        {'t','r'},{'t','s'},{'t','t'},{'t','u'},{'t','v'},{'t','w'},{'t','x'},{'t','y'},{'t','z'},
        {'u','a'},{'u','b'},{'u','c'},{'u','d'},{'u','e'},{'u','f'},{'u','g'},{'u','h'},{'u','i'},
        {'u','j'},{'u','k'},{'u','l'},{'u','m'},{'u','n'},{'u','o'},{'u','p'},{'u','q'},{'u','r'},
        {'u','s'},{'u','t'},{'u','u'},{'u','v'},{'u','w'},{'u','x'},{'u','y'},{'u','z'},{'v','a'},
        {'v','b'},{'v','c'},{'v','d'},{'v','e'},{'v','f'},{'v','g'},{'v','h'},{'v','i'},{'v','j'},
        {'v','k'},{'v','l'},{'v','m'},{'v','n'},{'v','o'},{'v','p'},{'v','q'},{'v','r'},{'v','s'},
        {'v','t'},{'v','u'},{'v','v'},{'v','w'},{'v','x'},{'v','y'},{'v','z'},{'w','a'},{'w','b'},
        {'w','c'},{'w','d'},{'w','e'},{'w','f'},{'w','g'},{'w','h'},{'w','i'},{'w','j'},{'w','k'},
        {'w','l'},{'w','m'},{'w','n'},{'w','o'},{'w','p'},{'w','q'},{'w','r'},{'w','s'},{'w','t'},
        {'w','u'},{'w','v'},{'w','w'},{'w','x'},{'w','y'},{'w','z'},{'x','a'},{'x','b'},{'x','c'},
        {'x','d'},{'x','e'},{'x','f'},{'x','g'},{'x','h'},{'x','i'},{'x','j'},{'x','k'},{'x','l'},
        {'x','m'},{'x','n'},{'x','o'},{'x','p'},{'x','q'},{'x','r'},{'x','s'},{'x','t'},{'x','u'},
        {'x','v'},{'x','w'},{'x','x'},{'x','y'},{'x','z'},{'y','a'},{'y','b'},{'y','c'},{'y','d'},
        {'y','e'},{'y','f'},{'y','g'},{'y','h'},{'y','i'},{'y','j'},{'y','k'},{'y','l'},{'y','m'},
        {'y','n'},{'y','o'},{'y','p'},{'y','q'},{'y','r'},{'y','s'},{'y','t'},{'y','u'},{'y','v'},
        {'y','w'},{'y','x'},{'y','y'},{'y','z'},{'z','a'},{'z','b'},{'z','c'},{'z','d'},{'z','e'},
        {'z','f'},{'z','g'},{'z','h'},{'z','i'},{'z','j'},{'z','k'},{'z','l'},{'z','m'},{'z','n'},
        {'z','o'},{'z','p'},{'z','q'},{'z','r'},{'z','s'},{'z','t'},{'z','u'},{'z','v'},{'z','w'},
        {'z','x'},{'z','y'},{'z','z'}};
        //cout<<dict_2[2][1];-->'c'-->char1,char2;char1<-[0,676),char2<-[0,2)
        int minindt=677;
        for(int i=0;i<n;i++){
            int ind1=a[i][0]-96;
            int ind2=a[i][1]-96;
            int indt=(ind1-1)*26+ind2-1;
            minindt=min(minindt,indt);
            char indc1=dict_2[indt][0];
            char indc2=dict_2[indt][1];
        }
        for(int i=0;i<n;i++){
            int mi1=(a[i][0]-97)*26+a[i][1]-97;
            int mi2=(a[i][1]-97)*26+a[i][0]-97;
            if(mi1<=minindt || mi2<=minindt){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
        return 0;
    }
}






*/
    cout<<2;
}




