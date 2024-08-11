#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1000+5,inf=LLONG_MAX/4;
ll c,T,n,m,k,d,f[N][N];
struct node{
  ll len,v;
  node(ll len=0,ll v=0):len(len),v(v){}
};
vector<node>vec[N];
bool cmp(node x,node y){return x.len<y.len;}
int main(){
  freopen("run.in","r",stdin);
  freopen("run.out","w",stdout);
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin>>c>>T;
  while(T--){
    cin>>n>>m>>k>>d;
    for(int i=1;i<=n;++i)vec[i].clear();
    for(int i=1;i<=m;++i){
      int x,y,v;cin>>x>>y>>v;
      vec[x].push_back(node(y,v));
    }
    for(int i=1;i<=n;++i){
      sort(vec[i].begin(),vec[i].end(),cmp);
      for(int j=1;j<vec[i].size();++j)vec[i][j].v+=vec[i][j-1].v;
    }
    for(int i=0;i<=n;++i)for(int j=0;j<=n;++j)f[i][j]=-inf;
    f[0][0]=0;
    for(int i=1;i<=n;++i){
      for(int j=0;j<=i-1;++j)f[i][0]=max(f[i-1][j],f[i][0]);
      int cur=0;
      for(int j=1;j<=k;++j){
        f[i][j]=f[i-1][j-1]-d;
        while(cur<vec[i].size()&&j>=vec[i][cur].len)++cur;
        if(cur)f[i][j]+=vec[i][cur-1].v;
      }
    }
    ll ans=-inf;
    for(int i=0;i<=k;++i)ans=max(ans,f[n][i]);
    cout<<ans<<endl;
  }
  return 0;
}
