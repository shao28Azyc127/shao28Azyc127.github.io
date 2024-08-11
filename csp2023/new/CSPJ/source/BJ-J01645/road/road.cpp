#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
int v[100001],a[100001],minn=2e7,d,n;
int read()
{
	int x=0,f=1;
	char ch;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
void dfs(int sta,int oil,int sum)
{
	int tots=0,toto=0,totm=0;
	if(sta==n)
	{
		minn=min(minn,sum);
		return;
	}
	if(sta==n-1)
	{
		if(oil>v[sta])
			minn=min(minn,sum);
		else
			minn=min(minn,(int)ceil((double)v[sta]/(double)d)*a[sta]+sum);
		return;
	}
	f(i,sta+1,n)
		f(j,i+1,n)
		{
			tots+=v[i-1];
			toto=ceil((double)tots/(double)d);
			totm=toto*a[sta];
			dfs(i,oil+toto,sum+totm);
		}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	d=read();
	f(i,1,n-1)
		v[i]=read();
	f(i,1,n)
		a[i]=read();
	dfs(1,0,0);
	cout<<minn;
	return 0;
}
