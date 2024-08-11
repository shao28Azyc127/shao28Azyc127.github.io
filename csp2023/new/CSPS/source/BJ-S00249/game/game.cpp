#include <bits/stdc++.h>
using namespace std;
const int N=8e3+5;
struct hw{int l,r;};
int n;
char str[N];
bitset<N> f[N],vis[N];
long long ans;
inline void file(){
  freopen("game.in","r",stdin);
  freopen("game.out","w",stdout);
}
bool check(int l,int r){
  if(vis[l][r]) return f[l][r];
  vis[l][r]=1;
  if(str[l]==str[r]){
    if(r==l+1) return f[l][r]=1;
    return f[l][r]=check(l+1,r-1);
  }
  for(int t=l+1;t<r-1;t+=2) if(check(l,t)&&check(t+1,r)) return f[l][r]=1;
  return f[l][r]=0;
}
int main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  file();
  cin >> n >> str;
  for(int i=0;i<n;++i) for(int j=i-1;j>=0;j-=2) if(check(j,i)) ++ans;
  cout << ans;
  return 0;
}