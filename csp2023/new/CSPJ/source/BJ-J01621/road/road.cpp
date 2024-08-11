#include <bits/stdc++.h>
using namespace std;
int n,d,v[100005],a[100005],now=1;long long sum[100005],ans,lou;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){cin>>v[i];sum[i]=v[i]+sum[i-1];}
    for(int i=1;i<=n;i++) cin>>a[i];a[n]=0;
    //for(int i=1;i<n;i++){cout<<sum[i]<<" ";}cout<<endl;
    //cout<<(long long)ceil((double)(sum[5]-sum[4]-0)/4)*a[4]<<endl;
    //cout<<((int)ceil((double)(sum[1]-sum[0]-0)/4))*4-(sum[1]-sum[0]-0)<<endl;
    for(int i=2;i<=n;i++){
        if(a[i]<a[now]){
            ans+=(long long)ceil((double)(sum[i-1]-sum[now-1]-lou)/d)*a[now];
            now=i;
            lou+=(long long)(ceil((double)((sum[i-1]-sum[now-1]-lou)/d))*d)-sum[i-1]+sum[now-1];
        }//cout<<"i="<<i<<" ans="<<ans<<" lou="<<lou<<" now="<<now<<endl;
    }cout<<ans;

    return 0;
}
