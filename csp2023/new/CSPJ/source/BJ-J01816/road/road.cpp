#include<bits/stdc++.h>
using namespace std;
long long n,d,v[100005],a[100005],ans=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<n;i++){
        scanf("%lld",&v[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    long long last=0;
    int i=1;
    while(i<n){
        long long cnt=0;
        for(int j=i+1;j<=n;j++){
            cnt+=v[j-1];
            if(a[i]>a[j] || j==n){
                if(cnt-last>0){
                    if((cnt-last)%d==0){
                        ans+=((cnt-last)/d)*a[i];
                        last=0;
                        //cout<<666;
                    }else{
                        ans+=((cnt-last)/d+1)*a[i];
                        //<<last<<" ";
                        last=(last+(((cnt-last)/d+1)*d))-cnt;
                    }
                }
                //cout<<i<<" "<<j<<" "<<cnt<<" "<<ans<<endl;
                cnt=0;
                i=j;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
