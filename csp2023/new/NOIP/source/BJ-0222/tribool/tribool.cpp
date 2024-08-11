#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
const int pow3[15] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049};

int c, t;
int n, m, a, b, cnt, ans;
int aa[15], bb[15];
char u[15], v;
int vars[maxn], vare[maxn];
bool flag;

int not1 (int x)
{
    if (x == 0) return 1;
    if (x == 1) return 0;
    return 2;
}

void init ()
{
    n = m = a = b = cnt = v = 0;
    ans = 1e5;
    memset (aa, 0, sizeof (a));
    memset (bb, 0, sizeof (b));
    memset (u, 0, sizeof (u));
    memset (vars, 0, sizeof (vars));
    memset (vare, 0, sizeof (vare));
    flag = 0;
}

void c12 ()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        cin >> u[i];
        if (u[i] == '+' || u[i] == '-')
            cin >> aa[i] >> bb[i];
        else
            cin >> aa[i];
    }
    for (int w = 0; w <= pow3[n] - 1; w ++)
    {
        flag = 0;
        cnt = 0;
        for (int i = 1; i <= n; i ++)
        {
            vars[i] = (w / pow3[i - 1]) % 3;
            vare[i] = vars[i];
        }
        for (int i = 1; i <= m; i ++)
        {
            //if (w == 0) cout << u[i] << a[i] << b[i] << endl;
            if (u[i] == '+' || u[i] == '-')
            {
                if (u[i] == '+') vare[aa[i]] = vare[bb[i]];
                else vare[aa[i]] = not1 (vare[bb[i]]);
            }
            else
            {
                if (u[i] == 'F') vare[aa[i]] = 0;
                else if (u[i] == 'T') vare[aa[i]] = 1;
                else vare[aa[i]] = 2;
            }
        }
        for (int i = 1; i <= n; i ++)
        {
            if (vars[i] != vare[i])
            {
                flag = 1;
                break;
            }
            if (vars[i] == 2) cnt ++;
        }
        if (flag) continue;
        ans = min (ans, cnt);
    }
    cout << ans << endl;
}

void c34 ()
{
    cin >> n >> m;
    ans = 0;
    for (int i = 1; i <= m; i ++)
    {
        cin >> v >> a;
        if (v == 'U')
        {
            vare[a] = 1;
            ans ++;
        }
        else if (vare[a] == 1)
        {
            vare[a] = 0;
            ans --;
        }
    }
    cout << ans << endl;
}

int main ()
{
    freopen ("tribool.in", "r", stdin);
    freopen ("tribool.out", "w", stdout);
    cin >> c >> t;
    while (t --)
    {
        //memset (vars, -1, sizeof (vars));
        init ();
        if (c == 1 || c == 2)
            c12 ();
        if (c == 3 || c == 4)
            c34 ();
    }
    return 0;
}
