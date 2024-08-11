#include<bits/stdc++.h>
using namespace std;

int a[10001];
vector<int> p[20001];
queue<int> q;
int n, m, k, u, v, fr;

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v >> a[i];
        p[u].push_back(v);
    }
    bool flag = 1;
    long long ans = 0, size = 1;
    q.push(1);
    while(flag)
    {
        ans++;
        for(int i = 0; i < size; i++)
        {
            fr = q.front();
            if(fr == n && ans % k == 0)
            {
                cout << ans << endl;
                return 0;
            }
            for(int j = 0; j < p[fr].size(); j++)
                q.push(p[fr][j]);
            q.pop();
        }
    }
    return 0;
}