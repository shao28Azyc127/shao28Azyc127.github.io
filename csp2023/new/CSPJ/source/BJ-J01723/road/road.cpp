#include<bits/stdc++.h>
using namespace std;
int main() 
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,d,cnt=1,sum,zh=0,ans=0,cur=0;
	cin>>n>>d;
	long long v[n],a[n+1];
	v[1]=0;
	for(long long i=2;i<=n;i++)
	{
		cin>>v[i];
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		if(i<cnt) continue;
		for(long long j=i;j<=n;j++)
		{
			if(a[j]<a[i])
			{
				cnt=j;
				break;
			}
		}
		if(cnt==i)
		{
			for(long long j=i+1;j<=n;j++)
			{
				zh+=v[i];
			}
			if(zh-(zh/d*d)<=cur)
			{
				ans=ans+(zh/d)*a[i];
			}
			else
			{
				ans=ans+(zh/d+1)*a[i];
			}
			break;
		}
		sum=0;
		for(long long j=i+1;j<=cnt;j++)
		{
			sum+=v[j];
		}
		if(sum-(sum/d*d)<=cur)
		{
			ans=ans+(sum/d)*a[i];
			cur=cur-sum+sum/d*d;
		}
		else
		{
			ans=ans+(sum/d+1)*a[i];
			cur=cur+((sum/d+1)*d)-sum;
		}
	}
	cout<<ans;
}
