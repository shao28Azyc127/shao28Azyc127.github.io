#include <iostream>
#include <cstring>

using namespace std;

constexpr int N = 1e5 + 5, M = 1e5 + 5;

bool f[N];

int n, m;

int a[N], b[N];
int ans;
struct T {
    char opt;
    int i, j;
} input[N];
void dfs(int dep) {
    //cout << dep << endl;
    if (dep > n) {
        memcpy(b, a, (n + 2) * sizeof(int));
        for (int k = 0; k < m; k++) {
            const char opt = input[k].opt;
            const int i = input[k].i, j = input[k].j;
            if (opt == '+') {
                b[i] = b[j];
            } else if (opt == '-') {
                if (b[j] == 0 || b[j] == 1)
                    b[i] = !b[j];
                else
                    b[i] = b[j];
            } else if (opt == 'T') {
                b[i] = 1;
            } else if (opt == 'F') {
                b[i] = 0;
            } else if (opt == 'U') {
                b[i] = 2;
            }
        }
        int i;
        for (i = 1; i <= n; i++)
            if (a[i] != b[i])
                break;
        if (i > n) {
            //for (int j = 1; j <= n; j++)
            //    cout << a[j] << ' ';
            //cout << endl;
            int tmp = 0;
            for (int j = 1; j <= n; j++)
                if (a[j] == 2)
                    tmp++;
            ans = min(ans, tmp);
        }
        return;
    }
    a[dep] = 0;
    dfs(dep + 1);
    a[dep] = 1;
    dfs(dep + 1);
    a[dep] = 2;
    dfs(dep + 1);
}

int z[N];

int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c, t;
    cin >> c >> t;
    while (t--) {
        ans = 0x3f3f3f3f;
        cin >> n >> m;
        if (c == 3 || c == 4) {
            memset(z, 0, sizeof z);
            for (int i = 0; i < m; i++) {
                char opt;
                int x;
                cin >> opt >> x;
                if (opt == 'T')
                    z[x] = 1;
                else if (opt == 'F')
                    z[x] = 2;
                else if (opt == 'U')
                    z[x] = 3;
            }
            int res = 0;
            for (int i = 1; i <= n; i++)
                if (z[i] == 3)
                    res++;
            cout << res << '\n';
        } else {
            for (int i = 0; i < m; i++) {
                cin >> input[i].opt;
                if (input[i].opt == '+' || input[i].opt == '-')
                    cin >> input[i].i >> input[i].j;
                else
                    cin >> input[i].i;
            }
            dfs(1);
            cout << ans << '\n';
        }
    }
    return 0;
}
