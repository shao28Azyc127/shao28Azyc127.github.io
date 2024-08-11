#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll n,a[N],b[N],c[N],d[N];
vector<int>adj[N];
bool chk(){
  if(d[1]!=1||d[n]!=1)return false;
  for(int i=2;i<n;++i)if(d[i]!=2)return false;
  return true;
}
__int128 get(int i,ll mid){
  return (__int128)b[i]*mid+(__int128)mid*(mid+1)/2*(__int128)c[i];
}
ll jisuan(int i){
  b[i]+=c[i]*(i-1);
  if(c[i]>=0){
    ll l=1,r=1e9,ans;
    while(l<=r){
      ll mid=(l+r)>>1;
      __int128 tmp=get(i,mid);
      if(tmp>=a[i])ans=mid,r=mid-1;
      else l=mid+1;
    }
    return ans;
  }else{
    if(b[i]<=-c[i])return a[i];
    ll up=(double)(1-b[i])/c[i];
    ll l=1,r=up,ans=-1;
    while(l<=r){
      ll mid=(l+r)>>1;
      __int128 tmp=get(i,mid);
      if(tmp>=a[i])ans=mid,r=mid-1;
      else l=mid+1;
    }
    if(ans==-1){
      __int128 tmp=get(i,up);
      return up+a[i]-tmp;
    }else return ans;
  }
}
void sub1(){
  ll ans=0;
  for(int i=1;i<=n;++i)ans=max(ans,jisuan(i)+i-1);
  cout<<ans<<endl;
}
int main(){
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin>>n;
  for(int i=1;i<=n;++i)cin>>a[i]>>b[i]>>c[i];
  for(int i=1;i<n;++i){
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    ++d[u];++d[v];
  }
  if(chk())sub1();
  return 0;
}
