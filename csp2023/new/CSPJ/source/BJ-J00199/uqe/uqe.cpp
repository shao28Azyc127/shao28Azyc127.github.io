#include <bits/stdc++.h>
using namespace std;

int t, m;

#define abs(x) ((x) > 0 ? (x) : -(x))

int int_sqrt(int num)
{
    int k = sqrt(num) + 2;
    while (k * k > num) k--;
    return k;
}

bool issquare(int num)
{
    int k = int_sqrt(num);
    if (k * k == num) return true;
    else return false;
}

int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}

void simplify_rational(int &deno, int &nume)
{
    bool negnume = nume < 0;
    bool negdeno = deno < 0;
    bool negres = negdeno ^ negnume;
    deno = abs(deno);
    nume = abs(nume);
    int gc = gcd(deno, nume);
    deno /= gc;
    nume /= gc;
    if (negres) deno *= -1;
}

void output_rational(int deno, int nume)
{
    int d = deno, n = nume;
    simplify_rational(d, n);
    if (n != 1) cout << d << "/" << n;
    else cout << d;
}

void simplify_root(int &delta, int &q2)
{
    for (int i = delta; i >= 1; i--) {
        if (delta % i == 0) {
            if (issquare(i)) {
                // gotcha
                q2 = int_sqrt(i);
                delta /= i;
                return;
            }
        }
    }
}

void output_sqrt(int delta, int nume)
{
    nume = abs(nume);
    int q2deno = 0, q2nume = nume, n = delta;
    simplify_root(n, q2deno);
    simplify_rational(q2deno, q2nume);
    if (q2deno == q2nume && q2nume == 1) {
        cout << "sqrt(" << n << ")";
        return;
    }
    if (q2nume == 1) {
        cout << q2deno << "*sqrt(" << n << ")";
        return;
    }
    if (q2deno == 1) {
        cout << "sqrt(" << n << ")/" << q2nume;
        return;
    }
    cout << q2deno << "*sqrt(" << n << ")/" << q2nume;
    return;
}

void solve(int a, int b, int c)
{
    int delta = b * b - 4 * a * c;
    if (delta < 0) {
        cout << "NO" << endl;
        return;
    }
    if (issquare(delta)) {
        int k = int_sqrt(delta);
        int nume = 2 * a;
        int deno = -b + k;
        bool negnume = nume < 0;
        if (negnume) deno = min(deno, -b - k);
        else deno = max(deno, -b - k);
        output_rational(deno, nume);
        cout << endl;
        return;
    }
    int q1deno = -b, q1nume = 2 * a;
    if (q1deno != 0) {
        output_rational(q1deno, q1nume);
        cout << "+";
    }
    output_sqrt(delta, q1nume);
    cout << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t >> m;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        solve(a, b, c);
    }
    return 0;
}