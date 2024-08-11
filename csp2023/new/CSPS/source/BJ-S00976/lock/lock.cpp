#include <iostream>

#define rep(i, a, b) for (int i = a; i <= b; i = -~i) 

using namespace std;

int n;
int a[10][5];
int p[10];

bool check()
{
    rep(i, 1, n)
    {
        int cnt = 0;
        rep(j, 1, 5) if (p[j] != a[i][j]) cnt++;
        if (cnt >= 3) return false;
        if (cnt == 0) return false;
        if (cnt == 2)
        {
            bool Flg = 0;
            rep(j, 1, 4)
                if (p[j] != a[i][j] && p[j + 1] != a[i][j + 1])
                {
                    if ((a[i][j] - p[j] + 10) % 10 == (a[i][j + 1] - p[j + 1] + 10) % 10) { Flg = 1; break; }
                }
            if (!Flg) return false;
        }
    }
    // cout << p[1] << p[2] << p[3] << p[4] << p[5] << "\n";
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    cin >> n;
    rep(i, 1, n) rep(j, 1, 5) cin >> a[i][j];
    int ans = 0;
    rep(i1, 0, 9)
        rep(i2, 0, 9)
            rep(i3, 0, 9)
                rep(i4, 0, 9)
                    rep(i5, 0, 9)
                    {
                        p[1] = i1, p[2] = i2, p[3] = i3, p[4] = i4, p[5] = i5;
                        if (check()) ans++;
                    }
    cout << ans << "\n";
    return 0;
}