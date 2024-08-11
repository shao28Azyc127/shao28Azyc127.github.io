#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100+5,N2=1e6+5;
int n,cur,tot,id[N][N],fa[N2],wht[N2];
string nd,tpp,d2[N*N],tp[N],tt[N];
map<string,int>mp,d;
int main(){
  freopen("struct.in","r",stdin);
  freopen("struct.out","w",stdout);
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin>>n;
  mp["byte"]=1;mp["short"]=2;mp["int"]=4;mp["long"]=8;
  for(int i=1;i<=n;++i){
    int op,k;cin>>op;
    if(op==1){
      cin>>nd>>k;
      int ma=0;
      for(int j=1;j<=k;++j){
        cin>>tp[j]>>tt[j];
        ma=max(ma,mp[tp[j]]);
      }
      cout<<ma*k<<" "<<ma<<endl;
    }else if(op==2){
      string tmp;
      cin>>tpp>>tmp;
      cout<<cur<<endl;
      if(d.count(tmp)==0)d[tmp]=++tot,d2[tot]=tmp;
      if(tpp==nd){
        int ma=0;
        for(int j=1;j<=k;++j){
          if(d.count(tt[j])==0)d[tt[j]]=++tot,d2[tot]=tt[j];
          ma=max(ma,mp[tp[j]]);
        }
        for(int j=1;j<=k;++j){
          id[d[tmp]][d[tt[j]]]=cur;
          for(int l=cur;l<=cur+mp[tp[j]]-1;++l){
            wht[l]=d[tt[j]];
            fa[l]=d[tmp];
          }
          cur+=ma;
        }
      }else{
        for(int j=cur;j<=cur+mp[tpp]-1;++j)wht[j]=d[tmp];
        id[d[tmp]][0]=cur;
        cur+=mp[tpp];
      }
    }else if(op==3){
      string tmp;cin>>tmp;
      int mid=-1,x,y;
      for(int j=0;j<tmp.size();++j){
        if(tmp[j]=='.'){
          mid=j;
          break;
        }
      }
      if(mid==-1)x=d[tmp],y=0;
      else{
        string t="";
        for(int j=0;j<mid;++j)t.push_back(tmp[j]);
        x=d[t];
        t="";
        for(int j=mid+1;j<tmp.size();++j)t.push_back(tmp[j]);
        y=d[t];
      }
      cout<<id[x][y]<<endl;
    }else if(op==4){
      ll tmp;cin>>tmp;
      if(tmp>1e5||!wht[tmp]){
        cout<<"ERR"<<endl;
        continue;
      }
      if(fa[tmp])cout<<d2[fa[tmp]]<<"."<<d2[wht[tmp]]<<endl;
      else cout<<d2[wht[tmp]]<<endl;
    }
  }
  return 0;
}
