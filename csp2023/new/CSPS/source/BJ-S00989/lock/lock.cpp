#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n, cnt, ans = 0;
    int s[8][5];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s[i][0] >> s[i][1] >> s[i][2] >> s[i][3] >> s[i][4];
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                for (int l = 0; l < 10; l++) {
                    for (int m = 0; m < 10; m++) {
                        cnt = 0;
                        for (int num = 0; num < n; num++) {
                            if (i == s[num][0]) {
                                if (j == s[num][1]) {
                                    if (k == s[num][2]) {
                                        if (l == s[num][3]) {
                                            if (m == s[num][4]) {
                                                break;
                                            } else {
                                                cnt++;
                                                continue;
                                            }
                                        } else {
                                            if (m == s[num][4] || (s[num][3] - l + 10) % 10 == (s[num][4] - m + 10) % 10) {
                                                cnt++;
                                                continue;
                                            }
                                            else break;
                                        }
                                     } else {
                                        if (l == s[num][3] || (s[num][3] - l + 10) % 10 == (s[num][2] - k + 10) % 10) {
                                            if (m == s[num][4]) {
                                                cnt++;
                                                continue;
                                            }
                                            else break;
                                        } else break;
                                     }
                                } else {
                                    if (k == s[num][2] || (s[num][1] - j + 10) % 10 == (s[num][2] - k + 10) % 10) {
                                        if (l == s[num][3]) {
                                            if (m == s[num][4]) {
                                                cnt++;
                                                continue;
                                            } else {
                                                break;
                                            }
                                        } else break;
                                     } else break;
                                }
                            } else {
                                if (j == s[num][1] || (s[num][1] - j + 10) == (s[num][0] - i + 10) % 10) {
                                    if (k == s[num][2]) {
                                        if (l == s[num][3]) {
                                            if (m == s[num][4]) {
                                                cnt++;
                                                continue;
                                            } else {
                                                break;
                                            }
                                        } else break;
                                     } else break;
                                } else break;
                            }
                        }

                        if (cnt == n) {
                            ans++;
                        }
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}