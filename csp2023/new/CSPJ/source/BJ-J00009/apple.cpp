#include <bits/stdc++.h>

using namespace std;

int n;
int ans1;
int ans2;

int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    cin >> n ;

    while (n) {
        if (1.0 * (n - 1) / 3 == int(1.0 * (n - 1) / 3) && !ans2) {
            ans2 = ans1 + 1;
        }

        n -= 1.0 * n / 3;
        ans1++;

    }

    cout << ans1 << ' ' << ans2 << endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
