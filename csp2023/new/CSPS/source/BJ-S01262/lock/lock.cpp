#include<bits/stdc++.h>
using namespace std;
int n;
string s,t;
map<string,int>mp;
int main(){
  freopen("lock.in","r",stdin);
  freopen("lock.out","w",stdout);
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin>>n;
  for(int i=1;i<=n;++i){
    s.clear();
    for(int j=1;j<=5;++j){
      int x;cin>>x;
      s.push_back(x+'0');
    }
    for(int j=0;j<5;++j){
      for(int k=1;k<=9;++k){
        t=s;
        int x=t[j]-'0';
        x=(x+k)%10;
        t[j]=x+'0';
        ++mp[t];
      }
    }
    for(int j=0;j<4;++j){
      for(int k=1;k<=9;++k){
        t=s;
        int x=t[j]-'0',y=t[j+1]-'0';
        x=(x+k)%10;y=(y+k)%10;
        t[j]=(char)(x+'0');t[j+1]=(char)(y+'0');
        ++mp[t];
      }
    }
  }
  map<string,int>::iterator it;
  int ans=0;
  for(it=mp.begin();it!=mp.end();++it){
    if((*it).second==n){
      ++ans;
    }
  }
  cout<<ans<<endl;
  return 0;
}
