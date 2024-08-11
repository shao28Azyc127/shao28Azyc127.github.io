#include<bits/stdc++.h>
using namespace std;
int f[10001], v[10001], n;
bool a[10001][10001];
int dfs(int pos)
{
    //cout<<"            "<<pos<<endl;
    if (pos==1)
    {
        return 0;
    }
    if (f[pos]!=0)
    {
        return f[pos];
    }
    int ans=2147483647;
    for (int i=1;i<=n;i++)
    {
        if (v[i]==0&&a[pos][i])
        {
            //cout<<"      "<<i<<endl;
            v[i]=1;
            ans=min(ans, dfs(i));
            v[i]=0;
        }
    }
    f[pos]=ans+1;
    return ans+1;
}
int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    int m, k;
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++)
    {
        int u, v, aa;
        cin>>u>>v>>aa;
        a[u][v]=1;
        a[v][u]=1;
    }
    int d;
    v[n]=1;
    d=dfs(n);
    //for (int i=1;i<=n;i++)
    //{
    //    cout<<f[i]<<endl;
    //}
    if (d%k==0)
    {
        cout<<d<<endl;
    }
    else
    {
        cout<<d/k*k+k<<endl;
    }
    return 0;
}
