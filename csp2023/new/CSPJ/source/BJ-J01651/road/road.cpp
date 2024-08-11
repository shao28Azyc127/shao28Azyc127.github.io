//CSP-J2023l!2
#include<stdio.h>
#define G getchar_unlocked()
#define ll long long
#define MAXN 100001

int re(){
  int i=0,c,f=0;
  while((c=G)<48)c=='-'&&(f=1);
  for(;c>47;c=G)i=(i<<1)+(i<<3)+(c^48);
  return i;
}

int n,dper,dis[MAXN],a[MAXN];
int main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  n=re(),dper=re();
  for(int i=1;i<n;++i)dis[i]=re();
  for(int i=1;i<=n;++i)a[i]=re();
  ll ans=0,big=a[1],distance=dis[1];
  for(int i=2;i<n;distance+=dis[i++]){
    if(a[i]<big){
      //printf("dis=%d big=%lld ans=%lld a[%d]=%d\n",distance,big,ans,i,a[i]);
      ll di=distance/dper;
      if(distance>0){
        if(di*dper==distance){
          distance=0;
          ans+=di*big;
          big=a[i];
        }
        else{
          distance-=(++di)*dper;
          ans+=di*big;
          big=a[i];
        }
      }
    }
  }
  ll di=0;
  if(distance>0){
    if(distance%dper==0)
      di=distance/dper;
    else di=distance/dper+1;
  }
  printf("%lld\n",ans+di*big);
  return 0;
}

