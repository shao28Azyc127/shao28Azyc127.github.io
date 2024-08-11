#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int delta(int a, int b, int c){
    return b * b - 4 * a * c;
}
int sign(int x){
    if(x > 0) return 1;
    else if(x == 0) return 0;
    return -1;
}
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}
int simp_sqrt(int x){
    for(int i = 2; i * i <= x; i++){
        while(x % (i * i) == 0){
            x /= i * i;
        }
    }
    return x;
}
void print_frac(int x, int y, int sq=0){
    if(x % y == 0){
        if(!sq) printf("%d", x / y);
        else{
            if(x / y != sign(x / y)) printf("%d*sqrt(%d)", x / y, sq);
            else printf("sqrt(%d)", sq);
        }
        return;
    }
    double ans = 1.0 * x / y;
    x = abs(x);
    y = abs(y);
    int gcdans = gcd(x, y);
    if(ans < 0 && !sq) printf("-");
    x /= gcdans;
    y /= gcdans;
    if(!sq) printf("%d/%d", x , y);
    else if(x == 1) printf("sqrt(%d)/%d", sq, y);
    else printf("%d*sqrt(%d)/%d", x, sq, y);
}
int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, _;
    scanf("%d%d", &t, &_);
    while(t--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if(a < 0){
            a = -a;
            b = -b;
            c = -c;
        }
        int gcdans = gcd(abs(a), gcd(abs(b), abs(c)));
        a /= gcdans;
        b /= gcdans;
        c /= gcdans;
        int d = delta(a, b, c);
        if(d < 0){
            printf("NO\n");
            continue;
        }else if(d == 0){
            print_frac(-b, 2 * a);
        }else{
            int sqd = sqrt(d);
            if(sqd * sqd == d){
                print_frac(-b + sqd, 2 * a);
            }else{
                if(b){
                    print_frac(-b, 2 * a);
                    printf("+");
                }
                int simp = simp_sqrt(d);
                int mul = sqrt(d / simp);
                print_frac(mul, 2 * a, simp);
            }
        }
        printf("\n");
    }
    return 0;
}