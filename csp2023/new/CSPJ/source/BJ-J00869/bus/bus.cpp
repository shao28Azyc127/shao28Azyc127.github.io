#include<bits/stdc++.h>
using namespace std;
int a[10010][10010];
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a[u][v]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(a[1][i]==1&&a[i][j]==1&&a[j][k]==1&&a[k][n]==1)
                {
                    cout<<k+4;
                    return 0;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[1][i]==1&&a[i][j]==1&&a[j][n]==1)
            {
                cout<<k+3;
                return 0;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[1][i]==1&&a[i][n]==1)
        {
            cout<<k+2;
            return 0;
        }
    }
    if(a[1][n]==1)cout<<k+1;
    cout<<-1;
    return 0;
}
