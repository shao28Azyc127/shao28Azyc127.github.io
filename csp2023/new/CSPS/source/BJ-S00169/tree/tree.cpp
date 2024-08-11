#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],b[100005],c[100005],u[100005],v[100005];
bool B,D;
bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]>0) return 0;
	}
	return 1;
}
struct node
{
	long long x,y;
}no[100005];
bool cmp(node x,node y)
{
	return x.x>y.x;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<n;i++)
	{
		cin>>u[i]>>v[i];
		if(u[i]!=i||v[i]!=i+1)
		{
			B=1;
		}
		if(u[i]!=1)
		{
			D=1;
		}
	}
	if(B==0)
	{
		long long day=1;
		for(;day<=n;day++)
		{
			for(int i=1;i<day;i++)
			{
				a[i]-=max(b[i]+day*c[i],1ll*1);
			}
		}
		day--;
		for(;check()==0;day++)
		{
			for(int i=1;i<=n;i++)
			{
				a[i]-=max(1ll*1,b[i]+day*c[i]);
			}
		}
		cout<<day<<endl;
	}
	if(D==0)
	{
		no[1].y=1ll*1;
		for(int i=2;i<=n;i++)
		{
			no[i].x=(a[i]+b[i]+c[i]-1)/(b[i]+c[i]);
			no[i].y=i;
		}
		sort(no+2,no+n+1,cmp);
		long long day=1;
		for(;day<=n;day++)
		{
			for(int i=1;i<day;i++)
			{
				a[no[i].y]-=max(1ll*1,b[no[i].y]+day*c[no[i].y]);
			}
		}
		day--;
		for(;check()==0;day++)
		{
			for(int i=1;i<=n;i++)
			{
				a[no[i].y]-=max(1ll*1,b[no[i].y]+day*c[no[i].y]);
			}
		}
		cout<<day<<endl;
			
	}
	return 0;
}
