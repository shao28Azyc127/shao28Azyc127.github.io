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
const ll inf=4e18;
map<int,int>f;
int t,n,m,k,d,tx[100005],ty[100005],w[100005],b[200005],tot;
ll tr[800005],lz[800005],dp[200005];
struct node
{
	int p,w;
};
vector<node>s[200005];
inline void push(int o)
{
	if(lz[o])
	{
		tr[o<<1]+=lz[o];
		lz[o<<1]+=lz[o];
		tr[o<<1|1]+=lz[o];
		lz[o<<1|1]+=lz[o];
		lz[o]=0;
	}
}
void add(int o,int l,int r,int x,ll k)
{
	if(l==r)
	{
		tr[o]=k+1ll*d*b[l];
		return;
	}
	push(o);
	int mid=(l+r)>>1;
	if(x<=mid) add(o<<1,l,mid,x,k);
	else add(o<<1|1,mid+1,r,x,k);
	tr[o]=max(tr[o<<1],tr[o<<1|1]);
}
void update(int o,int l,int r,int x,ll k)
{
	if(r<=x)
	{
		tr[o]+=k;
		lz[o]+=k;
		return;
	}
	push(o);
	int mid=(l+r)>>1;
	update(o<<1,l,mid,x,k);
	if(x>mid) update(o<<1|1,mid+1,r,x,k);
	tr[o]=max(tr[o<<1],tr[o<<1|1]);
}
ll query(int o,int l,int r,int x,int y)
{
	if(x<=l&&r<=y) return tr[o];
	push(o);
	int mid=(l+r)>>1;
	ll res=0;
	if(x<=mid) res=query(o<<1,l,mid,x,y);
	if(y>mid) res=max(res,query(o<<1|1,mid+1,r,x,y));
	return res;
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	read();
	t=read();
	while(t--)
	{
		n=read();
		m=read();
		k=read();
		d=read();
		vector<int>a;
		for(re int i=1;i<=m;++i)
		{
			ty[i]=read();
			tx[i]=ty[i]-read()+1;
			w[i]=read();
			a.push_back(tx[i]);
			a.push_back(ty[i]);
		}
		sort(a.begin(),a.end());
		f.clear();
		tot=0;
		for(re int i=0;i<a.size();++i)
		{
			if(!i||a[i]>a[i-1])
			{
				b[++tot]=a[i];
				f[a[i]]=tot;
			}
		}
		for(re int i=1;i<=m;++i)
		{
			tx[i]=f[tx[i]];
			ty[i]=f[ty[i]];
			s[ty[i]].push_back((node){tx[i],w[i]});
		}
		for(re int i=1;i<=(tot<<2);++i)
		{
			tr[i]=-inf;
			lz[i]=0;
		}
		ll ans=0;
		add(1,1,tot,1,0);
		for(re int i=1;i<=tot;++i)
		{
			for(re int j=0;j<s[i].size();++j) update(1,1,tot,s[i][j].p,s[i][j].w);
			s[i].clear();
			int l=1,r=i;
			while(l<r)
			{
				int mid=(l+r)>>1;
				if(b[i]-b[mid]+1>k) l=mid+1;
				else r=mid;
			}
			dp[i]=max(dp[i-1],query(1,1,tot,l,i)-1ll*(b[i]+1)*d);
			if(i<tot) add(1,1,tot,i+1,dp[i]);
			ans=max(ans,dp[i]);
		}
		write(ans);
		puts("");
	}
	return 0;
}