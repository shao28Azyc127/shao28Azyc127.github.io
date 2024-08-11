#include<iostream>
#include<cstdio>
#include<algorithm>
#include<utility>
#include<map>
#include<cstring>
#include<vector>
#define int long long
using namespace std;

struct h
{
    string x, y;
};

int key = 0;
map<string, int> m;
map<string, vector<h> > mp1;
map<string, pair<string, int> > v;

void f()
{
    m["byte"] = 1;
    m["short"] = 2;
    m["int"] = 4;
    m["long"] = 8;
}

void op1()
{
    int n, k = -1e9,cnt = 0;
    string s;
    cin >> s >> n;
    for (int i = 1; i <= n; i++)
    {
        string x, y;
        cin >> x >> y;
        h g;
        g.x = x, g.y = y;
        mp1[s].push_back(g);
        k = max(k, m[x]);
        cnt += m[x];
    }
    m[s] = n * k;
    cout << cnt << " " << k << endl;
}

void op2()
{
    string x, y;
    cin >> x >> y;
    h g;
    g.x = x, g.y = y;
    cout << key << endl;
    v[y] = make_pair(x, key);
    key += m[x];
}

void op3()
{
    int ans = 0;
    string s, x = "", y = "";
    cin >> s;
    s = s + '.';
    int i = 0;
    for ( ; i < s.size(); i++)
    {
        if (s[i] != '.')
        {
            y += s[i];
        }
        else break;
    }
    ans += v[y].second;
    x = v[y].first;
    y = "";
    for ( ; i < s.size(); i++)
    {
        if (s[i] != '.')
        {
            y += s[i];
        }
        else
        {
            for (int j = 0; j < mp1[x].size(); j++)
            {
                if (mp1[x][j].y == y)
                {
                    ans += m[x] / mp1[x].size() * j;
                    x = mp1[x][j].x;
                    y = "";
                }
            }
        }
    }
    cout << ans << endl;
}

void op4()
{
    cout << endl;
}

signed main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    f();
    int t;
    cin >> t;
    while (t--)
    {
        int op;
        cin >> op;
        if (op == 1) op1();
        if (op == 2) op2();
        if (op == 3) op3();
        if (op == 4) op4();
    }
    return 0;
}
