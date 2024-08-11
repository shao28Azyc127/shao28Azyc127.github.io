#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t, m;
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &t, &m);
    while(t --){
        ll a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        ll delta = (b*b) - (4*a*c);
        if(delta < 0){
            printf("NO\n");
            continue;
        }
        if((double)delta == sqrt(delta)){
            printf("%lld", sqrt(delta));
        }
    }
    return 0;
}