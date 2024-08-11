#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
   int q=0,a[10000],p[10000],v[10000],n,d,s=0,z=0,l=0,t[6];
   cin>>n>>d;
   for(int i=1;i<n;i++){
    cin>>v[i];
    z=z+v[i];
   }
   for(int i=1;i<=n;i++){
    cin>>a[i];
    p[i]=a[i];
   }
 sort(a+1,a+n+1);
 s=a[1]*z/d;
 cout<<s;
return 0;
}
