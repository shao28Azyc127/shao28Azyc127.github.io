#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int n, d;
int v[maxn], a[maxn];
long long sum[maxn];
long long money=0, fuel=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d", &n, &d);
    for(int i=2;i<=n;i++){
        scanf("%d", &v[i]);
        sum[i]=sum[i-1]+v[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    int mn=a[1], mnx=1;
    for(int i=2;i<=n;i++){
        if(a[i]<mn){
            long long dis=sum[i]-sum[mnx];
            long long m=(dis+d-1-fuel)/d;
            money+=m*a[mnx];
            fuel=fuel+m*d-dis;
            mn=a[i];
            mnx=i;
        }
    }
    if(mnx!=n){
        long long dis=sum[n]-sum[mnx];
        long long m=(dis+d-1-fuel)/d;
        money+=m*a[mnx];
    }
    printf("%lld", money);
    return 0;
}
