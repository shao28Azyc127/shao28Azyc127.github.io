#include<vector>
#include<algorithm>
#include<iostream>
#include<stdio.h>
//#include<pair>
#define ll long long
using namespace std;
char s[2000001];
int length;
ll f[2000001];
struct str{int l,r;};
vector<str> V;
bool cmp(str A,str B){
  if(A.l!=B.l)
    return A.l<B.l;
  return A.r>B.r;
}
int main(){
  freopen("game.in","r",stdin);
  freopen("game.out","w",stdout);
  scanf("%d%s",&length,s);
  for(int i=0;i<length-1;++i)
    if(s[i]==s[i+1]){
      V.push_back({i,i+1});
      int x=i-1,y=i+2;
      while(x>=0&&y<length&&s[x]==s[y]){
        V.push_back({x--,y++});
      }
    }
  sort(V.begin(),V.end(),cmp);
  /*puts("reach1");
  for(str i:V){
    printf("same:%d %d\n",i.l,i.r);
  }*/
  for(int i=V.size()-1;i>=0;--i)
    f[V[i].l]+=f[V[i].r+1]+1;
  ll sum=0;
  for(int i=0;i<length;++i)
    sum+=f[i];
  printf("%lld\n",sum);
  return 0;
}
