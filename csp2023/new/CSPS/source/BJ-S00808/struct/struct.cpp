#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<string, int> mp;
string name[115][115];
int id, tot0;
ll siz[115], single[115];

vector<int> g[115];
vector<ll> prepos[115], endpos[115];

int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    mp["byte"] = 1, siz[1] = single[1] = 1;
    mp["short"] = 2, siz[2] = single[2] = 2;
    mp["int"] = 3, siz[3] = single[3] = 4;
    mp["long"] = 4, siz[4] = single[4] = 8;
    id = 4;
    int n;
    cin >> n;
    while (n--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            string s;
            int k;
            cin >> s >> k;
            mp[s] = ++id;
            ll max_size = 0, nwsum = 0;
            siz[id] = 0;
            for (int i = 1; i <= k; i++)
            {
                string t, sn;
                cin >> t >> sn;
                name[id][i] = sn;
                int nwd = mp[t];
                g[id].emplace_back(nwd);
                ll nowpos = !siz[id] ? 0 : ((siz[id] - 1) / single[nwd] + 1) * single[nwd];
                prepos[id].emplace_back(nowpos);
                endpos[id].emplace_back(nowpos + siz[nwd]);
                siz[id] = nowpos + siz[nwd];
                max_size = max(max_size, single[nwd]);
            }
            single[id] = max_size;
            siz[id] = ((siz[id] - 1) / single[id] + 1) * single[id];

            cout << siz[id] << " " << max_size << "\n";
        }
        else if (op == 2)
        {
            string t, sn;
            cin >> t >> sn;
            int id = mp[t];
            ll nowpos = !siz[0] ? 0 : ((siz[0] - 1) / single[id] + 1) * single[id];
            prepos[0].emplace_back(nowpos);
            endpos[0].emplace_back(nowpos + siz[id]);
            cout << nowpos << "\n";
            siz[0] = nowpos + siz[id];
            g[0].emplace_back(id);
            name[0][++tot0] = sn;
        }
        else if (op == 3)
        {
            string T, sn = "";
            cin >> T;
            int pos = 0;
            ll ans = 0;
            T = T + '.';
            for (int i = 0; i < T.length(); i++)
            {
                if (T[i] != '.')
                {
                    sn = sn + T[i];
                    continue;
                }
                for (int j = 0; j < g[pos].size(); j++)
                {
                    if (name[pos][j + 1] == sn)
                    {
                        ans += prepos[pos][j];
                        pos = g[pos][j];
                        break;
                    }
                }
                sn = "";
            }
            cout << ans << "\n";
        }
        else if (op == 4)
        {
            ll addr;
            cin >> addr;
            int pos = 0;
            string T = "";
            bool noans = false;
            if (siz[0] <= addr)
            {
                cout << "ERR\n";
                continue;
            }
            while (g[pos].size())
            {
                if (pos) T = T + ".";
                bool fl = false;
                for (int i = 0; i < g[pos].size(); i++)
                {
                    if (prepos[pos][i] <= addr && endpos[pos][i] > addr)
                    {
                        fl = true;
                        T = T + name[pos][i + 1];
                        addr -= prepos[pos][i];
                        pos = g[pos][i];
                        break;
                    }
                }
                if (!fl)
                {
                    noans = true;
                    break;
                }
            }
            if (noans) cout << "ERR\n";
            else cout << T << "\n";
        }
    }
    return 0;
}