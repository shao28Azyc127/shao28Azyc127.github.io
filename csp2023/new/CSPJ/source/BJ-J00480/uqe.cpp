#include <bits/stdc++.h>
using namespace std;

int t, m;
int a[5005], b[5005], c[5005];
void yue(int &x, int &y) {
    int g = __gcd(x, y);
    x /= g;
    y /= g;
}

int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >> m;
    for (int i = 0; i < t; i++)
        cin >> a[i] >> b[i] >> c[i];
    for (int i = 0; i < t; i++) {
        if (abs(a[i] == 1) && b[i] == 0 && c[i] == 0)
            cout << 0 << endl;
        else {
            int pbs = b[i]*b[i]-4*a[i]*c[i];
            if (pbs < 0)
                cout << "NO" << endl;
            else {
                double sqpbs = sqrt(pbs);
                if (int(sqpbs) * int(sqpbs) == pbs) {
                    // youlishu
                    int up = (a[i] > 0) ? (-b[i]+int(sqpbs)) : (-b[i]-int(sqpbs));
                    int down = 2*a[i];
                    yue(up, down);
                    if (down < 0) {
                        down = -down;
                        up = -up;
                    }
                    if (down == 1) cout << up << endl;
                    else printf("%d/%d\n", up, down);
                }
                else {
                    // wulishu
                    int beishu = 1;
                    for (int j = 4; j < pbs; j++) {
                        while (int(sqrt(j))*int(sqrt(j))==j && pbs % j == 0) {
                            pbs /= j;
                            beishu *= int(sqrt(j));
                        }
                    }
                    if (a[i] < 0)
                        beishu = -beishu;
                    int p1 = -b[i], q1 = 2*a[i], p2 = beishu, q2 = 2*a[i];
                    yue(p1, q1);
                    yue(p2, q2);
                    if (p1 != 0) {
                        if (q1 < 0) {
                            q1 = -q1;
                            p1 = -p1;
                        }
                        if (q1 == 1) cout << p1;
                        else printf("%d/%d", p1, q1);
                        cout << '+';
                    }
                    if (p2 == 1 && q2 == 1)
                        printf("sqrt(%d)\n", pbs);
                    else if (q2 == 1)
                        printf("%d*sqrt(%d)\n", p2, pbs);
                    else if (p2 == 1)
                        printf("sqrt(%d)/%d\n", pbs, q2);
                    else
                        printf("%d*sqrt(%d)/%d\n", p2, pbs, q2);
                }
            }
        }
    }
    return 0;
}