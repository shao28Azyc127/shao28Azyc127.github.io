#include <bits/stdc++.h>
using namespace std;

int n, m;
int a, b, c;
int num;
int up, down;
int k;
int l;

bool cmp(int x){
    int y = sqrt(x);
    if(y*y==x) return true;
    return false;
}

int gcd(int x, int y){
    if(y==0) return x;
    return gcd(y, x%y);
}

int number(int x){
    int y = 1, z;
    for(int i=2; i<=sqrt(x); i++){
        z = i * i;
        if(x%z==0){
            while(x%z==0){
                y *= i;
                x /= z;
            }
        }
    }
    return y;
}

int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);

    scanf("%d%d", &n, &m);
    while(n--){
        scanf("%d%d%d", &a, &b, &c);
        num = up = down = k = l = 0;
        num = b * b - 4 * a * c;
        if(num<0){
            printf("NO\n");
            continue;
        }
        if(cmp(num)){
            if(a<0) up = -sqrt(num) - b;
            else up = sqrt(num) - b;
            if(up*a<0) printf("-");
            up = abs(up), a = abs(a);
            int k = gcd(up, 2*a);
            if(2*a==k){
                printf("%d\n", up/2/a);
            }else{
                printf("%d/%d\n", up/k, 2*a/k);
            }
            continue;
        }
        l = number(num);
        if(b!=0){
            if(b/a>0) printf("-");
            b = abs(b), a = abs(a);
            k = gcd(b, 2*a);
            if(k==2*a){
                printf("%d", b/k);
            }else{
                printf("%d/%d", b/k, 2*a/k);
            }
        }
        if(b!=0) printf("+");
        a = abs(a);
        if(l==1){
            printf("sqrt(%d)/%d\n", num, 2*a);
        }else if(l==2*a){
            printf("sqrt(%d)\n", num/l/l);
        }else{
            num = num / l / l;
            k = gcd(l, 2*a);
            if(2*a==k){
                if(l==k) printf("sqrt(%d)\n", num);
                else printf("%d*sqrt(%d)\n", l/k, num);
            }else{
                if(l==k) printf("sqrt(%d)/%d\n", num, 2*a/k);
                else printf("%d*sqrt(%d)/%d\n", l/k, num, 2*a/k);
            }
        }
    }

    return 0;
}
