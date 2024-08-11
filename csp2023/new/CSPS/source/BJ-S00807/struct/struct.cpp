#include <bits/stdc++.h>
#define mk make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair <int, int> pii;
const int N = 100 + 10;
inline int read ()
{
    int x = 0, f = 1;
    char c = getchar ();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar (); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c ^ 48); c = getchar (); }
    return x * f;
}
int n;
long long p;
string op, name;
struct Str {
    string op[N], name[N];
    long long siz[N];
    int mx, cnt;
}str[N];
struct op2 {
    string op, name;
}M[N]; int cntm;
struct query {
    string name;
    int i;
}Q[N];
vector <query> vec[N];
long long ans2[N], ans3[N];
struct query2 {
    int x, i;
    bool operator < (const query2 &A) const {
        return x < A.x;
    }
}Q2[N]; int cntq; string ans4[N][N]; int len[N];
pii ans1[N];
map <string, int> mp, mp2;
int opet[N];
int cnts, cnts2;
void find (string op, int x, string name)
{
    string now2; int now;
    for (int i = name.find ('.') + 1; i < name.size (); i++)
        if (name[i] == '.') { now2 = name.substr (name.find ('.') + 1, i - 1); now = i + 1; break; }
    do
    {
        int s = mp[op]; int sum = 0;
        for(int j = 1; j <= str[s].cnt; j++)
        {
            sum += str[s].siz[j];
            if (str[s].name[j] == now2)
            {
                op = str[s].op[j];
                for (int i = now; i < name.size (); i++)
                    if (name[i] == '.') { now2 = name.substr (now, i - 1); now = i + 1; break; }
                break;
            }
        }
    } while (now < name.size());
}
bool check (string o)
{
    if (o == "byte") return true;
    else if (o == "short") return true;
    else if (o == "int") return true;
    else if (o == "long") return true;
    return false;
}
signed main ()
{
    // freopen ("struct.in", "r", stdin);
    // freopen ("struct.out", "w", stdout);
    n = read ();
    for (int i = 1; i <= n; i++)
    {
        opet[i] = read ();
        if (opet[i] == 1)
        {
            cin >> name;
            mp[name] = ++cnts;
            str[cnts].cnt = read (); str[cnts].mx = 0;
            for (int i = 1; i <= str[cnts].cnt; i++)
            {
                cin >> str[cnts].op[i] >> str[cnts].name[i];
                if (str[cnts].op[i] == "byte") str[cnts].siz[i] = 1, str[cnts].mx = max (str[cnts].mx, 1);
                else if (str[cnts].op[i] == "short") str[cnts].siz[i] = 2, str[cnts].mx = max (str[cnts].mx, 2);
                else if (str[cnts].op[i] == "int") str[cnts].siz[i] = 4, str[cnts].mx = max (str[cnts].mx, 4);
                else if (str[cnts].op[i] == "long") str[cnts].siz[i] = 8, str[cnts].mx = max (str[cnts].mx, 8);
                else
                {
                    int s = mp[str[cnts].op[i]];
                    str[cnts].siz[i] = 1ll * str[s].mx * str[s].mx;
                    str[cnts].mx = max (str[cnts].mx, str[s].mx);
                }
            }
            ans1[i] = mk (str[cnts].mx, str[cnts].cnt);
        }
        if (opet[i] == 2) { ++cntm; cin >> M[cntm].op >> M[cntm].name; mp2[M[cntm].name] = cntm;}
        if (opet[i] == 3)
        {
            string Name;
            cin >> name;name[name.size()] = '.';
            int s = name.find ('.');
            Name = name.substr(0, s);
            vec[mp2[Name]].pb((query){name, i});
        }
        if (opet[i] == 4) { int k = read (); Q2[++cntq] = (query2){k, i}; }
    }
    sort (Q2 + 1, Q2 + cntq + 1);
    int p1 = 0, p2 = 1;
    for (int i = 1; i <= n; i++)
    {
        if (opet[i] == 2)
        {
            p1++; ans2[i] = p;
            long long tmp;
            if (M[p1].op == "byte") tmp = 1;
            else if (M[p1].op == "short") tmp = 2;
            else if (M[p1].op == "int") tmp = 4;
            else if (M[p1].op == "long") tmp = 8;
            else tmp = (1ll * str[mp[M[p1].op]].mx * str[mp[M[p1].op]].cnt);
            // for (auto v : vec[mp2[M[p1].name]]) find (M[p1].op, v.i, v.name);
            cout << p << " " << tmp << "\n";
            while (Q2[p2].x <= p + tmp && p2 <= cntq)
            {
                ans4[i][++len[i]] = M[p1].name; op = M[p1].op;
                while (!check (op))
                {
                    int s = mp[op]; int sum = 0;
                    for(int j = 1; j <= str[s].cnt; j++)
                    {
                        sum += str[s].siz[j];
                        if (Q2[p2].x <= p + sum)
                        {
                            cout << str[s].op[j] << "\n"; return 0;
                            op = str[s].op[j], ans4[i][++len[i]] = str[s].name[j];
                            break;
                        }
                    }
                }
                p2++;
            }
            p += tmp;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (opet[i] == 1) printf ("%lld %d\n", 1ll * ans1[i].fi * ans1[i].se, ans1[i].fi);
        else if (opet[i] == 2) printf ("%lld\n", ans2[i]);
        else if (opet[i] == 3) printf ("%lld\n", ans3[i]);
        else
        {
            cout << len[i] << " ";
            for (int j = 1; j <= len[i]; j++) printf ("%s.", ans4[i][j]);
        }
    }
    return 0;
}
/*
5
1 a 2
short aa
int ab
1 b 2
a ba
long bb
2 b x
3 x.ba.ab
4 10
*/