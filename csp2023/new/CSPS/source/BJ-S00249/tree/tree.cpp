#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
  long long a;
  int b,c,ans;
};
int n,tot,dfsres,bfsres,hgres;
node tr[N];
bitset<N> vis;
long long ans;
queue<int> q;
vector<int> ch[N];
priority_queue<pair<int,int> > pq;
inline void file(){
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
}
inline int calc(int x,long long a,int b,long long c){
  if(a<=0) return x-1;
  if(b+x*c<0) return a+x-2;
  return calc(x+1,a-(b+x*c),b,c);
}
void dfs(int p){
  vis[p]=1;
  tr[p].ans=calc(tot,tr[p].a,tr[p].b,tr[p].c);
  ++tot;
  for(int i=0;i<ch[p].size();++i) if(!vis[ch[p][i]]) dfs(ch[p][i]);
}
inline void bfs(){
  q.push(1);
  int p;
  while(!q.empty()){
    p=q.front();
    q.pop();
    vis[p]=1;
    tr[p].ans=calc(tot,tr[p].a,tr[p].b,tr[p].c);
    ++tot;
    for(int i=0;i<ch[p].size();++i) if(!vis[ch[p][i]]) q.push(ch[p][i]);
  }
}
void hg(){
  tr[1].ans=calc(tot,tr[1].a,tr[1].b,tr[1].c);
  pq.push({tr[1].ans,1});
  int p;
  while(!pq.empty()){
    p=pq.top().second;
    pq.pop();
    vis[p]=1;
    tr[p].ans=calc(tot,tr[p].a,tr[p].b,tr[p].c);
    ++tot;
    for(int i=0;i<ch[p].size();++i) if(!vis[ch[p][i]]) pq.push({calc(tot,tr[ch[p][i]].a,tr[ch[p][i]].b,tr[ch[p][i]].c),ch[p][i]});
  }
}
int main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  file();
  cin >> n;
  for(int i=1;i<=n;++i) cin >> tr[i].a >> tr[i].b >> tr[i].c;
  for(int i=1,u,v;i<n;++i){
    cin >> u >> v;
    ch[u].push_back(v),ch[v].push_back(u);
  }
  tot=1,dfs(1);
  for(int i=1;i<=n;++i) dfsres=max(dfsres,tr[i].ans);
  vis.reset();
  tot=1,bfs();
  for(int i=1;i<=n;++i) bfsres=max(bfsres,tr[i].ans);
  vis.reset();
  tot=1,hg();
  for(int i=1;i<=n;++i) hgres=max(hgres,tr[i].ans);
  ans=min(hgres,min(dfsres,bfsres));
  cout << ans;
  return 0;
}