#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,sum[100005],v[100005],ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>k;
    int a=0;
    for(int i=2;i<=n;i++){
        scanf("%d",&a);
        sum[i]=sum[i-1]+a;
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&v[i]);
    }
    v[n]=0;
    ll oil=0;
    int i=1;
    for(int j=i+1;j<=n;j++){
        if(v[i]>v[j]){
            if(sum[j]-sum[i]>=oil){
                ans+=((sum[j]-sum[i]-oil)%k==0?(sum[j]-sum[i]-oil)/k:(sum[j]-sum[i]-oil)/k+1)*v[i];
                if((sum[j]-sum[i]-oil)%k!=0)oil=((sum[j]-sum[i]-oil)/k+1)*k-(sum[j]-sum[i]-oil);//oil=k-(sum[j]-sum[i]-oil)%k;
                else oil=0;
            }else{
                oil-=(sum[j]-sum[i]);
            }
            i=j;
        }
    }
    cout<<ans;
    return 0;
}