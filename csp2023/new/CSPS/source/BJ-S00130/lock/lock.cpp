#include <iostream>
using namespace std;
const int NR = 10;
int a[NR][NR], ans;
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 5; j++)
            cin >> a[i][j];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; k++)
                for (int l = 0; l < 10; l++)
                    for (int m = 0; m < 10; m++)
                    {
                        bool flag = true;
                        for (int x = 1; x <= n; x++)
                        {
                            bool vis = false;
                            int a1 = a[x][1], a2 = a[x][2], a3 = a[x][3], a4 = a[x][4], a5 = a[x][5];
                            if (a1 == i && a2 == j && a3 == k && a4 == l && a5 == m) {flag = false; break;}
                            if (a2 == j && a3 == k && a4 == l && a5 == m) vis = true;
                            if (a1 == i && a3 == k && a4 == l && a5 == m) vis = true;
                            if (a1 == i && a2 == j && a4 == l && a5 == m) vis = true;
                            if (a1 == i && a2 == j && a3 == k && a5 == m) vis = true;
                            if (a1 == i && a2 == j && a3 == k && a4 == l) vis = true;
                            if (a3 == k && a4 == l && a5 == m)
                            {
                                if (i > a1) a1 += 10;
                                if (j > a2) a2 += 10;
                                if (a1 - i == a2 - j) vis = true;
                            }
                            if (a1 == i && a4 == l && a5 == m)
                            {
                                if (j > a2) a2 += 10;
                                if (k > a3) a3 += 10;
                                if (a2 - j == a3 - k) vis = true;
                            }
                            if (a1 == i && a2 == j && a5 == m)
                            {
                                if (k > a3) a3 += 10;
                                if (l > a4) a4 += 10;
                                if (a3 - k == a4 - l) vis = true;
                            }
                            if (a1 == i && a2 == j && a3 == k)
                            {
                                if (l > a4) a4 += 10;
                                if (m > a5) a5 += 10;
                                if (a4 - l == a5 - m) vis = true;
                            }
                            flag &= vis;
                        }
                        if (flag) ans++;
                        // if (flag) cout << i << " " << j << " " << k << " " << l << " " << m << '\n';
                    }
    cout << ans << '\n';
    return 0;
}
