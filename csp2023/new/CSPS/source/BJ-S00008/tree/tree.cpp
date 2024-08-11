#include <bits/stdc++.h>

using namespace std;

int n;
int a[100001];
int b[100001];
int c[100001];
int high[100001];
bool plant[100001];
int day = 1;

vector<int> G[100001];
queue<int> q;

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    cin >> n ;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    int n1 = n - 1;

    for (int i = 0; i < n1; i++) {
        int u, v;
        cin >> u >> v ;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    q.push(1);

    while (!q.empty()) {
        int tot = q.front();
        q.pop();
        int len = G[tot].size();
        for (int i = 0; i < len; i++) {
            if (!plant[G[tot][i]]) {
                plant[G[tot][i]] = 1;
                q.push(G[tot][i]);
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            high[i] += max(b[i] + day * c[i], 1);
        }
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            if (high[i] < a[i]) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            cout << day << endl;
        }
        day++;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
