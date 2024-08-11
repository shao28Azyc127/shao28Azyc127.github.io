#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
typedef long long ll;
ll n, d, v[N], a[N], s[N], ans, pos, mon;
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld%lld", &n, &d);
    for(int i = 2; i <= n; i++){
        scanf("%lld", &v[i]);
        s[i] = s[i-1] + v[i];
    }
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    a[n] = -1;
    ll i = 1;
    while(i<n){
        ll j, sum;
        for(j = i+1; j <= n; j++)
            if(a[j] < a[i]) break;
        sum = (s[j]-pos)/d;
        if((s[j]-pos) % d) sum++;
        pos += sum*d, mon += sum*a[i];
        i = j;
    }
    printf("%lld", mon);
    return 0;
}
