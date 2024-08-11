#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+5;
int tr[MAXN<<2],val[MAXN],tag[MAXN<<2],t,c,n,k,m,d,N,ans,q[MAXN],tot,dp[MAXN],b[MAXN];
struct node
{
	int l,r,w;
	bool operator<(const node &o) const
	{
		return r<o.r;
	}
}a[MAXN];
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
vector<int> vc;
void bd(int u,int l,int r)
{
	if(l==r)
	{
		tr[u]=(val[l]-1)*d;
		return;
	}
	int mid=(l+r)/2;
	bd(u*2,l,mid),bd(u*2+1,mid+1,r);
	tr[u]=max(tr[u*2],tr[u*2+1]);
}
void push_down(int u,int l,int r)
{
	tr[u*2]+=tag[u],tr[u*2+1]+=tag[u];
	tag[u*2]+=tag[u],tag[u*2+1]+=tag[u];
	tag[u]=0;
}
void add(int u,int l,int r,int L,int R,int x)
{
	if(L<=l&&r<=R)
	{
		tr[u]+=x,tag[u]+=x;
		return;
	}
	if(L>r||l>R) return;
	push_down(u,l,r);
	int mid=(l+r)/2;
	add(u*2,l,mid,L,R,x),add(u*2+1,mid+1,r,L,R,x);
	tr[u]=max(tr[u*2],tr[u*2+1]);
}
int qr(int u,int l,int r,int L,int R)
{
	if(L<=l&&r<=R) return tr[u];
	if(L>r||l>R) return 0;
	push_down(u,l,r);
	int mid=(l+r)/2;
	return max(qr(u*2,l,mid,L,R),qr(u*2+1,mid+1,r,L,R));
}
void solve()
{
	n=read(),m=read(),k=read(),d=read();
	vc.clear(),ans=tot=0;
	for(int i=1;i<=m;i++)
	{
		a[i].r=read(),a[i].l=read(),a[i].w=read();
		a[i].l=a[i].r-a[i].l+1;
		vc.push_back(a[i].l);
	}
	memset(tr,0,sizeof(tr)),memset(tag,0,sizeof(tag));
	sort(a+1,a+m+1);
	sort(vc.begin(),vc.end());
	N=1,b[1]=vc[0];
	for(int i=1;i<vc.size();i++)
		if(vc[i]!=vc[i-1]) b[++N]=vc[i];
	for(int i=1;i<=m;i++)
	{
		int l=1,r=N,find;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(b[mid]<=a[i].l) find=mid,l=mid+1;
			else r=mid-1;
		}
		val[find]=a[i].l,a[i].l=find;
	}
	bd(1,1,N);
	int ll=1,rr=1;
	for(int i=1;i<=m;i++)
	{
		add(1,1,N,1,a[i].l,a[i].w);
		while(val[ll]<=a[i].r-k) ll++;
		while(rr<N&&val[rr+1]<=a[i].r) rr++;
		// cout<<ll<<' '<<rr<<" "<<val[ll]<<' '<<val[rr]<<endl;
		// cout<<i<<" "<<a[i].l<<' '<<a[i].r<<' '<<a[i].w<<endl;
		if(ll<=rr) dp[i]=max(qr(1,1,N,ll,rr)-a[i].r*d,0ll);
		else dp[i]=0;
		ans=max(ans,dp[i]);
		int L=rr+1;
		while(L<=n&&val[L]<=a[i].r+1) L++;
		if(L>n) continue;
		if(!tot||dp[i]>dp[q[tot]])
			add(1,1,N,L,N,dp[i]-dp[q[tot]]),q[++tot]=i;
	}
	cout<<ans<<endl;
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read(),t=read();
	while(t--) solve();
	return 0;
}