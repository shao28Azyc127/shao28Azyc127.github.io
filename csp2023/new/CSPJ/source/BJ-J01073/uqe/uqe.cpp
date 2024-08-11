#include <bits/stdc++.h>
using namespace std;
int t, m;
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &t, &m);
    while(t--) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        if(b == 0) {
            if(a * c > 0) printf("NO\n");
            else if(c == 0) printf("0\n");
            else {
                int zi = abs(c), mu = abs(a);
                zi /= gcd(zi, mu), mu /= gcd(zi, mu);
                int out = 1;
                for(int i = 1; i <= zi * mu; i++)
                    if((zi * mu) % i == 0 && ceil(sqrt(i)) == (floor)(sqrt(i))) out *= sqrt(i);
                // zi = out*sqrt{zi*mu}, mu = mu
                out /= gcd(out, mu), mu /= gcd(out, mu);
                if(mu == 1) {
                    if(out == 1) printf("sqrt(%d)\n", zi * mu);
                    else printf("%d*sqrt(%d))\n", out, zi * mu / out);
                }
                else {
                    if(out == 1) printf("sqrt(%d)/%d\n", zi * mu, mu);
                    else printf("%d*sqrt(%d))/%d\n", out, zi * mu / out, mu);
                }
            }
        }
        else if(c == 0) {
            int x = max(0, -b);
            printf("%d\n", x);
        }
        else printf("NO\n");
    }    
    return 0;
}