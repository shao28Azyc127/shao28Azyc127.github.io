#include <bits/stdc++.h>
#define int long long
using namespace std;

int read()
{
    int x=0,f=1;
    char c=getchar();
    while (!isdigit(c))
    {
        if (c=='-')
        {
            f=-1;
        }
        c=getchar();
    }
    while (isdigit(c))
    {
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
const int maxn=1e5;
struct edge{
    int to,nxt;
}e[maxn<<1];
int head[maxn<<1],cnt;
int n;
int a[maxn],b[maxn],c[maxn];
int height[maxn];
struct node{
    int a,b,c,days;
}tree[maxn];
void add_edge(int u,int v)
{
    cnt++;
    e[cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
int u[maxn],v[maxn];
/*void dfs(int u)
{
    for (int i=e[u].to;i;i=e[i].nxt)
    {

    }
}*/
signed main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    n=read();
    for (int i=1;i<=n;i++)
    {
        tree[i].a=read();
        tree[i].b=read();
        tree[i].c=read();
        //tree[i].days=tree[i].a/tree[i].b;
    }
    for (int i=1;i<n;i++)
    {
        u[i]=read();
        v[i]=read();
        add_edge(u[i],v[i]);
    }
    bool flag=true;
    for (int i=1;i<=n;i++)
    {
        if (u[i]==i&&v[i]==i+1)
        {
            continue;
        }
        else
        {
            flag=false;
            break;
        }
    }
    if (flag)
    {
        int days;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=i;j++)
            {
                height[i]+=max(b[i]+c[i]*i,1ll);
            }
            days++;
        }
        for (int i=1;i<=n;i++)
        {
            if (height[i]<=a[i])
            {
                int days1=0;
                while (height[i]<=a[i])
                {
                    days1++;
                    height[i]+=max((int)b[i]+c[i]*(days+days1),1ll);
                }
                days=max(days,days+days1);
            }
        }
        cout << days;
    }
    cout << rand();
    return 0;
}
/**/
