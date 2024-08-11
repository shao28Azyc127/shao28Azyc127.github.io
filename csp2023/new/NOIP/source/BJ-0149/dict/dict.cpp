#include<bits/stdc++.h>
using namespace std;
namespace solve
{
	typedef long long ll;
	const int N=3000+5;
	const int P=1001015413;
	const int B=13331;
	ll p1[N][N],p2[N][N];
	char s1[N][N],s2[N][N];
	int n,m;
	int read()
	{
		int res=0;
		char c=0;
		while(c<'0' || c>'9') c=getchar();
		while(c>='0' && c<='9') res*=10,res+=c-'0',c=getchar();
		return res;
	}
	void reads(int x)
	{
		char c=0;
		while(c<'a' || c>'z') c=getchar();
		int i=1;
		while(c>='a' && c<='z')
		{
			s1[x][i]=c;
			c=getchar();
			//p[x][i]=(p[x][i-1]*B%P+c)%P;
			i++;
		}
	}
	bool cmp(char a,char b)
	{
		return a>b;
	}
	bool cmpstr(int a,int b,int l=1,int r=m)
	{
		if(l==r)
		{
			return s1[a][l]<s2[b][l];
		}
		int mid=(l+r)>>1;
		if(p1[a][mid]!=p2[b][mid])
		{
			return cmpstr(a,b,l,mid);
		}
		else
		{
			return cmpstr(a,b,mid+1,r);
		}
	}// -fsanitize=address,undefined -g  
	void main()
	{
		freopen("dict.in","r",stdin);
		freopen("dict.out","w",stdout);
		//ios::sync_with_stdio(0);
		n=read();
		m=read();
		for(int i=1;i<=n;++i) reads(i);
		for(int i=1;i<=n;++i)
		{
			sort(s1[i]+1,s1[i]+m+1);
			for(int j=1;j<=m;++j)
			{
				s2[i][j]=s1[i][j];
				p1[i][j]=(p1[i][j-1]*B%P+s1[i][j])%P;
			}
		}
		for(int i=1;i<=n;++i)
		{
			sort(s2[i]+1,s2[i]+m+1,cmp);
			for(int j=1;j<=m;++j)
			{
				p2[i][j]=(p2[i][j-1]*B%P+s2[i][j])%P;
			}
		}
		for(int i=1;i<=n;++i)
		{
			bool suc=1;
			for(int j=1;j<=n;++j)
			{
				if(j==i) continue;
				if(!cmpstr(i,j)) suc=0;
			}
			if(suc) putchar('1');
			else putchar('0');
		}
		putchar('\n');
	}
}
int main()
{
	solve::main();
	return 0;
}
