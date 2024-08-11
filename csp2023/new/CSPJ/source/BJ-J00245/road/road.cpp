#include<bits/stdc++.h>
using namespace std;
int n,m,v[100005],a[100005],d[100005],xj,ans,ii;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m;
	for(int i=2;i<=n;i++)
	{
		cin>>v[i];
		d[i]=d[i-1]+v[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ii=a[1];
	for(int i=2;i<=n;i++)
	{
		int tmp=d[i]-ans;
		ans+=(tmp+m-1)/m*m;
		xj+=(tmp+m-1)/m*ii;
		ii=min(ii,a[i]);
	}
	cout<<xj<<endl;
	
	return 0;
}
