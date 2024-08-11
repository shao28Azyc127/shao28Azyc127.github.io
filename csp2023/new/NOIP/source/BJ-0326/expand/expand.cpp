#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=1e5+50;
int l[N],r[N],a[N],c,t,n,m,k,d,dp[N],s[N];
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int i,j,k;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m>>k>>d;
		for(i=1;i<=m;i++) cin>>l[i]>>r[i]>>a[i];
		for(i=1;i<=m;i++)
			dp[i]=-1e9;
		for(i=1;i<=m;i++)
			s[i]=s[i-1]+a[i]-(r[i]-l[i]+1)*d;
		for(i=1;i<=m;i++) {
			//int v=a[i]-(r[i]-l[i]+1)*d;
		//	int cnt=0;
			if(r[i]-l[i]+1<=k)
			{
				dp[i]=r[i]-l[i]+1;
				for(j=i;j>=1;j++)
				{
					if(r[i]-l[j]+1>k) break;
					for(k=j-1;k>=1;k--)
						if(r[k]<l[j]){
							dp[i]=max(dp[i],dp[k]+s[i]-s[j-1]);
							break;
					}
				}
			}
			dp[i]=max(dp[i-1],dp[i]);
		}
		int ans=-1e9;
		for(i=1;i<=m;i++)
			ans=max(ans,dp[i]);
		cout<<ans<<endl;
	}
	return 0;
}
