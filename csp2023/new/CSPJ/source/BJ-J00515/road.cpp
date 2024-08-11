#include <cstdio>
#include <iostream>
using namespace std;
int n;
long long d,s[100005],p[100005],ans,pmin = 1e9,last,now;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%lld",&n,&d);
    for(int i = 1;i <= n - 1;i++) scanf("%lld",&s[i]);
    for(int i = 1;i <= n;i++) scanf("%lld",&p[i]);
    for(int i = 1;i <= n - 1;i++){
        pmin = min(pmin,p[i]);
        now = s[i] - last;
        if(now % d == 0) ans += now / d * pmin, last = 0;
        else ans += (now / d + 1) * pmin, last = d - now % d;
    }
    printf("%lld",ans);
    return 0;
}