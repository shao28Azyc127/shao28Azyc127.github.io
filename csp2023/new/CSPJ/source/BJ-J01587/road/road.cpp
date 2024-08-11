#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL NR = 1e5;
LL v[NR + 10];
LL a[NR + 10];

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    LL n;
    LL d;
    scanf("%lld%lld", &n, &d);
    for(int i = 1;i < n;i++){
        scanf("%lld", &v[i]);
    }
    a[0] = LLONG_MAX;
    for(int i = 1;i <= n;i++){
        scanf("%lld", &a[i]);
        a[i] = min(a[i], a[i - 1]);
        //printf("%lld ", a[i]);
    }
    //printf("\n");
    LL sum = 0;
    LL oil = 0;
    //printf("%lld\n", sum);
    for(int i = 1;i < n;i++){
        if(oil > v[i]){
            oil -= v[i];
            continue;
        }
        LL tmp = (LL)ceil(1.0 * (v[i] - oil) / d);
        sum += tmp * a[i];
        oil = oil + tmp * d - v[i];
        //printf("oil=%lld ", oil);
        //printf("tmp=%lld\n", tmp);
    }
    printf("%lld\n", sum);
    return 0;
}
/*
5 4
10 10 10 10
9 8 9 6 5
*/
