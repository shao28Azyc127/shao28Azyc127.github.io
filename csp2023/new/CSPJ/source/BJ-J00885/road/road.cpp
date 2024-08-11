#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n,d,w[N],v[N],minn[N];
long long sum,ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i = 1;i < n;i++)
        scanf("%d",&w[i]);
    minn[0] = 1e9;
    for(int i = 1;i <= n;i++){
        scanf("%d",&v[i]);
        minn[i] = min(minn[i - 1],v[i]);
    }
    minn[n] = 1e9;
    for(int i = 1;i < n;i++){
        sum += w[i];
        if(minn[i] != minn[i + 1] && sum > 0){
            int x = 1ll * d - ((sum + d - 1) % d);
            ans += 1ll * (sum + d - 1) / d * minn[i];
            sum = -x;
        }
        //printf("%lld %lld\n",sum,ans);
    }
    printf("%lld\n",ans);
    return 0;
}