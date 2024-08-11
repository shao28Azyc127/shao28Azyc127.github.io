#include<bits/stdc++.h>
using namespace std;
namespace solve
{
	typedef long long ll;
	int read()
	{
		int res=0;
		char c=0;
		while(c<'0' || c>'9') c=getchar();
		while(c>='0' && c<='9') res*=10,res+=c-'0',c=getchar();
		return res;
	}
	const int M=100+5;
	int n,m,k,d;
	int l[M],r[M],v[M];
	void main()
	{
		n=read();
		m=read();
		k=read();
		d=read();
		for(int i=1;i<=m;++i)
		{
			int y;
			r[i]=read();
			y=read();
			v[i]=read();
			l[i]=r[i]-y;
			r[i]--;
		}
		ll ans=0;
		for(int i=1;i<(1<<n);++i)
		{
			bool err=0;
			int last=-1;
			ll val=0;
			for(int j=0;j<n;++j)
			{
				if((i&(1<<j))==0) last=j;
				else val-=d;
				if(j-last>k) err=1;
			}
			if(err) continue;
			//cout<<val<<endl;
			for(int j=1;j<=m;++j)
			{
				bool suc=1;
				//cout<<l[j]<<" "<<r[j]<<endl;
				for(int k=l[j];k<=r[j];++k)
				{
					//cout
					if((i&(1<<k))==0) suc=0;
				}
				if(suc) val+=v[j];
			}
			ans=max(ans,val);
			//cout<<val<<" "<<i<<endl;
		}
		printf("%lld",ans);
	}
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,T;
	c=solve::read();
	T=solve::read();
	while(T--)
	{
		//cout<<"?"<<endl;
		solve::main();
	}
	return 0;
}
