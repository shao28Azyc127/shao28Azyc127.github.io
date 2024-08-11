#include <iostream>
#include <queue>
#include <cmath>
#define int unsigned long long
using namespace std;
int n;

int a[100001], b[100001], c[100001];

int help(int day, int x, int y, int z){
    while (x > 0){
        x -= max(y + z * day, 1ULL);
        day++;
    }
    return day - 1;
}

vector<int> g[100001];
signed main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> c[i];
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    queue<int> q;
    q.push(1);
    int day = 0;
    int enday = 0;
    while (!q.empty())
    {
        vector<int> v;
        day++;
        int x = q.size(), y = 0, z = -1;
        for (int i = 1; i <= x; i++){
            int k = help(day, a[q.front()], b[q.front()], c[q.front()]);
            if (y < k) { y = k, z = q.front(); }

            v.push_back(q.front());
            q.pop();
        }
        for (auto tt:v){
            if (tt != z) q.push(tt);
        }
        enday = max(enday, y);
        for (auto x : g[z]){
            q.push(x);
        }
    }
    cout << enday;
    return 0;
}
