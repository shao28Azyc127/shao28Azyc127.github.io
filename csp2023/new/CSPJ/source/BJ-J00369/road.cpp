#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,d,v1,v2,b[maxn],a,mina=INT_MAX,ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++)
	{
		cin>>v1;
		if(v2>v1)
		{
			v2-=v1;
			continue;
		}
		v1=v1-v2;
		if(v1%d==0)
		{
			b[i]=v1/d;
			v2=0;
		}
		else
		{
			b[i]=v1/d+1;
			v2=(b[i]*d)-v1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(a<mina) mina=a;
		ans+=mina*b[i];
		//cout<<mina<<" "<<b[i]<<" "<<ans<<endl;
	}
	cout<<ans;
	return 0;
}