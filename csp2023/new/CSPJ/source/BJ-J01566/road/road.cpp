#include <bits/stdc++.h>
using namespace std;
int n,d;
int price[100010];
int f[100010];
int node[100010];

int upp(double x)
{
    if(1.0*int(x)<x)
    {
        return x/1+1;
    }
    return x;
}
long long ans=0;
int cnt=0;

void dfs(int r)
{
    if(r==1)
    {
        return ;
    }
    int minn=2147483647;
    int x=0;
    for(int i=1;i<r;i++)
    {
        if(price[i]<minn)
        {
            minn=price[i];
            x=i;
        }
    }
    node[++cnt]=x;
    dfs(x);
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>> n >>d;
    for(int i=2;i<=n;i++)
    {
        int x;
        cin>> x;
        f[i]=f[i-1]+x;
    }
    for(int i=1;i<=n;i++)
    {
        cin>> price[i];
    }
    dfs(n);
    node[++cnt]=n;
    sort(node+1,node+cnt+1);
    double last=0;
    int v=1;
    for(int i=1;i<=cnt;i++)
    {
        ans+=upp(1.0*(f[node[i]]-f[v])/d-last)*price[v];
        last=last+upp(1.0*(f[node[i]]-f[v])/d-last)-1.0*(f[node[i]]-f[v])/d;
        v=node[i];
    }
    cout << ans << endl;
    return 0;
}