#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const ll MAXN=1e5+5;
ll c,t;
struct query{
    char op;
    ll x,y;
}q[MAXN];
ll n,m;
void init(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=m;++i){
        cin>>q[i].op;
        if(q[i].op=='+'||q[i].op=='-'){
            scanf("%lld%lld",&q[i].x,&q[i].y);
        }else{
            scanf("%lld",&q[i].x);
        }
    }
}
char change(char x){
    if(x=='T'){
        return 'F';
    }else if(x=='F'){
        return 'T';
    }
    return 'U';
}
namespace Task1_2{
    char num[20],nxt[20];
    ll ans=1e18;
    void dfs(ll u,ll val){
        if(u==n+1){
            for(int i=1;i<=n;++i){
                nxt[i]=num[i];
            }
            for(int i=1;i<=m;++i){
                if(q[i].op=='+'){
                    nxt[q[i].x]=nxt[q[i].y];
                }else if(q[i].op=='-'){
                    nxt[q[i].x]=change(nxt[q[i].y]);
                }else{
                    nxt[q[i].x]=q[i].op;
                }
            }
            bool good=true;
            for(int i=1;i<=n;++i){
                if(nxt[i]!=num[i]){
                    good=false;
                    break;
                }
            }
            if(good){
                ans=min(ans,val);
            }
            return;
        }
        num[u]='T';
        dfs(u+1,val);
        num[u]='F';
        dfs(u+1,val);
        num[u]='U';
        dfs(u+1,val+1);
    }
    void Do(){
        ans=1e18;
        dfs(1,0);
        printf("%lld\n",ans);
    }
}
namespace Task3_4{
    bool good[MAXN];
    void Do(){
        memset(good,false,sizeof(good));
        ll ans=0;
        for(int i=1;i<=m;++i){
            if(q[i].op=='U'){
                good[q[i].x]=true;
            }else{
                good[q[i].x]=false;
            }
        }
        for(int i=1;i<=n;++i){
            if(good[i]){
                ans++;
            }
        }
        printf("%lld\n",ans);
    }
}
/*
namespace onm{
    pair<ll,ll>f[1005][1005];
    ll vis[1005];
    void Do(){
        for(int i=0;i<1005;++i){
            vis[i]=0;
            for(int j=0;j<1005;++j){
                f[i][j]={0,0};
            }
        }
        for(int i=0;i<1005;++i){
            f[i][0]={i,1};
        }
        for(int i=1;i<=m;++i){
            if(q[i].op=='+'){
                ll u=q[i].x,v=q[i].y;
                f[u][i]=f[v][i-1];
            }else if(q[i].op=='-'){
                ll u=q[i].x,v=q[i].y;
                f[u][i]=f[v][i-1];
                f[u][i].second*=-1;
            }else if(q[i].op=='T'){
                ll u=q[i].x,v=n+1;
                f[u][i]=f[v][i-1];
            }else if(q[i].op=='F'){
                ll u=q[i].x,v=n+2;
                f[u][i]=f[v][i-1];
            }else if(q[i].op=='U'){
                ll u=q[i].x,v=n+3;
                f[u][i]=f[v][i-1];
            }
            for(int j=1;j<=n+3;++j){
                if(j!=q[i].x){
                    f[j][i]=f[j][i-1];
                }
            }
        }
        ll ans=0;
        for(int i=1;i<=n;++i){
            if(f[i][m].first==n+3){
                vis[i]=1;
                ans++;
            }
            if(f[i][m].first==i&&f[i][m].second==-1){
                vis[i]=1;
                ans++;
            }
        }
        while(true){
            bool finish=true;
            for(int i=1;i<=n;++i){
                if(vis[i]==1){
                    for(int j=1;j<=n;++j){
                        if(!vis[j]&&f[j][m].first==i){
                            vis[j]=1;
                            ans++;
                            finish=false;
                        }
                    }
                }
            }
            if(finish){
                break;
            }
        }
        printf("%lld\n",ans);
    }
}
*/
namespace Task5_6{
    pair<ll,ll>f[MAXN];
    vector<ll>adj[MAXN];
    bool vis[MAXN];
    ll ans;
    void dfs(ll u){
        for(auto v:adj[u]){
            if(vis[v]){
                continue;
            }
            vis[v]=true;
            ans++;
            dfs(v);
        }
    }
    void Do(){
        ans=0;
        memset(vis,false,sizeof(vis));
        for(int i=0;i<MAXN;++i){
            f[i]={i,1};
            adj[i].clear();
        }
        for(int i=1;i<=m;++i){
            if(q[i].op=='+'){
                ll u=q[i].x,v=q[i].y;
                f[u]=f[v];
            }else if(q[i].op=='-'){
                ll u=q[i].x,v=q[i].y;
                f[u]=f[v];
                f[u].second*=-1;
            }else if(q[i].op=='T'){
                ll u=q[i].x,v=n+1;
                f[u]=f[v];
            }else if(q[i].op=='F'){
                ll u=q[i].x,v=n+2;
                f[u]=f[v];
            }else if(q[i].op=='U'){
                ll u=q[i].x,v=n+3;
                f[u]=f[v];
            }

        }
        for(int i=1;i<=n;++i){
            adj[f[i].first].push_back(i);
        }
        for(int i=1;i<=n;++i){
            if(f[i].first==n+3){
                vis[i]=true;
                ans++;
                dfs(i);
            }
            if(f[i].first==i&&f[i].second==-1){
                vis[i]=true;
                ans++;
                dfs(i);
            }
        }
        printf("%lld\n",ans);
    }
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    if(c<=2){
        while(t--){
            init();
            Task1_2::Do();
        }
    }else if(c<=4){
        while(t--){
            init();
            Task3_4::Do();
        }
    }else if(c<=6){
        while(t--){
            init();
            Task5_6::Do();
        }
    }
    return 0;
}

