#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int, int> > v[100010];
int dp[1010][1010];
int dp2[2][100010];
map<int, int> mp;
signed main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c, t;
    cin >> c >> t;
    if (c <= 9)
    {
        while (t--)
        {
            int n, m, k, d;
            cin >> n >> m >> k >> d;
            for (int i = 1; i <= n; i++) v[i].clear();
            while (m--)
            {
                int x, y, w;
                cin >> x >> y >> w;
                v[x].push_back(make_pair(y, w));
            }
            memset(dp, 0, sizeof(dp));
            for (int i = 1; i <= n; i++)
            {
                sort(v[i].begin(), v[i].end());
                for (int j = 0; j <= k; j++) dp[i][0] = max(dp[i][0], dp[i - 1][j]);
                int now = 0, sum = 0;
                for (int j = 1; j <= k; j++)
                {
                    while (now < v[i].size() && v[i][now].first <= j) sum += v[i][now].second, now++;
                    dp[i][j] = dp[i - 1][j - 1] + sum - d;
                }
            }
            int ans = 0;
            for (int i = 0; i <= k; i++) ans = max(ans, dp[n][i]);
            cout << ans << '\n';
        }
    }
    else if (c <= 11)
    {
        while (t--)
        {
            int n, m, k, d;
            cin >> n >> m >> k >> d;
            for (int i = 1; i <= n; i++) v[i].clear();
            mp.clear();
            vector<int> vec;
            while (m--)
            {
                int x, y, w;
                cin >> x >> y >> w;
                v[x].push_back(make_pair(y, w));
                if (!mp[x]) vec.push_back(x);
                if (!mp[x - y + 1]) vec.push_back(x - y + 1);
                mp[x] = mp[x - y + 1] = 1;
            }
            vec.push_back(0);
            sort(vec.begin(), vec.end());
            memset(dp2, 0, sizeof(dp2));
            for (int i = 1; i < vec.size(); i++)
            {
                int y = vec[i];
                sort(v[y].begin(), v[y].end());
                memset(dp2[i & 1], 0, sizeof(dp2[i & 1]));
                for (int j = 0; j <= k; j++) dp2[i & 1][0] = max(dp2[i & 1][0], dp2[i & 1 ^ 1][j]);
                for (int j = 1; j < vec[i] - vec[i - 1]; j++) dp2[i & 1][j] = dp2[i & 1][j - 1] - d;
                int now = 0, sum = 0;
                for (int j = vec[i] - vec[i - 1]; j <= k; j++)
                {
                    while (now < v[y].size() && v[y][now].first <= j) sum += v[y][now].second, now++;
                    dp2[i & 1][j] = dp2[i & 1 ^ 1][j - (vec[i] - vec[i - 1])] + sum - d * (vec[i] - vec[i - 1]);
                }
            }
            int ans = 0;
            for (int i = 0; i <= k; i++) ans = max(ans, dp2[vec.size() & 1 ^ 1][i]);
            cout << ans << '\n';
        }
    }
    else
    {
        while (t--)
        {
            int n, m, k, d;
            cin >> n >> m >> k >> d;
            int ans = 0;
            while (m--)
            {
                int x, y, w;
                cin >> x >> y >> w;
                if (y <= k && w - d * y > 0) ans += w - d * y;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}