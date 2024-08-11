#include <bits/stdc++.h>
using namespace std;
int t, m;
struct power {
    int d, m;
};
struct frac {
    int fz, fm;
};
bool check(double a) {
    return int(a+0.99999) == a;
}
int gcd(int n, int m) {
    //cout << "gcd " << n << ' ' << m << ' ';
    while (m) {
        int t = n % m;
        n = m;
        m = t;
    }
    //cout << n << '\n';
    return n;
}
frac getfraction(int a, int b) {
    int g;
    if (b < 0) {
        a = -a;
        b = -b;
    }
    if (a < 0) g = gcd(-a, b);
    else g = gcd(a, b);

    return (frac){a/g, b/g};
}
string getfrac(int a, int b) {
    frac f = getfraction(a, b);
    if (f.fm == 1) return to_string(f.fz);
    else return to_string(f.fz) + "/" + to_string(f.fm);
}
string getsqrt(int a, int b) {
    // cout << "[Debug] Getsqrt" << a << '\n';
    int s = 2, xs = 1, sq = 1;
    vector<power> v;
    while (a > 1) {
        int cnt = 0;
        power p = (power){0, 0};
        if (a % s == 0) p.d = s;
        while (a % s == 0) {
            cnt++;
            a /= s;
        }
        if (cnt != 0) {
            p.m = cnt;
            v.push_back(p);
        }
        s++;
    }
    // for (auto cur : v) cout << "[power] " << cur.d << '^' << cur.m << '\n';
    for (auto cur : v) {
        if (cur.m % 2 == 0) xs *= pow(cur.d, cur.m);
        else {
            if (cur.m > 2) xs *= pow(cur.d, cur.m-1);
            sq *= cur.d;
        }
        // cout << "[Debug] " << xs << ' ';
    }
    xs = sqrt(xs);
    frac xsf = getfraction(xs, b);
    // cout << "[result] " << xs << "sqrt(" << sq << ')';
    if (xsf.fz < 0) xsf.fz = -xsf.fz;
    string finalres = "";
    if (xsf.fz != 1) finalres += (to_string(xsf.fz) + '*');
    finalres += "sqrt(";
    finalres += (to_string(sq) + ')');
    if (xsf.fm != 1) {
        finalres += '/';
        finalres += to_string(xsf.fm);
    }
    return finalres;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >> m;
    while (t--) {
        int a, b, c, delta, fm;
        cin >> a >> b >> c;
        delta = b*b-4*a*c;
        fm = 2*a;

        if (delta < 0) cout << "NO\n";
        else if (delta == 0) {
            int fz = -b;
            cout << getfrac(fz, fm) << '\n';
        }
        else {
            if (check(sqrt(delta))) {
                //cout << "youlishu\n";
                int fz1 = -b+sqrt(delta), fz2 = -b-sqrt(delta), fz;
                if (fz1/fm > fz2 / fm) fz = fz1;
                else fz = fz2;
                cout << getfrac(fz, fm) << '\n';
            }
            else {
                //cout << "wulishu\n";
                //cout << "wulishu " << -b << ' ' << fm << '\n';
                double temp = 1.0*(-b)/(2*a);
                if (temp != 0)
                    cout << getfrac(-b, fm) << '+';

                cout << getsqrt(delta, fm) << '\n';
            }
        }
    }
    return 0;
}
