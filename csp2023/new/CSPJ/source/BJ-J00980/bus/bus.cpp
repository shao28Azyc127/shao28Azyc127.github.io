#include<bits/stdc++.h>
using namespace std;
const int N=4e4+5;
int g[N][N];
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int u,v,w;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        g[u][v]=w;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(g[i][k]+g[k][j]<g[i][j])
                    g[i][j]=g[i][k]+g[k][j];
    cout<<g[1][n]<<endl;
    return 0;
}

