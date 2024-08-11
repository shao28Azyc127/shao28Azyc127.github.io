#include<stdio.h>
#define G getchar_unlocked()
#define ll long long
r(){
  int i=0,c,f=0;
  while((c=G)<48)c=='-'&&(f^=1);
  for(;c>47;c=G)i=i*10+(c^48);
  return f?-i:i;
}
void put(int i){
  if(i<0)putchar('-'),i=-i;
  if(i>9)put(i/10);
  putchar(i%10^48);
}
a1[500000],a2[500000],tmp,c,n,m,q;
qa1[500000],qa2[500000];
_Bool res[5000][5000],ok[5000][5000];
_Bool search(int i,int j){
  if(ok[i][j])return res[i][j];
  if(qa1[i]<=qa2[j]){ok[i][j]=1;return 0;}
  if(i==n&&j==m){ok[i][j]=1;return res[i][j]=1;}
  _Bool res1=search(i,j+1);ok[i][j+1]=1,res[i][j+1]=res1;
  _Bool res2=search(i+1,j+1);ok[i+1][j+1]=1,res[i+1][j+1]=res2;
  return res1||res2;
}
void print(a,b){
if(a!=b){
      putchar('1');
    }
    else{
      putchar('0');
    }
}
main(){
  freopen("expand.in","r",stdin),freopen("expand.out","w",stdout);
  c=r(),n=r(),m=r(),q=r();
  if(n==1){
    int a=r(),b=r();
    print(a,b);
    while(q--){int kx=r(),ky=r();while(kx--){r(),a=r();}while(ky--){r(),b=r();}print(a,b);}
  }
  else{
  for(int i=0;i<n;++i)a1[i]=r();
  for(int i=0;i<m;++i)a2[i]=r();
  if(*a1==*a2){putchar('0');goto _;}
  if(*a1<*a2){
    for(int i=0;i<n>m?n:m;++i)
      tmp=a1[i],a1[i]=a2[i],a2[i]=tmp;
    tmp=n,n=m,m=tmp;
  }
  for(int i=0;i<n;++i)qa1[i]=a1[i];
  for(int i=0;i<m;++i)qa2[i]=a2[i];
  _Bool ans=search(0,0);
  putchar(ans?'1':'0');
  _:;
  while(q--){
    for(int i=0;i<n;++i)qa1[i]=a1[i];
    for(int i=0;i<m;++i)qa2[i]=a2[i];
    int kx=r(),ky=r();
    while(kx--){
      int pos=r()-1;qa1[pos]=r();
    }
    while(ky--){
      int pos=r()-1;qa2[pos]=r();
    }
    _Bool ans=search(0,0);
    putchar(ans?'1':'0');
  }
  }
}
