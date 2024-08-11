#include<bits/stdc++.h>
using namespace std;
long long x[600000];
long long maxx=0, maxy=0;
long long px, py, vx, vy;
long long y[600000], a[600000], b[600000];
int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    long long c, n, m, q, cnt=0;
    long long kx, ky;
    cin>>c>>n>>m>>q;
    for(long long i=1;i<=n;i++) cin>>x[i];
    for(long long i=1;i<=m;i++) cin>>y[i];
    for(long long i=1;i<=n;i++)
    {
        if(maxx<x[i]) maxx=x[i];
    }
    for(long long i=1;i<=m;i++)
    {
        if(maxy<y[i]) maxy=y[i];
    }
    if(maxx<maxy&&x[1]<y[1]&&x[n]<y[m]) cout<<1;
    else if(maxx>maxy&&x[1]>y[1]&&x[n]>y[m]) cout<<1;
    else cout<<0;
    for(long long i=1;i<=n;i++) a[i] = x[i];
    for(long long j=1;j<=m;j++) b[j] = y[j];
    for(long long i=0;i<q;i++)
    {
        for(long long i=1;i<=n;i++) a[i] = x[i];
        for(long long j=1;j<=m;j++) b[j] = y[j];
        cin>>kx>>ky;
        for(long long j=0;j<kx;j++)
        {
            cin>>px>>vx;
            a[px]=vx;
        }
        for(long long j=0;j<ky;j++)
        {
            cin>>py>>vy;
            b[py]=vy;
        }
        maxx=0, maxy=0;
        for(long long i=1;i<=n;i++)
        {
            if(maxx<a[i]) maxx=a[i];
        }
        for(long long i=1;i<=m;i++)
        {
            if(maxy<b[i]) maxy=b[i];
        }
        if(maxx<maxy&&a[1]<b[1]&&a[n]<b[m]) cout<<1;
        else if(maxx>maxy&&a[1]>b[1]&&a[n]>b[m]) cout<<1;
        else cout<<0;
    }
    return 0;
}
