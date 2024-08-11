#include<bits/stdc++.h>
using namespace std;
int w[100005],r[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,b,minr = 1e9,idx,ans;
	long long sw = 0;
	cin>>n>>b;
	for(int i = 1;i <= n - 1;i++)
	{
		cin>>w[i];
		sw += w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin>>r[i];
		if(minr > r[i])
		{
			minr = min(minr,r[i]);
			idx = i;
		}
	}
	if(idx == 1)
	{
		if(sw % minr == 0)
		{
			cout<<sw / minr;
		}
		else
		{
			cout<<sw / minr + 1;
		}
		return 0;
	}
	ans = sw * b;
	cout<<ans;
	return 0;
}
