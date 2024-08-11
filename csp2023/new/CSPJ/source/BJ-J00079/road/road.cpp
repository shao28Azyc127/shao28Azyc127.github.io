#include<bits/stdc++.h>
using namespace std;
int n,d,v[100010],a[100010],x[100010],y[100010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=2;i<=n;i++)
	{
		cin>>v[i];
		v[i]+=v[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=n;i++)
	{
		x[i]=INT_MAX;
		for(int j=1;j<i;j++)
		{
			int l=v[i]-v[j];
			l-=y[j];
			int s=l/d;
			if(l%d!=0)
			{
				s++;
			}
			if(x[i]>x[j]+s*a[j])
			{
				x[i]=x[j]+s*a[j];
				y[i]=s*d-l;
			}
		}
	}
	cout<<x[n];
	return 0;
}