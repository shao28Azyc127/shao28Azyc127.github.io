#include<iostream>
#include<cstring>
using namespace std;

const int maxdelta=5e6+10;
int fsqr[maxdelta],T,M,a,b,c,delta;
int dsqr[maxdelta];

int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
int abs(int a){ return a>0?a:-a; }
void print(int a,int b,char end){
  if(b<0)a=-a,b=-b;
  int p=gcd(abs(a),abs(b));
  a/=p; b/=p;
  if(b!=1)cout<<a<<'/'<<b;
  else cout<<a;
  cout<<end;
}

int main(){
  freopen("uqe.in","r",stdin);
  freopen("uqe.out","w",stdout);
  memset(dsqr,-1,sizeof(dsqr));
  memset(fsqr,-1,sizeof(fsqr));
  for(int i=0;i*i<maxdelta;i++){
    dsqr[i*i]=i;
    if(i>1)for(int j=i*i;j<maxdelta;j+=i*i)fsqr[j]=i*i;
  }
  cin>>T>>M;
  while(T--){
    cin>>a>>b>>c;
    delta=b*b-4*a*c;
    if(delta<0)cout<<"NO"<<endl;
    else if(dsqr[delta]!=-1){ // 结果为有理数
      if(a>0)print(dsqr[delta]-b,2*a,'\n');
      else print(-dsqr[delta]-b,2*a,'\n');
    }else{
      if(b!=0)print(-b,2*a,'+');
      int qrmul=1;
      while(fsqr[delta]!=-1)qrmul*=dsqr[fsqr[delta]],delta/=fsqr[delta];
      int divto=2*a;
      if(divto<0)divto=-divto;
      int x=gcd(qrmul,divto); qrmul/=x; divto/=x;
      if(qrmul==1&&divto==1)printf("sqrt(%d)\n",delta);
      else if(qrmul==1)printf("sqrt(%d)/%d\n",delta,divto);
      else if(divto==1)printf("%d*sqrt(%d)\n",qrmul,delta);
      else printf("%d*sqrt(%d)/%d\n",qrmul,delta,divto);
    }
  }
  
}
