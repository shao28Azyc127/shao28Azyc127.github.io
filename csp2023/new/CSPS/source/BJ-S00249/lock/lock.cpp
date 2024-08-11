#include <bits/stdc++.h>
using namespace std;
const int N=6,maxn=1e5;
int n,a,cnt,dis,dis2,init,memp,tot=maxn;
bool flag;
vector<int> er;
unordered_set<int> s;
inline void file(){
  freopen("lock.in","r",stdin);
  freopen("lock.out","w",stdout);
}
inline bool check(int x,int y){
  cnt=0,flag=0,memp;
  for(int i=1;i<=1e4;i*=10) if((x/i)%10!=(y/i)%10) ++cnt;
  if(cnt>2||cnt<1) return 0;
  if(cnt==1) return 1;
  for(int i=1;i<=1e4;i*=10){
    if((x/i)%10!=(y/i)%10){
      if(!flag){
        dis=(x/i)%10-(y/i)%10;
        if(dis<0) dis+=10;
        flag=1,memp=i;
      }
      else{
        if(i!=10*memp) return 0;
        dis2=(x/i)%10-(y/i)%10;
        if(dis2<0) dis2+=10;
        if(dis2!=dis) return 0;
        return 1;
      }
    }
  }
}
int main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  file();
  for(int i=0;i<maxn;++i) s.insert(i);
  cin >> n;
  while(n--){
    a=0,er.clear();
    for(int i=1;i<=5;++i) cin >> init,a=a*10+init;
    for(auto it=s.begin();it!=s.end();++it) if(!check((*it),a)) --tot,er.push_back((*it));
    for(int i=0;i<er.size();++i) s.erase(er[i]);
  }
  cout << tot;
  return 0;
}