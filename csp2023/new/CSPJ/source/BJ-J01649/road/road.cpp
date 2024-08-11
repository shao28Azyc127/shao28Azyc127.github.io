#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, d;
int v[N], a[N];
double yy;

int dfs(int r)
{
        if (r == 1) return 0;
        int minn = 2e9, p;
        for (int i = 1; i < r; i++)
                if (a[i] < minn)
                        p = i, minn = a[i];
        int res = 0;
        for (int i = p; i < r; i++)
                res += v[i];
        int ans = dfs(p) + ceil(((double) res - yy * d) / d) * a[p];
        yy = ceil(((double) res - yy * d) / d) - ((double) res - yy * d) / d;
        //printf("%d->%d, money %d, yy %lf\n", p, r, ans, yy * d);
        return ans;
}

int main()
{
        freopen("road.in", "r", stdin);
        freopen("road.out", "w", stdout);
        scanf("%d%d", &n, &d);
        for (int i = 1; i <= n - 1; i++)
                scanf("%d", &v[i]);
        for (int i = 1; i <= n; i++)
                scanf("%d", &a[i]);
        printf("%d\n", dfs(n));

        return 0;
}
