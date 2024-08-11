#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100001],v[100001];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	cin>>n>>d;
	for(int i=1;i<n;i++)	cin>>v[i];
	ll sum=0;
	for(int i=1;i<n;i++)	sum+=v[i];
	for(int i=1;i<=n;i++)	cin>>a[i];
	ll ans=0;
	while(sum>0)
	{
		ans++;
		sum-=d;
	}
	cout<<ans*a[1];
	return 0;
}
// 1 1 1
// 2 2 2
// 3 3 3
// 4 3 1
// 5 4 4
// 6 4 2
// 7 4 1
// 8 5 5
