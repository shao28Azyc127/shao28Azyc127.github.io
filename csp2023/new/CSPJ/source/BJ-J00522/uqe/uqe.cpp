#include<bits/stdc++.h>
using namespace std;

int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x*10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}
const double mi = 1e-7;
int culdelta (int a, int b, int c) {
    return b * b - 4 * a * c;
}
int gcd (int a, int b) {
    return b==0 ? a : gcd(b, a%b);
}
void outyouli (int u, int d, int& ansu, int& ansd) {
    if (u == 0) {ansu = 0; ansd = 1; return;}
    // printf("u:%d, d:%d, gcd:%d\n", u, d, gcd(u,d));
    int t = gcd(u, d); ansu = u/t, ansd = d/t;
    if (ansd < 0) ansd *= -1, ansu *= -1;
}
vector<int> sq;
void huajian (int d, int& ansx, int& anssq) {
    if (d == 0) {ansx = 0, anssq = 1; return;}
    if (abs((int)sqrt(d) * (int)sqrt(d) - d) < mi) {
        ansx = sqrt(d);
        anssq = 1;
    } else {
        int x = 1;
        for (int i=sqrt(d);i>=2;i--) {
            if (d % (i*i) == 0) d /= i*i, x *= i;
        }
        ansx = x;
        anssq = d;
    }
}
int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);

    int t, mx; cin >> t >> mx;
    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        int delta = culdelta(a, b, c);
        if (delta < 0) {cout << "NO" << endl; continue;}
        // -b/2a
        int u, v;
        outyouli(-b, 2*a, u, v);

        int ur, vr;
        int x, rt;
        huajian(delta, x, rt);
        outyouli(x, 2*a, ur, vr);
        //printf("huajian: %d, %d\n", x, rt);
        //printf("youli: %d, %d\n" ,u, v);
       //  cout << u << v << ' '<< ur << ' '<< vr;
        if (rt == 1 || rt == 0) {

            u = u*vr + ur*v;
            v = v * vr;
         // out << '!'<< u << ' ' << v << ' ' << ur << ' ' << vr << endl;
            outyouli(u, v, u, v);
            if (v == 1) cout << u;
            else cout << u << '/' << v;
            cout << endl; continue;
        } else {
            if (u != 0) {
                if (v == 1) cout << u;
                else cout << u << '/' << v;
                cout << '+';
            }
        }

        if (ur == 1 && vr ==1) printf("sqrt(%d)", rt);
        else if (vr == 1) printf("%d*sqrt(%d)", ur, rt);
        else if (ur == 1) printf("sqrt(%d)/%d", rt, vr);
        else printf("%d*sqrt(%d)/%d", ur, rt, vr);
        cout << endl;
    }
    return 0;
}

