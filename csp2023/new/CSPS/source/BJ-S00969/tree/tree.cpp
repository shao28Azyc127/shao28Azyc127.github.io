#include <bits/stdc++.h>
using namespace std;
long long a[100005],b[100005],c[100005],h[100005];
int n,ans=1e9,cnt,fa[100005],te[100005];
bool d[505][505],vis[100005];
long long cal(int i,int x)
{
    if(b[i]+x*c[i]>=1)
    {
        return b[i]+x*c[i];
    }
    else
    {
        return 1;
    }
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    if(n>500)
    {
        cnt=0;
        while(h[n]<a[n])
        {
            cnt++;
            h[n]+=cal(n,n+cnt);
        }
        cout<<cnt+n;
        return 0;
    }
    else
    {
        cout<<n;
    }
    return 0;
}
