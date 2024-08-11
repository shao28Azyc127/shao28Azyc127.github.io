#include <bits/stdc++.h>
using namespace std;
int T, M;
int a, b, c;
int gcd(int a, int b){
    return (b == 0) ? a : gcd(b, a % b);
}
int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &T, &M);
    while(T--){
        scanf("%d%d%d", &a, &b, &c);
        int d = b * b - 4 * a * c;
        if(d < 0){
            printf("NO\n");
        }else{
            if(d == 0){
                int g = gcd(-b, 2*a);
                int p = -b / g;
                int q = 2 * a / g;
                if(p < 0&&q>0||p>0&&q<0){
                    printf("-");
                }
                if(q == 1){
                    printf("%d\n", abs(p));
                    continue;
                }else{
                    printf("%d/%d\n", abs(p), abs(q));
                    continue;
                }
            }else{
                int g = gcd(-b, 2*a);
                int p = -b / g;
                int q = 2 * a / g;
                if(p < 0&&q>0||p>0&&q<0){
                    printf("-");
                }
                if(q == 1){
                    printf("%d\n", abs(p));
                }else{
                    printf("%d/%d\n", abs(p), abs(q));
                }
                int r = 1;
                for(int i = 2; i * i <= d; i++){
                    if(d % i * i == 0){
                        r *= i;
                        d /= i * i;
                    }
                }
                g = gcd(r, 2*a);
                r /= g;
                q = 2*a / g;
                if(sqrt(d) == (int)d){
                    r *= d;
                    d = 0;
                }
                if(r && q) {
                    printf("+");
                }
                else{
                    printf("\n");
                }
                if(q < 0){
                    q = -q;
                    if(r != 1)
                            printf("%d*", r);
                    if(d)
                            printf("sqrt(%d)", d);
                    if(q != 1){
                        printf("/%d\n", q);
                    }else{
                        printf("\n");
                    }
                }else if (q > 0){
                    q = -q;
                    if(r != 1)
                            printf("%d*", r);
                    if(d)
                            printf("sqrt(%d)", d);
                    if(q != 1){
                        printf("/%d\n", q);
                    }else{
                        printf("\n");
                    }
                }
            }
        }
    }
    return 0;
}
