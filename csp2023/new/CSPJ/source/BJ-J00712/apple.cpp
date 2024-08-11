#include<iostream>
using namespace std;
#include<cstdio>
int n,m,t,s,q,res;
long long a[100000005];
int main()
{

    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
     cin>>n;
     for(int i=1;i<=n;i++)
     {
         a[i]=1;
     }
     m=n;
     s=1;
     q=1;
     t=1;
     res=0;
     while(m>0)
     {
         if(a[q]==1)
         {
             if(s==1&&q==n)
             {
                 res=t;
                 //a[q]=0;
             }
             if(s==1)
             {
                 a[q]=0;
                 m=m-1;
                 //cout<<m<<endl;
             }
             if(s!=3)
             {
                 s=s+1;
             }
             else
             {
                 s=1;
             }
         }
         if(q==n)
         {
             q=1;
             t=t+1;
             s=1;
         }
         if(q!=n)
         {
             q=q+1;
         }
     }
     if(t-1==res)
     {
         t=t-1;
     }
     cout<<t<<' '<<res<<endl;
     fclose(stdin);
     fclose(stdout);
     return 0;
}

