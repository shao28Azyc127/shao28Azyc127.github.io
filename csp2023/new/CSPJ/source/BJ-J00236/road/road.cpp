#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("road.in","r",stdin);
   freopen("road.out","w",stdout);
   ios::sync_with_stdio(false);
   int n,d;
   cin>>n>>d;
   int u[n+2];
   int a[n+2];
   int money=0;
   for(int i=1;i<n;i++)
   {
       cin>>u[i];
   }
   u[n]=0;
   for(int i=1;i<=n;i++)
   {
       cin>>a[i];
   }

   int k=0,s=0;
   for(int j=1;j<n;j++)
   {
      if(a[j]>=a[j+1])
      {
         break;
      }
      s+=u[j];
      if(j==n-1)
      {
          int cnt=ceil(s/d);
          cout<<cnt*a[1];
          return 0;
      }
   }
   for(int i=1;i<n;i++)
   {

       int sum=0;
       k=u[i];
       for(int j=i+1;j<n;j++)
       {
           if(a[i]<a[j])
           {
               sum++;
               k+=u[j];
           }
           else
           {
               break;
           }
       }

       if(sum!=0)
       {
           int m=ceil(k/d);
           i+=sum;
            money+=m*a[i];
            k=m*d-k;
       }
       else
        {
            int m=ceil(u[i]/d);
             money+=m*a[i];
            k=m*d-k;
        }

    }
    cout<<money;

   return 0;
}
