#include <bits/stdc++.h>
#define MP make_pair
using namespace std;
typedef long long ll;
int n;
struct node
{
    int t[6];
    inline bool operator<(const node &y) const
    {
        for (int i = 1; i <= 5; i++)
            if (t[i] != y.t[i])
                return t[i] < y.t[i];
        return 0;
    }
} a[10];
set<node> s;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5; j++)
            cin >> a[i].t[j];
        for (int j = 1; j <= 5; j++)
        {
            node cur = a[i];
            for (int cnt = 0; cnt < 9; cnt++)
                (cur.t[j] += 1) %= 10, s.insert(cur);
        }
        for (int j = 1; j <= 4; j++)
        {
            node cur = a[i];
            for (int cnt = 0; cnt < 9; cnt++)
                (cur.t[j] += 1) %= 10, (cur.t[j + 1] += 1) %= 10, s.insert(cur);
        }
    }
    int cnt = 0;
    for (node x : s)
    {
        bool fflg = 1;
        for (int i = 1; i <= n; i++)
        {
            bool flag = 0;
            for (int p = 1; p <= 5; p++)
            {
                node cur = x;
                for (int cnt = 0; cnt < 9; cnt++)
                {
                    (cur.t[p] += 1) %= 10;
                    bool tmp = 1;
                    for (int j = 1; j <= 5; j++)
                        if (a[i].t[j] != cur.t[j])
                            tmp = 0;
                    if (tmp)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag)
                    break;
            }
            for (int p = 1; p <= 4; p++)
            {
                node cur = x;
                for (int cnt = 0; cnt < 9; cnt++)
                {
                    (cur.t[p] += 1) %= 10, (cur.t[p + 1] += 1) %= 10;
                    bool tmp = 1;
                    for (int j = 1; j <= 5; j++)
                        if (a[i].t[j] != cur.t[j])
                            tmp = 0;
                    if (tmp)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag)
                    break;
            }
            if (!flag)
            {
                fflg = 0;
                break;
            }
        }
        cnt += fflg;
    }
    cout << cnt << '\n';
    return 0;
}