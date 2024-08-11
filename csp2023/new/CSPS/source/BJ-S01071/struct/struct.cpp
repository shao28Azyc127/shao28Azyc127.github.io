#include <iostream>
#include <cstring>
#include <map>

typedef long long ll;
typedef double lf;

namespace FastIO
{
    const int MAXSIZE = 1 << 20;
    char buf[MAXSIZE], *p1, *p2;
    #define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2) ? EOF : *p1++)
    #define isdigit(x) ((x) >= '0' && (x) <= '9')
    template <typename T>
    inline void Read(T &x)
    {
        x = 0; bool f = 0; char ch = gc();
        while (!isdigit(ch)) {if (ch == '-') f = 1; ch = gc();}
        while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = gc();
        if (f) x = -x;
    }
}

using FastIO::Read;
using namespace std;

struct Type
{
    ll sz; int len, cnt;
    string name, nm[105];
    int tp[105];
    ll pos[105];
}f[110];
int tot;
map <string, int> idx;

string vari[105];
int bel[105], n;
ll st[105], prv;

int Q;

int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    tot++, f[tot].sz = f[tot].len = 1, f[tot].name = "byte", idx["byte"] = 1;
    tot++, f[tot].sz = f[tot].len = 2, f[tot].name = "short", idx["short"] = 2;
    tot++, f[tot].sz = f[tot].len = 4, f[tot].name = "int", idx["int"] = 3;
    tot++, f[tot].sz = f[tot].len = 8, f[tot].name = "long", idx["long"] = 4;
    cin >> Q;
    int op, k; ll addr;
    string type, name, tp, nm;
    while (Q--)
    {
        cin >> op;
        // cout << "#\n";
        if (op == 1)
        {
            cin >> name >> k;
            tot++, f[tot].name = name, f[tot].cnt = k, idx[name] = tot;
            int len = 0; ll pre = 0;
            for (int i = 1; i <= k; i++)
            {
                cin >> tp >> nm;
                f[tot].tp[i] = idx[tp], f[tot].nm[i] = nm, len = max(len, f[f[tot].tp[i]].len);
            }
            f[tot].len = len;
            for (int i = 1; i <= k; i++)
            {
                pre = (pre + f[f[tot].tp[i]].len - 1) / (ll)f[f[tot].tp[i]].len * (ll)f[f[tot].tp[i]].len;
                f[tot].pos[i] = pre, pre += f[f[tot].tp[i]].sz;
            }
            pre = (pre + len - 1) / (ll)len * (ll)len;
            f[tot].sz = pre;
            cout << f[tot].sz << " " << f[tot].len << "\n";
        }
        else if (op == 2)
        {
            cin >> type >> name;
            n++, vari[n] = name, bel[n] = idx[type];
            prv = (prv + f[bel[n]].len - 1ll) / (ll)f[bel[n]].len * (ll)f[bel[n]].len;
            st[n] = prv, prv += f[bel[n]].sz;
            cout << st[n] << "\n";
        }
        else if (op == 3)
        {
            cin >> name;
            bool flag = 0; int cur = 0; ll strt = 0;
            for (int l = 0, r = 0; l < name.size(); l = r + 1)
            {
                // cout << l << " " << r << "\n";
                type = "", r = l;
                while (r < name.size() && name[r] != '.') type += name[r], r++;
                if (!flag)
                {
                    for (int i = 1; i <= n; i++)
                        if (vari[i] == type)
                        {
                            strt = st[i], cur = bel[i];
                            break;
                        }
                    flag = 1;
                }
                else
                {
                    for (int i = 1; i <= f[cur].cnt; i++)
                        if (f[cur].nm[i] == type)
                        {
                            strt += f[cur].pos[i], cur = f[cur].tp[i];
                            break;
                        }
                }
            }
            cout << strt << "\n";
        }
        else
        {
            cin >> addr;
            name = "";
            int cur = 1, nc; bool flag = 0;
            while (cur < n && st[cur + 1] <= addr) cur++;
            if (st[cur] + f[bel[cur]].sz <= addr) {cout << "ERR\n"; continue;}
            addr -= st[cur], name += vari[cur], cur = bel[cur];
            while (cur > 4)
            {
                nc = 1;
                while (nc < f[cur].cnt && f[cur].pos[nc + 1] <= addr) nc++;
                if (f[cur].pos[nc] + f[f[cur].tp[nc]].sz <= addr) {flag = 1; break;}
                addr -= f[cur].pos[nc], name += "." + f[cur].nm[nc], cur = f[cur].tp[nc];
            }
            if (flag) {cout << "ERR\n"; continue;}
            cout << name << "\n";
        }
    }
    return 0;
}