#include <cstdio>
int n,d,v[100005],a[100005],mn = 1e9;
long long sum[100005],lst,ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i = 1;i < n;i++){
        scanf("%d",&v[i]);
        sum[i] = sum[i - 1] + v[i];
    }
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        if(a[i] < mn){
            ans += ((sum[i - 1] / d + (bool)(sum[i - 1] % d)) * d - lst) / d * mn;
            mn = a[i];
            lst = (sum[i - 1] / d + (bool)(sum[i - 1] % d)) * d;
        }
    }
    ans += ((sum[n - 1] / d + (bool)(sum[n - 1] % d)) * d - lst) / d * mn;
    printf("%lld",ans);
    return 0;
}
