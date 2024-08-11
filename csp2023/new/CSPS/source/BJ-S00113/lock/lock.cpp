#include <cstdio>
#include <vector>
using namespace std;

const int N = 10, M = 1e5 + 5;

int n, x, val[N], vis[M], ans;
vector<int> v[N];

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            scanf("%d", &x);
            val[i] = val[i] * 10 + x;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int a = (val[i] / 10000) % 10, b = (val[i] / 1000) % 10, c = (val[i] / 100) % 10, d = (val[i] / 10) % 10, e = val[i] % 10;
        for (int j = 0; j <= 9; j++)
            if (j != a)
                v[i].push_back(j * 10000 + b * 1000 + c * 100 + d * 10 + e);
        for (int j = 0; j <= 9; j++)
            if (j != b)
                v[i].push_back(a * 10000 + j * 1000 + c * 100 + d * 10 + e);
        for (int j = 0; j <= 9; j++)
            if (j != c)
                v[i].push_back(a * 10000 + b * 1000 + j * 100 + d * 10 + e);
        for (int j = 0; j <= 9; j++)
            if (j != d)
                v[i].push_back(a * 10000 + b * 1000 + c * 100 + j * 10 + e);
        for (int j = 0; j <= 9; j++)
            if (j != e)
                v[i].push_back(a * 10000 + b * 1000 + c * 100 + d * 10 + j);
        int tmp1, tmp2;
        for (int j = 1; j <= 9; j++)
        {
            tmp1 = (a + j) % 10, tmp2 = (b + j) % 10;
            v[i].push_back(tmp1 * 10000 + tmp2 * 1000 + c * 100 + d * 10 + e);
        }
        for (int j = 1; j <= 9; j++)
        {
            tmp1 = (b + j) % 10, tmp2 = (c + j) % 10;
            v[i].push_back(a * 10000 + tmp1 * 1000 + tmp2 * 100 + d * 10 + e);
        }
        for (int j = 1; j <= 9; j++)
        {
            tmp1 = (c + j) % 10, tmp2 = (d + j) % 10;
            v[i].push_back(a * 10000 + b * 1000 + tmp1 * 100 + tmp2 * 10 + e);
        }
        for (int j = 1; j <= 9; j++)
        {
            tmp1 = (d + j) % 10, tmp2 = (e + j) % 10;
            v[i].push_back(a * 10000 + b * 1000 + c * 100 + tmp1 * 10 + tmp2);
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 81; j++)
            vis[v[i][j]]++;
    for (int i = 0; i < 100000; i++)
        if (vis[i] == n)
            ans++;
    printf("%d", ans);
    return 0;
}