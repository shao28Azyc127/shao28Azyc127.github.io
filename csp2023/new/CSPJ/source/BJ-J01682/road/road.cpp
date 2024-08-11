#include <bits/stdc++.h>
using namespace std;
int n,d;
int a[100005],v[100005];
long long he[100005];
struct Node
{
    int yuan;
    int left; 
} dp[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for (int i=1;i<n;i++)
    {
        cin>>v[i];
        he[i]=he[i-1]+v[i];
    }
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (i!=1)
        {
            dp[i].yuan=100000005;
        }
        else
        {
            dp[i].yuan=0;
        }
        for (int j=1;j<i;j++)
        {
            int yo;
            long long lu=he[i-1]-he[j-1]-dp[j].left;
            if (lu%d==0)
            {
                yo=lu/d;
            }
            else
            {
                yo=lu/d+1;
            }

            if (dp[i].yuan>dp[j].yuan+yo*a[j])
            {
                dp[i].left=(yo)*d-lu;
            }
            dp[i].yuan=min(dp[i].yuan,dp[j].yuan+yo*a[j]);

        }

    }
    cout<<dp[n].yuan;

    return 0;
}