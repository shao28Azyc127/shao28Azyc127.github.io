#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int fun(int x,int y)
{
	if(x%y!=0)
	{
		return x/y+1;
	}
	return x/y;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	cin>>n>>d;
	for(int i=1;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	long long ans=0;
	int sum=0;
	for(int i=1;i<n;)
	{
		int x=b[i];
		long long cnt=0;
		while(b[i]>=x && i<n)
		{
			cnt=cnt+a[i];
			i++;
		}
		ans+=fun(abs(cnt-sum),d)*x;
		sum=abs(cnt-sum)%d;
	}
	cout<<ans;
	return 0;
}