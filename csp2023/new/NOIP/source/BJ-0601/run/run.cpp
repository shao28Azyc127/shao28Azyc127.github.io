#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c, t, n, m, k, d; //试运行的天数、挑战的个数、大 Y 单次跑步打卡的连续天数限制以及大 Y 跑步打卡减少的能量值
ll ans = 0;
ll cnttt = 0;
bool vis[1005];
struct challenge //start from start + 1, end at x, duration:y
{
    ll x, y, v;
    ll start;
}challs[100005];

bool cmp(challenge &a, challenge &b)
{
    if (a.start != b.start)
        return a.start > b.start;
    if (a.y != b.y)
        return a.y > b.y;
    if (a.x != b.x)
    {
        return a.x > b.x;
    }
    else return a.v < b.v;
}
void dfs(bool v[], ll energy, long long ci, bool take)  //vis, energy, challengeindex
{
    cnttt++;
    if (cnttt % 100000 == 0)
    {
        cout << cnttt << endl;
    }
    bool vi[1005];
    for (int i = 0;i<=n;i++)
    {
        vi[i] = v[i];
    }
    //if (0-challs[ci].y * d + challs[ci].v < 0) return;
    if (ci >= m) return;
    //cout << energy << " " << ci << " " << take << endl;
    if (!take)
    {
        dfs(vi, energy, ci+1, true);
        dfs(vi, energy, ci+1, false);
    }
    challenge c = challs[ci];
    long long cnt = 0;  //count for decrease energy
    for (int i = c.start; i <= c.x;++i)
    {
        //cout << vi[i] << " ";
        if (!vi[i])
        {
            vi[i] = true;
            cnt++;
        }
    }
    //cout << endl;
    long long ccc = 0;
    for (int i = 0;i<=n;i++)
    {
        if (vi[i] == true) ++ccc;
        else ccc = 0;
        if (ccc > k) return;
    }
    //cout << "cnt" << cnt << endl;
    ll invest = c.v - cnt * d;
    //cout << invest << "=" << c.v << "-" << cnt * d << endl;
    //if (invest < 0)return;
    ans = max(ans, energy + invest);
    if (ans == energy + invest)
    {

    dfs(vi, energy + invest, ci+1, true);
    dfs(vi, energy + invest, ci+1, false);
    }

}



int main()
{
    ios::sync_with_stdio(false);
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    cin >> c >> t;
    while(t--)
    {
        ans = 0;
        cin >> n >> m >> k >>d;
        for (int i = 0;i<m;i++)
        {
            cin >> challs[i].x >> challs[i].y >> challs[i].v;
            challs[i].start = challs[i].x-challs[i].y+1;
            if (challs[i].start <= 0 || challs[i].y > k)
            {
                i--;
                m--;
            }
        }
        //sort(challs, challs + m, cmp);
        memset(vis, 0, sizeof(vis));
        dfs(vis, 0, 0, true);
        dfs(vis, 0, 0, false);

        cout << ans << endl;
    }
}
//1 2     /25
