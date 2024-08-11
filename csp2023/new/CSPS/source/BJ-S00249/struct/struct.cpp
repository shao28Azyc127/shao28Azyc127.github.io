#include <bits/stdc++.h>
using namespace std;
struct ibasic{
  int startaddr;
  string t,x;
};
struct istruct{
  int startaddr,totsize;
  string name;
  vector<string> t,x;
};
int n,k,addr,maxcnt,totaddr=-1;
string s,t,x;
ibasic init_basic;
istruct init_struct;
vector<ibasic> mem_basic;
vector<istruct> mem_struct;
unordered_map<string,int> sz;
inline void file(){
  freopen("struct.in","r",stdin);
  freopen("struct.out","w",stdout);
}
/*
这次真完蛋了。感觉自己不管是150pts还是160pts都肯定没tg1=。真是没救了。
哎……写一点是一点吧。
*/
int main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  file();
  sz["byte"]=1,sz["short"]=2,sz["int"]=4,sz["long"]=8;
  cin >> n;
  for(int i=1,op;i<=n;++i){
    cin >> op;
    if(op==1){
      cin >> init_struct.name >> k;
      maxcnt=0;
      for(int j=0;j<k;++j){
        cin >> s;
        init_struct.t.push_back(s);
        maxcnt=max(maxcnt,sz[init_struct.t[j]]);
        init_struct.totsize+=sz[init_struct.t[j]];
        cin >> s;
        init_struct.x.push_back(s);
      }
      init_struct.startaddr=((totaddr+maxcnt)/maxcnt)*maxcnt;
      cout << ((init_struct.totsize+maxcnt-1)/maxcnt)*maxcnt << ' ' << maxcnt << '\n';
      mem_struct.push_back(init_struct);
      totaddr=init_struct.startaddr+init_struct.totsize-1;
    }
    else if(op==2){
      cin >> init_basic.t >> init_basic.x;
      init_basic.startaddr=((totaddr+sz[init_basic.t])/sz[init_basic.t])*sz[init_basic.t];
      cout << init_basic.startaddr << '\n';
    }
    else if(op==3){
      cin >> s;
    }
    else{
      cin >> addr;
    }
  }
  return 0;
}