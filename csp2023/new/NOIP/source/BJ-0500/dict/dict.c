#include<stdio.h>
#include<string.h>
int n,m;
short s[3000][26];
char st[3000][3001];
_Bool cmp[3000][3000],yes[3000][3000];
_Bool scmp(int n,int m){
  for(int i=0;i<26;++i){
    if(s[n][i]){
      for(int j=25;~j;--j)
        if(s[m][j]){
          //printf("\nn=%s m=%s n:%c m:%c n:%d m:%d\n",st[n],st[m],i+'a',j+'a',s[n][i],s[m][j]);
          if(i<j)return 1;
          return 0;
        }
    }
  }
  return 0;
}
int main(){
  freopen("dict.in","r",stdin),freopen("dict.out","w",stdout);
  scanf("%d%d",&n,&m);
  if(n==1)return putchar(49),0;
  for(int i=0;i<n;++i){
    scanf("%s",st[i]);
    for(int j=0;j<m;++j)++s[i][st[i][j]-'a'];
  }
  int t=0;
  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
      if(i==j)continue;
      if(yes[i][j]){
        if(!cmp[i][j])
          putchar(48);goto _;
      }
      else if(!(yes[i][j]=1,cmp[i][j]=scmp(i,j))){
        putchar(48);goto _;
      }
    }
    putchar(49);
    _:;
  }
  return 0;
}
