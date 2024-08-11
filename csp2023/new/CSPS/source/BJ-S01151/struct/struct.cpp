#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int N = 110;

int n, cnt = 4;
string ti[N], ni[N], tt[N], nn[N];
int sz[N] = {0, 1, 1, 1, 1}, mxsz[N] = {0, 1, 2, 4, 8}, tsz[N] = {0, 1, 2, 4, 8};
unordered_map<string, int> ntan[N], ntt, ntt2[N];
unordered_map<int, string> antn[N];
int acnt;

signed main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    ntt[string("byte")] = 1, ntt[string("short")] = 2, ntt[string("int")] = 3, ntt[string("long")] = 4;
    for (int i = 1; i <= n; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            string s;
            int k;
            cin >> s >> k;
            ntt[s] = ++cnt;
            for (int j = 1; j <= k; j++)
                cin >> ti[j] >> ni[j], mxsz[cnt] = max(mxsz[cnt], mxsz[ntt[ti[j]]]);
            for (int j = 1; j <= k; j++)
            {
                ntan[cnt][ni[j]] = sz[cnt];
                antn[cnt][sz[cnt]] = ni[j];
                ntt2[cnt][ni[j]] = ntt[ti[j]];
                sz[cnt] += ceil(1.0 * sz[ntt[ti[j]]] / mxsz[cnt]);
            }
            tsz[cnt] = sz[cnt] * mxsz[cnt] - (mxsz[cnt] - sz[ntt[ti[k]]] * mxsz[ntt[ti[k]]]);
            cout << sz[cnt] * mxsz[cnt] << ' ' << mxsz[cnt] << endl;
        }
        else if (op == 2)
        {
            acnt++;
            cin >> tt[acnt] >> nn[acnt];
        }
        else if (op == 3)
        {
            string s;
            cin >> s;
            int len = s.length(), lst = 0, now = 0, ans = 0;
            for (int j = 0; j <= len; j++)
                if (s[j] == '.' || j == len)
                {
                    string t = s.substr(lst, j - lst);
                    if (!lst)
                    {
                        for (int k = 1; k <= acnt; k++)
                        {
                            now = ntt[tt[k]];
                            if (nn[k] == t)
                                break;
                            ans += sz[now] * mxsz[now];
                        }
                        lst = j + 1;
                    }
                    else
                    {
                        ans += ntan[now][t] * mxsz[now];
                        now = ntt2[now][t];
                        lst = j + 1;
                    }
                }
            cout << ans << endl;
        }
        else if (op == 4)
        {
            int addr;
            cin >> addr;
            string ans = "";
            int now = 0, j = 1;
            bool flag = 0;
            for (j = 1; j <= acnt && !flag; j++)
            {
                now = ntt[tt[j]];
                if (addr <= sz[now] * mxsz[now])
                    flag = 1;
                addr -= sz[now] * mxsz[now];
            }
            addr += sz[now] * mxsz[now];
            if (!flag)
            {
                cout << "ERR" << endl;
                continue;
            }
            ans += nn[j - 1] + ".";
            while (now > 4)
            {
                if (addr > tsz[now])
                {
                    cout << "ERR" << endl;
                    flag = 0;
                    break;
                }
                int num = addr / mxsz[now];
                ans += antn[now][num] + ".";
                now = ntt2[now][antn[now][num]];
            }
            if (flag)
                cout << ans.substr(0, ans.length() - 1) << endl;
        }
    }
    return 0;
}

