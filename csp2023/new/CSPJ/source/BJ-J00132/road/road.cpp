#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,v[100000]={ },a[10000]={ },d,ans=0,cnt=0,r=0;
	double b=0;
	cin>>n>>d;
	for(int i=0;i<n-1;i++)
	{
		cin>>v[i];
	}
	int t=0;
	for(t=0;t<n;t++)
	{
		cin>>a[t];
		cnt+=a[t];
	}
	b=cnt/double(t);//ceil()
	if(a[0]<b&&a[0]<a[1])
	{
		ans+=ceil((v[0]+v[1])/double(d))*a[0];
		r+=ceil((v[0]+v[1])/double(d));
	}
	else
	{
		ans+=ceil((v[0])/double(d))*a[0];
		r+=ceil((v[0])/double(d));
	}
	for(int i=1;i<n-1;i++)
	{
		if(a[i]>b){
			if(a[i+1]>a[i])
			{
				ans+=ceil((v[i]+v[i+1])/double(d))*a[i];
				r+=ceil((v[i]+v[i+1])/double(d));
			}
			else
			{
				if(r<ceil(v[i]/double(d)))
				{
					ans+=ceil((v[i])/double(d))*a[i];
					r+=ceil((v[i])/double(d));
				}
			}
		}
		else
		{
			if(a[i+1]<a[i])
			{
				if(r<ceil(v[i]/double(d)))
				{
					ans+=ceil((v[i])/double(d))*a[i];
					r+=ceil((v[i])/double(d));
				}
				
			}
			else
			{
				ans+=ceil((v[i]+v[i+1])/double(d))*a[i];
				r+=ceil((v[i]+v[i+1])/double(d));
			}
		}
	}
	cout<<ans;
	return 0;
}
