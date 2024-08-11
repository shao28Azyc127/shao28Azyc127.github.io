#include<bits/stdc++.h>
using namespace std;
const int maxn=10001;
int n,m,k,d,c,t,x[maxn],y[maxn],v[maxn],p,f[maxn];
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<=m;i++)
		{
			int xt,yt,vt;
			scanf("%d%d%d",&xt,&yt,&vt);
			if((xt-vt+1)*d<vt && xt-vt+1<=k)
			{
				p++;
				x[p]=xt;
				y[p]=yt;
				v[p]=vt;
			}
		}
		int ans=0;
		for(int i=1;i<=p;i++)
		{
			ans+=(v[i]-(x[i]-y[i]+1)*d);
		}
		cout<<ans<<endl;
	}
	return 0;
}
