#include<cstdio>
const int N=2000010;
char a[N];
int mch[N],f[N];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n;
	scanf("%d%s",&n,a+1);
	long long ans=0;
	for(int i=1;i<=n;++i)
	{
		int j=i-1;
		while(j>0&&a[j]!=a[i]) j=mch[j]-1;
		if(j>0&&a[j]==a[i]) mch[i]=j,f[i]=f[j-1]+1,ans+=f[i];
	}
	printf("%lld\n",ans);
	return 0;
}