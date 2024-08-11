#include<cstdio>
const int N=3010;
char s[N];
char a[N<<1][N];
int stk[26][N<<1],cnt[26];
int p[N<<1],val[N<<1];
int n,m;
inline bool cmp(int x,int y)
{
	for(int i=1;i<=m;++i) if(a[x][i]!=a[y][i]) return false;
	return true;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(int j=0;j<26;++j) cnt[j]=0;
		for(int j=1;j<=m;++j) ++cnt[s[j]-'a'];
		for(int j=0,c=0;j<26;++j)
			for(int k=1;k<=cnt[j];++k) a[i*2-1][++c]=j;
		for(int j=25,c=0;j>=0;--j)
			for(int k=1;k<=cnt[j];++k) a[i*2][++c]=j;
	}
	for(int i=1;i<=n*2;++i) p[i]=i;
	for(int i=m;i>=1;--i)
	{
		for(int j=0;j<26;++j) cnt[j]=0;
		for(int j=1;j<=n*2;++j)
		{
			int x=a[p[j]][i];
			stk[x][++cnt[x]]=p[j];
		}
		for(int j=0,c=0;j<26;++j) for(int k=1;k<=cnt[j];++k) p[++c]=stk[j][k];
	}
	for(int i=1,c=0;i<=n*2;)
	{
		++c;
		int j=i;
		while(j<n*2&&cmp(p[i],p[j+1])) ++j;
		for(;i<=j;++i) val[p[i]]=c;
	}
	for(int i=1;i<=n;++i)
	{
		bool flag=true;
		for(int j=1;j<=n;++j) if(j!=i&&val[i*2-1]>=val[j*2]) flag=false;
		putchar(flag?'1':'0');
	}
	puts("");
	return 0;
}