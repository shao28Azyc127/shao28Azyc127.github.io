#include<bits/stdc++.h>
using namespace std;
int f[5005];
inline int gcd(int x,int y) {
    if (x>y) swap(x,y);
    while (x) {
        y%=x;
        swap(x,y);
    }
    return y;
}
struct fen{
    int son,mot,if_s;
};
inline fen fenshu(int x,int y) {
    if (!x) return {0,1,1};
    int p=1;
    if (x<0) x*=-1,p/=-1;
    if (y<0) y*=-1,p/=-1;
    int g=gcd(x,y);
    x/=g,y/=g;
    return {x/p,y,1};
}
inline fen genshi(int x,int y) {
    if (!x) return {0,1,1};
    y=abs(y);
    int k=1;
    for (int i=2;f[i]<=x;i++) {
        while (x && x%f[i]==0) {
            k*=i;
            x/=f[i];
        }
    }
    if (x==1) {
        return fenshu(k,y);
    }
    int g=gcd(k,y);
    return {k/g,y/g,x};
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    scanf("%d %d",&t,&m);
    for (int i=1;i<=t;i++) f[i]=i*i;
//    printf("6");return 0;
    while (t--) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int der=b*b-4*a*c;
        if (der<0) {
            printf("NO\n");
            continue;
        }
        fen q1=fenshu(b*-1,a<<1);
        fen q2=genshi(der,a<<1);
        if (q1.son==0 && q2.son==0) {
            printf("0\n");
            continue;
        }
        if (q1.mot==1 && q2.mot==1 && q2.if_s==1) {
            printf("%d\n",q1.son+q2.son);
            continue;
        }

        if (q2.if_s==1) {
            int a=q1.son*q2.mot+q1.mot*q2.son;
            int b=q1.mot*q2.mot;
            int p=1;
            if (a<0) a/=-1,p/=-1;
            if (b<0) b/=-1,p/=-1;
            if (a==0) {
                printf("0\n");
                return 0;
            }
            int g=gcd(a,b);
            a/=g,b/=g;
            if (b==1) printf("%d\n",a*p);
            else printf("%d/%d\n",a*p,b);
            continue;
        }

        if (q1.son!=0) {
            printf("%d",q1.son);
            if (q1.mot!=1) {
                printf("/%d",q1.mot);
            }
        }
        if (q2.son!=0){
            if (q1.son!=0) printf("+");
            if (q2.son!=1) {
                printf("%d*",q2.son);
            }
            printf("sqrt(%d)",q2.if_s);
            if (q2.mot!=1) printf("/%d",q2.mot);
        }
        printf("\n");
    }
    return 0;
}
