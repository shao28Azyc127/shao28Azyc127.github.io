#include<bits/stdc++.h>
using namespace std;
int v[100005],a[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d,i;
	long long sum=0;
	cin>>n>>d;
	for(i=1;i<n;i++)
	{
		cin>>v[i];
		sum+=v[i];
	}
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<sum/d*v[1];
	return 0;
}
