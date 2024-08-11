//我欲乘风归去，又恐琼楼玉宇，高处不胜寒。起舞弄清影，何似在人间。
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int N = 2e5 + 10;

int typ[maxn], op[maxn];
int fa[N], siz[N], unk[N], col[N];
vector<int> v[N];

inline int findfa(int x) { return x == fa[x] ? x : fa[x] = findfa(fa[x]); }
void merge(int x, int y)
{
    x = findfa(x); y = findfa(y);
    if (x == y) return;
    if (siz[x] < siz[y]) swap(x, y);
    fa[y] = x; siz[x] += siz[y];
}

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int c, T;
    cin >> c >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n + 2; i++) typ[i] = i, op[i] = 1;
        while (m--)
        {
            char s[3];
            cin >> s;
            int x, y;
            if (s[0] == '+' || s[0] == '-')
            {
                cin >> x >> y;
                typ[x] = typ[y];
                if (s[0] == '+') op[x] = op[y];
                else op[x] = -op[y];
            }
            else
            {
                cin >> x;
                if (s[0] == 'U') typ[x] = n + 2, op[x] = 1;
                else typ[x] = n + 1, op[x] = (s[0] == 'T' ? 1 : -1);
            }
        }

        for (int i = 1; i <= 2 * n + 4; i++) fa[i] = i, siz[i] = 1, unk[i] = 0, v[i].clear(), col[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            if (op[i] == 1) merge(i, typ[i]), merge(i + n + 2, typ[i] + n + 2);
            else merge(i, typ[i] + n + 2), merge(i + n + 2, typ[i]);
        }
        merge(n + 2, 2 * n + 4);

        for (int i = 1; i <= n; i++)
            if (findfa(i) == findfa(i + n + 2)) unk[findfa(i)] = 1;
        for (int i = 1; i <= 2 * n + 4; i++) v[findfa(i)].push_back(i);
        for (int i = 1; i <= 2 * n + 4; i++)
            if (fa[i] == i && unk[i])
                for (int x : v[i])
                {
                    col[x] = 1;
                    if (x > n + 2) col[x - n - 2] = 1;
                    else col[x + n + 2] = 1;
                }
        
        int ans = 0;
        for (int i = 1; i <= n; i++) if (col[i]) ans++;
        cout << ans << "\n";
    }
    return 0;
}