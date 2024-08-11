#include<bits/stdc++.h>
using namespace std;
long long T, M;

long long gcd(long long x, long long y) {
    if(x==0) return y;
    else return gcd(y%x, x);
}

long long lcm(long long x, long long y) {
    return x*y/gcd(x, y);
}

void prt(long long a, long long b) {
    long long A=abs(a), B=abs(b);
    bool f;
    if((a<0 && b<0) || (a>0 && b>0)) f=0;
    else f=1;

    long long g=gcd(A, B);
    A/=g;
    B/=g;

    if(A==0) {
        printf("0");
        return;
    }

    if(B!=1) {
        if(f==1) putchar('-');
        printf("%lld/%lld", A, B);
    } else {
        if(f==1) putchar('-');
        printf("%lld", A);
    }
}

long long a, b, c;
long long qx1, qy1, qx2, qy2;
void work() {
   // cout<<endl<<endl;

    scanf("%lld %lld %lld", &a, &b, &c);

    long long delta=b*b-4*a*c;

    if(delta<0) {
        printf("NO\n");
        return;
    }

    qx1=-b;
    qy1=2*a;

    if(delta==0) {
        prt(qx1, qy1);
        putchar('\n');
        return;
    }

    qx2=1;
    qy2=2*a;
    long long res=delta;
    for(long long i=2; res!=1 && i*i<=res; i++) {
        while(res%(i*i)==0) {
            qx2*=i;
            res/=i*i;
        }
    }

  //  cout<<delta<<endl;
   // cout<<qx1<<" "<<qy1<<" "<<qx2<<" "<<qy2<<" "<<res<<endl;

    if(res!=1 && res!=0) {
        if(qx1!=0) {
            prt(qx1, qy1);
            putchar('+');
        }

        qx2=abs(qx2);
        qy2=abs(qy2);

        long long g=gcd(abs(qx2), abs(qy2));
        qx2/=g, qy2/=g;

        if(qx2!=1) printf("%lld*", qx2);
        printf("sqrt(%lld)", res);
        if(qy2!=1) printf("/%lld", qy2);

        putchar('\n');
        return;
    } else {
        if(a>0) {
            long long qx=qx1+qx2;
            prt(qx, qy1);
            putchar('\n');
        } else {
            long long qx=qx1-qx2;
            prt(qx, qy1);
            putchar('\n');
        }
        return;
    }

}

int main() {

    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);

    scanf("%lld %lld", &T, &M);
    while(T--) work();
    return 0;
}
