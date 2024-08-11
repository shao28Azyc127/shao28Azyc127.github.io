#include <bits/stdc++.h>
using namespace std;
int a[100100],dp[100100],n,d,i,j,s=0,sum[100100],t;
int ro(int b,int a){
    int ans=0;
    if(s>b) s=(s-b);
    else {
        ans+=(b-s)/d*a;
        if((b-s)%d!=0) ans+=a;
    }
    return ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(i=2;i<=n;i++) {scanf("%d",&t);sum[i]=sum[i-1]+t;}
    for(i=1;i<=n;i++) {scanf("%d",&a[i]);}
    for(i=1;i<=n;i++){
		dp[i]=dp[i-1]+ro(sum[i],a[i-1]);
        for(j=1;j<i;j++)
            dp[i]=min(dp[i-j]+ro(sum[i]-sum[i-j],a[i-j]),dp[i]);
    }
    printf("%d",dp[n]);
    return 0;
}
