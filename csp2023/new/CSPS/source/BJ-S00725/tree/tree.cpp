//tree.cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[100005],b[100005],c[100005],dfn[100005];
struct p{
    ll val,cur;
}ds[100005];
bool flagb=true,flaga=true,flagd=true;
vector<ll> G[100005];
bool sets[25],cho[25];
ll heig[25],ans=1e9;
bool cmp(p a,p b){
    return a.val>b.val;
}
void dfs(ll x,ll days){
    bool flag2=true;
    for(ll i=1;i<=n;i++){
        if(heig[i]<a[i]){
            flag2=false;
            break;
        }
    }
    if(flag2){
        ans=min(ans,days);
        return;
    }
    for(ll i=1;i<=n;i++){
        if(sets[i] && !cho[i]){
            cho[i]=true;
            heig[i]+=max(b[i]+c[i]*days,1ll);
            ll siz=G[i].size();
            for(ll j=0;j<siz;j++){
                if(!cho[j]){
                    sets[G[i][j]]=true;
                }
            }
            for(int j=1;j<=n;j++){
                if(cho[j] && j!=i)
                heig[j]+=max(b[j]+c[j]*days,1ll);
            }
            dfs(i,days+1);
            for(ll j=0;j<siz;j++){
                if(!cho[j]){
                    sets[G[i][j]]=false;
                }
            }
            for(int j=1;j<=n;j++){
                if(cho[j] && j!=i)
                heig[j]-=max(b[j]+c[j]*days,1ll);
            }
            heig[i]-=max(b[i]+c[i]*days,1ll);
            cho[i]=false;
        }
    }
    bool flag=false;
    for(ll i=1;i<=n;i++){
        if(!cho[i]){
            flag=false;
            break;
        }
    }
    if(flag)dfs(x,days+1);
}
bool vis[200005];
void dfs2(int fa){
    int siz=G[fa].size();
    for(int i=1;i<=siz;i++){
        if(!vis[G[fa][i]]){
            vis[G[fa][i]]=true;
            dfn[G[fa][i]]=dfn[fa]+1;
            dfs2(G[fa][i]);
        }
    }
}
bool choosed[200005];
bool tmpc[200005];
ll ald;
void dfs3(int x,int dst){
    if(tmpc[dst]){
        for(int i=1;i<=n;i++){
            if(tmpc[i]){
                choosed[i]=true;
            }
        }
        return;
    }
    int siz=G[x].size();
    for(int i=1;i<=siz;i++){
        if(!tmpc[G[x][i]]){
            tmpc[G[x][i]]=true;
            dfs3(G[x][i],dst);
            tmpc[G[x][i]]=false;
        }
    }
}
bool vist[200005];
int dfs4(int fa,int step){
    if(choosed[fa]){
        return step;
    }
    int siz=G[fa].size();
    for(int i=1;i<=siz;i++){
        if(!vist[G[fa][i]]){
            vist[G[fa][i]]=true;
            int k=dfs4(G[fa][i],step+1);
            if(k){return k;}
        }
    }
    return 0;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
        if(c[i]!=0)flaga=false;
    }
    for(ll i=1;i<=n-1;i++){
        ll u,v;
        scanf("%lld%lld",&u,&v);
        if(v!=u+1)flagb=false;
        if(u!=1)flagd=false;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(n<=20){
        G[0].push_back(1);
        sets[1]=true;
        dfs(0,0);
        sets[1]=false;
        printf("%lld\n",ans);
    }else if(flaga){
        dfs2(1);
        for(int i=1;i<=n;i++){
            ds[i].val=ceil(a[i]*1.0/(b[i]*1.0))+dfn[i];
            ds[i].cur=i;
        }
        sort(ds+1,ds+n+1,cmp);
        ald=1;
        choosed[1]=true;
        for(int i=1;i<=n;i++){
            if(!choosed[ds[i].cur]){
                tmpc[1]=true;
                ald+=dfs4(ds[i].cur,0);
                dfs3(1,ds[i].cur);
                tmpc[1]=false;
                ans=min(ans,ald+ds[i].val-dfn[i]);
            }
        }
        printf("%lld\n",ans);
    }else{
        printf("%lld\n",n);
    }
    return 0;
}
