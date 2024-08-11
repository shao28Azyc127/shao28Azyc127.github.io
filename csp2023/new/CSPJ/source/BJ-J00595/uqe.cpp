#include <bits/stdc++.h>
using namespace std;
int main()
{
freopen ("uqe.in","r",stdin);
freopen("uqe.out","w",stdout);
  {
  cout<<-1*b/gcd(2a,b)<<"/"<<2a/gcd(2a,b)<<endl;
  }
 }
 }
else
{
 if(sqrt(b*b-4*a*c)%1==0)
 {
  if((-1*b+sqrt(b*b-4*a*c))%2a==0)
  {
  cout<<(-1*b+sqrt(b*b-4*a*c))/2a<<endl;
  }
  else
  {
   if(-1*b+sqrt(b*b-4*a*c))%2a>0)
   {
   cout<<-1*b+sqrt(b*b-4*a*c)<<"/"<<2a<<endl;
   }
   else
   {
   cout<<"-"<<-1*b+sqrt(b*b-4*a*c)<<"/"<<2a<<endl;
   }
  }
 }
 else
 {
  if(b>0&&a>0)
  {
   cout<<-b/2a<<"+sqrt("<<b*b-4ac<<")/"<<2a<<endl;
  }
 }
}
}
}