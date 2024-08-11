#include<bits/stdc++.h>
using namespace std;
int c,n,m,qq,x,y,p,q,a,b;
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>n>>m>>qq;
	cin>>a>>b;
	if(a==b)cout<<1;
		else cout<<0;
	for(int i=1;i<=qq;i++)
	{
		cin>>x>>y;
		for(int i=1;i<=x;i++)cin>>p>>q,a=q;
		for(int j=1;j<=x;j++)cin>>p>>q,b=q;
		if(a==b)cout<<1;
		else cout<<0;
	}
	return 0;
	}
