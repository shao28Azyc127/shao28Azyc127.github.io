#include<bits/stdc++.h>
using namespace std;
int n,d;
long long ans,fsum[100005];
int a[100005],b[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	a[1]=0;
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		fsum[i]=fsum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	int stop=1;
	long long have=0;
	bool flag=false;
	for(int i=2;i<=n;i++)
	{
		long long sumst=0,x=0,y=0,z=0,sumgo=0;
		if(i==n)
		{
			if(flag)
			{
				if((a[i]-have)%d==0) x+=(a[i]-have)/d;
				else
				{
					x+=(a[i]-have)/d;
					x++;
				}
				x*=b[i-1];
				ans+=x;
			}
			else
			{
				if((fsum[i]-fsum[stop]-have)%d==0) x+=(fsum[i]-fsum[stop]-have)/d;
				else
				{
					x+=(fsum[i]-fsum[stop]-have)/d;
					x++;
				}
				x*=b[stop];
				ans+=x;
			}
			break;
		}
		if((fsum[i]-fsum[stop]-have)%d==0)
		{
			x+=(fsum[i]-fsum[stop]-have)/d;
			z=0;
		}
		else
		{
			x+=(fsum[i]-fsum[stop]-have)/d;
			x++;
			z=((fsum[i]-fsum[stop]-have)/d+1)*d-(fsum[i]-fsum[stop]-have);
		}
		x*=b[stop];
		if((fsum[i+1]-fsum[i]-z)%d==0)
		{
			y+=(fsum[i+1]-fsum[i]-z)/d;
		}
		else
		{
			y+=(fsum[i+1]-fsum[i]-z)/d;
			y++;
		}
		y*=b[i];
		sumst=x+y;
		if((fsum[i+1]-fsum[stop]-have)%d==0)
		{
			sumgo+=(fsum[i+1]-fsum[stop]-have)/d;
		}
		else
		{
			sumgo+=(fsum[i+1]-fsum[stop]-have)/d;
			sumgo++;
		}
		sumgo*=b[stop];
		if(sumgo<sumst)
		{
			continue;
		}
		else if(sumgo==sumst)
		{
			if(b[i]<b[stop])
			{
				stop=i;
				ans+=x;
				have=z;
				if(i==n-1) flag=1;
			}
			else if(b[i]==b[stop])
			{
				continue;
			}
			else continue;
		}
		else
		{
			stop=i;
			ans+=x;
			have=z;
			if(i==n-1) flag=1;
		}
	}
	cout<<ans;
	return 0;
}