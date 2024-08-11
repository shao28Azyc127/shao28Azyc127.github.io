#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int n,d,a[10005];
double v[10005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int minn=100000;
    double y=0;
    int x=0;
    for(int i=1;i<=n-1;i++)
    {
        minn=min(minn,a[i]);
        a[i]=minn;
        v[i]-=y*d;
        x+=ceil(v[i]/d)*a[i];
        y=ceil(v[i]/d)-(v[i]/d);
    }
    cout<<x<<endl;
    return 0;
}
