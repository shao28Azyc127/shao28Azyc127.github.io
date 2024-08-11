#include<bits/stdc++.h>
using namespace std;
long long n,d;
long long v[100005],a[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	long long dis=0;
	long long minn=10000001;
	for(int i=1;i<=n-1;i++)
	{
		cin>>v[i];
		dis+=v[i];
	}
	long long h;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<minn)
			h=i;
	}
	if(n==1)
	{
		cout<<"0";
		return 0;
	}
	if(n==2)
	{
		if(v[1]%d==0)
		{
			cout<<v[1]/d*a[1];
		}
		else
		{
			cout<<(v[1]/d+1)*a[1];
		}
		return 0;
	}
	if(h==1)
	{
		if(dis%d==0)
		{
			cout<<(dis/d)*a[1];
		}
		else
		{
			cout<<(dis/d+1)*a[1];
		}
		return 0;
	}
	long long cnt;
	long long zl=0;
	if(v[1]%d==0)
	{
		cnt=(v[1]/d)*a[1];
	}
	else
	{
		cnt=(v[1]/d+1)*a[1];
		zl=v[1]%d;
	}
	long long nm=a[1];
	for(int i=2;i<=n-1;i++)
	{
		if(a[i]<=nm)
		{
			nm=a[i];
		}
		long long ts=zl;
		if((v[i]-ts)%d==0)
		{
			cnt+=(v[i]/d)*nm;
			zl=(v[i]-ts)%d;
		}
		else
		{
			cnt+=(v[i]/d+1)*nm;
			zl=(v[i]-ts)%d;
		}
	}
	cout<<cnt;
	return 0;
}
