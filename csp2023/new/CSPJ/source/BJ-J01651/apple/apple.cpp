//CSP-J2023l!2
#include<stdio.h>
#define G getchar_unlocked()
#define MAXN 1000000001
long long n,role;
bool en;
int re(){
  int i=0,c,f=0;
  while((c=G)<48)c=='-'&&(f=1);
  for(;c>47;c=G)i=(i<<1)+(i<<3)+(c^48);
  return i;
}
long long f(int n){
  if(n<=3){if(!en)role+=n;return n;}
  if(!en){
    ++role;//printf("%d %d\n",n,role);
    if(n==(n/3)*3+1)
      en=1;
  }
  return f(n-n/3-1)+1;
}
int main(){
  freopen("apple.in","r",stdin);
  freopen("apple.out","w",stdout);
  printf("%lld ",f(re()));
  printf("%lld\n",role);
  return 0;
}
