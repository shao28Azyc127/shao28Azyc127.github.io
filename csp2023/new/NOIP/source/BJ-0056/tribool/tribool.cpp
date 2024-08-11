#include<cstdio>
char buf[1<<21],*p1=buf,*p2=buf;
inline char Getc(){if(p1==p2){p2=(p1=buf)+fread(buf,1,1<<21,stdin);if(p1==p2) return EOF;}return *p1++;}
inline char rd_c()
{
	static char ch;
	while(ch=Getc(),ch!='T'&&ch!='U'&&ch!='F'&&ch!='+'&&ch!='-');
	return ch;
}
inline int rd()
{
	static char ch;
	while(ch=Getc(),ch<'0'||ch>'9');
	int x=ch^'0';
	while(ch=Getc(),'0'<=ch&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');
	return x;
}
const int N=100010;
int a[N],n,m;
int head[N],to[N<<1],nxt[N<<1],val[N<<1],p;
inline void add(int u,int v,int w){++p;to[p]=v,val[p]=w,nxt[p]=head[u];head[u]=p;}
int stk[N],sp;
bool vis[N];
int cnt,cnt2;
bool flag,z;
void dfs(int u,int e)
{
	vis[u]=true,++cnt,cnt2+=((a[u]>>1)==n+2),stk[++sp]=u;
	for(int i=head[u];i;i=nxt[i])
	{
		if(i==(e^1)) continue;
		int v=to[i];
		if(!vis[v]) dfs(v,i);
		else if(!z)
		{
			// puts("###");
			z=true;
			bool st=0;
			int c=0;
			for(int j=1;j<=sp;++j)
			{
				if(stk[j]==v) st=true;
				if(st)
				{
					// printf("???%d %d\n",stk[j],(j<sp)?stk[j+1]:v);
					// for(int k=head[stk[j]];k;k=nxt[k])
						// if(to[k]==(((j<sp)?stk[j+1]:v))) c+=val[k];
					c+=a[stk[j]]&1;
				}
			}
			if(c&1) flag=true;
		}
	}
	--sp;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	rd();
	int T=rd();
	while(T--)
	{
		n=rd(),m=rd();
		for(int i=1;i<=n;++i) a[i]=i*2,vis[i]=false,head[i]=0;
		p=1;
		while(m--)
		{
			char opt=rd_c();
			int x=rd(),y;
			if(opt=='T') a[x]=(n+1)*2;
			else if(opt=='F') a[x]=(n+1)*2+1;
			else if(opt=='U') a[x]=(n+2)*2;
			else if(opt=='+') y=rd(),a[x]=a[y];
			else if(opt=='-') y=rd(),a[x]=a[y]^1;
		}
		// for(int i=1;i<=n;++i) printf("#%d ",a[i]);
		// puts("");
		for(int i=1;i<=n;++i) if(a[i]<=n*2+1) add(i,a[i]>>1,a[i]&1),add(a[i]>>1,i,a[i]&1);
		int ans=0;
		for(int i=1;i<=n;++i)
			if(!vis[i])
			{
				cnt=cnt2=0,flag=z=false;
				dfs(i,0);
				// if(flag) puts("####");
				if(cnt2||flag) ans+=cnt;
			}
		printf("%d\n",ans);
	}
	return 0;
}