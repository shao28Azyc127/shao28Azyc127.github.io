#include<bits/stdc++.h>
using namespace std;
int f[100001], y[100001], n, d, a[100001], b[100001], b2[100001], c[100001];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin>>n>>d;
    f[1]=0;
    y[1]=0;
    for (int i=1;i<n;i++)
    {
        cin>>a[i];
    }
    b2[0]=2147483647;
    for (int i=1;i<=n;i++)
    {
        cin>>b[i];
        if (b[i]<b2[i-1])
        {
            b2[i]=b[i];
            c[i]=i;
        }
        else
        {
            b2[i]=b2[i-1];
            c[i]=c[i-1];
        }

    }
    for (int i=2;i<=n;i++)
    {
        int need=0;
        //cout<<c[i-1]<<endl;
        for (int j=c[i-1];j<i;j++)
        {
            need+=a[j];
        }
        need-=y[c[i-1]];
        //cout<<f[c[i-1]]<<' '<<b2[i-1]<<' '<<need<<' '<<d<<endl;
        f[i]=f[c[i-1]]+b2[i-1]*((need/d)+(need%d!=0));
        y[i]=d-need%d;
        if (y[i]==d)
        {
            y[i]=0;
        }
        //cout<<f[i]<<' '<<y[i]<<endl;
    }
    cout<<f[n]<<endl;
    return 0;
}
