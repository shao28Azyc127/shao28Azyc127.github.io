#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,ll> m;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	ll n,c=0,i,ans=0,cnt=0;
	cin>>n;
	if(n<4)
	{
		cout<<n<<" "<<n;
		return 0;
	}
	while(c<n)
	{
		cnt++;
		ll t=2;
		for(i=1;i<=n;i++)
		{
			if(!m.count(i)&&t==2)
			{
				c++;
				t=0;
				m[i]=1;
				if(i==n) ans=cnt;
			}
			else if(!m.count(i)) t++;
		}
	}
	cout<<cnt<<" "<<ans;
	return 0;
}