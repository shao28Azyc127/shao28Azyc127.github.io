#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c,n,m,q,x[N],y[N],x2[N],y2[N];
void solve(){
  if(x2[1]==y2[1])cout<<0;
  else cout<<1;
}
int main(){
  freopen("expand.in","r",stdin);
  freopen("expand.out","w",stdout);
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin>>c>>n>>m>>q;
  for(int i=1;i<=n;++i){
    cin>>x[i];
    x2[i]=x[i];
  }
  for(int i=1;i<=m;++i){
    cin>>y[i];
    y2[i]=y[i];
  }
  solve();
  while(q--){
    int kx,ky;cin>>kx>>ky;
    for(int i=1;i<=n;++i)x2[i]=x[i];
    for(int i=1;i<=m;++i)y2[i]=y[i];
    for(int i=1;i<=kx;++i){
      int p,v;cin>>p>>v;
      x2[p]=v;
    }
    for(int i=1;i<=ky;++i){
      int p,v;cin>>p>>v;
      y2[p]=v;
    }
    solve();
  }
  cout<<endl;
  return 0;
}
