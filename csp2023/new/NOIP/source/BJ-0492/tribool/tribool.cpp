#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 2e5 + 10, M = 8e5 + 10;
int n, m, a[N], fath[N], tr_size[N], tag[N];

inline int inv(int t)
{
    if (t > 2 * n)
        return 4 * n + 4 - t;
    else
        return t > n ? t - n : t + n;
}

int findf(int p)
{
    if (fath[p] == p)
        return p;
    fath[p] = findf(fath[p]);
    return fath[p];
}

void add(int u, int v)
{
    int p = findf(u), q = findf(v);
    if (p != q)
    {
        fath[p] = q;
        tr_size[q] += tr_size[p];
    }
}

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);

    int c, T;
    cin >> c >> T;
    while(T -- )
    {
        cin >> n >> m;
        for (int i = 1; i <= n * 2 + 3; ++ i )
            fath[i] = i, tr_size[i] = 1, tag[i] = 0, a[i] = i;

        while(m -- )
        {
            char x;
            int u, v;
            cin >> x;
            if (x == '+' || x == '-') cin >> u >> v;
            else cin >> u;

            if (x == '+') a[u] = a[v];
            else if (x == '-')
            {
                //cout<<u<<' '<<v<<' '<<inv(a[v])<<endl;
                a[u] = inv(a[v]);
            }
            else if (x == 'T') a[u] = 2 * n + 3;
            else if (x == 'F') a[u] = 2 * n + 1;
            else a[u] = 2 * n + 2;
        }
        for (int i = 1; i <= n; ++ i )
        {
            //cout<<a[i]<<' ';
            add(i, a[i]);
            add(i + n, inv(a[i]));
        }
        //cout<<endl;

        for (int i = 1; i <= n * 2; ++ i )
            findf(i);
        for (int i = 1; i <= n; ++ i )
            if (fath[i] == fath[i + n])
            {
                tag[fath[i]] = 1;
                //cout<<i<<' '<<fath[i]<<endl;
            }
        int res = 0;
        tag[2 * n + 2] = 1;
        for (int i = 1; i <= 2 * n + 2; ++ i )
            if (tag[i] && fath[i] == i)
            {
                res += tr_size[i];
                //cout<<"ROOT "<<i<<' '<<tr_size[i]<<endl;
            }

        /*if (res % 2 == 0)
            puts("WRONG WONG !!!!!!!");*/
        printf("%d\n", (res - 1) / 2);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
