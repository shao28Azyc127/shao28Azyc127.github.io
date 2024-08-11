//佛祖保佑！！！
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
stack<char>q;
LL n;
string s;
LL cnt;
//乱七八糟的定义
int main(){
    //奇怪的小方法2，光看数据大约50分
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n;
    cin >> s; // 两个输入好突兀
    //通过对字符串每一个字符依次进入栈，若栈空了，
    //则为可以完全消除的字串，同时cnt++
    //决定入栈顺序，从第i个元素开始，依次入栈
    //int T = 0;
    for(LL T = 0; T < n-1; T++)
    {
        //if((n-T) % 2 != 0) continue; 
        // 剪枝，但是失败
        q.push(s[T]);
        for(LL i = T+1; i < s.size(); i++)
        {
            //判断即将入栈元素能不能与顶部元素消掉
            if(q.empty()) 
            {
                //cnt++;
                q.push(s[i]);
                continue;
            }
            if(s[i] == q.top())
            {
                q.pop();
                //将栈顶元素pop除去
                if(q.empty())
                {
                    //判断是否empty,其实在第20行判断也可以
                    cnt++;
                }
            }
            else q.push(s[i]);
        }
        while(!q.empty())
        {
            q.pop();
            //将所有空余的元素除去（最开始错这里调了半天-_-|）
        }
    }
    cout << cnt << endl;//输出结果
    return 0;//好习惯
}