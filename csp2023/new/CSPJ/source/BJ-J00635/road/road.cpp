#include <iostream>
#include <cstdio>
using namespace std;

// BJ-J00635 road.cpp
// can not be changed now.
// The test 1,2 are AC, limit can run.

long long v[100005], a[100005];

long long mny(long long rd, long long pr, long long nw, long long d) {
    int x = rd - nw;
    int y = x / d;
    if (x % d != 0) y++;
    return y * pr;
}

int main() {

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    long long n, d;
    cin >> n >> d;
    for (int i = 1; i < n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long now = 1, ans = 0, o = 0;
    while (now < n) {
        long long i = now;
        long long sum = 0;
        do {
            if (i > n) break;
            sum += v[i];
            i++;
        } while (a[i] > a[now] && i <= n);
        long long m = mny(sum, a[now], o, d);
        ans += m;
        o += (m / a[now] * d);
        o -= sum;
        //printf("At station %d : go to station %d, buy %d L oil, now %d (add %d), money %d (add %d)\n", now, i, m / a[now], o, m / a[now] * d, ans, m);
        now = i;
    }
    cout << ans << endl;
    return 0;
}
