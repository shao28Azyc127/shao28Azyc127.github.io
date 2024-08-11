#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int v[N],a[N],s[N];
int n,d;
int ans;

void dfs(int step,int money,int oil)
{
	if(step==n)
	{ 	
		ans=min(ans,money);
		return;
	}
	oil-=v[step];
	int mini,maxi;
	if(v[step+1]-oil<=0) mini=0;
	else mini=(v[step+1]-oil)/d;
	maxi=(s[n]-s[step])/d-oil;
	for(int i=mini;i<=maxi;i++)
	{
		dfs(step+1,money+i*a[step],oil+i*d);
	}
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>d;
	s[1]=0;
	for(int i=2;i<=n;i++) 
	{
		cin>>v[i];
		s[i]=s[i-1]+v[i];
	}
	int mina=1e9;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		mina=min(a[i],mina);
	}
	if(mina==a[1])
	{
		if(s[n]%d==0) cout<<s[n]/d*a[1];
		else cout<<(s[n]/d+1)*a[1];
		return 0;
	}
	ans=1e9+5;
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}
