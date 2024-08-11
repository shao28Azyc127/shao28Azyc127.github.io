#include <bits/stdc++.h>
using namespace std;

int c, n, m, q, a, b, kx, ky, px, vx, py, vy, a1, b1;

void check(){
    if(a == a1 || b == b1){
        if((a > b && a1 > b1) || (a < b && a1 < b1)){
            printf("1");
        }else{
            printf("0");
        }
    }
    if(a == b || a1 == b1){
        printf("0");
        return;
    }else if(a == b1 || a1 == b){
        if((a > b && a1 > b1) || (a < b && a1 < b1)){
            printf("1");
        }else{
            printf("0");
        }
        return;
    }
            if(a > a1 && a > b || a > b && a > b1 || a > a1 && a > b1){
                a = -a;
                b = -b;
                a1 = -a1;
                b1 = -b1;
            }
    if(a < a1 && a1 < b && b < b1){
        printf("1");
        return;
    }else if(a < a1 && a1 < b1 && b1 < b){
        printf("1");
        return;
    }else if(a < b && b < a1 && a1 < b1){
        printf("1");
        return;
    }else if(a < b1 && b1 < a1 && a1 < b){
        printf("0");
        return;
    }else if(a < b && b < b1 && b1 < a1){
        printf("0");
        return;
    }else if(a < b1 && b1 < b && b < a1){
        printf("0");
        return;
    }else if(a1 < a && a < b && b < b1){
        printf("1");
        return;
    }else if(a1 < a && a < b1 && b1 < b){
        printf("1");
        return;
    }else if(b < a && a < a1 && a1 < b1){
        printf("0");
        return;
    }else if(b1 < a && a < a1 && a1 < b){
        printf("0");
        return;
    }else if(b < a && a < b1 && b1 < a1){
        printf("1");
        return;
    }else if(b1 < a && a < b && b < a1){
        printf("0");
        return;
    }
}

int main(){
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    scanf("%d%d%d%d", &c, &n, &m, &q);
    if(c == 1){
        scanf("%d%d", &a, &b);
        if(a == b){
            printf("0");
        }else{
            printf("1");
        }
        while(q --){
            scanf("%d%d", &kx, &ky);
            while(kx --){
                scanf("%d%d", &px, &vx);
                a = vx;
            }
            while(ky --){
                scanf("%d%d", &py, &vy);
                b = vy;
            }
            if(a == b){
                printf("0");
            }else{
                printf("1");
            }
        }
    }else if(c == 2){
        scanf("%d%d%d%d", &a, &a1, &b, &b1);
        check();
        while(q --){
            scanf("%d%d", &kx, &ky);
            while(kx --){
                scanf("%d%d", &px, &vx);
                if(px == 1){
                    a = vx;
                }else{
                    a1 = vx;
                }
            }
            while(ky --){
                scanf("%d%d", &py, &vy);
                if(py == 1){
                    b = vy;
                }else{
                    b1 = vy;
                }
            }
            check();
        }
    }
    return 0;
}
