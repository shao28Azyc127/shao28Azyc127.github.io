#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int c,T,n,m,tot,fir[N],lst[N],isfir[N],islst[N],vis[N],ok[N];
struct node{
  int v,w;
  node(int v=0,int w=0):v(v),w(w){}
};
vector<node>adj[N];
void init(){
  for(int i=1;i<=tot;++i)adj[i].clear();
  for(int i=1;i<=max(tot,n);++i)fir[i]=lst[i]=isfir[i]=islst[i]=vis[i]=ok[i]=0;
  tot=0;
}
bool chk(int x,int y){
  if(!isfir[x]&&!islst[x])return 0;
  if(!isfir[y]&&!islst[y])return 0;
  if(isfir[x]==islst[y]||isfir[y]==islst[x])return 1;
  return 0;
}
int dfs(int u,int tp){
  for(int i=0;i<adj[u].size();++i){
    int v=adj[u][i].v,w=adj[u][i].w,nex;
    if(w)nex=3-tp;
    else nex=tp;
    if(ok[v]){
      if(ok[v]!=nex)return 1;
      continue;
    }else{
      ok[v]=nex;
      if(dfs(v,nex)){
        ok[v]=0;
        return 1;
      }
    }
  }
  return 0;
}
void upd(int u){
  ok[u]=3;
  for(int i=0;i<adj[u].size();++i){
    int v=adj[u][i].v;if(ok[v]==3)continue;
    upd(v);
  }
}
int main(){
  freopen("tribool.in","r",stdin);
  freopen("tribool.out","w",stdout);
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin>>c>>T;
  while(T--){
    cin>>n>>m;init();
    for(int i=1;i<=m;++i){
      int x,y;
      char op;cin>>op>>x>>y;
      if(!vis[y])fir[y]=vis[y]=++tot,isfir[tot]=y;
      if(!vis[x])fir[x]=vis[x]=++tot,isfir[tot]=x;
      else vis[x]=++tot;
      lst[y]=vis[y],lst[x]=vis[x];
      adj[vis[y]].push_back(node(vis[x],(op=='-')));
      adj[vis[x]].push_back(node(vis[y],(op=='-')));
    }
    for(int i=1;i<=n;++i)if(lst[i])islst[lst[i]]=i;
    for(int i=1;i<=n;++i)if(fir[i]!=lst[i]){
      adj[fir[i]].push_back(node(lst[i],0));
      adj[lst[i]].push_back(node(fir[i],0));
    }
    for(int i=1;i<=tot;++i){
      if(!ok[i]){
        ok[i]=1;
        if(dfs(i,1)){
          ok[i]=0;
          upd(i);
        }
      }
    }
    int ans=0;
    for(int i=1;i<=n;++i)ans+=(ok[fir[i]]==3);
    cout<<ans<<endl;
  }
  return 0;
}
