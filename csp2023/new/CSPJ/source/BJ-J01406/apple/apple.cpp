#include <bits/stdc++.h>
using namespace std;

bool arr[1000000000];

int main ()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    int n, cou = 2, day = -1, num = 0, cnt;

    cin >> n;

    while (cnt != 0) {
        day++;
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!arr[i]) {
                cou++;
            }
            if (cou == 3) {
                arr[i] = 1;
                cou = 0;
                cnt++;
            }
        }

        if (arr[n] && num == 0) {
            num = day + 1;
        }

        cou = 2;
    }

    cout << day << " " << num;

    return 0;
}
//want to get 90pts