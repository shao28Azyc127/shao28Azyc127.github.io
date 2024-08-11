#include <bits/stdc++.h>
using namespace std;
int f[20001],vis[20001],n,m,k,s,e,ind[20001],outd[20001],ans=100000000,cnt=0;
struct edge{
    int t,w;
    edge(int _t,int _w):t(_t),w(_w){}
};
vector <edge> v[20001];
void dfs(int ne,int x,int t){
    cnt++;
    if(cnt>10000000){
        if(ans!=100000000) printf("%d",ans);
        else puts("-1");
        exit(0);
    }
    if(x==e){
        while(ne>t) t+=k;
        if(t%k==0){
            ans=min(ans,t);
        }
        return;
    }
    if(t>ans) return;
    while(ne>t) t+=k;
    for(int i=0;i<v[x].size();++i){
        int nee=v[x][i].w,y=v[x][i].t;
        dfs(nee,y,t+1);
    }
}
int main(){
    srand(time(0));
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;++i){
        int u,x,y;
        scanf("%d%d%d",&u,&x,&y);
        v[u].push_back(edge(x,y));
        ind[x]++;
        outd[u]++;
    }
    for(int i=1;i<=n;++i){
        if(ind[i]==0) s=i;
        if(outd[i]==0) e=i;
    }
    dfs(0,s,0);
    if(ans!=100000000) printf("%d",ans);
    else puts("-1");
    return 0;
}
