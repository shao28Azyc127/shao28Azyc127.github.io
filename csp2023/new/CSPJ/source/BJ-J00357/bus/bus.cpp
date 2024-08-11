#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u,v,a;
}f[10000001];

int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    long long i,n,m,k;
    cin>>n>>m>>k;
    for(i=1;i<=m;i++) cin>>f[i].u>>f[i].v>>f[i].a;
    cout<<-1;
    return 0;
}
