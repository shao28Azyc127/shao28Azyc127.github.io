#include <bits/stdc++.h>
using namespace std;
int a[8];
int f(int n){
    int i=0;
    while(n>0)
    {i++;
     n=n/10;
    }
    return i;
}
int g(int n){
    int d;
    while(d*d<=n/2)
    {if(n/d/d==n*1.0/d/d)
     {
      return d;
     }
    }
    return -1;
}
int main(){
    freopen(uqe.in,"r",stdin);
    freopen(uqe.out,"w",stdout);
    int T,M;
    scanf("%d %d",&T,&M);
    int q1,q2,r,n,m,delta,ans,l;
    bool b[8];
    string s;
    for(int i=1;i<=T;i++)
    {
     getline(cin,s);
     n=s.size();
     for(int j=1;j<=n;j++)
     {m=0;
      if(s[j]==' ')
      {
       m++;
       bool[m]=true;
      }
      if(s[j]=='-')
      {
       m++;
       bool[m]=false;
      }
      if(s[j]>='0'&&s[j]<='9')
      {
       a[m]=a[m]*10+(s[j]-48);
      }
      for(int k=1;k<=3;k++)
      {if(b[k]==false)
       {
        a[k]=-a[k];
       }
      }
     }
     delta=a[2]*a[2]-4*a[1]*a[3];
     if(delta<0)
     {
      printf("NO");
      cout<<endl;
     }
     else if(sqrt(delta)/1.0=sqrt(delta))
     {
      ans=(-a[2]+sqrt(delta));
      printf("%d",ans);
      cout<<"/"<<2*a[1]<<endl;
      
     }
     else
     {if(-a[2]/2.0/a[1]==-a[2]/2/a[1])
      {
       cout<<-a[2]/2/a[1];
      }
      else
      {
       cout<<-a[2]<<"/"<<2*a[1]<<"+";
      }
      if(g(delta)==-1)
      {
       cout<<1<<"/"<<2*a[1]<<"*sqrt("<<delta<<")"<<endl;
      }
      else
      {if(g(delta)/2.0/a[1]==g(delta)/2/a[1])
       {cout<<g(delta)/2/a[1]<<"*"<<"sqrt("<<delta/g(delta)/g(delta)<<")"<<endl;}
        else
        {cout<<g(delta)<<"/"<<2*a[1]<<"*"<<"sqrt("<<delta/g(delta)/g(delta)<<")"<<endl;}
      }
     }
    }
    return 0;
}