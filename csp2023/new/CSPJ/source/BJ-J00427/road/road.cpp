#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int d,v[100010],n,a[100010],y,s,minn,minid,vs[100010];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<n;i++)
    {
        minn=min(minn,a[i]);
        if(minn==a[i])
        {
            minid=i;
        }
        vs[i]=vs[i-1]+v[i];
    }
    minn=min(minn,a[n]);
    if(minn==a[1])
    {
        cout<<(vs[n-1]/d)*a[1];
        return 0;
    }
    else{
        if(vs[minid]%d)
        {
            s+=(vs[minid]/d+1)*a[1];
            s+=(vs[n-1]-vs[minid-1])*a[minid];
        }
        else{
            s+=(vs[minid]/d)*a[1];
            s+=(vs[n-1]-vs[minid-1])*a[minid];
        }
    }
    cout<<s;
    return 0;
}
