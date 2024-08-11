#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,c,n,m,k,d,ans;
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m>>k>>d;ans=0;
		for(ll i=1;i<=m;i++)
		{
			ll x,y,z;
			cin>>x>>y>>z;
			if(y>k) continue;
			if(z-y*d>0) ans+=z-y*d;
		}
		cout<<ans<<endl;
	}
	return 0;
}