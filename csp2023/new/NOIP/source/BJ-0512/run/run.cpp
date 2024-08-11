#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,k,d;
int C,T;
int x[100005],y[100005],v[100005];
bool l[100005];
int ans;
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&x[i],&y[i],&v[i]);
			if(v[i]>y[i]*d&&y[i]<=k)
			{
				for(int i=x[i]-y[i]+1;i<=x[i];i++)
				    l[i]=1;
				ans+=v[i];
			}
		}
		for(int i=1;i<=100005;i++)
		{
			if(l[i]==1)
			{
				ans-=d;
			}
		}
		ans=max(ans,0);
		printf("%d\n",ans);
	}
	return 0;
}
