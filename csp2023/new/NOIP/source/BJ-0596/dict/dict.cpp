# include "bits/stdc++.h"

using namespace std;
const int maxn = 3e3 + 10;
struct node
{
    string s,sm, sn;
    int id, ans;
}a[maxn];
int n, m, k;
int down2, down3;
char minn, maxx;
string s;
char c;
inline void Swap (char &a, char &b)
{
    c = a;a = b;b = c;
}
inline bool cmp1 (node a, node b)
{
    return (a.s < b.s);
}
inline bool cmp2 (node a, node b)
{
    return (a.id < b.id);
}

int main ()
{
    freopen ("dict.in", "r", stdin);
    freopen ("dict.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) {cin >> a[i].s;a[i].id = i;}
    sort (a + 1, a + n + 1, cmp1);a[1].ans = 1;sort (a + 1, a + n + 1, cmp2);
    if (n == 1){puts ("1");return (0);}
    for (int i = 1 ; i <= n ; i++)
    {
        a[i].sn = a[i].s; a[i].sm = a[i].s;
        minn = 'z'; maxx = 'a';
        for (int j = 0 ; j < m ; j++)
            if (maxx <= a[i].s[j])
            {
                maxx = a[i].s[j];
                down3 = j;
                if (maxx == 'z')
                    break;
            }
        for (int j = m - 1 ; j > 0 ; j--)
            if (minn >= a[i].s[j])
            {
                minn = a[i].s[j];
                down2 = j;
                if (minn == 'a')
                    break;
            }
        for (int j = 0 ; j < down2 ; j++)
            if (a[i].sn[j] != a[i].sn[down2])
            {
                Swap (a[i].sn[j], a[i].sn[down2]);
                break;
            }
        for (int j = 0 ; j < down3 ; j++)
            if (a[i].sm[j] != a[i].sm[down3])
            {
                Swap (a[i].sm[j], a[i].sm[down3]);
                break;
            }
        a[i].s = a[i].sm;
    }
    for (int i = 1 ; i <= n ; i++)
    {
        k = i;
        a[i].s = a[i].sn;
        sort (a + 1, a + n + 1, cmp1);
        s = a[1].s;
        sort (a + 1, a + n + 1, cmp2);
        if (s == a[k].s)
            a[k].ans = 1;
        a[k].s = a[k].sm;
    }
    for (int i = 1 ; i <= n ; i++)
        cout << a[i].ans;
    cout << "\n";
    return (0);
}