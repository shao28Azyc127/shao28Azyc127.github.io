#include<stdio.h>
#include<string.h>
using namespace std;
const int NR=2e6+5;
char s[NR];
int fa[NR];
int lst[NR][26];
int cnt[NR];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n;scanf("%d",&n);
	scanf("%s",s+1);
	memset(lst,-1,sizeof(lst));
	for(int i=0;i<=n;++i) fa[i]=-1;
	long long ans=0;
	lst[1][s[1]-'a']=1;
	for(int i=2;i<=n;++i)
	{
		int x=lst[i-1][s[i]-'a'];
		if(x!=-1) fa[i]=x-1;
		//printf("%d %d\n",i,fa[i]);
		if(x!=-1) ans+=(cnt[i]=cnt[x-1]+1);
		if(x!=-1)
		{
			for(int j=0;j<26;++j) lst[i][j]=lst[x-1][j];
		} 
		lst[i][s[i]-'a']=i;
	}
	printf("%lld\n",ans);
	return 0;
}