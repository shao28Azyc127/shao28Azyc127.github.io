#include<bits/stdc++.h>
using namespace std;
long long t, m ,a, b, c, d, e, num[1005], z[1005], cnt;
long long gcd(long long a, long long b){
    while(1){
            int c;
        if(a % b == 0) return b;
        else c = a, a = b, b = c % b;
    }
}int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &t, &m);
    while(t--){
        scanf("%d%d%d", &a, &b, &c); d = 2 * a; e = 0;
        if(b == 0 && c == 0){
            printf("0\n"); continue;
        }if(a > 0 && b < 0) e = 0;
        else if(a < 0 && b < 0) e = -2 * b;
        else if(a > 0 && b > 0) e = -2 * b;
        else if(a < 0 && b > 0) e = 0;
        else if(d < 0) d = -d, e = -e;
        int k = gcd(d, e); d /= k; e /= k;
        if(e == 0) printf("0\n");
        else if(d == 1) printf("%d\n", e);
        else printf("%d/%d\n", e, d);
    }
    return 0;
}