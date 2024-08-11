#include <bits/stdc++.h>
using namespace std;
int v[100005];
int a[100005];
int sum[100005],m,minx;
int n,d;
int price;
int dis;
int main()
{
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)
    {
    	cin>>v[i];
    	sum[i]=v[i]+sum[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==1)
			m=a[1];
		if(a[i]<m&&i!=n)
		{
			m=a[i];
			minx=i;
		}
	}
	if(m==a[1])
	{
		if(sum[n-1]%d==0)
		{
			cout<<sum[n-1]/d;
			return 0;
		}
		else
		{
			cout<<sum[n-1]/d+1;
			return 0;
		}
	}
	int x=m,y=minx;
	int p=n;
	while(p!=1)
	{
		if((sum[p-1]-sum[minx-1])%d==0)
		{
			price+=(sum[p-1]-sum[minx-1])/d*m;
			dis+=sum[p-1]-sum[minx-1];
		}
		else
		{
			price+=((sum[p-1]-sum[minx-1])/d+1)*m;
			dis+=d*((sum[p-1]-sum[minx-1])/d+1);
		}
		p=minx;
		for(int i=1;i<=p-1;i++)
		{
			if(i==1)
			{
				m=a[1];
				minx=1;
			}
			if(a[i]<m&&i!=p-1)
			{
				m=a[i];
				minx=i;
			}
		}
	}
	if(dis-sum[n-1]>0)
	{
		if((dis-sum[n-1])/d>=1)
		{
			price-=(dis-sum[n-1])/d*x;
		}
	}
	cout<<price;
	return 0;
}
