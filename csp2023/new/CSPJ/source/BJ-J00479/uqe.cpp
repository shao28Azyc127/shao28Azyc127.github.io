#include<bits/stdc++.h>
using namespace std;
int n, k;
int delta, a, b, c;
void geshi(int x, int y){
    int z = __gcd(abs(x), abs(y));
    x = x / z;
    y = y / z;
    if(y<0){
        y = -y;
        x = -x;
    }
    if(x==0) return;
    if(y==1) printf("%d", x);
    else printf("%d/%d", x, y);
    return;
}
void geshisqrt(int x, int y, int sqr){
    int z = __gcd(abs(x), abs(y));
    x = x / z;
    y = y / z;
    if(y<0){
        y = -y;
        x = -x;
    }
    if(x==1) printf("sqrt(%d)/%d", sqr, y);
    else printf("%d*sqrt(%d)/%d", x, sqr, y);
}
int heshu(int x){
    for(int i=1;i*i<=x;i++){
        if(x % (i*i) == 0){
            return i;

        }
    }
}
int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin>>n>>k;
    while(n--){
        int q1 = 0, q2 = 1;
        scanf("%d%d%d", &a, &b, &c);
        delta = b * b - 4 * a * c;
        if(delta<0){
            printf("NO\n");
            continue;
        }
        int temp = delta;
        for(int i=2;i*i<=temp;i++){
            while(delta % (i*i) == 0){
                q2 *= i;
                delta /= (i*i);
            }
        }
        if(delta==1){
            if(2*a>0) q2 = abs(q2);
            else q2 = -abs(q2);
            geshi(-b+q2, 2*a);
            printf("\n");
            continue;
        }
        geshi(-b, 2*a);
        if(delta==0){
            printf("\n");
            continue;
        }
        if(-b!=0) printf("+");
        if(q2==2*a){
            printf("sqrt(%d)\n", delta);
            continue;
        }
        if(q2%(2*a)==0){
            q2 = abs(q2 / (2 * a));
            if(q2==1) printf("sqrt(%d)\n", delta);
            else printf("%d*sqrt(%d)\n", q2, delta);
            continue;
        }
        geshisqrt(abs(q2), abs(2*a), delta);
        printf("\n");
    }
    return 0;
}
