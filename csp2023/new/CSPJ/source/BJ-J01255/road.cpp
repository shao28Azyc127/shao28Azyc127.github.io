#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n,d;
int v[N],a[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long sum=0,oil=0;
	bool flag1=true,flag2=true;
	cin>>n>>d;
	long long allall=0;
	for(int i=1;i<=n-1;i++)
	{
		cin>>v[i];
		if(v[i]%d!=0)
		{
			flag2=false;
		}
		allall+=v[i];
	}
	cin>>a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		if(a[1]>a[i])
		{
			flag1=false;
		}
	}
	if(flag1==true)
	{
		while(oil*d<allall)
		{
			sum+=a[1];
			oil++;
		}
		cout<<sum;
		return 0;
	}
	if(flag2==true)
	{
		for(int i=1;i<=n-1;i++)
		{
			while(oil*d<v[i])
			{
				sum+=a[i];
				oil++;
			}
			oil=0;
			if(a[i]<a[i+1])
			{
				a[i+1]=a[i];
			}
		}
		cout<<sum;
		return 0;
	}
	return 0;
}
