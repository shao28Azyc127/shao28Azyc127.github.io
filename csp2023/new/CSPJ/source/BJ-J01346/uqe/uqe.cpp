#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <cmath>
using namespace std;

int getgcd(int a, int b) {
    return b == 0 ? a : getgcd(b, a % b);
}

void output(int up, int down) {
    if (down < 0) {
        up = -up;
        down = -down;
    }

    int gcd = getgcd(abs(up), abs(down));
    up /= gcd;
    down /= gcd;
    if (down == 1) {
        cout << up;
    } else {
        cout << up << "/" << down;
    }
}

void do_something() {
    int a, b, c;
    cin >> a >> b >> c;
    int delta = b * b - 4 * a * c;
    if (delta < 0) {
        cout << "NO" << "\n";
        return;
    }
    int sqrt_delta = std::sqrt(delta + 1e-3);
    if (sqrt_delta * sqrt_delta == delta) {
        int up = -b + sqrt_delta;
        int down = 2 * a;
        if (a < 0) {
            up = -b - sqrt_delta;
        }
        output(up, down);
    } else {
        int out = 1;
        for (out = sqrt_delta; out >= 2; --out) {
            if (delta % (out * out) == 0) {
                break;
            }
        }
        if (b != 0) {
            output(-b, 2 * a);
            cout << "+";
        }
        if (a < 0) {
            a = -a;
        }

        int down = 2 * a;
        int t = getgcd(out, down);
        delta /= out * out;
        out /= t;
        down /= t;
        if (out != 1) cout << out << "*";
        cout << "sqrt(" << (delta) << ")";
        if (down > 1) cout << "/" << down;

    }
    cout << "\n";
}

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        do_something();
    }
    return 0;
}
