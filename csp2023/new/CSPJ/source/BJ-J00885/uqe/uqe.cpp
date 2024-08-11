#include<bits/stdc++.h>
using namespace std;
int T,M;
int abs(int x){
    return (x < 0 ? -x : x);
}
int gcd(int a,int b){
    if(b == 0) return a;
    return gcd(b,a % b);
}
int get(int x){
    int a = abs(x);
    for(int i = sqrt(a);i >= 2;i--){
        if(a % (i * i) == 0)
            return i;
    }
    return 1;
}
void yls(int a,int b){
    if(a == 0){
        printf("0"); return;
    }
    int x = (a < 0) + (b < 0);
    if(x == 1) printf("-");
    a = abs(a),b = abs(b);
    int g = gcd(a,b); a /= g,b /= g;
    printf("%d",a);
    if(b != 1) printf("/%d",b);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&T,&M);
    while(T--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int der = b * b - 4 * a * c;
        if(der < 0){
            printf("NO\n");
            continue;
        }
        int f = sqrt(der),u,d;
        if(f * f == der){
            d = 2 * a;
            if(d < 0) u = -b - f;
            else u = -b + f;
            yls(u,d); printf("\n");
            continue;
        }
        int q = get(der); der /= (q * q);
        if(b != 0){
            yls(-b,2 * a); printf("+");
        }
        a = abs(a);
        if(q == (2 * a)){
            printf("sqrt(%d)",der);
        }
        else if(q % (2 * a) == 0){
            printf("%d*sqrt(%d)",q / (2 * a),der);
        }
        else if((2 * a) % q == 0){
            printf("sqrt(%d)/%d",der,(2 * a / q));
        }
        else{
            d = 2 * a,u = q;
            int g = gcd(u,d); u /= g,d /= g;
            printf("%d*sqrt(%d)/%d",u,der,d);
        }
        printf("\n");
    }
    return 0;
}