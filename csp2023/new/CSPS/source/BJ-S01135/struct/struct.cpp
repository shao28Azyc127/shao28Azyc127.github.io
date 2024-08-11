//struct
#include<stdio.h>
#include<map>
#include<pair>
#include<iostream>
#include<string>
#include<ctype.h>
#define G getchar_unlocked()
using namespace std;
struct t{
  string name;
  int sum,duiqi,mem;
  string names[100];
  int siz[100];
}struc[300];int l=0;
pair<string,string> objs[300];int obl;
map<string,int> memsiz;
int memor;
int n;
void init(){
  ios::sync_with_stdio(0),cin.tie(nullptr);
  memsiz["byte"]=1;memsiz["short"]=2;memsiz["int"]=4;memsiz["long"]=8;
  cin>>n;
}
int main(){
  freopen("struct.in","r",stdin);
  freopen("struct.out","w",stdout);
  init();
  while(n--){
    int op;cin>>op;
    if(op==1){
      string tmp;
      cin>>struc[l].name>>struc[l].sum;
      for(int i=0;i<struc[l].sum;++i){
        cin>>tmp>>struc[l].names[i];
        struc[l].siz[i]=memsiz[tmp];
        struc[l].duiqi=max(struc[l].duiqi,struc[l].siz[i]);
      }
      memsiz[struc[l].name]=struc[l].mem=struc[l].duiqi*struc[l].sum;
      printf("%d %d\n",struc[l].mem,struc[l].duiqi);
      ++l;
    }
    else if(op==2){
      printf("%d\n",memor);
      cin>>objs[obl].first>>objs[obl].second;
      memor+=memsiz[name];
      ++obl;
    }
    else if(op==3){
      string elm;
      cin>>elm;
    }
    else{
      ;
    }
  }
  return 0;
}
