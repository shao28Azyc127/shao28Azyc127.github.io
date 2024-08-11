//CSP-J2023l!2
#include<stdio.h>
#include<math.h>
#include<iostream>
using std::max;
#define G getchar_unlocked()
#define ll long long
#define MAXN 100001

void print(int zi,int mu){
  if(mu==1)printf("%d",zi);
  else printf("%d/%d",zi,mu);
}
int main(){
  freopen("uqe.in","r",stdin);
  freopen("uqe.out","w",stdout);
  int q,maxi;scanf("%d%d",&q,&maxi);
  while(q--){
    int a,b,c;scanf("%d%d%d",&a,&b,&c);
    int inside=b*b-4*a*c;
    if(inside<0||a==0){/*printf("inside=%d a=%d b=%d c=%d\n",inside,a,b,c);*/puts("NO");continue;}
    int zi=-b,mu=a<<1,s;
    int gg=sqrt(inside);
    a<0?s=-1:(s=1);
    if(gg*gg==inside){
      int au=zi+s*gg;
      bool sign=(au<0&&mu<0)||(au>=0&&mu>=0);
      au<0&&(au=-au),mu<0&&(mu=-mu);
      if(!sign)putchar('-');
      for(int i=2;i<=max(au,mu);++i)
        while(au%i==0&&mu%i==0)au/=i,mu/=i;
      if(mu==1)printf("%d",au);
      else printf("%d/%d",au,mu);
    }
    else{
      float fenzi=s*sqrt(inside)+zi;
      int tmpzi=zi,tmpmu=mu,tu=mu;
      zi<0&&(zi=-zi),mu<0&&(mu=-mu),tu<0&&(tu=-tu);
      int d;
      for(int i=2;i<=max(zi,mu);++i){
        while(zi%i==0&&mu%i==0)
          zi/=i,mu/=i;
      }
      //printf("zi=%d inside=%d mu=%d\n",zi,inside,mu);
      for(int i=2;i<=max(inside,tu);++i){
        while(inside%(d=i*i)==0&&tu%i==0)
          inside/=d,tu/=i;
      }
      bool pri=0;
      if(zi!=0){
        /*if(zi==mu){
          if((tmpzi<0&&tmpmu>0)||(tmpzi>0&&tmpmu<0))putchar('-');
          putchar(49);pri=1;goto _;}*/
        pri=1;
        if((tmpzi>0&&tmpmu>0)||(tmpzi<0&&tmpmu<0))
          print(zi,mu);
        else putchar('-'),print(zi,mu);
      }
      _:;
      if((s==1&&tmpmu>0)||(s==-1&&tmpmu<0))pri==1&&(putchar('+'));
      else putchar('-');
      int cheng=1;
      for(int i=2;i<inside;++i)
        while(inside%(d=i*i)==0)inside/=d,cheng*=i;
      if(cheng==1){
        if(tu==1)printf("sqrt(%d)",inside);
        else printf("sqrt(%d)/%d",inside,tu);
      }
      else{
        if(tu==1)printf("%d*sqrt(%d)",cheng,inside);
        else printf("%d*sqrt(%d)/%d",cheng,inside,tu);
      }
    }
    putchar(10);
  }
  return 0;
}
