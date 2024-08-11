/*
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e5+5;
int tr[MAXN<<6],ls[MAXN<<6],rs[MAXN<<6],u,v,n,w[MAXN],cnt,hd[MAXN];
vector<int> E[MAXN];
ll to[MAXN],a[MAXN],b[MAXN],c[MAXN];
inline int read()
{
	int p=1,q=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') p=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		q=(q<<1)+(q<<3)+(ch^48),ch=getchar();
	return p*q;
}
bool chck(ll i,ll x,ll y,ll z,ll l,ll r)
{
	if(z==0) return (x<=y*(r-l+1));
	if(z>0)
	{
		x-=y*(r-l+1);
		ll tmp=r*(r+1)/2-l*(l-1)/2;
		return x/(double)tmp<=z;
	}
	if(z<0)
	{
		ll R=min(r+1,to[i]);
		if(l>=R) return (r-l+1>=x);
		x-=(r-R+1),r=R-1;
		x-=(r-l+1)*y;
		ll tmp=r*(r+1)/2-l*(l-1)/2;
		return x/(double)tmp<=z;
	}
	return 0;
}
void get_val(int id,int u)
{
	int l=1,r=n;
	w[id]=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(chck(id,a[id],b[id],c[id],mid,u)) w[id]=mid,l=mid+1;
		else r=mid-1;
	}
}
void bd(int &u,int l,int r,int x)
{
	if(!u) u=++cnt;
	tr[u]=1;
	if(l==r) return;
	int mid=(l+r)/2;
	if(mid>=x) bd(ls[u],l,mid,x);
	else bd(rs[u],mid+1,r,x);
}
int merge(int &u,int v,int l,int r,int x)
{
	if(!x)
	{
		if(!u) u=v;
		if(!u) return 0;
	}
	if(!u) swap(u,v);
	if(!u) u=++cnt;
	if(l==r)
	{
		tr[u]+=tr[v];
		x+=max(0,tr[u]-1);
		tr[u]=min(tr[u],1);
		if(!x) return 0;
		if(tr[u]) return x;
		tr[u]++;
		return max(0,x-1);
	}
	int mid=(l+r)/2;
	int tmp=merge(rs[u],rs[v],mid+1,r,x);
	tmp=merge(ls[u],ls[v],l,mid,tmp);
	tr[u]=tr[ls[u]]+tr[rs[u]];
	return tmp;
}
bool dfs(int u,int fa)
{
	bd(hd[u],1,n,w[u]);
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v==fa) continue;
		if(!dfs(v,u)) return 0;
		int tmp=merge(hd[u],hd[v],1,n,0);
		if(merge(hd[u],hd[v],1,n,0)) return 0;
		cout<<u<<"->"<<v<<" "<<tmp<<' '<<tr[hd[u]]<<endl;
	}
	return 1;
}
bool check(int d)
{
	for(int i=1;i<=n;i++)
	{
		get_val(i,d);
		if(!w[i]) return 0;
	}
	memset(tr,0,sizeof(tr));
	memset(ls,0,sizeof(ls));
	memset(rs,0,sizeof(rs));
	cnt=0;
	return dfs(1,0);
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read(),b[i]=read(),c[i]=read();
		if(c[i]<0)
		{
			to[i]=b[i]/(-c[i]);
			while(b[i]+to[i]*c[i]>1) to[i]++;
		}
	}
	for(int i=1;i<n;i++)
	{
		u=read(),v=read();
		E[u].push_back(v),E[v].push_back(u);
		// cout<<u<<' '<<v<<endl;
	}
	int l=n,r=1e9,find;
	while(l<=r)
	{
		int mid=(l+r)/2;
		// cout<<l<<' '<<r<<" "<<mid<<endl;
		if(check(mid)) r=mid-1,find=mid;
		else l=mid+1;
	}
	cout<<find;
	return 0;
}
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e5+5;
int tr[MAXN<<6],ls[MAXN<<6],rs[MAXN<<6],u,v,n,w[MAXN],hd[MAXN];
vector<int> E[MAXN];
ll to[MAXN],a[MAXN],b[MAXN],c[MAXN];
bool flag2=1,flag1=1;
inline ll read()
{
	ll p=1,q=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') p=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		q=(q<<1)+(q<<3)+(ch^48),ch=getchar();
	return p*q;
}
bool chck(ll i,ll x,ll y,ll z,ll l,ll r)
{
	if(r-l<=1000)
	{
		ll sum=0;
		for(int i=l;i<=r;i++)
		{
			sum+=max(1ll,y+z*i);
			if(sum>=x)return 1;
		}
		return 0;
	}
	if(z==0) return (x<=y*(r-l+1));
	if(z>0)
	{
		x-=y*(r-l+1);
		ll tmp=r*(r+1)/2-l*(l-1)/2;
		return x/(double)tmp<=z;
	}
	if(z<0)
	{
		ll R=min(r+1,to[i]);
		if(l>=R) return (r-l+1>=x);
		x-=(r-R+1),r=R-1;
		x-=(r-l+1)*y;
		ll tmp=r*(r+1)/2-l*(l-1)/2;
		return x/(double)tmp<=z;
	}
	return 0;
}
void get_val(int id,int u)
{
	int l=1,r=n;
	w[id]=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(chck(id,a[id],b[id],c[id],mid,u)) w[id]=mid,l=mid+1;
		else r=mid-1;
	}
}
int cnt[1005][1005];
bool dfs(int u,int fa)
{
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v==fa) continue;
		dfs(v,u);
		for(int i=1;i<=n;i++)
			cnt[u][i]+=cnt[v][i];
	}
	int mn=w[u]+1;
	for(int i=n;i>0;i--)
	{
		if(!cnt[u][i]) continue;
		cnt[u][i-1]+=cnt[u][i]-1;
		cnt[u][i]=1,mn=min(mn,i);
		// cout<<u<<' '<<i<<' '<<cnt[]
	}
	// cout<<u<<' '<<mn<<endl;
	if(mn==1) return 0;
	cnt[u][mn-1]=1;
	return 1;
}
int ct[MAXN];
bool check(int d)
{
	for(int i=1;i<=n;i++)
	{
		get_val(i,d);
		// cout<<i<<' '<<w[i]<<' '<<d<<endl;
		if(!w[i]) return 0;
	}
	if(flag1)
	{
		for(int i=1;i<=n;i++)
			if(w[i]<i) return 0;
		return 1;
	}
	if(flag2)
	{
		memset(ct,0,sizeof(ct));
		for(int i=2;i<=n;i++)
		{
			ct[w[i]]++;
		}
		for(int i=n;i>0;i--)
		{
			if(!ct[i]) continue;
			ct[i-1]+=ct[i]-1;
		}
		if(ct[1]) return 0;
		return 1;
	}
	memset(cnt,0,sizeof(cnt));
	return dfs(1,0);
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read(),b[i]=read(),c[i]=read();
		if(c[i]<0)
		{
			to[i]=b[i]/(-c[i]);
			while(b[i]+to[i]*c[i]>1) to[i]++;
		}
	}
	for(int i=1;i<n;i++)
	{
		u=read(),v=read();
		E[u].push_back(v),E[v].push_back(u);
		// cout<<u<<' '<<v<<endl;
		if(u!=i||v!=i+1) flag1=0;
		if(u!=1) flag2=0;
	}
	int l=n,r=1e9,find;
	while(l<=r)
	{
		int mid=(l+r)/2;
		// cout<<l<<' '<<r<<" "<<mid<<endl;
		if(check(mid)) r=mid-1,find=mid;
		else l=mid+1;
	}
	cout<<find;
	return 0;
}