#include <bits/stdc++.h>

using namespace std;

struct st{
    int nxt, time;
};

struct st2{
    int num, time;
};

int n;
int m;
int k;
int in[10001];
int out[10001];
int num[10001];

vector<st> G[10001];
queue<st2> q;

int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);

    cin >> n >> m >> k ;

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z ;
        st t;
        t.nxt = y;
        t.time = z;
        G[x].push_back(t);
    }

    out[1] = 1;
    memset(num, -1, sizeof num);
    num[1] = k;
    st2 t;
    t.num = 1;
    t.time = k;
    q.push(t);

    while (!q.empty()) {
        st2 tot = q.front();
        q.pop();
        int totnum = tot.num;
        int len = G[totnum].size();
        for (int i = 0; i < len; i++) {
            if (G[totnum][i].time <= tot.time) {
                t.num = i + 1;
                out[i + 1]--;
                t.time = tot.time + 1;
                num[i] = t.time;
                q.push(t);
            }
        }
    }

    cout << ceil(1.0 * num[n] / k) + k << endl;

    return 0;
}
