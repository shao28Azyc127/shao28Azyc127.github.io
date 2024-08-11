#include <iostream>
#include <cmath>

using namespace std;
int n,d,a[100005],b[10005],sum=0,dp[10005][10005],s[10005];

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    s[0]=0;
    for(int i=1;i<=n-1;i++)
    {
        cin>>a[i];
        sum+=a[i];
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    int l=1,r=sum*b[1];
    int ans=0;
    for(int i=1;i<=sum*b[1];i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=i;k++)
            {

                if(k>=b[j]&&dp[j][k-b[j]]>=s[j-1])
                dp[j][k]=max(dp[j-1][k],dp[j][k-b[j]]+d);
                else dp[j][k]=dp[j-1][k];
            }
        }
        if(dp[n][i]>=sum)
        {

            cout<<i;break;
        }
    }
    /*while(l<=r)
    {
        int mid=(l+r+1)/2;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=mid;j++)
            {
                dp[i][j]=0;
            }
        }


        //cout<<dp[n][mid/b[n]];
        if(dp[n][mid]>=sum)r=mid;
        else l=mid+1;
    }*/
    return 0;
}
