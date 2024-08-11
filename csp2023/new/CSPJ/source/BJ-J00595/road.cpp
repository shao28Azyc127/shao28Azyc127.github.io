#include <bits/stdc++.h>
using namespace std;
int n,m,a[10000],x,b[10000],sum,s,c[10000],z,y;
int main()
{
freopen ("road.in","r",stdin);
freopen("road.out","w",stdout);
cin>>n>>m;
for(int i=1;i<n;i++)
{
 cin>>a[i];
 c[i]=c[i-1]+a[i];
}
for(int i=1;i<=n;i++)
{
 cin>>b[i];
}
x=b[1];
s=1;
z=0;
b[n]=0;
for(int i=2;i<=n;i++)
{
 if(b[i]<x)
 {
  if(c[i]-c[s]-z)%m==0)
  {
  sum+=((c[i]-c[s]-z)/m)*b[s];
  }
  else
  {
  sum+=((c[i]-c[s]-z)/m+1)*b[s];
  }
  z=c[i]%m;
  s=i;
  x=b[i];
 }
}
cout<<sum;
}