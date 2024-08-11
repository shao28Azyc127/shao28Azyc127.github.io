#include <bits/stdc++.h>
using namespace std;
int n,now,cnt;
inline void file(){
  freopen("apple.in","r",stdin);
  freopen("apple.out","w",stdout);
}
int s(int k){
  if(k%3==1) return 1;
  return s(k-(k+2)/3)+1;
}
int main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  file();
  cin >> n;
  now=n;
  while(now>0) ++cnt,now-=(now+2)/3;
  cout << cnt << ' ' << s(n);
  return 0;
}