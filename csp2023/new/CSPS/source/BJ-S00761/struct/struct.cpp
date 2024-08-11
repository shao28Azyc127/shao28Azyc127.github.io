#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX = 105;
int N, op[MX], K[MX], addr[MX], st, req[MX], len[MX];
string s[MX], t[MX][MX], n[MX][MX], nm[100005];
bool fA = 1, fC = 1, fD = 1;
map<string, int> sz, ST, tab;
namespace A
{
    void solve()
    {
        for (int i = 1; i <= N; i++)
        {
            if (op[i] == 2)
            {
                st = ceil(1.0 * st / sz[t[i][1]]) * sz[t[i][1]];
                cout << st << endl;
                ST[n[i][1]] = st;
                for (int j = 1; j <= sz[t[i][1]]; j++) nm[st++] = n[i][1];
            }
            else if (op[i] == 3) cout << ST[s[i]] << endl;
            else if (nm[addr[i]] != "") cout << nm[addr[i]] << endl;
            else puts("ERR");
        }
    }
}
namespace C
{
    void solve()
    {
        for (int i = 1; i <= N; i++)
        {
            if (op[i] == 1)
            {
                for (int j = 1; j <= K[i]; j++) req[i] = max(req[i], sz[t[i][j]]);
                len[i] = req[i] * K[i];
                cout << len[i] << " " << req[i] << endl;
            }
            else if (op[i] == 2)
            {
                if (t[i][1] != "byte" && t[i][1] != "short" && t[i][1] != "int" && t[i][1] != "long")
                {
                    int TB = tab[t[i][1]];
                    st = ceil(1.0 * st / req[TB]) * req[TB];
                    cout << st << endl;
                    ST[n[i][1]] = st;
                    for (int j = 1; j <= K[TB]; j++)
                    {
                        for (int k = st; k < st + sz[t[TB][j]]; k++) nm[k] = n[i][1] + "." + n[TB][j];
                        ST[n[i][1] + "." + n[TB][j]] = st;
                        st += req[TB];
                    }
                }
                else {
                    st = ceil(1.0 * st / sz[t[i][1]]) * sz[t[i][1]];
                    cout << st << endl;
                    ST[n[i][1]] = st;
                    for (int j = 1; j <= sz[t[i][1]]; j++) nm[st++] = n[i][1];
                }
            }
            else if (op[i] == 3) cout << ST[s[i]] << endl;
            else if (nm[addr[i]] != "") cout << nm[addr[i]] << endl;
            else puts("ERR");
        }
    }
}
int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cin >> N;
    sz["byte"] = 1, sz["short"] = 2, sz["int"] = 4, sz["long"] = 8;
    for (int i = 1; i <= N; i++)
    {
        cin >> op[i];
        if (op[i] == 1)
        {
            fA = 0;
            cin >> s[i] >> K[i];
            tab[s[i]] = i;
            for (int j = 1; j <= K[i]; j++)
            {
                cin >> t[i][j] >> n[i][j];
                if (t[i][j] != "long") fD = 0;
                if (t[i][j] != "byte" && t[i][j] != "short" && t[i][j] != "int" && t[i][j] != "long") fC = 0;
            }
        }
        if (op[i] == 2)
        {
            cin >> t[i][1] >> n[i][1];
            if (t[i][1] != "long") fD = 0;
        }
        if (op[i] == 3) cin >> s[i];
        if (op[i] == 4) cin >> addr[i];
    }
    if (fA) A::solve();
    else if (fC) C::solve();
    //else if (fD) D::solve();
    return 0;
}
