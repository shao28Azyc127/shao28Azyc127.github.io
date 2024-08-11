#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,d,a[100010];
long long v[100010];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=2;i<=n;i++)
    {
        cin>>v[i];
        v[i]+=v[i-1];
    }
    for(int i=1;i<=n;i++)cin>>a[i];
    int minn=a[1];
    long long last=0,sum=0;
    for(int i=2;i<=n;i++)
    {
        int cnt=(v[i]-last+d-1)/d;
        sum+=1ll*cnt*minn;
        minn=min(minn,a[i]);
        last+=1ll*cnt*d;
    }
    cout<<sum<<endl;
    return 0;
}