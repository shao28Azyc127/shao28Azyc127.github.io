#include<bits/stdc++.h>
using namespace std;
const int N=3000+5;
int n,m,mi[N],ma[N],cnt[N];
string s;
int main(){
  freopen("dict.in","r",stdin);
  freopen("dict.out","w",stdout);
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;++i){
    cin>>s;mi[i]=1e9;ma[i]=-1;
    for(int j=0;j<m;++j){
      mi[i]=min(mi[i],s[j]-'a');
      ma[i]=max(ma[i],s[j]-'a');
    }
    ++cnt[ma[i]];
  }
  for(int i=1;i<=n;++i){
    int c=0;
    for(int j=mi[i]+1;j<26;++j)c+=cnt[j];
    if(ma[i]!=mi[i])--c;
    if(c==n-1)cout<<1;
    else cout<<0;
  }
  cout<<endl;
  return 0;
}
