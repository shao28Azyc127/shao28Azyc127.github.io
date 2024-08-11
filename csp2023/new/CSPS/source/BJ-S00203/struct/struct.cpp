#include<bits/stdc++.h>
#define ll long long
#define re register
using namespace std;
inline ll read()
{
	ll res=0,op=0;
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
inline void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
}
map<string,ll>f,f1,f2[105];
ll n,m,tot,tp[105],pos[105],sz[105],ms[105];
vector<ll>t[105],p[105];
string s1,s2,fs[105],fs1[105],fs2[105][105];
int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	f["byte"]=sz[1]=ms[1]=1;
	f["short"]=sz[2]=ms[2]=2;
	f["int"]=3;
	sz[3]=ms[3]=4;
	f["long"]=tot=4;
	sz[4]=ms[4]=8;
	n=read();
	while(n--)
	{
		int op=read();
		if(op==1)
		{
			cin>>s1;
			ll k=read();
			f[s1]=++tot;
			fs[tot]=s1;
			p[tot].push_back(0);
			for(re int i=1;i<=k;++i)
			{
				cin>>s1>>s2;
				ll x=f[s1];
				f2[tot][s2]=i-1;
				fs2[tot][i-1]=s2;
				t[tot].push_back(x);
				ms[tot]=max(ms[tot],ms[x]);
			}
			for(re int i=1;i<k;++i) p[tot].push_back((p[tot][i-1]+sz[t[tot][i-1]]+ms[t[tot][i]]-1)/ms[t[tot][i]]*ms[t[tot][i]]);
			sz[tot]=(p[tot][k-1]+sz[t[tot][k-1]]+ms[tot]-1)/ms[tot]*ms[tot];
			write(sz[tot]);
			putchar(' ');
			write(ms[tot]);
			puts("");
		}
		else if(op==2)
		{
			cin>>s1>>s2;
			ll x=f[s1];
			f1[s2]=++m;
			fs1[m]=s2;
			tp[m]=x;
			pos[m]=(pos[m-1]+sz[tp[m-1]]+ms[x]-1)/ms[x]*ms[x];
			write(pos[m]);
			puts("");
		}
		else if(op==3)
		{
			cin>>s1;
			s2.clear();
			int j=0;
			while(j<s1.size()&&s1[j]!='.')
			{
				s2+=s1[j];
				++j;
			}
			ll x=f1[s2],ps=pos[x];
			x=tp[x];
			s2.clear();
			for(re int i=j+1;i<s1.size();++i)
			{
				if(s1[i]=='.')
				{
					ll y=f2[x][s2];
					ps+=p[x][y];
					x=t[x][y];
					s2.clear();
					continue;
				}
				s2+=s1[i];
			}
			if(s2.size()) ps+=p[x][f2[x][s2]];
			write(ps);
			puts("");
		}
		else
		{
			ll ps=read(),l=1,r=m;
			if(ps>=pos[m]+sz[tp[m]])
			{
				puts("ERR");
				continue;
			}
			while(l<r)
			{
				ll mid=(l+r)>>1;
				if(ps>=pos[mid+1]) l=mid+1;
				else r=mid;
			}
			ps-=pos[l];
			ll x=tp[l];
			string ans=fs1[l];
			while(x>4)
			{
				l=0;
				r=p[x].size()-1;
				while(l<r)
				{
					ll mid=(l+r)>>1;
					if(ps>=p[x][mid+1]) l=mid+1;
					else r=mid;
				}
				ps-=p[x][l];
				ans+='.'+fs2[x][l];
				x=t[x][l];
			}
			if(sz[x]>ps) cout<<ans<<'\n';
			else puts("ERR");
		}
	}
	return 0;
}