#include<bits/stdc++.h>
using namespace std;
const long long maxn=100005;
long long n, d;
long long v[maxn], a[maxn];
long long dis, pos, mn=1e12, ans=0;
int main() {

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    scanf("%lld %lld", &n, &d);
    for(long long i=2; i<=n; i++) scanf("%lld", &v[i]);
    for(long long i=1; i<=n; i++) scanf("%lld", &a[i]);


    for(long long i=2; i<=n; i++) {
        dis+=v[i];
        mn=min(mn, a[i-1]);
        while(pos<dis) {
            pos+=d;
            ans+=mn;
        }
        //cout<<dis<<" "<<pos<<" "<<v[i]<<" "<<a[i]<<" "<<" "<<mn<<" "<<ans<<endl;
    }

    printf("%lld", ans);
    return 0;
}
