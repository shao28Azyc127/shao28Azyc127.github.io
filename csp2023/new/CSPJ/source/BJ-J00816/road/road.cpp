#include<bits/stdc++.h>
using namespace std;
int v[100010],a[100010];
long long sum[100010];
long long dp[100010];
int main(){
    int n,d;
    cin>>n>>d;
    v[1]=0;
    sum[1]=0;
    for(int i=2;i<=n;i++)
    {
        cin>>v[i];
        sum[i]=sum[i-1]+v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        long long minn=1e10;
        for(int j=1;j<i;j++)
        {
            long long yu=(sum[i]-sum[j])%d;
            if(yu!=0)
            {
                yu=1;
            }
            long long sn=dp[j]+(sum[i]-sum[j])*a[j]/d+yu*a[j];
            minn=min(sn,minn);
        }
        dp[i]=minn;
    }
    cout<<dp[n];
    return 0;
}
