#include<bits/stdc++.h>
#define ll long long
#define re register
using namespace std;
inline int read()
{
	int res=0,op=0;
	char ch=getchar();
	while(!isdigit(ch))
	{
		op|=ch=='-';
		ch=getchar();
	}
	while(isdigit(ch))
	{
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	return op?-res:res;
}
inline void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
}
int t,n,m,c[200005],fa[200005];
inline int find(int x)
{
	return x==fa[x]?x:(fa[x]=find(fa[x]));
}
vector<int>s[200005];
bool f[200005],f1[200005];
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	read();
	t=read();
	while(t--)
	{
		int ans=0;
		n=read();
		m=read();
		for(re int i=1;i<=(n<<1)+3;++i)
		{
			f1[i]=0;
			c[i]=i;
			fa[i]=i;
			s[i].clear();
		}
		while(m--)
		{
			char ch=getchar();
			int a1,a2,b1,b2;
			a1=read();
			a2=a1+n;
			if(ch=='T')
			{
				b1=n<<1|1;
				b2=(n<<1)+2;
			}
			else if(ch=='F')
			{
				b1=(n<<1)+2;
				b2=n<<1|1;
			}
			else if(ch=='U') b1=b2=(n<<1)+3;
			else if(ch=='+')
			{
				b1=read();
				b2=b1+n;
			}
			else
			{
				b2=read();
				b1=b2+n;
			}
			if(min(a1,a2)==min(b1,b2))
			{
				if(ch=='-') swap(c[a1],c[a2]);
				continue;
			}
			c[a1]=c[b1];
			c[a2]=c[b2];
		}
		for(re int i=1;i<=(n<<1);++i)
		{
			int x=find(i),y=find(c[i]);
			if(x!=y) fa[x]=y;
		}
		for(re int i=1;i<=(n<<1);++i) s[find(i)].push_back(i);
		for(re int i=1;i<=(n<<1)+3;++i)
		{
			bool flag=0;
			for(re int j=0;j<s[i].size();++j)
			{
				f[s[i][j]]=1;
				if(f[s[i][j]>n?(s[i][j]-n):(s[i][j]+n)])
				{
					f1[i]=1;
					break;
				}
			}
			for(re int j=0;j<s[i].size();++j) f[s[i][j]]=0;
		}
		for(re int i=1;i<=n;++i)
		{
			int x=find(i),y=find(i+n);
			if(x!=y)
			{
				fa[x]=y;
				f1[y]|=f1[x];
			}
		}
		for(re int i=1;i<=n;++i) ans+=f1[find(i)];
		write(ans);
		puts("");
	}
	return 0;
}