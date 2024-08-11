#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
    register int x = 0, f = 1;
    register char c = getchar();
    while(c < '0' || c > '9')
    {
        if(c == '-')f = -1;
        c = getchar();
    }
    while(c <= '9' && c >= '0')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

//第一下想到扩展
//数据范围只支持O(n)，那我们就对于每一个可删除的，只找他两次（删除+配对）
//感觉不好写，先看T3
//问题可以转化成有多少连续的可删除序列
//主要问题是找到一块可以删的之后如何统计答案？很简单：乘法原理
//先开干这个题再做T3
//我们用链表实现这个字符串的操作

//观察发现删除顺序不影响答案


//15:22 我们需要给这个代码来一个大换血，希望四点前能写完
//没写完，不过没有关系还有时间
//我要用30min写完他然后看后面的

//现在是17：39，我还是0分
//我开始想50分做法

//50pts:O(1)求出每一个的答案
//或是O(1)从前面的推出来这个的答案
//怎么说呢，我们发现一个可以的区间不一定有可以的子区间？
//一定有只有两个的
//so how??????
//nnd就写35了
//35都没有
//奇！
//尝试分层嵌套
//失败，写dfs
//写完，过掉了所有手造小样例

char c[2000010];

int ans;

bool f[8018][8018];

bool daoguo[8010][8018];

bool dfs(int l, int r)
{
    if(l >= r)
    {
        f[l][r] = 0;
        return 0;
    }
    if(l + 1 == r)
    {
        if(c[l] == c[r])f[l][r] = 1;
        return f[l][r];
    }
    if(f[l][r])
    {
        return f[l][r];
    }
    for(int i = l;i < r - 1;i++)
    {
        if(dfs(l, i) && dfs(i + 1, r))
        {
            //cout << l << " " << r << " " << i << "\n";
            f[l][r] = 1;
        }
    }
    if(c[l] == c[r] && dfs(l + 1, r - 1))f[l][r] = 1;
    return f[l][r];
}

signed main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    srand(time(0) + 2327);
    int n = read();
    scanf("%s", c + 1);
    dfs(1, n);
    for(int i = 1;i <= n;i++)
    {
        for(int j =i + 1;j <= n;j++)
        {
            if(f[i][j])
            {
                //cout << i << " " << j << "\n";
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}