#include <iostream>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

struct Edge {
    int v;
    int w;
    int a;
    Edge(int _v, int _w, int _a) {
        v = _v;
        w = _w;
        a = _a;
    }
};

int Dijkstra(int n, int m, int k, vector<vector<Edge>>& adj_list) {
    vector<int> dist(n + 1, numeric_limits<int>::max());
    dist[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, 1));

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (int i = 0; i < adj_list[u].size(); i++) {
            int v = adj_list[u][i].v;
            int w = adj_list[u][i].w;
            int a = adj_list[u][i].a;

            int new_dist = d + w;

            if (new_dist % k < a) {
                int wait_time = a - new_dist % k;
                new_dist += wait_time;
            }

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push(make_pair(new_dist, v));
            }
        }
    }

    return dist[n];
}

int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<Edge>> adj_list(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, a;
        cin >> u >> v >> a;
        adj_list[u].push_back(Edge(v, 1, a));
    }

    int ans = Dijkstra(n, m, k, adj_list);

    if (ans == numeric_limits<int>::max()) {
        cout << -1 << endl;
    } else {
        cout << ans*k << endl;
    }

    return 0;
}//
