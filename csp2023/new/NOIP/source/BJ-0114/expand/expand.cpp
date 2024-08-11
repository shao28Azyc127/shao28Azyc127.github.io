#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5],b[5];
signed main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,n,m,q;cin>>c>>n>>m>>q;
	if(c==1)
	{
		int x,y;cin>>x>>y;
		if(x!=y) cout<<1;
		else cout<<0;
		int xx=x,yy=y;
		while(q--)
		{
			x=xx,y=yy;
			int k1,k2;cin>>k1>>k2;
			while(k1--)
			{
				int p;cin>>p>>x;
			}
			while(k2--)
			{
				int p;cin>>p>>y;
			}
			if(x!=y) cout<<1;
			else cout<<0;
		}
		return 0;
	}
	else if(c==2)
	{
		cin>>a[1]>>a[2]>>b[1]>>b[2];int a1=a[1],a2=a[2],b1=b[1],b2=b[2];
		if((a[1]-b[1])*(a[2]-b[2])>0) cout<<1;
		else cout<<0;
		while(q--)
		{
			a[1]=a1,a[2]=a2,b[1]=b1,b[2]=b2;
			int k1,k2;cin>>k1>>k2;
			while(k1--)
			{
				int x,v;cin>>x>>v;
				a[x]=v;
			}
			while(k2--)
			{
				int x,v;cin>>x>>v;
				b[x]=v;
			}
			if((a[1]-b[1])*(a[2]-b[2])>0) cout<<1;
			else cout<<0;
		}
	}
}