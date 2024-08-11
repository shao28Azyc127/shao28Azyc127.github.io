#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
const ll MAX=1e5+7;
ll n,d;
ll v[MAX],a[MAX];
ll sum=0;
ll ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(ll i=1;i<n;i++)
	{
		cin>>v[i];
	}
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(ll i=1;i<n;i++)
	{
		if(sum>=v[i])
		{
			sum-=v[i];
		}
		else if(a[i+1]>a[i])
		{
			ll l=(v[i]/d)+(v[i+1]/d);
			if(((v[i]%d)+(v[i+1]%d))%d!=0)
			{
				l++;
			}
			ans=ans+l*a[i];
			sum=sum+l-v[i];
		}
		else
		{
			ll l=(v[i]/d);
			if((v[i]%d)!=0)
			{
				l++;
			}
			ans+=l*a[i];
			sum=sum+l-v[i];
		}
	}
	cout<<ans;
	return 0;
}
