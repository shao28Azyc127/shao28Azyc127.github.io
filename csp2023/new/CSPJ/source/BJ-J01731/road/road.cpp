#include <iostream>
using namespace std;
int v[100001];
int a[100001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	cin>>n>>d;
	int sum=0;
	int ans=0;
	for(int i=1;i<n;i++)
	{
		cin>>v[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		if(sum>=v[i])
		{
		    sum-=v[i];
			continue;
		}
		int t=i+1;
		int l=v[i];
		while(a[i]<a[t])
		{
			l+=v[t];
			t++;
		}
		l-=sum;
		if(l%d==0)
		{
			ans+=l/d*a[i];
			sum+=l-v[i];
		}
		else
		{
			ans+=(l/d+1)*a[i];
			sum+=(l/d+1)*d-v[i];
		}
	}
	cout<<ans;
	return 0;
}