#include <iostream>
using namespace std;
int n,d,v[100001],a[100001],zs[100001];
struct node{
    long long m;
    long long y;
}dp[100001];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n-1;i++){
        scanf("%d",&v[i]);
        zs[i]=zs[i-1]+v[i];
    }
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=2;i<=n;i++){
        dp[i].m=10000000000000001;
        for(int j=1;j<i;j++){
            if(dp[j].m+((zs[i-1]-zs[j-1]-dp[j].y)/d+(((zs[i-1]-zs[j-1]-dp[j].y)%d)>0?1:0))*a[j]<dp[i].m){
                if(((zs[i-1]-zs[j-1]-dp[j].y)%d)>0) dp[i].y=d-(zs[i-1]-zs[j-1]-dp[j].y)%d;
                dp[i].m=dp[j].m+((zs[i-1]-zs[j-1]-dp[j].y)/d+(((zs[i-1]-zs[j-1]-dp[j].y)%d)>0?1:0))*a[j];
            }            
        }
    }
    printf("%lld",dp[n].m);
    fclose(stdin);
    fclose(stdout);
    return 0;
}