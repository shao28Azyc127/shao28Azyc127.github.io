#include<bits/stdc++.h>
using namespace std;
int sqt(int x) {
    int ret = 1;
    for(int i = 2; i * i <= x;) {
        if(x % (i * i)) ++i;
        else while(!(x % (i * i))) ret *= i, x /= i * i;
    }
    return ret;
}
int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    scanf("%d%d", &t, &m);
    while(t--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if(!c) {
            if(a * b > 0) puts("0");
            else {
            if(b >= 0) a = -a, b = -b;
            b = -b;
            int gd = __gcd(a, b);
            a /= gd, b /= gd;
            if(a * b < 0) b = -abs(b), a = abs(a);
            else b = abs(b), a = abs(a);
            if(a ^ 1) printf("%d/%d\n", b, a);
            else printf("%d\n", b);
            }
        } else if(!b) {
            if(a * c >= 0) puts("NO");
            else {
                int q2 = sqt(-a * c), q3 = a;
                int st = -a * c / (q2 * q2), gd = __gcd(q2, q3);
                q2 /= gd, q3 /= gd;
                q2 = abs(q2), q3 = abs(q3);
                if(st ^ 1 && q2 == 1) printf("sqrt(%d)", st);
                else {
                    printf("%d", q2);
                    if(st ^ 1) printf("*sqrt(%d)", st);
                }if(q3 ^ 1) printf("/%d", q3);
                putchar('\n');
            } 
        } else {
            int derta = b * b - (a * c * 4);
            if(derta < 0) puts("NO");
            else if(!derta) {
                int fz = -b, fm = a * 2;
                int gd = __gcd(fz, fm);
                fz /= gd, fm /= gd;
                if(fz * fm < 0) fz = -abs(fz), fm = abs(fm);
                else fz = abs(fz), fm = abs(fm);
                if(fz) {
                    if(fm ^ 1) printf("%d/%d\n", fz, fm);
                    else printf("%d\n", fz);
                } else puts("0");
                //cout<<fz<<" "<<fm<<" "<<gd<<endl;
            } else {
                int fz = -b, fm = a * 2;
                //cout<<fz<<" "<<fm<<endl;
                int ggd = __gcd(fz, fm);
                fz /= ggd, fm /= ggd;
                int q2 = sqt(derta), q3 = a * 2;
                int st = derta / (q2 * q2), gd = __gcd(q2, q3);
                q2 = abs(q2 / gd), q3 = abs(q3 / gd);
                //cout<<fz<<" "<<fm<<" "<<q2<<" "<<q3<<endl;
                if(st == 1) {
                    fz *= q3, q2 *= fm, fm *= q3;
                    fz += q2;
                    //cout<<q2<<" "<<fz<<" "<<fm<<endl;
                    gd = __gcd(fz,fm);
                    fz /= gd, fm /= gd;
                    if(fz * fm < 0) fz = -abs(fz), fm = abs(fm);
                    else fz = abs(fz), fm = abs(fm);
                    if(fz) {
                        if(fm ^ 1) printf("%d/%d", fz, fm);
                        else printf("%d", fz);
                    }
                } else {
                    if(fz * fm < 0) fz = -abs(fz), fm = abs(fm);
                    else fz = abs(fz), fm = abs(fm);
                    if(fz) {
                        if(fm ^ 1) printf("%d/%d+", fz, fm);
                        else printf("%d+", fz);
                    }
                    if(q2 == 1) printf("sqrt(%d)", st);
                    else {
                        printf("%d", q2);
                        if(st ^ 1) printf("*sqrt(%d)", st);
                    }if(q3 ^ 1) printf("/%d", q3);
                }
                putchar('\n');
            }
        }
    }
    return 0;
}