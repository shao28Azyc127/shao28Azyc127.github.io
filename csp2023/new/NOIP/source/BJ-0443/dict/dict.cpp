#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

const int MAXN = 3005;

int n, m;
char a[MAXN][MAXN];
multiset<char> s[MAXN];

bool check(int i) {
    for (int j = 1; j <= n; ++j) {
        if (i == j) continue;
        multiset<char> tmp = s[j];
        for (char ch : s[i]) {
            auto it = tmp.upper_bound(ch);
            if (it == tmp.end()) {
                it = tmp.find(ch);
                if (it == tmp.end()) return false;
                tmp.erase(it);
                continue;
            }
            break;
        }
    }
    return true;
}

int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", a[i] + 1);
        for (int j = 1; j <= m; ++j) s[i].insert(a[i][j]);
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d", check(i));
    }
    printf("\n");
    return 0;
}