//lock
#include<stdio.h>
//#include<algorithm>
//#include<queue>
//using namespace std;
#define G getchar_unlocked()
int re(){
  int i=0,c,f=0;
  while((c=G)<48)
    c=='-'&&(f=1);
  for(;c>47;c=G)
    i=(i<<1)+(i<<3)+(c^48);
  return f?-i:i;
}
int a[8][5];
int exist[100000];
//priority_queue<int,vector<int>,greater<int>> Q;
int main(){
  freopen("lock.in","r",stdin);
  freopen("lock.out","w",stdout);
  int n=re();
  for(int i=0;i<n;++i)
    for(int j=0;j<5;++j)
      a[i][j]=re();
  auto modify=[&](int n,int i,int k){
    int t=0;
    for(int j=0;j<5;++j){
      t=(t<<3)+(t<<1);
      if(j==i)t+=(a[n][j]+k)%10;
      else t+=a[n][j];
    }
    return t;
  };
  auto modi_1=[&](int n,int i,int k){
    int t=0;
    for(int j=0;j<5;++j){
      t=(t<<3)+(t<<1);
      if(j==i){
        t+=(a[n][j]+k)%10;
        t=(t<<3)+(t<<1);
        t+=(a[n][++j]+k)%10;
      }
      else t+=a[n][j];
    }
    return t;
  };

  for(int k=0;k<n;++k){
    for(int i=0;i<5;++i)
      for(int j=1;j<10;++j)
        ++exist[modify(k,i,j)];
    for(int i=0;i<4;++i)
      for(int j=1;j<10;++j)
        ++exist[modi_1(k,i,j)];
  }
  int ans=0;
  for(int i=0;i<100000;++i)
    if(exist[i]==n)++ans;
  printf("%d\n",ans);
  return 0;
}
