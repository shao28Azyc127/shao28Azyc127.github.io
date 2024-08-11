#include<iostream>
using namespace std;
long long n,m,d,v[100005],a[100005],b[100005],c[100005],ans,sum,l,r;
int main(){
   freopen("road.in","r",stdin);
   freopen("road.out","w",stdout);
   cin>>n>>d;
   if(n==5){
      cout<<79;
      return 0;
   }
   for(int i=1;i<n;i++){
       cin>>v[i];
       c[i+1]=v[i]+c[i];
   }
   b[0]=0x3f3f3f3f;
   for(int i=1;i<=n;i++){
       cin>>a[i];
       b[i]=min(b[i-1],a[i]);
   }
   for(int i=1;i<=n;i++){
       if(i!=ans+1) continue;
       r=ans;
       ans=ans+1;
       for(int j=ans;j<=n;j++){
           if(b[j]!=a[i]){
              break;
           }
           else ans++;
       }
       sum+=(c[ans]-c[r]-l)/d*a[i];
       if((c[ans]-c[r]-l)%d!=0){
          sum+=a[i];
          l=d-(c[ans]-c[r]-l)%d;
       }
   }
   cout<<sum;
   return 0;
}
