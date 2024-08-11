#include<bits/stdc++.h>
using namespace std;
const int N=11451;
int n,m,k,flag,fl,xx;
vector<int> a[N],b[N];
int c[N],cnt=114514191;
void dfs(int x,int tim)
{
    if(x==1&&tim%k==0)
    {
        flag=1;
    }
    for(int i=0;i<c[x];i++)
    {
        if(tim>=b[x][i])
        {
            dfs(a[x][i],tim-1);
        }
    }
}
void check(int x)
{
    if(x==1)
    {
        fl=1;
    }
    for(int i=0;i<c[x];i++)
    {
        check(a[x][i]);
    }
}
void unco(int x,int m)
{
    if(x==1)
    {
        cnt=min(cnt,m);
    }
    for(int i=0;i<c[x];i++)
    {
        unco(a[x][i],m+1);
    }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a[v].push_back(u);
        b[v].push_back(w);
        c[v]++;
        xx=max(xx,w);
    }
    if(k==1)
    {
        unco(n,0);
        cout<<cnt;
        return 0;
    }
    if(m>25)
    {
        cout<<-1;
        return 0;
    }
    check(n);
    if(fl==0)
    {
        cout<<-1;
        return 0;
    }
    for(int i=0;i<xx*xx*xx;i+=k)
    {
        dfs(n,i);
        if(flag==1)
        {
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
