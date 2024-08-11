#include <iostream>
#include <cmath>

using namespace std;

const int N = 5005;
int xi[N];
int T, M, dis, top;

int hard(int n, int m) {
    if (n > m) swap(n, m);
    if (m%n == 0) return n;
    m %= n;
}

void jisuan(int n) {
    int m = n;
    dis = 1;
    top = 1;
    for (int i = 2; i <= n; i++) {
        while (n%i == 0) {
            xi[i]++;
            n /= i;
        }

    }
    for (int i = 2; i <= m; i++) {
        if (xi[i] == 0) continue;
        while (xi[i] > 1) {
            xi[i] -= 2;
            dis *= i;
        }
        if (xi[i] == 1) top *= i;
        xi[i] = 0;
    }

}

int main () {
    cin >> T >> M;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        int t = (b*b) - (4*a*c);
        if (t<0) {cout << "NO" << endl; continue;}
        double dt = sqrt(t);
        double d = double(dt - b) / double(2*a);
        if (d == int(d)) {cout << int(d) << endl; continue;}
        jisuan(t);
        if (dt == 0) dis = 0;
        //dis  xishu       sqrt(top)
        int mu = 2 * a, zi = -b;
        int mu_ = 2 * a, zi_ = dis;
        if (top == 1) {
            zi += zi_;
            if (zi == 0) {
                cout << 0 << endl;
                continue;
            }
            int ju = zi;
            if (ju < 0) ju = -ju;
            int di = hard(mu, ju);
            if (di == mu) cout << zi / di << endl;
            else cout << zi/di << "/" << mu/di << endl;
        }
        else {
            int ju = zi;
            if (ju < 0) ju = -ju;

            if (b != 0) {
                int di = hard(mu, ju);
                if (di == mu) cout << zi / di << "+";
                else cout << zi / di << "/" << mu/di << "+";
            }
            if (zi_!=0) {
                int di = hard(mu_, zi_);
                if (di == mu_){
                    if (zi_ != di) cout << zi_ / di << "*";
                    cout << "sqrt(" << top <<")" << endl;
                }
                else {
                    if (zi_ != di) cout << zi_ / di << "*";
                    cout << "sqrt(" << top << ")";
                    cout << "/" << mu_ / di << endl;
                }
            }
            else {
                cout << "sqrt(" << top << ")";
                cout << "/" << mu_ << endl;
            }
        }
    }
    return 0;
}
