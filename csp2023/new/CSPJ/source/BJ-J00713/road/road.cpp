#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,d;
long long cnt,val=-1,gas;
long long w[1000050];
long long ans=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(long long i=1;i<=n-1;i++){
        scanf("%lld",&w[i]);
    }
    for(long long i=1;i<=n;i++){
        long long v;
        scanf("%lld",&v);
        val=((val==-1)?v:min(val,v));
        cnt+=w[i];

        if(cnt>gas){
            long long ned=cnt-gas;
            if(ned%d==0){
                ans+=ned/d*val;
                gas+=ned;
            }else{
                ans+=(ned/d+1)*val;
                gas+=(ned/d+1)*d;
            }
        }
    }
    cout<<ans;
    return 0;
}
