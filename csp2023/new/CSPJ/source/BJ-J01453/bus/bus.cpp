#include<bits/stdc++.h>
using namespace std;
int v[10000][10000],c[10000];
int n,m,k,a,b,x,maxx=0x3f3f;
void dfs(int x,int step)
{
    if(x==n)
    {
        if(step%k==0) maxx=min(maxx,step);
        return;
    }
    for(auto i=1;i<=c[x];i++)
    {
        dfs(v[x][i],step+1);
    }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b>>x;
        v[a][++c[a]]=b;
    }
    dfs(1,1);
    if(maxx==0x3f3f) cout<<-1;
    else cout<<maxx<<endl;
    return 0;
}
