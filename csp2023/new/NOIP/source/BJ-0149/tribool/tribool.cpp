#include<bits/stdc++.h>
using namespace std;
namespace solve
{
	const int N=100000+5;
	int read()
	{
		int res=0;
		char c=0;
		while(c<'0' || c>'9') c=getchar();
		while(c>='0' && c<='9') res*=10,res+=c-'0',c=getchar();
		return res;
	}
	int n,m;
	int val[N];
	vector<int> vv;
	char col[N*2];
	vector<int> adj[N*2];
	inline char inv(char x)
	{
		if(x=='T') return 'F';
		if(x=='F') return 'T';
		if(x=='U') return 'U';
		return 'E';
	}
	bool dfs(int u)
	{
		vv.push_back(u);
		if(u<=n&&(!col[u+n]))
		{
			col[u+n]=inv(col[u]);
			if(!dfs(u+n)) return false;
		}
		else if(u>n&&(!col[u-n]))
		{
			col[u-n]=inv(col[u]);
			if(!dfs(u-n)) return false;
		}
		for(int nxt:adj[u])
		{
			if(!col[nxt])
			{
				col[nxt]=col[u];
				if(!dfs(nxt)) return false;
			}
			else
			{
				if(col[nxt]!=col[u]) return false;
			}
		}
		return true;
	}
	void main()
	{
		n=read();
		m=read();
		for(int i=1;i<=n*2;++i) adj[i].clear();
		for(int i=1;i<=n;++i) val[i]=i;
		for(int i=1;i<=n*2;++i) col[i]=0;
		while(m--)
		{
			char opt=getchar();
			if(opt=='-')
			{
				int x,y;
				x=read();//9:31
				y=read();
				if(val[y]>n)
				{
					if(val[y]==n+1) val[x]=n+2;
					else if(val[y]==n+2) val[x]=n+1;
					else val[x]=val[y];
				}
				else val[x]=-val[y];
			}
			else if(opt=='+')
			{
				int x,y;
				x=read();//9:31
				y=read();
				val[x]=val[y];
			}
			else if(opt=='T')
			{
				int x;
				x=read();
				val[x]=n+1;
			}
			else if(opt=='F')
			{
				int x;
				x=read();
				val[x]=n+2;
			}
			else if(opt=='U')
			{
				int x;
				x=read();
				val[x]=n+3;
			}
			else
			{
				m++;
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			if(val[i]<0)
			{
				//if(val[i])
				adj[i].push_back(-val[i]+n);
				adj[-val[i]+n].push_back(i);
			}
			else if(val[i]<=n)
			{
				adj[i].push_back(val[i]);
				adj[val[i]].push_back(i);
			}
			else if(val[i]==n+1)
			{
				col[i]='T';
				col[i+n]='F';
			}
			else if(val[i]==n+2)
			{
				col[i]='F';
				col[i+n]='T';
			}
			else
			{
				col[i]='U';
				col[i+n]='U';
				//ans++;
			}
		}
			/*for(int i=1;i<=n;++i)
			{
				//if(col[i]!=)
				cerr<<(col[i]?col[i]:'0')<<" ";
			}
			cerr<<endl;
		for(int i=1;i<=n*2;++i)
		{
			for(int to:adj[i])
			{
				cout<<to<<" ";
			}
			cout<<endl;
		}*/
		for(int i=1;i<=n;++i)
		{
			if(!col[i])
			{
				col[i]='T';
				if(dfs(i))
				{
					vv.clear();
					continue;
				}
				for(int p:vv)
				{
					col[p]=0;
				}
				vv.clear();
				col[i]='F';
				if(dfs(i))
				{
					vv.clear();
					continue;
				}
				for(int p:vv)
				{
					col[p]=0;
				}
				vv.clear();
				col[i]='U';
				//ans++;
				dfs(i);
				vv.clear();
			}
			/*for(int i=1;i<=n*2;++i)
			{
				
				cout<<(col[i]?col[i]:'0')<<" ";
			}
			cout<<endl;*/
		}
		for(int i=1;i<=n;++i)
		{
			if(col[i]=='U')
			{
				ans++;
			}
			//cerr<<(col[i])<<" ";
		}
		//cerr<<endl;
		printf("%d\n",ans);
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,T;
	c=solve::read();
	T=solve::read();
	while(T--) solve::main();
	return 0;
}
