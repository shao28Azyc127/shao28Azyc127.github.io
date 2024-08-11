#include<bits/stdc++.h>
using namespace std;

long long n,d,a[100005],v[100005],s[100005],dp[100005];

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>d;
    for(long long i=2;i<=n;i++)
    {
        cin>>v[i];
        s[i]=s[i-1]+v[i];
    }
    s[1]=0;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(long long i=1;i<=n;i++)
    {
        for(long long j=(s[i]+d-1)/d;j<=(s[n]+d-1)/d;j++)
        {
            dp[j+1]=min(dp[j+1],dp[j]+a[i]);
            //if(dp[j-1]+a[i]==dp[j])
            //    cout<<dp[j]<<endl;
        }
    }
    cout<<dp[(s[n]+d-1)/d]<<endl;

    return 0;
}
