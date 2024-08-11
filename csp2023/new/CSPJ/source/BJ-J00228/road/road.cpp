#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],v[N];
int nxt[N];
long long s[N];
int n,d;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for (int i=1;i<n;i++)
	{
		cin>>v[i];
		s[i+1]=s[i]+v[i];
	}
	int minn=0;
	bool flga=true;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]<a[1]) flga=false;
	}
	if (flga)
	{
		long long len=s[n]-s[1];
		long long tot=(len+d-1)/d;
		long long ans=tot*a[1];
		cout<<ans<<endl;
		return 0;
	}
	minn=a[n];
	nxt[n]=n;
	for (int i=n-1;i>=1;i--)
	{
		if (a[i]<=a[i+1]) nxt[i]=nxt[i+1];
		else nxt[i]=i+1;
	}
	int now=1;
	long long ans=0,len=0,remain=0,cnt=0;
	while (now!=n)
	{
	//	cout<<now<<" ";
		len=s[nxt[now]]-s[now];
		len-=remain;
	//	cout<<len<<" ";
		remain=0;
		cnt=(len+d-1)/d;//3
		remain+=(cnt*d-len);
		//cout<<cnt<<" "<<remain<<endl;
		ans+=(cnt*a[now]);
		now=nxt[now];
	}
	cout<<ans<<endl;
	return 0;
}