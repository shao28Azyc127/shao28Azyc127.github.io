#include <iostream>
using namespace std;
long long a[1000005];
long long v[1000005];
long long sum[1000005];
long long s(long long x,long long y)
{
	if (x%y==0) return x/y;
	else return x/y+1;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long minx=9999999;
	long long n,d;
	long long su=0;
	cin>>n>>d;
	for (int i=1;i<=n-1;i++)
	{
		cin>>v[i];
		sum[i]=sum[i-1]+v[i];
		su+=v[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		minx=min(minx,a[i]);
	}
	if (minx==a[1])
	{
		long long mn=s(su,d)*a[1];
		cout<<mn;
		return 0;
	}
	else
	{
		long long mn=0;
		long long dms=0;
		for (int i=1;i<=n-1;i++)
		{
			if (i==1)
			{
				mn+=s(v[i],d)*a[i];
				dms+=s(v[i],d)*d;
			}
			else
			{
				if (dms<sum[i])
				{
					mn+=s(v[i],d)*a[i];
					dms+=s(v[i],d)*d;
				}
			}
		}
		cout<<mn;
	}
	return 0;
}
