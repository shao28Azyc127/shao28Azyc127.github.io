#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n,d;
int a[N],v[N];
int l[N];
struct node
{
	int val;
	int len;
	int t;
};
node dp[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>d;
	memset(dp,0x3f,sizeof(dp));
	dp[1].val=0;
	dp[1].len=0;
	l[1]=0;
	for(int i=1;i<n;i++)
	{
		cin>>v[i];
		l[i+1]=l[i]+v[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i].len=0;
	}
	for(int i=2;i<=n;i++)
	{
		int k,tp;
		for(int j=1;j<i;j++)
		{
			 k=l[i]-(l[j]+dp[j].len);
			 if(k%d==0) tp=(k/d)*a[j];
			 else tp=((k+d-(k%d))/d)*a[j];
			if(k<0) continue;
			if(dp[i].val>dp[j].val+tp)
			{
				dp[i].val=dp[j].val+tp;
				dp[i].len=max(0,(tp/a[j])*d-k);
			}
		}
	}
	cout<<dp[n].val<<endl;
	return 0;
}