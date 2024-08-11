#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define rep(i,x,y) for(LL i=(x);i<=(y);i++)
#define per(i,x,y) for(LL i=(x);i>=(y);i--)
#define all(x) x.begin(),x.end()
#define vi vector<LL>
#define pb push_back
#define pii pair<LL,LL>
#define fi first
#define se second
#define mp make_pair
LL c,T,N,M;
struct node{
    char op;LL u,v;
}ops[114514];
LL fa[114514],anss,mark[114514],ans[114514];
LL getneg(LL x){if(!x)return x;if(x==-1)return -2;return -1;}
vector<pii >G[114514];
LL erd;
void chkdfs(LL x){
    for(pii dt:G[x]){
        if(ans[dt.fi]==-3){
            if(dt.se==0)ans[dt.fi]=ans[x];
            if(dt.se==1)ans[dt.fi]=getneg(ans[x]);
            chkdfs(dt.fi);
        }else{
            if(dt.se==0&&ans[dt.fi]!=ans[x])erd=1;
            if(dt.se==1&&ans[dt.fi]==ans[x])erd=1;
        }
    }
    return ;
}
bool vis[114514];
void remarkdfs(LL x){
    ans[x]=0;vis[x]=1;
    for(pii dt:G[x])if(!vis[dt.fi])remarkdfs(dt.fi);
    return ;
}
void solve(){
    cin>>N>>M;
    rep(i,1,M){
        cin>>ops[i].op>>ops[i].v;if(ops[i].op=='+'||ops[i].op=='-')cin>>ops[i].u;
    }
    rep(i,1,N)fa[i]=i,G[i].clear(),vis[i]=mark[i]=0;
    rep(i,1,M){
        if(ops[i].op=='T')fa[ops[i].v]=-1;
        if(ops[i].op=='F')fa[ops[i].v]=-2;
        if(ops[i].op=='U')fa[ops[i].v]=0;
        if(ops[i].op=='+'){
            fa[ops[i].v]=fa[ops[i].u];mark[ops[i].v]=mark[ops[i].u];
        }
        if(ops[i].op=='-'){
            if(fa[ops[i].u]<=0)fa[ops[i].v]=getneg(fa[ops[i].u]);
            else fa[ops[i].v]=fa[ops[i].u],mark[ops[i].v]=mark[ops[i].u]^1;
        }
    }
    rep(i,1,N)ans[i]=-3;
    rep(i,1,N){
        if(fa[i]<=0)ans[i]=fa[i];
        else{
            if(mark[i])G[i].pb(mp(fa[i],1ll)),G[fa[i]].pb(mp(i,1ll));
            else G[i].pb(mp(fa[i],0ll)),G[fa[i]].pb(mp(i,0ll));
        }
    }
    rep(i,1,N){
        if(fa[i]<=0)chkdfs(i);
    }
    rep(i,1,N){
        if(ans[i]!=-3)continue;
        erd=0;ans[i]=-1;
        chkdfs(i);
        if(erd)remarkdfs(i);
    }
    anss=0;rep(i,1,N){if(!ans[i])anss++;}
    cout<<anss<<'\n';
    return ;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("tribool.in","r",stdin);freopen("tribool.out","w",stdout);
    cin>>c>>T;
    while(T--){
        solve();
    }
    return 0;
}
//You,solely,are responsible for this.
