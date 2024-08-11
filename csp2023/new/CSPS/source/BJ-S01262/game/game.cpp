#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int n,st[N],to[N][26],f[N];
ll ans;
string s;
void sub1(){
  for(int i=1;i<=n;++i){
    int t=1;st[1]=s[i]-'a';
    for(int j=i+1;j<=n;++j){
      if(t&&s[j]-'a'==st[t])--t;
      else st[++t]=s[j]-'a';
      if(!t)++ans;
    }
  }
  cout<<ans<<endl;
}
void sub2(){
  for(int i=n;i>=1;--i){
    to[i][s[i]-'a']=i;
    if(i==n)continue;
    int nex=to[i+1][s[i]-'a'];
    if(!nex)continue;
    ++nex;
    for(int j=0;j<26;++j){
      if(j==s[i]-'a')continue;
      to[i][j]=to[nex][j];
    }
  }
  for(int i=n;i>=1;--i){
    int nex=to[i+1][s[i]-'a'];
    if(!nex)continue;
    ++nex;
    f[i]=1+f[nex];
    ans+=f[i];
  }
  cout<<ans<<endl;
}
int main(){
  freopen("game.in","r",stdin);
  freopen("game.out","w",stdout);
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin>>n>>s;s="."+s;
  sub2();
  return 0;
}
