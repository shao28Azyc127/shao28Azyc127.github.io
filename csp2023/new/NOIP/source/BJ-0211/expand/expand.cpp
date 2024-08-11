//NOIP2023 RP++
#include<iostream>
using namespace std;
const int N=10;
int C,n,m,q,ka,kb,a[N],b[N],c[N],d[N];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>C>>n>>m>>q;
	if(C<=2)
	{
		int fa=0,fb=0;
		for(int i=1;i<=n;i++)	cin>>a[i];
		for(int i=1;i<=m;i++)	cin>>b[i];
		if(n==1)
		{
			fa=1;
			n=2;
			a[2]=a[1];
		}
		if(m==1)
		{
			fb=1;
			m=2;
			b[2]=b[1];
		}
		if((a[1]<b[1]&&a[2]<b[2])||(a[1]>b[1]&&a[2]>b[2]))	cout<<1;
		else	cout<<0;
		while(q--)
		{
			for(int i=1;i<=n;i++)	c[i]=a[i];
			for(int i=1;i<=m;i++)	d[i]=b[i];
			cin>>ka>>kb;
			for(int i=1,p,v;i<=ka;i++)
			{
				cin>>p>>v;
				c[p]=v;
				if(fa)	c[3-p]=v;
			}
			for(int i=1,p,v;i<=kb;i++)
			{
				cin>>p>>v;
				d[p]=v;
				if(fb)	d[3-p]=v;
			}
			if((c[1]<d[1]&&c[2]<d[2])||(c[1]>d[1]&&c[2]>d[2]))	cout<<1;
			else	cout<<0;
		}
	}
	return 0;
}
