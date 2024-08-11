//#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
using namespace std;

ifstream cin("tribool.in");
ofstream cout("tribool.out");

constexpr int VAL_T = 0x3f3f3f3f;
constexpr int VAL_F = -0x3f3f3f3f;
constexpr int VAL_U = 0;

int val[100005];

vector<pair<int, int> > edges[100005];
int ans[100005];
bool vis[100005];

bool dfs(int node)
{
    vis[node] = true;
    //cout << "visit " << node << "  now val=" << ans[node] << endl;
    for(pair<int, int> pii : edges[node])
    {
        if(vis[pii.first] && ans[node] && ans[pii.first] && ans[pii.first] != ans[node] * pii.second) return false;
        if(ans[pii.first] == ans[node] * pii.second) continue;
        ans[pii.first] = ans[node] * pii.second;
        if(!dfs(pii.first)) return false;
    }
    return true;
}

int main()
{
    int C, T;
    cin >> C >> T;
    while(T--)
    {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
        {
            val[i] = i;
        }
        for(int i = 1; i <= m; i++)
        {
            char v;
            int fir, sec;
            cin >> v >> fir;
            if(v == 'T') val[fir] = VAL_T;
            if(v == 'F') val[fir] = VAL_F;
            if(v == 'U') val[fir] = VAL_U;
            if(v == '+')
            {
                cin >> sec;
                val[fir] = val[sec];
            }
            if(v == '-')
            {
                cin >> sec;
                val[fir] = -val[sec];
            }
        }
        //cout << "check" << endl;
        for(int i = 1; i <= n; i++)
        {
            edges[i].clear();
            ans[i] = -1;
            vis[i] = false;
        }
        for(int i = 1; i <= n; i++)
        {
            if(val[i] == VAL_T || val[i] == VAL_F || val[i] == VAL_U)
            {
                ans[i] = val[i];
                continue;
            }
            if(val[i] < 0)
            {
                edges[i].push_back({-val[i], -1});
                edges[-val[i]].push_back({i, -1});
            }
            if(val[i] > 0)
            {
                edges[i].push_back({val[i], 1});
                edges[val[i]].push_back({i, 1});
            }
        }
        //cout << "check" << endl;
        for(int i = 1; i <= n; i++)
        {
            if(val[i] == VAL_T || val[i] == VAL_F || val[i] == VAL_U) dfs(i);
        }
        for(int i = 1; i <= n; i++)
        {
            if(vis[i]) continue;
            ans[i] = VAL_T;
            //cout << i << endl;
            if(!dfs(i))
            {
                //cout << "wrong" << endl;
                ans[i] = VAL_U;
                dfs(i);
            }
        }
        //cout << "check" << endl;
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(ans[i] == VAL_U) ++cnt;
        }
        cout << cnt << '\n';
    }
}
