#include <bits/stdc++.h>
#define MP make_pair
using namespace std;
typedef long long ll;
const int N = 3e5 + 5;
int n, tot, vis[N];
string name[N];
struct node
{
    vector<pair<string, string>> vec;
};
map<string, int> fnd;
map<string, node> mp;
inline void insert(string s, int len)
{
    while (tot % len)
        tot++;
    fnd[s] = tot;
    for (int i = 0; i < len; i++, tot++)
        name[tot] = s, vis[tot] = 1;
}
inline int getlen(string s)
{
    if (s == "byte")
        return 1;
    if (s == "short")
        return 2;
    if (s == "int")
        return 4;
    return 8;
}
int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            string s, s1, s2;
            int k;
            node t;
            cin >> s >> k;
            while (k--)
                cin >> s1 >> s2, t.vec.emplace_back(MP(s1, s2));
            mp[s] = t;
        }
        else if (op == 2)
        {
            string s1, s2;
            cin >> s1 >> s2;
            if (s1 == "byte" || s1 == "short" || s1 == "int" || s1 == "long")
                insert(s2, getlen(s1));
            else
            {
                node t = mp[s1];
                int mx = 0;
                for (pair<string, string> x : t.vec)
                    mx = max(mx, getlen(x.first));
                while (tot % mx)
                    tot++;
                fnd[s2] = tot;
                for (pair<string, string> x : t.vec)
                    insert(s2 + "." + x.second, getlen(x.first));
                while (tot % mx)
                    tot++;
            }
        }
        else if (op == 3)
        {
            string s;
            cin >> s;
            cout << fnd[s] << '\n';
        }
        else
        {
            int x;
            cin >> x;
            cout << (vis[x] ? name[x] : "ERR") << '\n';
        }
    }
    return 0;
}