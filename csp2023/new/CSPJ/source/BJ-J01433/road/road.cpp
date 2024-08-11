#include<bits/stdc++.h>
using namespace std;
int n,d,a[100100],p[100100];
long long ans,sum[100100];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    double left=0;
    for(int i=1;i<n;i++){
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }for(int i=1;i<n;i++){

        int j=i;
        while(p[i]<=p[j+1]&&j<n){ac
            j++;
        }
        if(j>n-1){
            j=n-1;
        }
        ans+=ceil(((sum[j]-sum[i-1])-left*d)*1.0/d)*p[i];
        left=ceil(((sum[j]-sum[i-1])-left*d)*1.0/d)-((sum[j]-sum[i-1])-left*d)*1.0/d;
        //cout<<sum[j]-sum[i-1]<<' '<<ceil(((sum[j]-sum[i-1])-left*1.0*d)*1.0/d)<<' '<<ans<<' '<<left<<endl;
        i=j;
    }
    printf("%lld",ans);
    return 0;
}
