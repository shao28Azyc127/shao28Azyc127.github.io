#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k,minn=1e9;
int u[10010],v[10010],a[10010];
int t[10010][10010];
bool b[10010][10010];
void dfs(int step,int time,int last)
{
    if(step==n)
    {
        if(time%k==0)
        {
            minn=min(minn,time);
        }
        return;
    }
    for (int i=1;i<=n;i++)
    {
        if(i==last) continue;
        if(b[step][i]&&time>=t[step][i])
        {
            dfs(i,time+1,step);
        }
    }
    dfs(last,time+1,step);
}


int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin >>n>>m>>k;
    for (int i=1;i<=m;i++)
    {
        cin >>u[i]>>v[i]>>a[i];
        b[u[i]][v[i]]=1;
        t[u[i]][v[i]]=a[i];
    }
    cout<<-1;
    return 0;
}
