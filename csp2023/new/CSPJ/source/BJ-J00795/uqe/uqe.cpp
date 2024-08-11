#include <cstdio>
#include <cmath>
int gcd(int a, int b){
    if(a == 0){
        return b;
    }
    return gcd(b % a, a);
}
int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m, a, b, c, d, delta;
    scanf("%d %d", &t, &m);
    for(int i = 1; i <= t; i++){
        scanf("%d %d %d", &a, &b, &c);
        d = 1;
        delta = -4 * a * c;
        if(delta < 0){
            printf("NO");
            continue;
        }
        for(int i = sqrt(delta); i > 0; i--){
            if(delta % (i * i) == 0){
                d = i;
                break;
            }
        }
        if(d == 2 * a){
            printf("sqrt(%d)", delta / d / d);
        }else if(d % (2 * a) == 0){
            printf("%d*sqrt(%d)", d / 2 / a, delta / d / d);
        }else if((2 * a) % d == 0){
            printf("sqrt(%d)/%d", delta / d / d, 2 * a / d);
        }else{
            printf("%d*sqrt(%d)/%d", d * gcd(d, 2 * a), delta / d / d, 2 * a * gcd(d, 2 * a));
        }
    }
    return 0;
}//30
