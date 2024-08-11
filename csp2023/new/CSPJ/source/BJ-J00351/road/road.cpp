#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,inf=0x3f3f3f3f;
struct node{int min=inf,minplace,l,r;};
int n,d,nowp,v[N],a[N];
node tr[N<<2];
long long ans,nowdis,needdis,predis[N];
vector<int> buypoint;
inline void file(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
}
inline void pushup(int p){
  if(tr[p<<1].min<tr[p<<1|1].min) tr[p].min=tr[p<<1].min,tr[p].minplace=tr[p<<1].minplace;
  else tr[p].min=tr[p<<1|1].min,tr[p].minplace=tr[p<<1|1].minplace;
}
void build(int p,int l,int r){
  tr[p].l=l,tr[p].r=r;
  if(l==r){
    tr[p].min=a[l],tr[p].minplace=l;
    return;
  }
  int mid=l+r>>1;
  build(p<<1,l,mid);
  build(p<<1|1,mid+1,r);
  if(tr[p<<1].min<tr[p<<1|1].min) tr[p].min=tr[p<<1].min,tr[p].minplace=tr[p<<1].minplace;
  else tr[p].min=tr[p<<1|1].min,tr[p].minplace=tr[p<<1|1].minplace;
}
node query(int p,int l,int r){
  node res;
  if(l<=tr[p].l&&tr[p].r<=r){
    res.min=tr[p].min,res.minplace=tr[p].minplace;
    return res;
  }
  int mid=tr[p].l+tr[p].r>>1;
  if(l<=mid){
    node qleft=query(p<<1,l,r);
    if(qleft.min<res.min) res.minplace=qleft.minplace,res.min=qleft.min;
  }
  if(mid<r){
    node qright=query(p<<1|1,l,r);
    if(qright.min<res.min) res.minplace=qright.minplace,res.min=qright.min;
  }
  return res;
}
int main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  file();
  cin >> n >> d;
  for(int i=1;i<n;++i) cin >> v[i],predis[i+1]=predis[i]+v[i];
  for(int i=1;i<=n;++i) cin >> a[i];
  build(1,1,n-1);
  nowp=n;
  buypoint.push_back(nowp);
  while(nowp>1) nowp=query(1,1,nowp-1).minplace,buypoint.push_back(nowp);
  reverse(buypoint.begin(),buypoint.end());
  for(int i=0;i<buypoint.size()-1;++i) needdis=predis[buypoint[i+1]]-nowdis,ans+=(needdis+d-1)/d*a[buypoint[i]],nowdis+=((needdis+d-1)/d)*d;
  cout << ans;
  return 0;
}