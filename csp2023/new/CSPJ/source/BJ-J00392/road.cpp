#include<bits/stdc++.h>
using namespace std;
int dp[100000010];
int path[100010]={0};
int price[100010];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,u;
    cin>>n>>u;
    int s=0,f;
    for(int i=1;i<n;i++)
    {
        cin>>f;
        path[i]=(f+s-1)/u+path[i-1];
        s=(f+s-1)%u+1;
    }
    for(int i=1;i<n;i++)
    {
        path[i]++;
    }
    for(int i=1;i<n;i++)
    {
        cin>>price[i];
    }
    int data=0;
    for(int i=1;i<=path[n-1];i++)
        dp[i]=1e7;
    for(int i=1;i<n;i++)
    {
        dp[path[i]]=min(dp[path[i]],dp[path[i-1]]+price[i]*(path[i]-path[i-1]));
        for(int j=path[i]+1;j<=path[n-1];j++)
        {
            dp[j]=min(dp[j],dp[j-1]+price[i]);
        }
    }
    cout<<dp[path[n-1]];
    return 0;
}
