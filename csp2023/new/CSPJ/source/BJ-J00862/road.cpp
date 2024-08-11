#include<bits/stdc++.h>
using namespace std;
int a[100005],v[100005],s[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j,n,d,mina=1e9,y=0,ans=0;
	cin>>n>>d;
	for(i=1;i<=n-1;i++)
		cin>>v[i];
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n-1;i++)
		s[i]=s[i-1]+v[i];
	s[n]=s[n-1]+v[n-1];
	for(i=1;i<=n;i++)
		mina=min(mina,a[i]);
	if(mina==1)
	{
		if(s[n-1]%d==0)
			cout<<s[n-1]/d;
		else
			cout<<s[n-1]/d+1;
		return 0;
	}
	for(i=1;i<=n-1;i++)
	{
		int nxt;
		for(j=i;j<=n;j++)
		{
			if(a[j]<a[i])
			{
				nxt=j;
				break;
			}
		}
		if(y>=s[nxt]-s[i])
		{
			y-=s[nxt]-s[i];
			continue;
		}
		else
		{
			if((s[nxt]-s[i]-y)%d==0)
			{
				ans+=(s[nxt]-s[i]-y)/d*a[i];
				y+=s[nxt]-s[i]-y;
				y-=s[i+1]-s[i];
			}
			else
			{
				ans+=((s[nxt]-s[i]-y)/d+1)*a[i];
				y+=((s[nxt]-s[i]-y)/d+1)*d;
				y-=s[i+1]-s[i];
			}
		}
		
	}
	cout<<ans;
	return 0;
}
