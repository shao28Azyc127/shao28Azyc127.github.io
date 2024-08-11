

#include <iostream>
#include <math.h>

using namespace std;

int t, m;
int a, b, c;
int solo, num, one, two, g;
int ans1, ans2, ans;

int gcd (int first, int second) {
    if (second == 0) return first;
    else return gcd(second, first % second);
}

int main () {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);

    cin >> t >> m;
    while (t--) {
        cin >> a >> b >> c;
        solo = b * b - 4 * a * c;
        if (solo < 0) {
            cout << "NO\n";
            continue;
        }
        num = sqrt(solo);

        one = -b + abs(num), two = 2 * a, ans1 = one / two, g = abs(gcd(one, two));
        one = -b - abs(num), two = 2 * a, ans2 = one / two, g = abs(gcd(one, two));
        ans = max(ans1, ans2);

        if (!(one % two)) cout << ans << endl;
        else cout << one / g << '/' << two / g << endl;
    }

    return 0;
}
