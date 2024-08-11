#include<bits/stdc++.h>
using namespace std;
long long a[100001],b[100001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,cnt=INT_MAX,ans=0,yu=0;
	cin>>n>>m;
	for(int i=1;i<n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<n;i++)
	{
		if(cnt>b[i])
			cnt=b[i];
		a[i]-=yu;
		if(a[i]%m==0)
		{
			ans+=cnt*(a[i]/m);
			yu=0;
		}
		else
		{
			ans+=cnt*(a[i]/m+1);
			yu=m*(a[i]/m+1)-a[i];
		}
	}
	cout<<ans;
	return 0;
}