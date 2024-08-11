#include <bits/stdc++.h>
#define ll long long
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
using namespace std;
ll n, ans1 = 0, ans2 = 0;
bool a[1000005];
//ll a[N];
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    memset(a, false, sizeof(a));

    scanf("%lld", &n);
    ll x = n;
    while (x > 0) {
        x -= (x + 2) / 3;
        ++ans1;
    }

    for (int i = 1; i <= ans1; ++i) {
        int cnt = 3;
        for (int j = 1; j <= n; ++j) {
            if (a[j] == false) {
                if (cnt == 3) {
                    a[j] = true;
                    cnt = 1;
                } else {
                    cnt++;
                }
            }

        }
        /*for (int i = 1; i <= n; ++i) {
            cout << a[i] << " ";
        }
        printf("\n");*/
        if (a[n]) {
            ans2 = i;
            break;
        }
    }

    printf("%lld %lld", ans1, ans2);


    /*for (int i = 0; i < n; i++) {
        mod 3 = 1
        mod 9 = 2 or 6
        mod 27 = 3 or 9 or 17 or 23
    }*/
    return 0;
}
