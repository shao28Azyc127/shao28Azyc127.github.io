#include <bits/stdc++.h>
using namespace std;
int n,d,v[100005],a[100005];
int dp[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=0;i<n-1;i++) scanf("%d",&v[i]);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int min_=INT_MAX,xiabiao;
        for(int j=0;j<i;j++){
            if(min_>a[j]){
                min_=a[j];
                xiabiao=j;
            }
        }
        int len=0;
        for(int j=xiabiao;j<i;j++) len+=v[j];
        int price=0;
        if(len%d==0) price=a[xiabiao]*(len/d);
        else{
            price=a[xiabiao]*((len/d)+1);
        }
        dp[i]=dp[xiabiao]+price;
    }
    printf("%d\n",dp[n-1]);
    return 0;
}
