#include <bits/stdc++.h>
#define N 2000011
#define ll long long
using namespace std;
int n,nxt[N],f[N];char s[N];
int main()
{
	freopen("game.in","r",stdin);freopen("game.out","w",stdout);
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;++i)
	{
		int p=i;
		while(p>1&&s[p-1]!=s[i])p=nxt[p-1];
		if(p<=1)nxt[i]=0,f[i]=0;
		else nxt[i]=p-1,f[i]=f[nxt[i]-1]+1;
	}
	ll ans=0;
	for(int i=1;i<=n;++i)ans+=f[i];
	printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);return 0;
}