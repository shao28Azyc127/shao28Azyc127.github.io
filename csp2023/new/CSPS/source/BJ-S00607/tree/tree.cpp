#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lll unsigned long long
ll a[100010],b[100010],c[100010],fa[100010],sz[100010],n;
vector<int>g[100010];
void dfs1(int nw,int f){
	fa[nw]=f,sz[nw]=1;
	for(auto i:g[nw])if(i^f)dfs1(i,nw),sz[nw]+=sz[i];
}
lll get(int id,ll x,ll y){
	if(c[id]>=0)return(2ull*b[id]+x*c[id]+y*c[id])*(y-x+1)/2;
	else{
		ll edti=(2ull+c[id]-b[id])/c[id];
		if(y<edti)return(2ull*b[id]+x*c[id]+y*c[id])*(y-x+1)/2;
		return(2ull*b[id]+x*c[id]+(edti-1)*c[id])*(edti-x)/2+y-edti+1;
	}
}
ll chk(int id,ll ed){
	ll l=1,r=ed;
	while(l<r){
		ll mid=(l+r+1)>>1;
		if(get(id,mid,ed)<a[id])r=mid-1;
		else l=mid;
	}
	return get(id,l,ed)>=a[id]?l:-1;
}
ll st[100010];
bitset<100010>vis;
int dfs2(int nw,ll x){
	vector<int>t;
	for(auto i:g[nw])if(i^fa[nw]){
		int tmp=dfs2(i,x);
		if(!tmp)return 0;
		t.push_back(st[i]);
	}
	sort(t.begin(),t.end());ll sum=1,ans=2e9;
	for(auto i:t){
		ans=min(ans,i-(sum++));
		if(ans<=0)return 0;
	}
	st[nw]=min(st[nw],ans);
	return 1;
}
int check(ll x){
	for(int i=1;i<=n;++i){
		st[i]=chk(i,x);
		if(st[i]==-1)return 0;
	}
	int t=dfs2(1,x);
	if(!t)return 0;
	vis=0;
	priority_queue<pair<ll,int>>q;q.push(make_pair(-st[1],1));
	ll cnt=0;
	while(!q.empty()){
		++cnt;
		pair<ll,int>tp=q.top();q.pop();
		tp.first=-tp.first;
		if(tp.first<cnt)return 0;
		vis[tp.second]=1;
		for(auto i:g[tp.second])if(!vis[i])q.push(make_pair(-st[i],i));
	}
	return 1;
}
inline ll read(){
	int f=0,t=getchar();ll x=0;
	while(t<'0'||t>'9')f=t=='-',t=getchar();
	while(t>='0'&&t<='9')x=x*10+(t^48),t=getchar();
	return f?-x:x;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)a[i]=read(),b[i]=read(),c[i]=read();
	for(int i=2,u,v;i<=n;++i)u=read(),v=read(),g[u].push_back(v),g[v].push_back(u);
	dfs1(1,1);
	ll l=1,r=1e9;
	while(l<r){
		ll mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}//4-7zijie