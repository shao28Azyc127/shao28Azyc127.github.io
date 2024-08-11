#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010, M = N << 1;

int n;
LL a[N], b[N], c[N];
int h[N], e[M], ne[M], idx;
int p[N];
LL hight[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int u, int father, int dep)
{
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == father) continue;
        p[dep + 1] = j;
        dfs(j, u, dep + 1);
    }
}

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i ++ )
        cin >> a[i] >> b[i] >> c[i];
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i ++ )
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    p[1] = 1;
    dfs(1, -1, 1);

    int res = 0;
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= i; j ++ )
        {
            int k = p[j];
            hight[k] += max(b[k] + i * c[k], (LL)1);
        }
        res ++ ;
    }

    int t = 0;
    for (int i = 1; i <= n; i ++ )
    {
        int j = p[i];
        if (hight[j] >= a[j]) continue;
        for (int x = n + 1; ; x ++ )
        {
            hight[j] += max(b[j] + x * c[j], (LL)1);
            if (hight[j] >= a[j])
            {
                t = max(t, x - n);
                break;
            }
        }
    }
    res += t;

    cout << res << endl;

    return 0;
}