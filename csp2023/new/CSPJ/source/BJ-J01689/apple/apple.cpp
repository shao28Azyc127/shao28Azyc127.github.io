#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("apple.in","r",stdin);
   freopen("apple.out","w",stdout);
   int n,x=1,numn,num;
   bool a[100000],b,c=false;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
       a[i]=false;
   }
   for(int i=1;i<=n;i++)
   {
      int q=1;
      for(int j=2;j<=n+1;j++)
      {
          if(!a[j])
            q++;
          if(q%3==1)
            a[j]=true;

      }
      if(a[n]==true&&c==false){
        numn=i;
        c=true;}
       num=i;
      for(int j=1;j<=n;j++)
      {
          b=true;
          if(!a[j])
            b=false;
      }
      if(b)
        break;

   }
   cout<<num+1<<" "<<numn+1;
return 0;
}

