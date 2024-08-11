#include <bits/stdc++.h>
#define N 200011
using namespace std;
int val[N],t,n,m;char cc[11];
int fa[N],siz[N];bool mk[N];
int get(int a){return fa[a]==a?a:fa[a]=get(fa[a]);}
void merge(int a,int b)
{//printf("merge(%d,%d)\n",a,b);
	a=get(a);b=get(b);
	if(a==b)return;
	if(siz[a]<siz[b])swap(a,b);
	fa[b]=a;siz[a]+=siz[b];
}
int Tv,Fv,Uv;
int main()
{
	freopen("tribool.in","r",stdin);freopen("tribool.out","w",stdout);
	scanf("%*d%d",&t);while(t--)
	{
		scanf("%d%d",&n,&m);Tv=n+1;Fv=-n-1;
		for(int i=1;i<=n;++i)val[i]=i;
		for(int i=0;i<=2*n+3;++i)fa[i]=i,siz[i]=1,mk[i]=0;
		while(m--)
		{
			int x,y;scanf("%s%d",cc+1,&x);
			if(cc[1]=='T')
			{
				val[x]=Tv;
			}
			else if(cc[1]=='F')
			{
				val[x]=Fv;
			}
			else if(cc[1]=='U')val[x]=Uv;
			else if(cc[1]=='+')
			{
				scanf("%d",&y);val[x]=val[y];
			}
			else
			{
				scanf("%d",&y);val[x]=-val[y];
			}
		}
		//printf("val:");for(int i=1;i<=n;++i)printf("%d ",val[i]);putchar(10);
		for(int i=1;i<=n;++i)
		{
			if(val[i]<0)
			{
				merge(2*i-1,2*-val[i]);
				merge(2*i,2*-val[i]-1);
			}
			else if(val[i]>0)
			{
				merge(2*i-1,2*val[i]-1);
				merge(2*i,2*val[i]);
			}
			else merge(2*i-1,0),merge(2*i,0);
		}
		for(int i=1;i<=n;++i)if(get(2*i-1)==get(2*i))mk[get(2*i-1)]=1;
		int ans=0;
		for(int i=0;i<=2*n+2;++i)if(get(i)==i&&mk[i])ans+=siz[i]/2;
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);return 0;
}