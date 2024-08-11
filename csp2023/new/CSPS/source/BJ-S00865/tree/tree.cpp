//#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream cin("tree.in");
ofstream cout("tree.out");

vector<int> edges[100005];

int n, u, v;
long long a[100005], b[100005], c[100005];
int max_time[100005];

vector<int> dfs(int node = 1, int fa = 0)
{
    int min_time = max_time[node];
    vector<int> res;
    for(int nxt : edges[node])
    {
        if(nxt != fa)
        {
            vector<int> num = dfs(nxt, fa);
            if(min_time >= res[0]) min_time = res[0] - 1;
            for(int x : num)
            {
                res.push_back(x);
            }
        }
    }
    res.push_back(min_time);
    sort(res.begin(), res.end());
    int last = res[res.size() - 1];
    for(int i = res.size() - 2; i >= 0; i--)
    {
        if(res[i] >= last) res[i] = last - 1;
        last = res[i];
    }
    return res;
}

bool check(int day)
{
    for(int i = 1; i <= n; i++)
    {
        max_time[i] = day - (a[i] + b[i] - 1) / b[i] + 1;
    }
    return dfs()[0] >= 1;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    for(int i = 1; i < n; i++)
    {
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    int l = n, r = 1000000000, mid;
    while(l < r)
    {
        mid = (l + r) >> 1;
        if(check(mid))
        {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l;
}
