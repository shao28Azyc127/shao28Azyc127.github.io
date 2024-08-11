#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("road.in","r",stdin);
   freopen("road.out","w",stdout);
  int n,v[1000],a[1000],d,sum;
  cin>>n>>d;
  for(int i=1;i<n;i++)
  {
      cin>>v[i];
      cin>>a[i];
      sum+=v[i];
  }
  if(sum%a[1]==0)
    cout<<sum/a[1];
  else
    cout<<sum/v[1]+1;
return 0;
}
