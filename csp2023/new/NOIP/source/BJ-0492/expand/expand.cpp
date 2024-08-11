#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int N = 2010;
int n, m, T, c, x[N], y[N], z[N], u[N], v[N], flag = 0;
int f[N][N];

int sign(int t)
{
    if (t > 0) return 1;
    else if (t < 0) return -1;
    else return 0;
}

bool solve()
{
/*
918655047 930778126 791681101 956185939 941339699 845896874
950087990 922968889 880355772 966742067 834991722 909678381
 */
    /*cout<<"x: ";
    for (int i = 1; i <= n; ++ i )
        cout<<x[i]<<' ';
    cout<<"\ny: ";
    for (int i = 1; i <= m; ++ i )
        cout<<y[i]<<' ';
    cout<<endl;*/
    if (sign(x[1] - y[1]) * sign(x[n] - y[m]) <= 0) return 0;
    if (x[1] > y[1])
    {
        flag = 1;
        swap(n, m);
        memcpy(z, x, sizeof x);
        memcpy(x, y, sizeof y);
        memcpy(y, z, sizeof z);
    }
    memset(f, 0, sizeof f);
    f[0][0] = 1;
    for (int i = 1; i <= n; ++ i )
        f[i][0] = 1;
    for (int j = 1; j <= m; ++ j )
        f[0][j] = 1;
    for (int i = 1; i <= n; ++ i )
    {
        for (int j = 1; j <= m; ++ j )
        {
            if (x[i] >= y[j]) continue;
            f[i][j] = f[i - 1][j - 1];
            if (x[i] < y[j - 1])
                f[i][j] |= f[i][j - 1];
            if (y[j] > x[i - 1])
                f[i][j] |= f[i - 1][j];
        }
    }


    return f[n][m];
}

int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);

    cin >> c >> n >> m >> T;
    for (int i = 1; i <= n; ++ i )
        scanf("%d", &u[i]);
    for (int i = 1; i <= m; ++ i )
        scanf("%d", &v[i]);

    memcpy(x, u, sizeof u);
    memcpy(y, v, sizeof v);
    for (int i = 0; i <= T; ++ i )
    {
        if (solve()) printf("1");
        else printf("0");

        memcpy(x, u, sizeof u);
        memcpy(y, v, sizeof v);
        if (flag)
        {
            flag = 0;
            swap(m, n);
        }

        if (i != T)
        {
            int k, l, p, v;
            scanf("%d%d", &k, &l);
            while(k -- )
            {
                scanf("%d%d", &p, &v);
                x[p] = v;
            }
            while(l -- )
            {
                scanf("%d%d", &p, &v);
                y[p] = v;
            }
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
