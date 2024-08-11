#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int t, m, a, b, c, op, sq, x, cnt[1005], vis[1005], p[1005];
int gcd(int x, int y){
    if(x % y == 0) return y;
    return gcd(y, x % y);
}
int sqt(int x){
    for(int i = 0; i <= 3000; ++i)
        if(i * i == x) return i;
}
int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    for(int i = 2; i <= 1000; ++i){
        if(vis[i]) continue;
        vis[i] = 1;
        p[i] = 1;
        for(int j = i * i; j <= 1000; ++j) vis[j] = 1;
    }
    scanf("%d%d", &t, &m);
    while(t--){
        memset(cnt, 0, sizeof(cnt));
        sq = 1;
        scanf("%d%d%d", &a, &b, &c);
        if(b * b - 4 * a * c < 0){
            puts("NO");
            continue;
        } else if(b == 0){
            for(int i = 2; i * i <= -a * c; ++i){
                if(i * i == -a * c){
                    op = 1;
                    sq = i;
                    break;
                }
                if(!p[i]) continue;
                int tmp = i;
                while((-a * c) % tmp == 0) cnt[i]++, tmp *= i;
            }
            if(op == 1){
                int tmp = gcd(max(sq, a), min(sq, a));
                if(a / tmp == 1) printf("%d\n", sq / tmp);
                else printf("%d/%d\n", sq / tmp, a / tmp);
            } else {
                for(int i = 2; i * i <= -a * c; ++i) cnt[i] /= 2, sq *= pow(i, cnt[i]);
                x = -a * c / sq / sq;
                int tmp = gcd(max(sq, a), min(sq, a));
                if(a / tmp == 1 && sq / tmp == 1) printf("sqrt(%d)\n", x);
                else if(a / tmp == 1) printf("%d*sqrt(%d)\n", sq / tmp, x);
                else if(sq / tmp == 1) printf("sqrt(%d)/%d\n", x, a / tmp);
                else printf("%d*sqrt(%d)/%d\n", sq / tmp, x, a / tmp);
            }
        } else if(c == 0){
            printf("%d\n", max(-b, 0));
        } else {
            int tmp = b * b - 4 * a * c;
            if(a > 0) printf("%d\n", (-b + sqt(tmp)) / (2 * a));
            else printf("%d\n", (-b - sqt(tmp)) / (2 * a));
        }
    }
    return 0;
}
