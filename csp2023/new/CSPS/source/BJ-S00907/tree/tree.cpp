#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define fir first
#define sec second
using namespace std;
const int N=2e5+10;
int n,a[N],b[N],c[N],u,v,flag1=1,flag2=1;
vector <int> edge[N];
namespace subtask1{
    int r[N],vis[N];
    void dfs(int u,int fa){
        r[u]=((a[u]-1)/b[u]+1);
        for(auto v:edge[u]){
            if(v==fa)continue;
            dfs(v,u);
            r[u]=max(r[u],r[v]+1);
        }
    }
    priority_queue < pair<int,int> > Q;
    vector <int> d;
    bool check(int x){
        for(int i=0;i<d.size();i++){
            int u=d[i];
            if(a[u]>(b[u]*(x-i)))return false;
        }
        return true;
    }
    void solve(){
        dfs(1,0);
        Q.push(mp(r[1],1));
        for(int i=1;i<=n;i++){
            int u=Q.top().sec;vis[u]=1;
            d.push_back(u);Q.pop();
            for(auto v:edge[u]){
                if(vis[v])continue;
                Q.push(mp(r[v],v));
            }
        }
        int l=0,r=1e9;
        while(l<r){
            int mid=(l+r)>>1;
            if(check(mid))r=mid;
            else l=mid+1;
        }
        cout<<l<<endl;
    }
}
namespace subtask2{
    int f[1<<21];
    void solve(){
        memset(f,0x3f,sizeof(f));
        f[0]=0;
        for(int i=1;i<(1<<n);i++){
            int step=__builtin_popcount(i);
            int now=step;
            int Min=1e9;
            for(int j=1;j<=n;j++){
                if((i>>(j-1))&1){
                    int tmp=a[j];
                    int qwq=step-1;
                    while(tmp>0){
                        qwq++;
                        tmp-=max(b[j]+qwq*c[j],1ll);
                        if(b[j]+qwq*c[j]<=0){
                            qwq+=tmp;
                            break;
                        }
                    }
                    Min=min(Min,max(f[i-(1<<(j-1))],qwq));
                }
            }
            f[i]=Min;
        }
        cout<<f[(1<<n)-1]<<endl;
    }
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<n;i++){
        cin>>u>>v;
        if(u!=i||v!=i+1)flag2=0;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        if(c[i]!=0)flag1=0;
    if(flag1)subtask1::solve();
    else subtask2::solve();
	return 0;
}
