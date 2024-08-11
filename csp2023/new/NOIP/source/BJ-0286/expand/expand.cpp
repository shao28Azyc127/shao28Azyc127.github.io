#include <bits/stdc++.h>
#define maxn 500001
using namespace std;
int c,n,m,q,kx,ky,p,v,x[maxn],y[maxn];
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>y[i];
    }
    if(x[1]==y[1]) cout<<0;
    else cout<<1;
    while(q--)
    {
        cin>>kx>>ky;
        for(int i=1;i<=kx;i++)
        {
            cin>>p>>v;
            x[p]=v;
        }
        for(int i=1;i<=ky;i++)
        {
            cin>>p>>v;
            y[p]=v;
        }
        if(x[1]==y[1]) cout<<0;
        else cout<<1;
    }
    return 0;
}
