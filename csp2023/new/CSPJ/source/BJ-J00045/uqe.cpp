#include <bits/stdc++.h>
using namespace std;
#define int long long

int T, M;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else return gcd(b, a % b);
}

int get_op(int n) {
    return n >= 0 ? 1 : -1;
}

pair<int, int> get_valid(int a, int b) {
    int g = gcd(a, b);
    return make_pair(get_op(a) * get_op(b) * abs(a / g), abs(b / g));
}

pair<int, int> split(int r) {
    int res1 = 1, res2 = 1;
    for (int i = 2; i <= r; i++) {
        int cnt = 0;
        while (r % i == 0) {
            cnt++;
            r /= i;
            if (cnt == 2) {
                cnt = 0;
                res1 *= i;
            }
        }
        if (cnt) {
            res2 *= i;
        }
    }
    return make_pair(res1, res2);
}

void print(pair<int, int> fr, string end = "") {
    if (fr.second != 1)
        printf("%lld/%lld", fr.first, fr.second);
    else
        printf("%lld", fr.first);
    printf("%s", end.c_str());
}

#undef int
int main()
#define int long long
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> T >> M;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        int delta = b * b - 4 * a * c;
        if (delta < 0) {
            cout << "NO\n";
        } else if (delta == 0) {
            pair<int, int> res = get_valid(-b, 2 * a);
            print(res, "\n");
        } else {
            pair<int, int> q1 = get_valid(-b, 2*a);
            pair<int, int> _r = split(delta);
            int q2 = _r.first, r = _r.second;
            if (r != 1) {
                // printf("br0\n");
                if (q1.first) {
                    print(q1, "+");
                }
                pair<int, int> qr = get_valid(q2, 2 * a);
                if (qr.first != 1) {
                    printf("%lld*", qr.first);
                }
                printf("sqrt(%lld)", r);
                if (qr.second != 1) {
                    printf("/%lld", qr.second);
                }
                printf("\n");
            } else {
                // printf("br1\n");
                pair<int, int> res = get_valid(-b + q2, 2*a);
                print(res, "\n");
            }
        }
    }
    return 0;
}
