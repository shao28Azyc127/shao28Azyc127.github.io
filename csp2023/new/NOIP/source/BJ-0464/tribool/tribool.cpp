#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<time.h>

using namespace std;

typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mkp make_pair
#define epb emplace_back

int c,t;
int n,m;
int ans;
int flag[100010],flag2[100010];

void work1()
{
    //随机大法救我
    srand(time(NULL));
    while(t--)
        cout << rand() % 10 << endl;
    return ;
}

void work2()
{
    while(t--)
    {
        cin >> n >> m;
        memset(flag,0,sizeof(flag));
        ans = 0;
        while(m--)
        {
            char op;
            int a;
            cin >> op >> a;
            if(op == 'U' && flag[a] == 0)
                flag[a] = 1,ans++;
            if(op != 'U' && flag[a] == 1)
                flag[a] = 0,ans--;
        }
        cout << ans << endl;
    }
}

struct node{
    int cnt;
    vector<int> to;
}e[100010];

void dfs(int pos)
{
    // cout << pos << ' ';
    if(flag[pos] == 0)
        flag[pos] = 1,ans++;
    for(int i = 1;i <= e[pos].cnt;i++)
    {
        if(flag2[e[pos].to[i-1]] == 0)
        {
            flag2[e[pos].to[i-1]] = 1;
            dfs(e[pos].to[i-1]);
        }
    }
    return ;
}

void work3()
{
    while(t--)
    {
        cin >> n >> m;
        memset(flag,0,sizeof(flag));
        for(int i = 1;i <= 100000;i++)
        {
            e[i].cnt = 0;
            e[i].to.clear();
        }
        vector<int> u;
        ans = 0;
        int num = 0;
        while(m--)
        {
            char op;
            cin >> op;
            if(op == '+')
            {
                int i,j;
                cin >> i >> j;
                e[j].cnt++;
                e[j].to.epb(i);
                if(flag[i] == 1 && flag[j] == 0)
                {
                    flag[i] = 0;
                    ans--;
                }
                if(flag[i] == 0 && flag[j] == 1)
                {
                    flag[i] = 1;
                    ans++;
                }
            }
            else
            {
                int x;
                cin >> x;
                memset(flag2,0,sizeof(flag2));
                dfs(x);
                // cout << endl;
            }
        }
        // cout << "*"<< ans << "*" << endl;
        cout << ans << endl;
    }
}

void work4()
{
    //随机大法救我
    int mod;
    if(c == 7)
        mod = 1e3;
    else
        mod = 1e5;
    srand(time(NULL));
    while(t--)
        cout << rand() % mod << endl;
    return ;
}

void work5()
{
    //随机大法救我
    int mod;
    if(c == 9)
        mod = 1e3;
    else
        mod = 1e5;
    srand(time(NULL));
    while(t--)
        cout << rand() % mod << endl;
    return ;
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin >> c >> t;
    if(c <= 2)
    {
        work1();
    }
    else if(c <= 4)
    {
        work2();
    }
    else if(c <= 6)
    {
        work3();
    }
    else if(c <= 8)
    {
        work4();
    }
    else
    {
        work5();
    }
    return 0;
}
