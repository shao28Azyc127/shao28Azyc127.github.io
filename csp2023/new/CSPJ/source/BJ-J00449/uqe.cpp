#include <cstdio>
#include <algorithm>
using namespace std;

int t, m;
long long a, b, c;

// get floor(sqrt(x)).
long long sqrt_int(long long x) {
    long long l = 0, r = x, ans = -1;
    while (l <= r) { // VVVVVXXXXX
        long long mid = (l + r) >> 1;
        if (mid * mid <= x)
            l = mid + 1, ans = mid;
        else
            r = mid - 1;
    }
    return ans;
}

// let d^2 | r disappear
// e.g. sqrt(8) = 2 * sqrt(2)
long long outside, inside;
void simp(long long x) {
    outside = inside = 1;
    for (long long i = 2; i * i <= x; i++) {
        int cnt = 0;
        while (x % i == 0) {
            x /= i;
            cnt++;
        }
        while (cnt >= 2) {
            cnt -= 2;
            outside *= i;
        }
        if (cnt == 1)
            inside *= i;
    }
    inside *= x;
}

struct Fraction {
    bool neg;
    unsigned long long up;
    unsigned long long down;

    void std() {
        long long gcdn = __gcd(up, down);
        up /= gcdn, down /= gcdn;
        if (up == 0)
            neg = false;
    }

    void out() {
        if (neg)
            putchar('-');
        printf("%lld", up);
        if (down > 1)
            printf("/%lld", down);
    }
};

Fraction make_fraction(long long u, long long d) {
    Fraction f;
    f.neg = (u >= 0) ^ (d >= 0);
    f.up = abs(u), f.down = abs(d);
    f.std();
    return f;
}

int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);

    scanf("%d%d", &t, &m);
    while (t--) {
        scanf("%lld%lld%lld", &a, &b, &c);

        long long delta = b * b - 4 * a * c;
        if (delta < 0) {
            puts("NO");
            continue;
        }

        long long sd = sqrt_int(delta);
        if (sd * sd == delta) {
            if (a > 0)
                make_fraction(-b + sd, 2 * a).out();
            else
                make_fraction(-b - sd, 2 * a).out();
            puts("");
            continue;
        }

        Fraction q1 = make_fraction(-b, 2 * a); // same in x1, x2
        if (q1.up != 0) {
            q1.out();
            putchar('+');
        }

        simp(delta);
        Fraction q2 = make_fraction(outside, 2 * abs(a));
        // if a > 0, is + sqrt(delta) / 2a
        // otherwise is - sqrt(delta) / 2a
        // => is + sqrt(delta) / abs(2a)
        if (q2.neg == false && q2.up == 1 && q2.down == 1)
            printf("sqrt(%lld)\n", inside);
        else if (q2.down == 1)
            printf("%lld*sqrt(%lld)\n", q2.up, inside);
        else if (q2.up == 1)
            printf("sqrt(%lld)/%lld\n", inside, q2.down);
        else
            printf("%lld*sqrt(%lld)/%lld\n", q2.up, inside, q2.down);
    }
    return 0;
}

/*
Comparator used in the exam

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string path1, path2;
    printf("file1: ");
    getline(cin, path1);
    printf("file2: ");
    getline(cin, path2);

    ifstream f1, f2;
    f1.open(path1.c_str());
    f2.open(path2.c_str());
    for (int i = 1; ; i++) {
        string line1, line2;
        getline(f1, line1);
        getline(f2, line2);
        if (f1.eof()) {
            printf("file1 EOF-ed (line %d). All same before this line.\n"
                   "Comparison terminated.\n", i);
            break;
        }
        if (f2.eof()) {
            printf("file2 EOF-ed (line %d). All same before this line.\n"
                   "Comparison terminated.\n", i);
            break;
        }

        while (line1.back() == ' ')
            line1.pop_back();
        while (line2.back() == ' ')
            line2.pop_back();

        if (line1 != line2) {
            printf("!!! Warning !!!\nDifference detected (line %d)\n", i);
            cout << "file1: " << line1 << endl;
            cout << "file2: " << line2 << endl;
            break;
        }
    }
    return 0;
}
*/
