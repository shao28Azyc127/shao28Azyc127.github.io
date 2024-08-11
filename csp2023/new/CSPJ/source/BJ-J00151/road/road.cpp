#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
long long n,d,v[100005],a[100005],vs[100005],dp[100005],mina;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    //freopen("road1.in","r",stdin);
    cin>>n>>d;
    for(int i=1;i<n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mina=min(mina,a[i]);
    }
    for(int i=2;i<=n;i++)
        vs[i]=vs[i-1]+v[i-1];
    if(mina==a[1])
    {
        long long t=(vs[n]-vs[1])/d*a[1]+((vs[n]-vs[1])%d!=0)*a[1];
        cout<<t;
        return 0;
    }
    memset(dp,0x3f,sizeof(dp));
    dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        int id;
        for(int j=1;j<=i-1;j++)
        {
            long long t=(vs[i]-vs[j])/d*a[j]+((vs[i]-vs[j])%d!=0)*a[i];
            if(dp[i]>dp[j]+t)
            {
                id=j;
                dp[i]=dp[j]+t;
            }
        }
        cout<<id<<' ';
    }
    cout<<dp[n];
    return 0;
}
