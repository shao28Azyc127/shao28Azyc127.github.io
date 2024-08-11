#include<bits/stdc++.h>
using namespace std;int dis[100010],pri[100010];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
   int n,d;cin>>n>>d;int s=0;
   for(int i=2;i<=n;i++)
   cin>>dis[i];s=s+dis[i];
   for(int i=1;i<=n;i++){
    cin>>pri[i];
   }
   int  sum;
   if(s%d==0){
        sum=s/d;
   }else{
        sum=s/d+1;
   }
   sum=sum*pri[1];
   cout<<sum;
    return 0;
}
