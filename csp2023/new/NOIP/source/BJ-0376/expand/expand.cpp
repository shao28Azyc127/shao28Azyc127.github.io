#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
const int INF=5e5+5;
int x_init[INF],y_init[INF],x[INF],y[INF],c,n,m,q,kx,ky;
void init()
{
	for(int i=1;i<=n;i++) x[i]=x_init[i];
	for(int i=1;i<=m;i++) y[i]=y_init[i];
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>x_init[i];
	for(int i=1;i<=m;i++) cin>>y_init[i];
	init();
	if((x[1]<=y[1] && x[n]>=y[m])||(x[1]>=y[1] && x[n]<=y[m])||(x[1]==y[1])||(x[n]==y[m])) cout<<0;
	else
	{
		bool flag=true;
		int last=1;
		if(x[1]<y[1])
		{
			for(int i=2;i<=n;i++)
			{
				if(x[i]>=y[last])
				{
					if(x[i]>=y[++last])
					{
						flag=false;
						break;
					}
				} 
			}
			while(++last!=m)
			{
				if(y[last]<=x[n])
				{
					flag=false;
					break;
				}
			}
		}
		else
		{
			for(int i=2;i<=n;i++)
			{
				if(x[i]<=y[last])
				{
					if(x[i]<=y[++last])
					{
						flag=false;
						break;
					}
				}
			}
			while(++last!=m)
			{
				if(y[last]>=x[n])
				{
					flag=false;
					break;
				}
			}
		}
		if(flag) cout<<1;
		else cout<<0;
	}
	while(q--)
	{
		init();
		cin>>kx>>ky;
		int p,v;
		for(int i=1;i<=kx;i++)
		{
			cin>>p>>v;
			x[p]=v;
		}
		for(int i=1;i<=ky;i++)
		{
			cin>>p>>v;
			y[p]=v;
		}
		if((x[1]<=y[1] && x[n]>=y[m])||(x[1]>=y[1] && x[n]<=y[m])||(x[1]==y[1])||(x[n]==y[m])) cout<<0;
		else
		{
			bool flag=true;
			int last=1;
			if(x[1]<y[1])
			{
				for(int i=2;i<=n;i++)
				{
					if(x[i]>=y[last])
					{
						if(x[i]>=y[++last])
						{
							flag=false;
							break;
						}
					} 
				}
				while(++last!=m)
				{
					if(y[last]<=x[n])
					{
						flag=false;
						break;
					}
				}
			}
			else
			{
				for(int i=2;i<=n;i++)
				{
					if(x[i]<=y[last])
					{
						if(x[i]<=y[++last])
						{
							flag=false;
							break;
						}
					}
				}
				while(++last!=m)
				{
					if(y[last]>=x[n])
					{
						flag=false;
						break;
					}
				}
			}
			if(flag) cout<<1;
			else cout<<0;
		}
	}
	return 0;
}