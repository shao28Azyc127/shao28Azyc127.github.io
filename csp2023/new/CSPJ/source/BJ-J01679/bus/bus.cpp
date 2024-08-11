#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[20005],v[20005],a[20005];
int g[20005][20005];
void bfs(int x)
{
    int t=0;
    if(x==n)
    {
        if(t%k==0){
        cout<<t;
        return ;
        }
        else
        {
        }
    }
    int now=1;
    for(int i=1;i<=m;i++)
    {
    }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>a[i];
        g[u[i]][v[i]]=a[i];
    }
    cout<<-1;
    return 0;
}
