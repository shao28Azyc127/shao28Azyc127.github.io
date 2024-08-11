#include <bits/stdc++.h>
using namespace std;
long long a[100010],b[100010],ans,x;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,d,i,mi;
	cin>>n>>d;
	for(i=1;i<n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		cin>>b[i];
	mi=b[1];
	for(i=1;i<n;i++)
	{
		mi=min(mi,b[i]);
		if(x<a[i])
		{
			long long y=(a[i]-x+d-1)/d;
			ans+=y*mi;
			x+=y*d;
			x-=a[i];
		}
		else
			x-=a[i];
	}
	cout<<ans;
	return 0;
}
