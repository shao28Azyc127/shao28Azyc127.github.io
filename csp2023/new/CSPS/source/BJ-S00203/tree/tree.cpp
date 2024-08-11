#include<bits/stdc++.h>
#define ll long long
#define it __int128
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
const ll inf=1e18;
int n,t[100005],fa[100005];
ll a[100005],b[100005],c[100005];
vector<int>tr[100005];
struct node
{
	int id,val;
	bool operator <(const node &x) const
	{
		return val>x.val;
	}
};
void dfs(int u)
{
	for(re int i=0;i<tr[u].size();++i)
	{
		int v=tr[u][i];
		if(v==fa[u]) continue;
		fa[v]=u;
		dfs(v);
		t[u]=min(t[u],t[v]-1);
	}
}
inline bool check(ll x)
{
	bool flag=1;
	for(re int i=1;i<=n;++i)
	{
		int l=0,r=min(x,(ll)n);
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			ll len=x-mid+1;
			if(len>=a[i]||b[i]>=(a[i]+len-1)/len||(c[i]&&(mid+x>=(inf*2+len-1)/len||(mid+x)*len/2>=(a[i]-b[i]*len+c[i]-1)/c[i]))) l=mid;
			else r=mid-1;
		}
		if(!l) return 0;
		t[i]=l;
		if(l<n) flag=0;
	}
	if(flag) return 1;
	dfs(1);
	int tm=1;
	priority_queue<node>q;
	q.push((node){1,t[1]});
	while(q.size())
	{
		int u=q.top().id,x=q.top().val;
		q.pop();
		if(x<tm) return 0;
		++tm;
		for(re int i=0;i<tr[u].size();++i)
		{
			int v=tr[u][i];
			if(v==fa[u]) continue;
			q.push((node){v,t[v]});
		}
	}
	return 1;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ll lim=0;
	n=read();
	for(re int i=1;i<=n;++i)
	{
		a[i]=read();
		b[i]=read();
		c[i]=read();
		lim=max(lim,a[i]/max(b[i],1ll));
	}
	for(re int i=1;i<n;++i)
	{
		int u=read(),v=read();
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	ll l=1,r=lim+n-1;
	while(l<r)
	{
		ll mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	write(l);
	return 0;
}