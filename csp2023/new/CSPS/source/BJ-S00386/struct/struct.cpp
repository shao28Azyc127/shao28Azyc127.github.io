#include <bits/stdc++.h>
using namespace std;

const int maxn = 120;
const int maxaddr = 1e5 + 10;

int n, k;
int opt, addr, cnt, now;
string typ, nam;
string a[maxaddr], s;

map <string, int> mp;
map <string, int> mp2;


int main ()
{
    freopen ("struct.in", "r", stdin);
    freopen ("struct.out", "w", stdout);
    mp["byte"] = 1;
    mp["short"] = 2;
    mp["int"] = 4;
    mp["long"] = 8;
    cin >> n;
    for (int z = 1; z <= n; z ++)
    {
        cin >> opt;
        if (opt == 2)
        {
            cin >> typ >> nam;
            now = ceil (now * 1.0 / mp[typ]) * mp[typ];
            cout << now << endl;
            mp2[nam] = now;
            for (int i = now; i <= now + mp[typ] - 1; i ++)
            {
                a[i] = nam;
            }
            now += mp[typ];
        }
        else if (opt == 3)
        {
            cin >> nam;
            cout << mp2[nam] << endl;
        }
        else
        {
            cin >> addr;
            cout << (a[addr] == "" ? "ERR" : a[addr]) << endl;
        }
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

const int maxn = 120;
const int maxaddr = 1e5 + 10;

struct stru
{
    int siz, tab, cnt;
    string contn[maxn];
    int contsi[maxn], contst[maxn];
};
struct var
{
    int nam, siz, st;
};

int n, k;
int opt, addr, cnt, now;
string typ, nam;
string a[maxaddr], s;

map <string, int> mp;
map <string, stru> mp2;
map <string, int> mp3;


int main ()
{
    freopen ("struct2.in", "r", stdin);
    mp["byte"] = 1;
    mp["short"] = 2;
    mp["int"] = 4;
    mp["long"] = 8;
    cin >> n;
    for (int z = 1; z <= n; z ++)
    {
        cin >> opt;
        if (opt == 1)
        {
            int now = 0;
            stru st;
            cin >> s >> k;
            for (int i = 1; i <= k; i ++)
            {
                st.cnt ++;
                cin >> typ >> nam;
                st.contn[st.cnt] = nam;
                st.contsi[st.cnt] = mp[typ];
                st.contst[st.cnt] = ceil (now * 1.0 / mp[typ]) * mp[typ];
                now = st.contst[st.cnt] + mp[typ] - 1;
                st.tab = max (st.tab, mp[typ]);
            }
            st.siz = ceil (now * 1.0 / st.tab) * st.tab;
            mp2[s] = st;
        }
        else if (opt == 2)
        {
            cin >> typ >> nam;
            if (typ == "byte" || typ == "short" || typ == "int" || typ == "long")
            {
                now = ceil (now * 1.0 / mp[typ]) * mp[typ];
                cout << now << endl;
                mp3[nam] = now;
                for (int i = now; i <= now + mp[typ] - 1; i ++)
                {
                    a[i] = nam;
                }
                now += mp[typ] - 1;
            }
            else
            {
                stru st = mp2[nam];
                now = ceil (now * 1.0 / st.tab) * st.tab;
                cout << now << endl;
                for (int i = 1; i <= st.cnt; i ++)
                {
                    if (i != 1)
                        now += st.contst[i] - st.contst[i - 1];
                    mp3["%s.%s", nam, st.contn[i]] = now;
                    for (int j = now + st.contst[i]; j <= now + st.contst[i] + st.contsi[i] - 1; j ++)
                    {
                        a[j] = "%s.%s", nam, st.contn[j];
                    }
                }
            }
        }
        else if (opt == 3)
        {
            cin >> nam;
            cout << mp3[nam] << endl;
        }
        else if (opt == 4)
        {
            cin >> addr;
            cout << (a[addr] == "" ? "ERR" : a[addr]);
        }
    }
    return 0;
}
*/
