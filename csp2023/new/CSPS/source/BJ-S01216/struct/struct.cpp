#include <bits/stdc++.h>
#define int long long
using namespace std;
map<string, int> mp, MP;
vector<pair<int, string> > v[110];
int l[110], ll[110];
vector<pair<int, string> > V;
int L[110], R[110];
signed main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t, now = 0;
    cin >> t;
    mp["byte"] = ++now;
    l[now] = ll[now] = 1;
    mp["short"] = ++now;
    l[now] = ll[now] = 2;
    mp["int"] = ++now;
    l[now] = ll[now] = 4;
    mp["long"] = ++now;
    l[now] = ll[now] = 8;
    int nowp = 0;
    while (t--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            string s;
            int k;
            cin >> s >> k;
            mp[s] = ++now;
            while (k--)
            {
                string s1, s2;
                cin >> s1 >> s2;
                v[now].push_back(make_pair(mp[s1], s2));
                l[now] = max(l[now], l[mp[s1]]);
            }
            for (auto i : v[now])
            {
                if (ll[now] % l[i.first] != 0) ll[now] = (ll[now] / l[i.first] + 1) * l[i.first];
                ll[now] += ll[i.first];
            }
            if (ll[now] % l[now] != 0) ll[now] = (ll[now] / l[now] + 1) * l[now];
            cout << ll[now] << " " << l[now] << '\n';
        }
        else if (op == 2)
        {
            string s1, s2;
            cin >> s1 >> s2;
            V.push_back(make_pair(mp[s1], s2));
            if (nowp % l[mp[s1]] != 0) nowp = (nowp / l[mp[s1]] + 1) * l[mp[s1]];
            L[V.size() - 1] = nowp, R[V.size() - 1] = nowp + ll[mp[s1]] - 1;
            MP[s2] = V.size() - 1;
            nowp += ll[mp[s1]];
            cout << L[V.size() - 1] << '\n';
        }
        else if (op == 3)
        {
            string s;
            cin >> s;
            int n = s.size();
            int last = 0;
            vector<string> vec;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '.')
                {
                    vec.push_back(s.substr(last, i - last));
                    last = i + 1;
                }
            }
            vec.push_back(s.substr(last, n - last));
            int x = V[MP[vec[0]]].first, ans = L[MP[vec[0]]];
            for (int i = 1; i < vec.size(); i++)
            {
                string S = vec[i];
                for (auto j : v[x])
                {
                    if (ans % l[j.first] != 0) ans = (ans / l[j.first] + 1) * l[j.first];
                    if (j.second == S)
                    {
                        x = j.first;
                        break;
                    }
                    else
                    {
                        ans += ll[j.first];
                    }
                }
            }
            cout << ans << '\n';
        }
        else
        {
            int p;
            cin >> p;
            int x = -1;
            for (int i = 0; i < V.size(); i++) if (L[i] <= p && p <= R[i]) x = i;
            if (x == -1)
            {
                cout << "ERR" << '\n';
                continue;
            }
            vector<string> vec;
            vec.push_back(V[x].second);
            int kkk = L[x];
            bool flag = true;
            x = V[x].first;
            while (x >= 5)
            {
                int fff = x;
                for (auto i : v[x])
                {
                    if (kkk % l[i.first] != 0) kkk = (kkk / l[i.first] + 1) * l[i.first];
                    if (kkk > p)
                    {
                        flag = false;
                        break;
                    }
                    if (kkk + ll[i.first] > p)
                    {
                        vec.push_back(i.second);
                        x = i.first;
                        break;
                    }
                    else kkk += ll[i.first];
                }
                if (x == fff) flag = false;
                if (!flag) break;
            }
            if (flag)
            {
                for (int i = 0; i < vec.size(); i++)
                {
                    if (i == 0) cout << vec[i];
                    else cout << "." << vec[i];
                }
                cout << '\n';
            }
            else cout << "ERR" << '\n';
        }
    }
    return 0;
}