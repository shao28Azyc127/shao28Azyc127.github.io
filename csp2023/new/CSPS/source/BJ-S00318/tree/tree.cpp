#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
struct edge{
	int v,nxt;
}e[N<<1];
int head[N],cnt;
inline void add(int u,int v){
	e[++cnt]={v,head[u]},head[u]=cnt;
}
int n,res=1e9,a[N],b[N],c[N],h[N];
struct Sol1{
	int cnt=0,t[N],h[N];int times=0;
	bool vis[N]={0};
	vector<int> V;
	typedef pair<int,int> pii;
	vector<pii> u1;
	bool go[N]={0};
	vector<int> upd;
	int T[25][25],Go[25][25];
	void dfs(int u,int fa){
		++times;vis[u]=1;
		u1.push_back({u,t[u]});
		if(t[u]==0)t[u]=times,++cnt;
		for(int i=1;i<=n;++i)T[u][i]=t[i];
		V.push_back(u);
		for(int i=head[u];i;i=e[i].nxt){
                if(!go[e[i].v])upd.push_back(e[i].v);
                go[e[i].v]=1;
		}
		for(int i=1;i<=n;++i)Go[u][i]=go[i];
		if(cnt==n){
			for(int i=1;i<=n;++i)h[i]=0;
			for(int x=1;x<=res;++x){
				for(int i=1;i<=n;++i){
					if(t[i]<=x)h[i]+=max(b[i]+x*c[i],1ll);
				}
				bool flg=1;
				for(int i=1;i<=n;++i)flg&=(h[i]>=a[i]);
				if(flg){res=x;break;}
			}
			return ;
		}
		for(int v=1;v<=n;++v){
            if(v==fa||vis[v]||!go[v])continue;
            vector<int> V1=V;
            int times1=times,cnt1=cnt;
            dfs(v,u);
            V=V1,times=times1,cnt=cnt1;
            for(int i=1;i<=n;++i)t[i]=T[u][i],go[i]=Go[u][i];
            vis[v]=0;
		}
	}
	void solve(){
	    go[1]=1;
		dfs(1,0);
		cout<<res<<'\n';
	}
}A;
int q[N];
int add(int i,int l,int r){
    int qq=min(q[i],r+1);
    int l1=max(qq-1-l+1,0ll),l2=max(r-qq+1,0ll);
    int sum=l2*1;
    sum+=l1*b[i]+(r+r-l1+1)*l1/2*c[i];
    return sum;
}
bool chk(int x){
    for(int i=1;i<=n;++i){
        if(add(i,i,x)<a[i])return 0;
    }
    return 1;
}
signed main() {
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	cin>>n;
	bool flg=1;
	for(int i=1;i<=n;++i)cin>>a[i]>>b[i]>>c[i];
	for(int i=1;i<n;++i){
		int u,v;cin>>u>>v;
		add(u,v),add(v,u);
		flg&=(abs(u-v)==1);
	}
	if(n<=20){A.solve();return 0;}
	if(flg){
        for(int i=1;i<=n;++i){
            if(b[i]+1e9*c[i]>=1){
                q[i]=1e9+1;
                continue;
            }
            int l=1,r=1e9;
            while(l<=r){
                int mid=(l+r)>>1;
                if(b[i]+mid*c[i]<1)q[i]=mid,r=mid-1;
                else l=mid+1;
            }
        }
        int l=n,r=1e9;
        while(l<=r){
            int mid=(l+r)>>1;
            if(chk(mid))res=mid,r=mid-1;
            else l=mid+1;
        }
        cout<<res<<'\n';
        return 0;
	}
	cout<<n<<'\n';

	return 0;
}
/*
pay attention:
1. cin/cout getchar()
2. sqrt(__int128)
3. N,M
4. freoepn
5. debug
6. memory limits and no RE
think twice, code once
CSPS 1= is easy and xunse
you will get 300+ pts
keep elegant, you'll AKIOI
*/
