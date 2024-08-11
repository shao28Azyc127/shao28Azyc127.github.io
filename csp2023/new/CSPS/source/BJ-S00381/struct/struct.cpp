#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,mx=8,x=-1,f[1000005],cnt;
map<ll,string> mp;
map<string,ll> id;
int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	mp[0]="ERR";
	while(n--)
	{
		ll op;
		cin>>op;
		if(op==2)
		{
			string t,name;
			cin>>t>>name;
			cnt++;
			ll l;
			if(t=="byte") l=1;
			else if(t=="short") l=2;
			else if(t=="int") l=4;
			else l=8;
			mx=max(mx,l);
			id[name]=x+1;
			mp[cnt]=name;
			cout<<x+1<<endl;
			for(ll i=x+1;i<=x+l;i++) f[i]=cnt;
			x+=mx;
		}
		else if(op==3)
		{
			string e;
			cin>>e;
			cout<<id[e]<<endl;
		}
		else
		{
			ll x;
			cin>>x;
			cout<<mp[f[x]]<<endl;
		}
	}
	return 0;
}