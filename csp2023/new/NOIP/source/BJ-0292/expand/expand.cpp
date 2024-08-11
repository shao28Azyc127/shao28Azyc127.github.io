#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int c,n,m,q;
int a[500005],b[500005];
int ina[500005],inb[500005],inn,inm;
string ans;
void solve()
{
    if(inn<inm)
    {
        for(int i=n+1;i<=m;i++)
            a[i]=a[i-1];
        inn=inm;
    }
    if(inm<inn)
    {
        for(int i=m+1;i<=n;i++)
            b[i]=b[i-1];
        inm=inn;
    }
    bool flag=1,bigg=1;
    if(a[1]==b[1])
        flag=0;
    else if(a[1]>b[1])
        bigg=1;
    else
        bigg=0;
    for(int i=1;i<=inn;i++)
    {
        if(flag==0)
            break;
        if(bigg)
            flag&=(a[i]>b[i]);
        else
            flag&=(a[i]<b[i]);
    }
    ans+=(flag?'1':'0');
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin >> c >> n >> m >> q;
    inn=n,inm=m;
    for(register int i=1;i<=n;i++)
    {
        cin >> a[i];
        ina[i]=a[i];
    }
    for(register int i=1;i<=m;i++)
    {
        cin >> b[i];
        inb[i]=b[i];
    }
    solve();
    for(register int i=1;i<=q;i++)
    {
        for(register int j=1;j<=n;j++)
            a[i]=ina[i];
        for(register int j=1;j<=m;j++)
            b[i]=inb[i];
        int kx,ky,p,v;
        cin >> kx >> ky;
        for(register int j=1;j<=kx;j++)
        {
            cin >> p >> v;
            a[p]=v;
        }
        for(register int j=1;j<=ky;j++)
        {
            cin >> p >> v;
            b[p]=v;
        }
        inn=n,inm=m;
        solve();
    }
    cout << ans << endl;
    return 0;
}
