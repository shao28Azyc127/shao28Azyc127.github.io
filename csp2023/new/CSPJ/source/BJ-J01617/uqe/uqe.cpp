#include<bits/stdc++.h>
using namespace std;
int t, m, a, b, c;
int gcd(int x, int y){
    if(y == 0) return x;
    return gcd(y, x%y);
}
int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &t, &m);
    while(t--){
        scanf("%d%d%d", &a, &b, &c);
        if(a < 0) a = -a, b = -b, c = -c;
        int dt = b * b - 4 * a * c;

        if(dt < 0){
            puts("NO");
            continue;
        }
        int s = sqrt(dt);
        if(s * s == dt){
            int x = -b + s, y = 2 * a;
            if(x == 0){
                puts("0");
                continue;
            }
            if(x % y == 0){
                printf("%d\n", x/y);
                continue;
            }
            int z = abs(gcd(x, y));
            x /= z, y /= z;
            printf("%d/%d\n", x, y);
            continue;
        }
        for(int i = s; i >= 1; i--)
            if(dt % (i * i) == 0){
                dt /= i*i;
                int y = 2 * a;
                int z1 = abs(gcd(-b, y)), z2 = abs(gcd(i, y));
                if(b != 0){
                    if(y == z1) printf("%d+", -b/y);
                    else printf("%d/%d+", -b/z1, y/z1);
                }
                if(i == y) printf("sqrt(%d)\n", dt);
                else if(y == z2) printf("%d*sqrt(%d)\n", i/z2, dt);
                else if(i != z2) printf("%d*sqrt(%d)/%d\n", i/z2, dt, y/z2);
                else printf("sqrt(%d)/%d\n", dt, y/z2);
                break;
            }
    }
    return 0;
}
