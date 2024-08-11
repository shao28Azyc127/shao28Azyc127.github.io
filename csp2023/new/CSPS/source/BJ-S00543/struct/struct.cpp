#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>

using namespace std;
typedef long long ll;
const ll N = 110;

map<string, int> tid, vid;
string tname[N] = { "", "byte", "short", "int", "long" }, vname[N];
ll siz[N] = { 0, 1, 2, 4, 8 }, tcnt;
ll vcnt, vt[N], vp[N], np;

bool find(int ad)
{
    for (int i = 1; i <= vcnt; i++)
    {
        if (vp[i] <= ad && vp[i] + siz[vt[i]] > ad)
        {
            cout << vname[i] << endl;
            return true;
        }
    }
    return false;
}

int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    for (int i = 1; i <= 4; i++)
    {
        tid[tname[i]] = i;
    }
    int T;
    cin >> T;
    while (T--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            string s;
            int n;
            cin >> s >> n;
            tname[++tcnt] = s;
            tid[s] = tcnt;
            for (int i = 1; i <= n; i++)
            {
                string typ, name;
                cin >> typ >> name;
            }
        }
        else if (op == 2)
        {
            string typ, name;
            cin >> typ >> name;
            vid[name] = ++vcnt;
            vname[vcnt] = name;
            ll t = tid[typ];
            vt[vcnt] = t;
            vp[vcnt] = np + (np % siz[t] ? siz[t] - np % siz[t] : 0);
            np = vp[vcnt] + siz[t];
        }
        else if (op == 3)
        {
            string name;
            cin >> name;
            cout << vp[vid[name]] << endl;
        }
        else
        {
            ll addr;
            cin >> addr;
            if (!find(addr))
            {
                puts("ERR");
            }
        }
    }
    return 0;
}