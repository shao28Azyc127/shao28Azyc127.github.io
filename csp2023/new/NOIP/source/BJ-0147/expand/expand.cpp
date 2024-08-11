#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+10;
int c,n,m,q,a[maxn],b[maxn],x[maxn],y[maxn];
void init()
{
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>a[i],x[i]=a[i];
    for(int i=1;i<=m;i++) cin>>b[i],y[i]=b[i];
}
inline bool calc()
{
    if((x[1]-y[1])*(x[n]-y[m])<=0) return 0;
    int mx=0,mn=1e18;
    for(int i=1;i<=n;i++)
    {
        mx=max(mx,x[i]);
        mn=min(mn,x[i]);
    }
    int mx2=0,mn2=1e18;
    for(int i=1;i<=m;i++)
    {
        mx2=max(mx2,y[i]);
        mn2=min(mn2,y[i]);
    }
    for(int i=1;i<=m;i++)
    {
        if(x[1]>y[1] && mx<=y[i]) return 0;
        if(x[1]<y[1] && mn>=y[i]) return 0; 
    }
    if(x[1]<y[1] && mx<mx2 && mn<mn2) return 1;
    if(x[1]>y[1] && mx>mx2 && mn>mn2) return 1;
    return 0;
}
void work()
{
    cout<<calc();
    while(q--)
    {
        for(int i=1;i<=n;i++) x[i]=a[i];
        for(int i=1;i<=m;i++) y[i]=b[i];
        int kx,ky;
        cin>>kx>>ky;
        for(int i=1;i<=kx;i++)
        {
            int p,q;
            cin>>p>>q;
            x[p]=q;
        }
        for(int i=1;i<=ky;i++)
        {
            int p,q;
            cin>>p>>q;
            y[p]=q;
        }
        cout<<calc();
    }
}
signed main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    init();
    work();
    return 0;
}