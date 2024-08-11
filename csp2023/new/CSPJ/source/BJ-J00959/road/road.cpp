#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long dp[100005]={0},price[100005],road[100005],n,d;
double rf;
long long sum=0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for (int i=1;i<=n-1;i++)
    {
        cin>>road[i];
    }
    for (int i=1;i<=n;i++)
    {
        cin>>price[i];
    }
    dp[2]=ceil(road[1]*1.0/d)*price[1];
    rf=ceil(road[1]*1.0/d)-road[1]*1.0/d;
    sum+=road[1];
    for (int i=3;i<=n;i++)
    {
        dp[i]=min(dp[i-1]+ceil((road[i-1]-rf*d)/d)*price[i-1],dp[i-2]+ceil((road[i-1]+road[i-2]-rf*d)/d)*price[i-2]);
        sum+=road[i-1];
        rf=ceil(sum*1.0/d)-sum*1.0/d;
    }
    cout<<dp[n]<<endl;
    return 0;
}
