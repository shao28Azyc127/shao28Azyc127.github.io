#include<bits/stdc++.h>
using namespace std;
//CSP-J 2023 RP ++ !!!;
int n, t, m, a, b, c, kn, zc, zk;
float d, kf, x1, x2;

int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &t, &m);
    while(t --){
        scanf("%d%d%d", &a, &b, &c);
        d = float(b) * float(b) - 4.0 * float(a) * float(c);
        if(d < 0){
            printf("NO\n");
            continue;
        }else if(d == 0){
            if(b == 0){
                printf("0\n");
                continue;
            }
            a *= 2;
            b = -b;
            zc = __gcd(a, b);
            if(zc < 0){
                zc = -zc;
            }
            if((a > 0 && b < 0) || (a < 0 && b > 0)){
                printf("-");
            }
            if(a < 0){
                a = -a;
            }
            if(b < 0){
                b = -b;
            }
            if(b % a == 0){
                printf("%d", b / a);
                continue;
            }
            printf("%d/%d\n", b / zc, a / zc);
            continue;
        }
        if(sqrt(d) == float(int(sqrt(d)))){
            kn = sqrt(d);
            a *= 2;
            x1 = float(-1 * b + kn) / float(a);
            x2 = float(-1 * b - kn) / float(a);
            if(x1 > x2){
                b = -1 * b + kn;
            }else{
                b = -1 * b - kn;
            }
            if(b == 0){
                printf("0\n");
                continue;
            }
            zc = __gcd(a, b);
            if(zc < 0){
                zc = -zc;
            }
            if((a > 0 && b < 0) || (a < 0 && b > 0)){
                printf("-");
            }
            if(a < 0){
                a = -a;
            }
            if(b < 0){
                b = -b;
            }
            if(float(a) / float(zc) == 1){
                printf("%d", b / zc);
                continue;
            }
            printf("%d/%d\n", b / zc, a / zc);
            continue;
        }
    }
    return 0;
}
