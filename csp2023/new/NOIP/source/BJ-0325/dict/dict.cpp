

#include <iostream>

const int MAXN = 3e3+9, inf = 2e9;
using namespace std;

int minn[MAXN], maxn[MAXN], N, M;
bool ans[MAXN];

int main () {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);

    cin >> N >> M;
    char ch;
    for (int i = 1; i < N+1; i++) {
        maxn[i] = -inf, minn[i] = inf;
        for (int j = 1; j < M+1; j++)
            cin >> ch, minn[i] = min(minn[i], ch-'a'), maxn[i] = max(maxn[i], ch-'a');
        // cerr << i << ' ' << minn[i] << ' ' << maxn[i] << '\n';
    }
    for (int i = 1; i < N+1; i++) {
        ans[i] = 1;
        for (int j = 1; j < N+1; j++) {
            if (j == i) continue;
            if (minn[i] >= maxn[j]) {ans[i] = 0;break;}
        }
    }

    for (int i = 1; i < N+1; i++) cout << ans[i];

    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}