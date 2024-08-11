#include<bits/stdc++.h>
using namespace std;
int dis[100005],a[100005];
int y[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d,need,now=0,ans=0,minn=1000000000;
	cin>>n>>d;
	for(int i=1;i<n;i++)
	{
		cin>>dis[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		if(now<dis[i])
		{
			need=dis[i]-now;
			minn=min(minn,a[i]);
			now=now+d*ceil(need/double(d))-dis[i];
			ans+=ceil(need/double(d))*minn;
		}
		
	}
	cout<<ans;
	
}
