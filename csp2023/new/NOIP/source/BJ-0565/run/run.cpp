#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define print1(x) cout << x << endl;
#define print2(x, y) cout << x << ' ' << y << endl;
#define print3(x, y, z) cout << x << ' ' << y << ' ' << z << endl;
using namespace std;

int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);

    long c, t;
    cin >> c >> t;
    for (long _ = 0; _ < t; _++) {
        long n, m, k, d;
        cin >> n >> m >> k >> d;
        vector<vector<long> > clg(m, vector<long>(3));
        for (long i = 0; i < m; i++) {
            cin >> clg[i][0] >> clg[i][1] >> clg[i][2];
            clg[i][0]--;
        }

        vector<vector<long> > dp(n, vector<long>(k + 1, -1000000));
        dp[0][0] = 0;
        dp[0][1] = -d;
        for (long i = 1; i < n; i++) {
            // dp[i][0]
            for (long j = 0; j < min(k + 1, i + 1); j++) dp[i][0] = (dp[i - 1][j] > dp[i][0]) ? dp[i - 1][j] : dp[i][0];
            // dp[i][1-(i+1)]
            for (long j = 1; j < min(k + 1, i + 2); j++) {
                //print2("i+2=", j)
                dp[i][j] = dp[i - 1][j - 1] - d;
                for (vector<long> c: clg) { // BETTER?
                    if (i == c[0] && j >= c[1]) dp[i][j] += c[2];
                }
            }
        }
        // for (vector<long> v: dp) {
        //     for (long i: v) cout << i << ' ';
        //     cout << endl;
        // }
        // BETTER?
        long maxEnergy = -1000000;
        for (long i = 0; i < k + 1; i++) {
            maxEnergy = (dp[n - 1][i] > maxEnergy) ? dp[n - 1][i] : maxEnergy;
        }
        cout << maxEnergy << endl;
    }

    return 0;
}
