#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, cnt = 4, tot, loc, q[110];
string t[110], name[110], xm[110];
struct node1 {
    int id, len;
};
map<string, node1> mp;
struct node2 {
    string str;
    int l, r;
};
map<string, node2> mp1;
vector<node2> v[110];
signed main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    scanf("%lld", &n);
    mp["byte"] = {1, 1};
    mp["short"] = {2, 2};
    mp["int"] = {3, 4};
    mp["long"] = {4, 8};
    while (n--) {
        int op;
        scanf("%lld", &op);
        if (op == 1) {
            string s;
            cin >> s;
            int k;
            scanf("%lld", &k);
            int mx = 0;
            for (int i = 1; i <= k; i++) {
                cin >> t[i] >> name[i];
                mx = max(mx, mp[t[i]].len);
            }
            mp[s] = {++cnt, mx * k};
            int pos = 0;
            for (int i = 1; i <= k; i++) {
                v[cnt].push_back({name[i], pos, pos + mp[t[i]].len - 1});
                pos += mx;
            }
            printf("%lld %lld\n", mx * k, mx);
        }
        else if (op == 2) {
            string t1, n1;
            cin >> t1 >> n1;
            q[++tot] = loc;
            xm[tot] = n1;
            mp1[n1] = {t1, loc, loc + mp[t1].len - 1};
            printf("%lld\n", loc);
            loc = loc + mp[t1].len;
        }
        else if (op == 3) {
            string s, s1 = "";
            cin >> s;
            int p = 0, num = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] != '.') s1 = s1 + s[i];
                else {
                    p = mp1[s1].l;
                    num = mp[mp1[s1].str].id;
                    s1 = "";
                }
            }
            if (!p && !num) printf("%lld\n", mp1[s].l);
            else {
                for (int i = 0; i < v[num].size(); i++) {
                    if (v[num][i].str == s1) {
                        p = p + v[num][i].l;
                        break;
                    }
                }
                printf("%lld\n", p);
            }
        }
        else {
            int pp;
            scanf("%lld", &pp);
            int x = lower_bound(q + 1, q + tot + 1, pp) - q;
            if (q[x] > pp || x > tot) x--;
            int tmp = pp - q[x], num = mp[mp1[xm[x]].str].id, flag = 0;
            if (num <= 4) {
                cout << xm[x] << '\n';
                continue;
            }
            for (int i = 0; i < v[num].size(); i++) {
                if (v[num][i].l <= tmp && v[num][i].r >= tmp) {
                    cout << xm[x] << '.' << v[num][i].str << '\n';
                    flag = 1;
                    break;
                }
            }
            if (!flag) puts("ERR");
        }
    }
    return 0;
}