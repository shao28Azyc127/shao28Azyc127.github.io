#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int M = 1e5+5;
long long c,t,m,n,k,d;
long long tiaox[M],tiaoy[M],tiaov[M],dp[N];//qiang zhi xuan
long long suan(long long x,long long y)
{
    long long sum = -(y-x+1)*d;
    for(int i = 1;i <= m;i++)
    {
        if(x<=tiaox[i]-tiaoy[i]+1&&tiaox[i]<=y)
            sum+=tiaov[i];
    }
    return sum;
}
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>m>>k>>d;
		for(int i = 1;i <= n;i++)
			dp[i] = 0;
        for(int i = 1;i <= m;i++)
            cin>>tiaox[i]>>tiaoy[i]>>tiaov[i];
        for(int i = 1;i <= k;i++)
        {
			dp[i] = -i*d;
			for(int j = 1;j <= m;j++)
				dp[i]+=bool(tiaox[j]<=i)*tiaov[j];
		}
        for(int i = k+1;i <= n;i++)
        {
            for(int j = i-k+1;j <= i;j++)//cong j lian xu dao i
            {
				if(dp[i]<dp[j-2]+suan(j,i))
					dp[i] = dp[j-2]+suan(j,i);
			}
        }
        long long ans = 0;
        for(int i = 1;i <= n;i++)
            ans = max(ans,dp[i])/*,cout<<dp[i]<<endl*/;
        cout<<ans<<endl;
    }
    return 0;
}
